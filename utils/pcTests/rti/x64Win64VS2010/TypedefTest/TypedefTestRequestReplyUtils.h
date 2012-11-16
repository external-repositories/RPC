
#ifndef _TypedefTest_REQUEST_REPLY_UTILS_H_
#define _TypedefTest_REQUEST_REPLY_UTILS_H_

/** 
 * Generated by DDSCS: Do not edit.  Version 1.0 *
 */

#include "utils/Messages.h"
#include "TypedefTestRequestReplySupport.h"

#include "ndds_namespace_cpp.h"


class TypedefTest_getLargoRequestUtils
{
    public:

        /**
         * \brief This function registers the type of the structure TypedefTest_getLargoRequest in the DDS domain participant.
         *
         * \param participant Pointer to the DDS domain participant. Cannot be NULL.
         * \return The type name of the structure TypedefTest_getLargoRequest.
         */
        static const char* registerType(DDS::DomainParticipant *participant);
        
        /**
         * \brief This function sets the parameters into the members of the structure TypedefTest_getLargoRequest.
         *
         * \param instance Pointer to the structure TypedefTest_getLargoRequest that will be filled. Cannot be NULL.
         */
        static void setTypeData(TypedefTest_getLargoRequest& instance, /*in*/ largo l1);
        
        /**
         * \brief This function extracts the parameters from the members of the structure TypedefTest_getLargoRequest.
         *
         * \param data Pointer to the structure TypedefTest_getLargoRequest that contains the parameters' data. Cannot be NULL.
         */
        static void extractTypeData(TypedefTest_getLargoRequest& data, /*in*/ largo& l1);
};


class TypedefTest_getLargoReplyUtils
{
    public:

        /**
         * \brief This function registers the type of the structure TypedefTest_getLargoReply in the DDS domain participant.
         *
         * \param participant Pointer to the DDS domain participant. Cannot be NULL.
         * \return The type name of the structure TypedefTest_getLargoReply.
         */
        static const char* registerType(DDS::DomainParticipant *participant);
        
        /**
         * \brief This function sets the parameters into the members of the structure TypedefTest_getLargoReply.
         *
         * \param instance Pointer to the structure TypedefTest_getLargoReply that will be filled. Cannot be NULL.
         */
        static void setTypeData(TypedefTest_getLargoReply& instance, /*out*/ largo l2, /*out*/ largo getLargo_ret);
        
        /**
         * \brief This function extracts the parameters from the members of the structure TypedefTest_getLargoReply.
         *
         * \param data Pointer to the structure TypedefTest_getLargoReply that contains the parameters' data. Cannot be NULL.
* \param retcode Internal message returned from the server.
         */
        static void extractTypeData(TypedefTest_getLargoReply& data, eProsima::DDSRPC::ReturnMessage& retcode, /*out*/ largo& l2, /*out*/ largo& getLargo_ret);
};


class TypedefTest_getLarguisimoRequestUtils
{
    public:

        /**
         * \brief This function registers the type of the structure TypedefTest_getLarguisimoRequest in the DDS domain participant.
         *
         * \param participant Pointer to the DDS domain participant. Cannot be NULL.
         * \return The type name of the structure TypedefTest_getLarguisimoRequest.
         */
        static const char* registerType(DDS::DomainParticipant *participant);
        
        /**
         * \brief This function sets the parameters into the members of the structure TypedefTest_getLarguisimoRequest.
         *
         * \param instance Pointer to the structure TypedefTest_getLarguisimoRequest that will be filled. Cannot be NULL.
         */
        static void setTypeData(TypedefTest_getLarguisimoRequest& instance, /*in*/ larguisimo ll1);
        
        /**
         * \brief This function extracts the parameters from the members of the structure TypedefTest_getLarguisimoRequest.
         *
         * \param data Pointer to the structure TypedefTest_getLarguisimoRequest that contains the parameters' data. Cannot be NULL.
         */
        static void extractTypeData(TypedefTest_getLarguisimoRequest& data, /*in*/ larguisimo& ll1);
};


class TypedefTest_getLarguisimoReplyUtils
{
    public:

        /**
         * \brief This function registers the type of the structure TypedefTest_getLarguisimoReply in the DDS domain participant.
         *
         * \param participant Pointer to the DDS domain participant. Cannot be NULL.
         * \return The type name of the structure TypedefTest_getLarguisimoReply.
         */
        static const char* registerType(DDS::DomainParticipant *participant);
        
        /**
         * \brief This function sets the parameters into the members of the structure TypedefTest_getLarguisimoReply.
         *
         * \param instance Pointer to the structure TypedefTest_getLarguisimoReply that will be filled. Cannot be NULL.
         */
        static void setTypeData(TypedefTest_getLarguisimoReply& instance, /*out*/ larguisimo ll2, /*out*/ larguisimo getLarguisimo_ret);
        
