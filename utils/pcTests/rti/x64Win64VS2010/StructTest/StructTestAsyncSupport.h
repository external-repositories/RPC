#ifndef _StructTest_ASYNC_SUPPORT_H_
#define _StructTest_ASYNC_SUPPORT_H_

/** 
 * Generated by DDSCS: Do not edit.  Version 1.0 *
 */

#include "client/AsyncTask.h"


/**
 * \brief This class represents a asynchronous task created to wait the reply of the procedure duplicate from the server in an asynchronous call.
 */
class StructTest_duplicateTask : public eProsima::DDSRPC::AsyncTask
{
    public:

        /**
         * \brief The default constructor.
         *
         * \param obj Object that implements the callbacks that DDSRPC will call when
         *            the reply will be received or and exception will be launched.
         * \param client Pointer to the server's proxy. Cannot be NULL.
         */
        StructTest_duplicateTask(StructTest_duplicateCallbackHandler &obj,
           eProsima::DDSRPC::Client *client);

        /// \brief The default destructor.
        virtual ~StructTest_duplicateTask();
        
        virtual void execute();
        
        virtual void on_exception(const eProsima::DDSRPC::SystemException &ex);
        
        /**
         * \brief This function returns the object used by the task.
         *
         * \return The object that implements the callbacks.
         */
        StructTest_duplicateCallbackHandler& getObject();
        
        void* getReplyInstance();
        
        private:
        
           StructTest_duplicateCallbackHandler &m_obj;
           
           StructTest_duplicateReply m_reply;
};

/**
 * \brief This class represents a asynchronous task created to wait the reply of the procedure suma from the server in an asynchronous call.
 */
class StructTest_sumaTask : public eProsima::DDSRPC::AsyncTask
{
    public:

        /**
         * \brief The default constructor.
         *
         * \param obj Object that implements the callbacks that DDSRPC will call when
         *            the reply will be received or and exception will be launched.
         * \param client Pointer to the server's proxy. Cannot be NULL.
         */
        StructTest_sumaTask(StructTest_sumaCallbackHandler &obj,
           eProsima::DDSRPC::Client *client);

        /// \brief The default destructor.
        virtual ~StructTest_sumaTask();
        
        virtual void execute();
        
        virtual void on_exception(const eProsima::DDSRPC::SystemException &ex);
        
        /**
         * \brief This function returns the object used by the task.
         *
         * \return The object that implements the callbacks.
         */
        StructTest_sumaCallbackHandler& getObject();
        
        void* getReplyInstance();
        
        private:
        
           StructTest_sumaCallbackHandler &m_obj;
           
           StructTest_sumaReply m_reply;
};

#endif // _StructTest_ASYNC_SUPPORT_H_