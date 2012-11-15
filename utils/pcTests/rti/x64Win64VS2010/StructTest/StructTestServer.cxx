/** 
 * Generated by DDSCS: Do not edit.  Version 1.0 *
 */

#include "StructTestServer.h"
#include "transports/UDPTransport.h"
#include "transports/TCPTransport.h"
#include "exceptions/ServerInternalException.h"
#include "StructTestRequestReplyPlugin.h"

#include "StructTestServerRPCSupport.h"

StructTestServer::StructTestServer(std::string serviceName, eProsima::DDSRPC::ServerStrategy *strategy,
    int domainId) :
    Server(serviceName, strategy, NULL, domainId)
{
    _impl = new StructTestServerImpl();

    createRPCs();
}

StructTestServer::StructTestServer(std::string serviceName, eProsima::DDSRPC::ServerStrategy *strategy,
    eProsima::DDSRPC::Transport *transport, int domainId) :
    Server(serviceName, strategy, transport, domainId)
{
    _impl = new StructTestServerImpl();
    
    createRPCs();
}

StructTestServer::~StructTestServer()
{
    delete _impl;    
}

void StructTestServer::createRPCs()
{
    this->setRPC(new StructTest_duplicateServerRPC("duplicate", this,
                StructTest_duplicateRequestUtils::registerType(getParticipant()),
                StructTest_duplicateReplyUtils::registerType(getParticipant()),
                &StructTestServer::duplicate));
    this->setRPC(new StructTest_sumaServerRPC("suma", this,
                StructTest_sumaRequestUtils::registerType(getParticipant()),
                StructTest_sumaReplyUtils::registerType(getParticipant()),
                &StructTestServer::suma));

}

void StructTestServer::duplicate(eProsima::DDSRPC::Server *server, void *requestData, eProsima::DDSRPC::ServerRPC *service) 
{ 
    StructTestServer *srv = dynamic_cast<StructTestServer*>(server);
    Envio ev;
        
    Recepcion duplicate_ret;
    memset(&duplicate_ret, 0, sizeof(Recepcion));       
    StructTest_duplicateReply replyData;
    

    StructTest_duplicateRequestUtils::extractTypeData(*(StructTest_duplicateRequest*)requestData, ev);

    try
    {
        duplicate_ret = srv->_impl->duplicate(ev);

        StructTest_duplicateReplyUtils::setTypeData(replyData, duplicate_ret);
        replyData.header.ddsrpcRetCode = eProsima::DDSRPC::OPERATION_SUCCESSFUL;
        replyData.header.ddsrpcRetMsg = NULL;

        service->sendReply(requestData, &replyData);
    }
    catch(const eProsima::DDSRPC::ServerInternalException &ex)
    {
        memset(&replyData, 0, sizeof(replyData));
        replyData.header.ddsrpcRetCode = eProsima::DDSRPC::SERVER_INTERNAL_ERROR;
        replyData.header.ddsrpcRetMsg = (char*)ex.what();
        
        service->sendReply(requestData, &replyData);
    }
    
    StructTest_duplicateRequestTypeSupport::delete_data((StructTest_duplicateRequest*)requestData);
    
    Recepcion_finalize(&duplicate_ret);    
}
void StructTestServer::suma(eProsima::DDSRPC::Server *server, void *requestData, eProsima::DDSRPC::ServerRPC *service) 
{ 
    StructTestServer *srv = dynamic_cast<StructTestServer*>(server);
    Envio ev1;
        
    Envio ev2;
        
    Recepcion suma_ret;
    memset(&suma_ret, 0, sizeof(Recepcion));       
    StructTest_sumaReply replyData;
    

    StructTest_sumaRequestUtils::extractTypeData(*(StructTest_sumaRequest*)requestData, ev1, ev2);

    try
    {
        suma_ret = srv->_impl->suma(ev1, ev2);

        StructTest_sumaReplyUtils::setTypeData(replyData, suma_ret);
        replyData.header.ddsrpcRetCode = eProsima::DDSRPC::OPERATION_SUCCESSFUL;
        replyData.header.ddsrpcRetMsg = NULL;

        service->sendReply(requestData, &replyData);
    }
    catch(const eProsima::DDSRPC::ServerInternalException &ex)
    {
        memset(&replyData, 0, sizeof(replyData));
        replyData.header.ddsrpcRetCode = eProsima::DDSRPC::SERVER_INTERNAL_ERROR;
        replyData.header.ddsrpcRetMsg = (char*)ex.what();
        
        service->sendReply(requestData, &replyData);
    }
    
    StructTest_sumaRequestTypeSupport::delete_data((StructTest_sumaRequest*)requestData);
    
    Recepcion_finalize(&suma_ret);    
}