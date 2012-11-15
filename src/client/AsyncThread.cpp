#include "client/AsyncThread.h"
#include "client/AsyncTask.h"
#include "client/ClientRPC.h"
#include "utils/Typedefs.h"
#include "exceptions/ServerTimeoutException.h"

#include <stdio.h>

static const char* const CLASS_NAME = "eProsima::DDSRPC::AsyncThread";

namespace eProsima
{
    namespace DDSRPC
    {
        bool asyncListSort(AsyncListPair i, AsyncListPair j)
        {
            return (i.first < j.first);
        }

        AsyncThread::AsyncThread() : m_guardWaitSet(NULL), m_exit(0)
        {
            m_timeout.sec = DDS::DURATION_INFINITE_SEC;
            m_timeout.nanosec = DDS::DURATION_INFINITE_NSEC;
        }

        int AsyncThread::init()
        {
            const char* const METHOD_NAME = "init";

            m_guardWaitSet = new DDS::GuardCondition();

            if(m_guardWaitSet != NULL)
            {
                m_waitSet = new DDS::WaitSet();

                if(m_waitSet != NULL)
                {
                    m_mutex =  new boost::mutex();

                    if(m_mutex != NULL)
                    {
                        try
                        {
                            m_thread = boost::thread(&AsyncThread::run, this);
                            return 0;
                        }
                        catch(boost::thread_resource_error ex)
                        {
                            printf("ERROR<%s::%s>: Cannot create thread\n", CLASS_NAME, METHOD_NAME);
                        }

                        delete m_mutex;
                    }
                    else
                    {
                        printf("ERROR<%s::%s>: Cannot create mutex\n", CLASS_NAME, METHOD_NAME);
                    }

                    delete m_waitSet;
                }
                else
                {
                    printf("ERROR<%s::%s>: Cannot create waitset\n", CLASS_NAME, METHOD_NAME);
                }

                delete m_guardWaitSet;
            }
            else
            {
                printf("ERROR<%s::%s>: Cannot create guard condition\n", CLASS_NAME, METHOD_NAME);
            }

            return -1;
        }

        void AsyncThread::exit()
        {
            m_exit = 1;
            m_guardWaitSet->set_trigger_value(1);
            m_thread.join();
            delete m_mutex;
            delete m_waitSet;
            delete m_guardWaitSet;
        }

        void AsyncThread::run()
        {
            const char* const METHOD_NAME = "run";
            DDS::Duration_t timeout = {DDS::DURATION_INFINITE_SEC, DDS::DURATION_INFINITE_NSEC};

            if(m_waitSet->attach_condition(m_guardWaitSet) == DDS::RETCODE_OK)
            {
                while(m_exit == 0)
                {
                    DDS::ReturnCode_t retCode;
                    DDS::ConditionSeq conds;
                    AsyncVector::iterator it;

                    boost::posix_time::ptime init_wait_moment = boost::posix_time::microsec_clock::local_time(); 

                    retCode = m_waitSet->wait(conds, timeout);

                    boost::posix_time::ptime final_wait_moment = boost::posix_time::microsec_clock::local_time();

                    boost::lock_guard<boost::mutex> lock_guard(*m_mutex);

                    // Update timeouts.
                    boost::posix_time::time_duration td = final_wait_moment - init_wait_moment;

                    for(it = m_vector.begin(); it != m_vector.end(); ++it)
                    {
                        it->first = it->first - td;
                        if(it->first.is_negative())
                            it->first = boost::posix_time::milliseconds(0);
                    }

                    if(retCode == DDS::RETCODE_OK)
                    {
                        for(int i = 0; i < conds.length(); ++i)
                        {
                            if(conds[i] == m_guardWaitSet)
                            {
                                m_guardWaitSet->set_trigger_value(BOOLEAN_FALSE);
                                // Signal the add function.
                                m_cond_wake_up.notify_one();
                            }
                            else
                            {
                                it = m_vector.begin();

                                for(; it != m_vector.end(); ++it)
                                {
                                    if(conds[i] == it->second.first)
                                    {
                                        break;
                                    }
                                }

                                if(it != m_vector.end())
                                {
                                    it->second.second->execute(it->second.first);
                                    m_waitSet->detach_condition(it->second.first);
                                    it->second.second->getRPC()->deleteQuery(it->second.first);
                                    delete it->second.second;
                                    m_vector.erase(it);
                                }
                            }
                        }
                    }
                    else if(retCode == DDS::RETCODE_TIMEOUT)
                    {
                        printf("WARNING <%s::%s>: Wait timeout. Retrying.\n", CLASS_NAME, METHOD_NAME);
                        
                        // Find the out of life tasks.
                        it = m_vector.begin();
                        while(it != m_vector.end())
                        {
                            if(it->first == boost::posix_time::milliseconds(0))
                            {
                                //TODO Send exception
                                it->second.second->on_exception(ServerTimeoutException("Asynchronous task exceed the time to wait the server's reply"));
                                m_waitSet->detach_condition(it->second.first);
                                it->second.second->getRPC()->deleteQuery(it->second.first);
                                //TODO No borrar.
                                delete it->second.second;
                                it = m_vector.erase(it);
                            }
                            else
                            {
                                ++it;
                            }
                        }
                    }

                    if(m_vector.empty())
                    {
                        timeout = m_timeout;
                        m_timeout.sec = DDS::DURATION_INFINITE_SEC;
                        m_timeout.nanosec = DDS::DURATION_INFINITE_NSEC;
                    }
                    else
                    {
                        DDS_TIMEOUT(auxTimeout, m_vector.begin()->first);

                        if((auxTimeout.sec < m_timeout.sec) ||
                                (auxTimeout.sec == m_timeout.sec && auxTimeout.nanosec < m_timeout.nanosec))
                        {
                            timeout = auxTimeout;
                        }
                        else
                            timeout = m_timeout;
                    }
                }

                m_waitSet->detach_condition(m_guardWaitSet);
            }
            else
            {
                printf("ERROR<%s::%s>: Cannot attach the guard condition to waitset\n", CLASS_NAME, METHOD_NAME);
            }

            return;
        }

        int AsyncThread::addTask(DDS::QueryCondition *query, AsyncTask *task, long timeout)
        {
            const char* const METHOD_NAME = "addTask";
            int returnedValue = -1;

            if(query != NULL && task != NULL)
            {
                AsyncTaskPair tpair(query, task);
                AsyncListPair lpair(boost::posix_time::milliseconds(timeout), tpair);

                boost::unique_lock<boost::mutex> lock(*m_mutex);

                // Set timeout like new for next calculation.
                DDS_TIMEOUT_SET(m_timeout, lpair.first);

                // Wake up the waitSet.
                m_guardWaitSet->set_trigger_value(BOOLEAN_TRUE);
                m_cond_wake_up.wait(lock);

                // Add new task and sort vector.
                m_vector.push_back(lpair);
                std::sort(m_vector.begin(), m_vector.end(), asyncListSort);

                // Attach query.
                if(m_waitSet->attach_condition(query) == DDS::RETCODE_OK)
                {
                    returnedValue = 0;
                }
                else
                {
                    printf("ERROR<%s::%s>: Cannot attach query condition\n", CLASS_NAME, METHOD_NAME);
                }
            }
            else
            {
                printf("ERROR<%s::%s>: Bad parameters\n", CLASS_NAME, METHOD_NAME);
            }

            return returnedValue;
        }

    } // namespace DDSRPC
} // namespace eProsima
