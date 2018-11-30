/* Created : Wed Aug 08 18:05:58 CDT 2018
   User    : rhirsh
   Project : habitat
   Script  : /gfe/TOOLS/cfs_tools/cfs_cdd/scripts/HabTypesHeaderExtended.js
   Table(s): ACAWS_FIR_HkTlm_t, CCSDS_TLM_HDR, CCSDS_Primary, ACAWS_FIR_OutData_Msg_t, ACAWS_FIR_OutData_t, ACAWS_FIR_ImpactType_t */

#ifndef _ACAWS_FIR_TYPES_H_
#define _ACAWS_FIR_TYPES_H_

#include "shared_types.h"
///* @file */

#include "acaws_de_types.h"
#include "acaws_model_config.h"



#ifdef __cplusplus
extern "C" {
#endif
/** Structure ACAWS_FIR_ImpactType_t (1 bytes in size)  *
* // HEY YOU: if these structs are added or changed, you need to change
// the serialization functions!
//
// The serialization of an ACAWS_SE_ImpactType_t fits into one octet
//  like this:
// |    byte       |
// |-|-|-|-|-|F|L|N|
// N = noImpact
// L = lor
// F = func
// - = not used
// and the left-most bit in the ascii picture is the most significant bit. 
// Again, this matches reading the struct order in a hexdump.

  // The fixed width integer bitfields are a GCC extension, ISO C99 only
  // allows for int, unsigned int. We are using them to have a better
  // correspondence between the struct and serialized formats.
*/
typedef struct
{
  uint8_t noImpact:1;                                         /* */ ///< [    0]   
  uint8_t lor:1;                                                    ///< [    0]   
  uint8_t func:1;                                                   ///< [    0]   
  uint8_t pad:5;                                                    ///< [    0]   
} ACAWS_FIR_ImpactType_t;     ///<  Total size of 1 bytes

/** Structure ACAWS_FIR_HkTlm_t (20 bytes in size)  *
* hk tlm message from "FIR" of ACAWS
*/
typedef struct
{
  CCSDS_TLM_HDR cfsHeader;                                          ///< [    0] (16 bytes)  Extended CFS SB message Header #CCSDS_TLM_HDR
  uint16_t usCmdCnt;                                                ///< [   16] (2 bytes)  
  uint16_t usCmdErrCnt;                                             ///< [   18] (2 bytes)  
} ACAWS_FIR_HkTlm_t;     ///<  Total size of 20 bytes

/** Structure ACAWS_FIR_OutData_Msg_t (18 bytes in size)  *
* published acaws FIR OutData message after serialization into byte array
*/
typedef struct
{
  CCSDS_TLM_HDR cfsHeader;                                          ///< [    0] (16 bytes)  Extended CFS SB message Header #CCSDS_TLM_HDR
  uint8_t data[CFS_ACAWS_FIR_OUTDATA_SERIALIZED_SIZE];              ///< [   16] (CFS_ACAWS_FIR_OUTDATA_SERIALIZED_SIZE x 1=2 bytes)  
} ACAWS_FIR_OutData_Msg_t;     ///<  Total size of 18 bytes

/** Structure ACAWS_FIR_OutData_t (113 bytes in size)  *
* out data of "FIR" of ACAWS
*/
typedef struct
{
  CCSDS_TLM_HDR cfsHeader;                                          ///< [    0] (16 bytes)  Extended CFS SB message Header #CCSDS_TLM_HDR
  uint16_t unique_instance_id;                                      ///< [   16] (2 bytes)  
  uint16_t failure_list_cnt;                                        ///< [   18] (2 bytes)  
  uint16_t acaws_fir_effects_cnt;                                   ///< [   20] (2 bytes)  
  ACAWS_FIR_ImpactType_t acaws_fir_effects[FIR_MAX_ELEM_SIZE];      ///< [   22] (FIR_MAX_ELEM_SIZE x 1=91 bytes)  
} ACAWS_FIR_OutData_t;     ///<  Total size of 113 bytes

void byteswap_ACAWS_FIR_OutData_t(ACAWS_FIR_OutData_t *inPtr, ACAWS_FIR_OutData_t *outPtr, int direction);
void bitswap_ACAWS_FIR_OutData_t(ACAWS_FIR_OutData_t *inPtr, ACAWS_FIR_OutData_t *outPtr, int direction);
void byteswap_ACAWS_FIR_OutData_Msg_t(ACAWS_FIR_OutData_Msg_t *inPtr, ACAWS_FIR_OutData_Msg_t *outPtr, int direction);
void bitswap_ACAWS_FIR_OutData_Msg_t(ACAWS_FIR_OutData_Msg_t *inPtr, ACAWS_FIR_OutData_Msg_t *outPtr, int direction);
void byteswap_ACAWS_FIR_HkTlm_t(ACAWS_FIR_HkTlm_t *inPtr, ACAWS_FIR_HkTlm_t *outPtr, int direction);
void bitswap_ACAWS_FIR_HkTlm_t(ACAWS_FIR_HkTlm_t *inPtr, ACAWS_FIR_HkTlm_t *outPtr, int direction);
void byteswap_CCSDS_TLM_HDR(CCSDS_TLM_HDR *inPtr, CCSDS_TLM_HDR *outPtr, int direction);
void bitswap_CCSDS_TLM_HDR(CCSDS_TLM_HDR *inPtr, CCSDS_TLM_HDR *outPtr, int direction);
void byteswap_CCSDS_Primary(CCSDS_Primary *inPtr, CCSDS_Primary *outPtr, int direction);
void bitswap_CCSDS_Primary(CCSDS_Primary *inPtr, CCSDS_Primary *outPtr, int direction);
void byteswap_ACAWS_FIR_ImpactType_t(ACAWS_FIR_ImpactType_t *inPtr, ACAWS_FIR_ImpactType_t *outPtr, int direction);
void bitswap_ACAWS_FIR_ImpactType_t(ACAWS_FIR_ImpactType_t *inPtr, ACAWS_FIR_ImpactType_t *outPtr, int direction);
// Helper function to serialize the ACAWS_SE_ImpactType_t bitfield struct
// into a byte array to help build a message
void read_ImpactType(uint8_t const * const p_bytes,
ACAWS_FIR_ImpactType_t * const p_it);

// Helper function to deserialize a byte array into the ACAWS_SE_ImpactType_t
// bitfield struct
void write_ImpactType(ACAWS_FIR_ImpactType_t const * const p_it,
uint8_t * const p_bytes);

// Helper function to serialize an SE_Outdata struct into a message
void acaws_FIR_out_data_struct_to_msg(
ACAWS_FIR_OutData_t const * const p_od,
ACAWS_FIR_OutData_Msg_t * const p_msg);

// Helper function to deserialize a message into an SE_Outdata struct
void acaws_FIR_out_data_msg_to_struct(
ACAWS_FIR_OutData_Msg_t const * const p_msg,
ACAWS_FIR_OutData_t * const p_od);
#ifdef __cplusplus
}
#endif
#endif /// #ifndef _ACAWS_FIR_TYPES_H_