        /**
         * \brief This function extracts the parameters from the members of the structure TypedefTest_getLarguisimoReply.
         *
         * \param data Pointer to the structure TypedefTest_getLarguisimoReply that contains the parameters' data. Cannot be NULL.
* \param retcode Internal message returned from the server.
         */
        static void extractTypeData(TypedefTest_getLarguisimoReply& data, eProsima::DDSRPC::ReturnMessage& retcode, /*out*/ larguisimo& ll2, /*out*/ larguisimo& getLarguisimo_ret);
};


class TypedefTest_getDatosDefRequestUtils
{
    public:

        /**
         * \brief This function registers the type of the structure TypedefTest_getDatosDefRequest in the DDS domain participant.
         *
         * \param participant Pointer to the DDS domain participant. Cannot be NULL.
         * \return The type name of the structure TypedefTest_getDatosDefRequest.
         */
        static const char* registerType(DDS::DomainParticipant *participant);
        
        /**
         * \brief This function sets the parameters into the members of the structure TypedefTest_getDatosDefRequest.
         *
         * \param instance Pointer to the structure TypedefTest_getDatosDefRequest that will be filled. Cannot be NULL.
         */
        static void setTypeData(TypedefTest_getDatosDefRequest& instance, /*in*/ const DatosDef& d1);
        
        /**
         * \brief This function extracts the parameters from the members of the structure TypedefTest_getDatosDefRequest.
         *
         * \param data Pointer to the structure TypedefTest_getDatosDefRequest that contains the parameters' data. Cannot be NULL.
         */
        static void extractTypeData(TypedefTest_getDatosDefRequest& data, /*in*/ DatosDef& d1);
};


class TypedefTest_getDatosDefReplyUtils
{
    public:

        /**
         * \brief This function registers the type of the structure TypedefTest_getDatosDefReply in the DDS domain participant.
         *
         * \param participant Pointer to the DDS domain participant. Cannot be NULL.
         * \return The type name of the structure TypedefTest_getDatosDefReply.
         */
        static const char* registerType(DDS::DomainParticipant *participant);
        
        /**
         * \brief This function sets the parameters into the members of the structure TypedefTest_getDatosDefReply.
         *
         * \param instance Pointer to the structure TypedefTest_getDatosDefReply that will be filled. Cannot be NULL.
         */
        static void setTypeData(TypedefTest_getDatosDefReply& instance, /*out*/ const DatosDef& d2, /*out*/ const DatosDef& getDatosDef_ret);
        
        /**
         * \brief This function extracts the parameters from the members of the structure TypedefTest_getDatosDefReply.
         *
         * \param data Pointer to the structure TypedefTest_getDatosDefReply that contains the parameters' data. Cannot be NULL.
* \param retcode Internal message returned from the server.
         */
        static void extractTypeData(TypedefTest_getDatosDefReply& data, eProsima::DDSRPC::ReturnMessage& retcode, /*out*/ DatosDef& d2, /*out*/ DatosDef& getDatosDef_ret);
};


class TypedefTest_getDatosDefondoRequestUtils
{
    public:

        /**
         * \brief This function registers the type of the structure TypedefTest_getDatosDefondoRequest in the DDS domain participant.
         *
         * \param participant Pointer to the DDS domain participant. Cannot be NULL.
         * \return The type name of the structure TypedefTest_getDatosDefondoRequest.
         */
        static const char* registerType(DDS::DomainParticipant *participant);
        
        /**
         * \brief This function sets the parameters into the members of the structure TypedefTest_getDatosDefondoRequest.
         *
         * \param instance Pointer to the structure TypedefTest_getDatosDefondoRequest that will be filled. Cannot be NULL.
         */
        static void setTypeData(TypedefTest_getDatosDefondoRequest& instance, /*in*/ const DatosDefondo& dd1);
        
        /**
         * \brief This function extracts the parameters from the members of the structure TypedefTest_getDatosDefondoRequest.
         *
         * \param data Pointer to the structure TypedefTest_getDatosDefondoRequest that contains the parameters' data. Cannot be NULL.
         */
        static void extractTypeData(TypedefTest_getDatosDefondoRequest& data, /*in*/ DatosDefondo& dd1);
};


class TypedefTest_getDatosDefondoReplyUtils
{
    public:

        /**
         * \brief This function registers the type of the structure TypedefTest_getDatosDefondoReply in the DDS domain participant.
         *
         * \param participant Pointer to the DDS domain participant. Cannot be NULL.
         * \return The type name of the structure TypedefTest_getDatosDefondoReply.
         */
        static const char* registerType(DDS::DomainParticipant *participant);
        
        /**
         * \brief This function sets the parameters into the members of the structure TypedefTest_getDatosDefondoReply.
         *
         * \param instance Pointer to the structure TypedefTest_getDatosDefondoReply that will be filled. Cannot be NULL.
         */
        static void setTypeData(TypedefTest_getDatosDefondoReply& instance, /*out*/ const DatosDefondo& dd2, /*out*/ const DatosDefondo& getDatosDefondo_ret);
        
        /**
         * \brief This function extracts the parameters from the members of the structure TypedefTest_getDatosDefondoReply.
         *
         * \param data Pointer to the structure TypedefTest_getDatosDefondoReply that contains the parameters' data. Cannot be NULL.
* \param retcode Internal message returned from the server.
         */
        static void extractTypeData(TypedefTest_getDatosDefondoReply& data, eProsima::DDSRPC::ReturnMessage& retcode, /*out*/ DatosDefondo& dd2, /*out*/ DatosDefondo& getDatosDefondo_ret);
};


