/** 
 * Generated by DDSCS: Do not edit.  Version 1.0 *
 */


#include "ServerExceptionProxy.h"
#include "client/ClientRPC.h"
#include "transports/UDPTransport.h"
#include "transports/TCPTransport.h"
#include "ServerExceptionRequestReplyPlugin.h"
#include "ServerExceptionAsyncSupport.h"
#include "exceptions/Exceptions.h"

ServerExceptionProxy::ServerExceptionProxy(std::string remoteServiceName, int domainId, long timeout) :
    Client(remoteServiceName, NULL, domainId, timeout)
{
    createRPCs();
}

ServerExceptionProxy::ServerExceptionProxy(std::string remoteServiceName, eProsima::DDSRPC::Transport *transport, int domainId, long timeout) :
    Client(remoteServiceName, transport, domainId, timeout)
{
    createRPCs();
}

ServerExceptionProxy::~ServerExceptionProxy()
{
    delete sendException_Service;
    delete sendExceptionTwo_Service;
    delete sendExceptionThree_Service;
}

void ServerExceptionProxy::createRPCs()
{
    this->sendException_Service = new ServerException_sendExceptionClientRPC("sendException",
                                  ServerException_sendExceptionRequestUtils::registerType(getParticipant()),
                                  ServerException_sendExceptionReplyUtils::registerType(getParticipant()),
                                  this);
    this->sendExceptionTwo_Service = new ServerException_sendExceptionTwoClientRPC("sendExceptionTwo",
                                  ServerException_sendExceptionTwoRequestUtils::registerType(getParticipant()),
                                  ServerException_sendExceptionTwoReplyUtils::registerType(getParticipant()),
                                  this);
    this->sendExceptionThree_Service = new ServerException_sendExceptionThreeClientRPC("sendExceptionThree",
                                  ServerException_sendExceptionThreeRequestUtils::registerType(getParticipant()),
                                  ServerException_sendExceptionThreeReplyUtils::registerType(getParticipant()),
                                  this);

}

 
void ServerExceptionProxy::sendException() 
{
    eProsima::DDSRPC::ReturnMessage retcode = eProsima::DDSRPC::CLIENT_INTERNAL_ERROR;
    ServerException_sendExceptionRequest instance;
    ServerException_sendExceptionReply retInstance;

    ServerException_sendExceptionReply_initialize(&retInstance);    
    ServerException_sendExceptionRequestUtils::setTypeData(instance);
    retcode = sendException_Service->execute(&instance, &retInstance, getTimeout());
    
    if(retcode == eProsima::DDSRPC::OPERATION_SUCCESSFUL)
    {
        ServerException_sendExceptionReplyUtils::extractTypeData(retInstance, retcode);  
    }
    
    switch (retcode)
    {
        case eProsima::DDSRPC::CLIENT_INTERNAL_ERROR:
            throw eProsima::DDSRPC::ClientInternalException("Error in client side");
            break;
        case eProsima::DDSRPC::NO_SERVER:
            throw eProsima::DDSRPC::ServerNotFoundException("Cannot connect to the server");
            break;
        case eProsima::DDSRPC::SERVER_TIMEOUT:
            throw eProsima::DDSRPC::ServerTimeoutException("Timeout waiting the server's reply");
            break;
        case eProsima::DDSRPC::SERVER_INTERNAL_ERROR:
            throw eProsima::DDSRPC::ServerInternalException(retInstance.header.ddsrpcRetMsg);
            break;
    };
    

}
 
char* ServerExceptionProxy::sendExceptionTwo(/*in*/ char* message, /*inout*/ char*& message2, /*out*/ char*& message3) 
{
    eProsima::DDSRPC::ReturnMessage retcode = eProsima::DDSRPC::CLIENT_INTERNAL_ERROR;
    char*  sendExceptionTwo_ret = NULL;    
    ServerException_sendExceptionTwoRequest instance;
    ServerException_sendExceptionTwoReply retInstance;

    ServerException_sendExceptionTwoReply_initialize(&retInstance);    
    ServerException_sendExceptionTwoRequestUtils::setTypeData(instance, message, message2);
    retcode = sendExceptionTwo_Service->execute(&instance, &retInstance, getTimeout());
    
    if(retcode == eProsima::DDSRPC::OPERATION_SUCCESSFUL)
    {
        ServerException_sendExceptionTwoReplyUtils::extractTypeData(retInstance, retcode, message2, message3, sendExceptionTwo_ret);  
    }
    
    switch (retcode)
    {
        case eProsima::DDSRPC::CLIENT_INTERNAL_ERROR:
            throw eProsima::DDSRPC::ClientInternalException("Error in client side");
            break;
        case eProsima::DDSRPC::NO_SERVER:
            throw eProsima::DDSRPC::ServerNotFoundException("Cannot connect to the server");
            break;
        case eProsima::DDSRPC::SERVER_TIMEOUT:
            throw eProsima::DDSRPC::ServerTimeoutException("Timeout waiting the server's reply");
            break;
        case eProsima::DDSRPC::SERVER_INTERNAL_ERROR:
            throw eProsima::DDSRPC::ServerInternalException(retInstance.header.ddsrpcRetMsg);
            break;
    };
    

    return sendExceptionTwo_ret;
}
 
