#ifndef _StructTest_CLIENT_RPC_SUPPORT_H_
#define _StructTest_CLIENT_RPC_SUPPORT_H_

/** 
 * Generated by DDSCS: Do not edit.  Version 1.0 *
 */

#include "utils/GenericClientRPC.h"
#include "StructTestRequestReplySupport.h"


GENERIC_CLIENT_RPC(StructTest_duplicateClientRPC, StructTest_duplicateRequestDataWriter, StructTest_duplicateReplyDataReader);


GENERIC_CLIENT_RPC(StructTest_sumaClientRPC, StructTest_sumaRequestDataWriter, StructTest_sumaReplyDataReader);


#endif  // _StructTest_CLIENT_RPC_SUPPORT_H_