class TypedefTest_getCadenaRequestUtils
{
    public:

        /**
         * \brief This function registers the type of the structure TypedefTest_getCadenaRequest in the DDS domain participant.
         *
         * \param participant Pointer to the DDS domain participant. Cannot be NULL.
         * \return The type name of the structure TypedefTest_getCadenaRequest.
         */
        static const char* registerType(DDS::DomainParticipant *participant);
        
        /**
         * \brief This function sets the parameters into the members of the structure TypedefTest_getCadenaRequest.
         *
         * \param instance Pointer to the structure TypedefTest_getCadenaRequest that will be filled. Cannot be NULL.
         */
        static void setTypeData(TypedefTest_getCadenaRequest& instance, /*in*/ cadena c1);
        
        /**
         * \brief This function extracts the parameters from the members of the structure TypedefTest_getCadenaRequest.
         *
         * \param data Pointer to the structure TypedefTest_getCadenaRequest that contains the parameters' data. Cannot be NULL.
         */
        static void extractTypeData(TypedefTest_getCadenaRequest& data, /*in*/ cadena& c1);
};


class TypedefTest_getCadenaReplyUtils
{
    public:

        /**
         * \brief This function registers the type of the structure TypedefTest_getCadenaReply in the DDS domain participant.
         *
         * \param participant Pointer to the DDS domain participant. Cannot be NULL.
         * \return The type name of the structure TypedefTest_getCadenaReply.
         */
        static const char* registerType(DDS::DomainParticipant *participant);
        
        /**
         * \brief This function sets the parameters into the members of the structure TypedefTest_getCadenaReply.
         *
         * \param instance Pointer to the structure TypedefTest_getCadenaReply that will be filled. Cannot be NULL.
         */
        static void setTypeData(TypedefTest_getCadenaReply& instance, /*out*/ cadena c2, /*out*/ cadena getCadena_ret);
        
        /**
         * \brief This function extracts the parameters from the members of the structure TypedefTest_getCadenaReply.
         *
         * \param data Pointer to the structure TypedefTest_getCadenaReply that contains the parameters' data. Cannot be NULL.
* \param retcode Internal message returned from the server.
         */
        static void extractTypeData(TypedefTest_getCadenaReply& data, eProsima::DDSRPC::ReturnMessage& retcode, /*out*/ cadena& c2, /*out*/ cadena& getCadena_ret);
};


class TypedefTest_getCorreaRequestUtils
{
    public:

        /**
         * \brief This function registers the type of the structure TypedefTest_getCorreaRequest in the DDS domain participant.
         *
         * \param participant Pointer to the DDS domain participant. Cannot be NULL.
         * \return The type name of the structure TypedefTest_getCorreaRequest.
         */
        static const char* registerType(DDS::DomainParticipant *participant);
        
        /**
         * \brief This function sets the parameters into the members of the structure TypedefTest_getCorreaRequest.
         *
         * \param instance Pointer to the structure TypedefTest_getCorreaRequest that will be filled. Cannot be NULL.
         */
        static void setTypeData(TypedefTest_getCorreaRequest& instance, /*in*/ correa cc1);
        
        /**
         * \brief This function extracts the parameters from the members of the structure TypedefTest_getCorreaRequest.
         *
         * \param data Pointer to the structure TypedefTest_getCorreaRequest that contains the parameters' data. Cannot be NULL.
         */
        static void extractTypeData(TypedefTest_getCorreaRequest& data, /*in*/ correa& cc1);
};


class TypedefTest_getCorreaReplyUtils
{
    public:

        /**
         * \brief This function registers the type of the structure TypedefTest_getCorreaReply in the DDS domain participant.
         *
         * \param participant Pointer to the DDS domain participant. Cannot be NULL.
         * \return The type name of the structure TypedefTest_getCorreaReply.
         */
        static const char* registerType(DDS::DomainParticipant *participant);
        
        /**
         * \brief This function sets the parameters into the members of the structure TypedefTest_getCorreaReply.
         *
         * \param instance Pointer to the structure TypedefTest_getCorreaReply that will be filled. Cannot be NULL.
         */
        static void setTypeData(TypedefTest_getCorreaReply& instance, /*out*/ correa cc2, /*out*/ correa getCorrea_ret);
        
        /**
         * \brief This function extracts the parameters from the members of the structure TypedefTest_getCorreaReply.
         *
         * \param data Pointer to the structure TypedefTest_getCorreaReply that contains the parameters' data. Cannot be NULL.
* \param retcode Internal message returned from the server.
         */
        static void extractTypeData(TypedefTest_getCorreaReply& data, eProsima::DDSRPC::ReturnMessage& retcode, /*out*/ correa& cc2, /*out*/ correa& getCorrea_ret);
};

 
#endif // _TypedefTest_REQUEST_REPLY_UTILS_H_
