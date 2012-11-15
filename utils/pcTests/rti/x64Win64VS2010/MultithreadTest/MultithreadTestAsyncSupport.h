#ifndef _MultithreadTest_ASYNC_SUPPORT_H_
#define _MultithreadTest_ASYNC_SUPPORT_H_

/** 
 * Generated by DDSCS: Do not edit.  Version 1.0 *
 */

#include "client/AsyncTask.h"


class MultithreadTest_testTask : public eProsima::DDSRPC::AsyncTask
{
    public:

        /// \brief The default constructor.
        MultithreadTest_testTask(MultithreadTest_testCallbackHandler &obj,
           eProsima::DDSRPC::Client *client);

        /// \brief The default destructor.
        virtual ~MultithreadTest_testTask();
        
        virtual void execute();
        
        virtual void on_exception(const eProsima::DDSRPC::SystemException &ex);
        
        MultithreadTest_testCallbackHandler& getObject();
        
        void* getReplyInstance();
        
        private:
        
           MultithreadTest_testCallbackHandler &m_obj;
           
           MultithreadTest_testReply m_reply;
};

#endif // _MultithreadTest_ASYNC_SUPPORT_H_