Estructura ServerExceptionProxy::sendExceptionThree(/*in*/ const Estructura& es, /*inout*/ Estructura& es2, /*out*/ Estructura& es3) 
{
    eProsima::DDSRPC::ReturnMessage retcode = eProsima::DDSRPC::CLIENT_INTERNAL_ERROR;
    Estructura sendExceptionThree_ret;
        
    ServerException_sendExceptionThreeRequest instance;
    ServerException_sendExceptionThreeReply retInstance;

    ServerException_sendExceptionThreeReply_initialize(&retInstance);    
    ServerException_sendExceptionThreeRequestUtils::setTypeData(instance, es, es2);
    retcode = sendExceptionThree_Service->execute(&instance, &retInstance, getTimeout());
    
    if(retcode == eProsima::DDSRPC::OPERATION_SUCCESSFUL)
    {
        ServerException_sendExceptionThreeReplyUtils::extractTypeData(retInstance, retcode, es2, es3, sendExceptionThree_ret);  
    }
    
    switch (retcode)
    {
        case eProsima::DDSRPC::CLIENT_INTERNAL_ERROR:
            throw eProsima::DDSRPC::ClientInternalException("Error in client side");
            break;
        case eProsima::DDSRPC::NO_SERVER:
            throw eProsima::DDSRPC::ServerNotFoundException("Cannot connect to the server");
            break;
        case eProsima::DDSRPC::SERVER_TIMEOUT:
            throw eProsima::DDSRPC::ServerTimeoutException("Timeout waiting the server's reply");
            break;
        case eProsima::DDSRPC::SERVER_INTERNAL_ERROR:
            throw eProsima::DDSRPC::ServerInternalException(retInstance.header.ddsrpcRetMsg);
            break;
    };
    

    return sendExceptionThree_ret;
}

 
void ServerExceptionProxy::sendException_async(ServerException_sendExceptionCallbackHandler &obj) 
{
	eProsima::DDSRPC::ReturnMessage retcode = eProsima::DDSRPC::CLIENT_INTERNAL_ERROR;
    ServerException_sendExceptionRequest instance;
    ServerException_sendExceptionTask *task = NULL;
    ServerException_sendExceptionRequestUtils::setTypeData(instance);
    task = new ServerException_sendExceptionTask(obj, this);
    retcode = sendException_Service->executeAsync(&instance, task, getTimeout());
    
    switch (retcode)
    {
        case eProsima::DDSRPC::CLIENT_INTERNAL_ERROR:
            throw eProsima::DDSRPC::ClientInternalException("Error in client side");
            break;
        case eProsima::DDSRPC::NO_SERVER:
             throw eProsima::DDSRPC::ServerNotFoundException("Cannot connect to the server");
             break;
    }
}
 
void ServerExceptionProxy::sendExceptionTwo_async(ServerException_sendExceptionTwoCallbackHandler &obj, /*in*/ char* message, /*inout*/ char* message2) 
{
	eProsima::DDSRPC::ReturnMessage retcode = eProsima::DDSRPC::CLIENT_INTERNAL_ERROR;
    ServerException_sendExceptionTwoRequest instance;
    ServerException_sendExceptionTwoTask *task = NULL;
    ServerException_sendExceptionTwoRequestUtils::setTypeData(instance, message, message2);
    task = new ServerException_sendExceptionTwoTask(obj, this);
    retcode = sendExceptionTwo_Service->executeAsync(&instance, task, getTimeout());
    
    switch (retcode)
    {
        case eProsima::DDSRPC::CLIENT_INTERNAL_ERROR:
            throw eProsima::DDSRPC::ClientInternalException("Error in client side");
            break;
        case eProsima::DDSRPC::NO_SERVER:
             throw eProsima::DDSRPC::ServerNotFoundException("Cannot connect to the server");
             break;
    }
}
 
void ServerExceptionProxy::sendExceptionThree_async(ServerException_sendExceptionThreeCallbackHandler &obj, /*in*/ const Estructura& es, /*inout*/ const Estructura& es2) 
{
	eProsima::DDSRPC::ReturnMessage retcode = eProsima::DDSRPC::CLIENT_INTERNAL_ERROR;
    ServerException_sendExceptionThreeRequest instance;
    ServerException_sendExceptionThreeTask *task = NULL;
    ServerException_sendExceptionThreeRequestUtils::setTypeData(instance, es, es2);
    task = new ServerException_sendExceptionThreeTask(obj, this);
    retcode = sendExceptionThree_Service->executeAsync(&instance, task, getTimeout());
    
    switch (retcode)
    {
        case eProsima::DDSRPC::CLIENT_INTERNAL_ERROR:
            throw eProsima::DDSRPC::ClientInternalException("Error in client side");
            break;
        case eProsima::DDSRPC::NO_SERVER:
             throw eProsima::DDSRPC::ServerNotFoundException("Cannot connect to the server");
             break;
    }
}