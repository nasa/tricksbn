/* Created : Wed Aug 08 11:18:03 CDT 2018
   User    : rhirsh
   Project : habitat
   Script  : /gfe/TOOLS/cfs_tools/cfs_cdd/scripts/HabTypesHeaderExtended.js
   Table(s): ACAWS_DE_DiagData_Msg_t, CCSDS_TLM_HDR, CCSDS_Primary, ACAWS_DE_DiagData_t, TEAMS_health_t, ACAWS_DE_ImpactReq_Msg_t, ACAWS_DE_ImpactReq_t, TEAMS_failure_t */

#ifndef _ACAWS_DE_TYPES_H_
#define _ACAWS_DE_TYPES_H_

#include "shared_types.h"
///* @file */
#include "acaws_model_config.h"

/* Constants for Reasoner_t */
#define  TEAMS 0
#define  HYDE  1
/* Constants for Certainty_t */
#define  CONFIRMED 0
#define  POSSIBLY  1



#ifdef __cplusplus
extern "C" {
#endif
/** Structure TEAMS_failure_t (4 bytes in size)  **/
typedef struct
{
  uint16_t failure_index;                                      ///< [    0] (2 bytes)  
  uint16_t failure_certainty;                                  ///< [    2] (2 bytes)  change to Certainty_t
} TEAMS_failure_t;     ///<  Total size of 4 bytes

/** Structure TEAMS_health_t (2 bytes in size)  **/
typedef struct
{
  uint16_t unknown:1;                                    /* */ ///< [    0]   
  uint16_t bad:1;                                              ///< [    0]   
  uint16_t suspect:1;                                          ///< [    0]   
  uint16_t minimal:1;                                          ///< [    0]   
  uint16_t residual:1;                                         ///< [    0]   
  uint16_t minimal_group:10;                                   ///< [    0]   
  uint16_t minimal_group_ovrflw:1;                             ///< [    0]   
} TEAMS_health_t;     ///<  Total size of 2 bytes

/** Structure ACAWS_DE_DiagData_Msg_t (312 bytes in size)  *
* published acaws de DiagData after serialization into byte array
*/
typedef struct
{
  CCSDS_TLM_HDR cfsHeader;                                     ///< [    0] (16 bytes)  Extended CFS SB message Header #CCSDS_TLM_HDR
  uint8_t data[CFS_ACAWS_DE_DIAG_DATA_SERIALIZED_SIZE];        ///< [   16] (CFS_ACAWS_DE_DIAG_DATA_SERIALIZED_SIZE x 1=296 bytes)  
} ACAWS_DE_DiagData_Msg_t;     ///<  Total size of 312 bytes

/** Structure ACAWS_DE_DiagData_t (312 bytes in size)  **/
typedef struct
{
  CCSDS_TLM_HDR cfsHeader;                                     ///< [    0] (16 bytes)  Extended CFS SB message Header #CCSDS_TLM_HDR
  uint16_t source_id;                                          ///< [   16] (2 bytes)  change data type to Reasoner_t
  uint16_t session_id;                                         ///< [   18] (2 bytes)  
  uint16_t unique_instance_id;                                 ///< [   20] (2 bytes)  
  uint16_t aspect_count;                                       ///< [   22] (2 bytes)  
  TEAMS_health_t aspect_diag[DIAG_MAX_ELEM_SIZE];              ///< [   24] (DIAG_MAX_ELEM_SIZE x 2=288 bytes)  
} ACAWS_DE_DiagData_t;     ///<  Total size of 312 bytes

/** Structure ACAWS_DE_ImpactReq_Msg_t (54 bytes in size)  *
* published acaws de ImpactReq message after serialization into byte array
*/
typedef struct
{
  CCSDS_TLM_HDR cfsHeader;                                     ///< [    0] (16 bytes)  Extended CFS SB message Header #CCSDS_TLM_HDR
  uint8_t data[CFS_ACAWS_DE_IMPACT_REQ_SERIALIZED_SIZE];       ///< [   16] (CFS_ACAWS_DE_IMPACT_REQ_SERIALIZED_SIZE x 1=38 bytes)  
} ACAWS_DE_ImpactReq_Msg_t;     ///<  Total size of 54 bytes

/** Structure ACAWS_DE_ImpactReq_t (54 bytes in size)  *
* impact request message from "diag Exec" of ACAWS
*/
typedef struct
{
  CCSDS_TLM_HDR cfsHeader;                                     ///< [    0] (16 bytes)  Extended CFS SB message Header #CCSDS_TLM_HDR
  uint16_t mode_aware;                                         ///< [   16] (2 bytes)  
  uint16_t unique_instance_id;                                 ///< [   18] (2 bytes)  
  uint16_t failure_list_cnt;                                   ///< [   20] (2 bytes)  
  TEAMS_failure_t failure_list[DIAG_MAX_IMPACT_REQ_SIZE];      ///< [   22] (DIAG_MAX_IMPACT_REQ_SIZE x 4=32 bytes)  
} ACAWS_DE_ImpactReq_t;     ///<  Total size of 54 bytes

void byteswap_ACAWS_DE_ImpactReq_t(ACAWS_DE_ImpactReq_t *inPtr, ACAWS_DE_ImpactReq_t *outPtr, int direction);
void bitswap_ACAWS_DE_ImpactReq_t(ACAWS_DE_ImpactReq_t *inPtr, ACAWS_DE_ImpactReq_t *outPtr, int direction);
void byteswap_ACAWS_DE_ImpactReq_Msg_t(ACAWS_DE_ImpactReq_Msg_t *inPtr, ACAWS_DE_ImpactReq_Msg_t *outPtr, int direction);
void bitswap_ACAWS_DE_ImpactReq_Msg_t(ACAWS_DE_ImpactReq_Msg_t *inPtr, ACAWS_DE_ImpactReq_Msg_t *outPtr, int direction);
void byteswap_ACAWS_DE_DiagData_t(ACAWS_DE_DiagData_t *inPtr, ACAWS_DE_DiagData_t *outPtr, int direction);
void bitswap_ACAWS_DE_DiagData_t(ACAWS_DE_DiagData_t *inPtr, ACAWS_DE_DiagData_t *outPtr, int direction);
void byteswap_ACAWS_DE_DiagData_Msg_t(ACAWS_DE_DiagData_Msg_t *inPtr, ACAWS_DE_DiagData_Msg_t *outPtr, int direction);
void bitswap_ACAWS_DE_DiagData_Msg_t(ACAWS_DE_DiagData_Msg_t *inPtr, ACAWS_DE_DiagData_Msg_t *outPtr, int direction);
void byteswap_TEAMS_health_t(TEAMS_health_t *inPtr, TEAMS_health_t *outPtr, int direction);
void bitswap_TEAMS_health_t(TEAMS_health_t *inPtr, TEAMS_health_t *outPtr, int direction);
void byteswap_CCSDS_TLM_HDR(CCSDS_TLM_HDR *inPtr, CCSDS_TLM_HDR *outPtr, int direction);
void bitswap_CCSDS_TLM_HDR(CCSDS_TLM_HDR *inPtr, CCSDS_TLM_HDR *outPtr, int direction);
void byteswap_CCSDS_Primary(CCSDS_Primary *inPtr, CCSDS_Primary *outPtr, int direction);
void bitswap_CCSDS_Primary(CCSDS_Primary *inPtr, CCSDS_Primary *outPtr, int direction);
void byteswap_TEAMS_failure_t(TEAMS_failure_t *inPtr, TEAMS_failure_t *outPtr, int direction);
void bitswap_TEAMS_failure_t(TEAMS_failure_t *inPtr, TEAMS_failure_t *outPtr, int direction);
// Helper function to serialize the TEAMS_health bitfield struct
// into a byte array to help build a message
void read_TEAMS_health(uint8_t const * const p_bytes,
TEAMS_health_t * const p_th);

// Helper function to deserialize a byte array into the TEAMS_health
// bitfield struct
void write_TEAMS_health(TEAMS_health_t const * const p_th,
uint8_t * const p_bytes);

// Helper function to serialize a DiagData struct into a message
void acaws_de_diag_data_struct_to_msg(
ACAWS_DE_DiagData_t const * const p_dd,
ACAWS_DE_DiagData_Msg_t * const p_msg);

// Helper function to deserialize a message into a DiagData struct
void acaws_de_diag_data_msg_to_struct(
ACAWS_DE_DiagData_Msg_t const * const p_msg,
ACAWS_DE_DiagData_t * const p_dd);

// Helper function to serialize an ImpactReq struct into a message
void acaws_de_impact_req_struct_to_msg(
ACAWS_DE_ImpactReq_t const * const p_ir,
ACAWS_DE_ImpactReq_Msg_t * const p_msg);

// Helper function to deserialize a message into an ImpactReq struct
void acaws_de_impact_req_msg_to_struct(
ACAWS_DE_ImpactReq_Msg_t const * const p_msg,
ACAWS_DE_ImpactReq_t * const p_ir);
#ifdef __cplusplus
}
#endif
#endif /// #ifndef _ACAWS_DE_TYPES_H_
