/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This copy of RPCDDS is licensed to you under the terms described in the
 * RPCDDS_LICENSE file included in this distribution.
 *
 *************************************************************************
 * 
 * @file CalculatorRequestReplyUtils.h
 * This header file contains the declaration of helpful functions for the DDS messages for interface Calculator.
 *
 * This file was generated by the tool rpcddsgen.
 */

#ifndef _Calculator_REQUEST_REPLY_UTILS_H_
#define _Calculator_REQUEST_REPLY_UTILS_H_

#include "utils/Messages.h"
#include "CalculatorRequestReplySupport.h"

#include "ndds_namespace_cpp.h"


/**
 * \brief This class contains helpful operations for the generated topic Calculator_additionRequest.
 */
class Calculator_additionRequestUtils
{
    public:

        /**
         * \brief This function registers the type of the structure Calculator_additionRequest in the DDS domain participant.
         *
         * \param participant Pointer to the DDS domain participant. Cannot be NULL.
         * \return The type name of the structure Calculator_additionRequest.
         */
        static const char* registerType(DDS::DomainParticipant *participant);
        
        /**
         * \brief This function sets the parameters into the members of the structure Calculator_additionRequest.
         *
         * \param instance Pointer to the structure Calculator_additionRequest that will be filled. Cannot be NULL.
         */
        static void setTypeData(Calculator_additionRequest& instance, /*in*/ DDS_Long value1, /*in*/ DDS_Long value2);
        
        /**
         * \brief This function extracts the parameters from the members of the structure Calculator_additionRequest.
         *
         * \param data Pointer to the structure Calculator_additionRequest that contains the parameters' data. Cannot be NULL.
         */
        static void extractTypeData(Calculator_additionRequest& data, /*in*/ DDS_Long& value1, /*in*/ DDS_Long& value2);
};


/**
 * \brief This class contains helpful operations for the generated topic Calculator_additionReply.
 */
class Calculator_additionReplyUtils
{
    public:

        /**
         * \brief This function registers the type of the structure Calculator_additionReply in the DDS domain participant.
         *
         * \param participant Pointer to the DDS domain participant. Cannot be NULL.
         * \return The type name of the structure Calculator_additionReply.
         */
        static const char* registerType(DDS::DomainParticipant *participant);
        
        /**
         * \brief This function sets the parameters into the members of the structure Calculator_additionReply.
         *
         * \param instance Pointer to the structure Calculator_additionReply that will be filled. Cannot be NULL.
         */
        static void setTypeData(Calculator_additionReply& instance, /*out*/ DDS_Long addition_ret);
        
        /**
         * \brief This function extracts the parameters from the members of the structure Calculator_additionReply.
         *
         * \param data Pointer to the structure Calculator_additionReply that contains the parameters' data. Cannot be NULL.
* \param retcode Internal message returned from the server.
         */
        static void extractTypeData(Calculator_additionReply& data, eProsima::RPCDDS::ReturnMessage& retcode, /*out*/ DDS_Long& addition_ret);
};


/**
 * \brief This class contains helpful operations for the generated topic Calculator_subtractionRequest.
 */
class Calculator_subtractionRequestUtils
{
    public:

        /**
         * \brief This function registers the type of the structure Calculator_subtractionRequest in the DDS domain participant.
         *
         * \param participant Pointer to the DDS domain participant. Cannot be NULL.
         * \return The type name of the structure Calculator_subtractionRequest.
         */
        static const char* registerType(DDS::DomainParticipant *participant);
        
        /**
         * \brief This function sets the parameters into the members of the structure Calculator_subtractionRequest.
         *
         * \param instance Pointer to the structure Calculator_subtractionRequest that will be filled. Cannot be NULL.
         */
        static void setTypeData(Calculator_subtractionRequest& instance, /*in*/ DDS_Long value1, /*in*/ DDS_Long value2);
        
        /**
         * \brief This function extracts the parameters from the members of the structure Calculator_subtractionRequest.
         *
         * \param data Pointer to the structure Calculator_subtractionRequest that contains the parameters' data. Cannot be NULL.
         */
        static void extractTypeData(Calculator_subtractionRequest& data, /*in*/ DDS_Long& value1, /*in*/ DDS_Long& value2);
};


/**
 * \brief This class contains helpful operations for the generated topic Calculator_subtractionReply.
 */
class Calculator_subtractionReplyUtils
{
    public:

        /**
         * \brief This function registers the type of the structure Calculator_subtractionReply in the DDS domain participant.
         *
         * \param participant Pointer to the DDS domain participant. Cannot be NULL.
         * \return The type name of the structure Calculator_subtractionReply.
         */
        static const char* registerType(DDS::DomainParticipant *participant);
        
        /**
         * \brief This function sets the parameters into the members of the structure Calculator_subtractionReply.
         *
         * \param instance Pointer to the structure Calculator_subtractionReply that will be filled. Cannot be NULL.
         */
        static void setTypeData(Calculator_subtractionReply& instance, /*out*/ DDS_Long subtraction_ret);
        
        /**
         * \brief This function extracts the parameters from the members of the structure Calculator_subtractionReply.
         *
         * \param data Pointer to the structure Calculator_subtractionReply that contains the parameters' data. Cannot be NULL.
* \param retcode Internal message returned from the server.
         */
        static void extractTypeData(Calculator_subtractionReply& data, eProsima::RPCDDS::ReturnMessage& retcode, /*out*/ DDS_Long& subtraction_ret);
};

 
#endif // _Calculator_REQUEST_REPLY_UTILS_H_