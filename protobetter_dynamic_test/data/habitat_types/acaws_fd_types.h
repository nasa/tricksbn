/* Created : Mon Aug 13 16:39:54 CDT 2018
   User    : rhirsh
   Project : habitat
   Script  : /gfe/TOOLS/cfs_tools/cfs_cdd/scripts/HabTypesHeaderExtended.js
   Table(s): acaws_fd_test_results_msg_type, CCSDS_TLM_HDR, CCSDS_Primary, acaws_fd_test_results_type */

#ifndef _ACAWS_FD_TYPES_H_
#define _ACAWS_FD_TYPES_H_

#include "shared_types.h"
///* @file */
#include "acaws_model_config.h"
// Here are the values that our test results and switch modes can have.
// These are defined constants instead of an enum to save space, since they
// can fit into a byte. (An enum is the size of an int.)
#define  CFS_ACAWS_FD_TEST_PASS          0
#define  CFS_ACAWS_FD_TEST_FAIL          1
#define  CFS_ACAWS_FD_TEST_UNKNOWN       2
#define  CFS_ACAWS_FD_TEST_UNSET         3
#define  CFS_ACAWS_FD_SWITCH_ON          4
#define  CFS_ACAWS_FD_SWITCH_OFF         5
#define  CFS_ACAWS_FD_SWITCH_UNSET       6
#define  CFS_ACAWS_FD_ENUM_RESULT_COUNT  7
#define  CFS_ACAWS_FD_INVALID_ENUM_RESULT CFS_ACAWS_FD_ENUM_RESULT_COUNT

// Some typedefs for convienence
typedef uint8_t acaws_fd_test_values_type;
typedef uint8_t acaws_fd_mode_type;
typedef uint8_t acaws_fd_test_result_type;


#ifdef __cplusplus
extern "C" {
#endif
/** Structure acaws_fd_test_results_msg_type (149 bytes in size)  *
* published acaws fd test results message after serialization into byte array
*/
typedef struct
{
  CCSDS_TLM_HDR cfsHeader;                                      ///< [    0] (16 bytes)  Extended CFS SB message Header #CCSDS_TLM_HDR
  uint8_t data[CFS_ACAWS_FD_TEST_RESULTS_SERIALIZED_SIZE];      ///< [   16] (CFS_ACAWS_FD_TEST_RESULTS_SERIALIZED_SIZE x 1=133 bytes)  
} acaws_fd_test_results_msg_type;     ///<  Total size of 149 bytes

/** Structure acaws_fd_test_results_type (150 bytes in size)  *
* test results message from "fd" of ACAWS
*/
typedef struct
{
  CCSDS_TLM_HDR cfsHeader;                                      ///< [    0] (16 bytes)  Extended CFS SB message Header #CCSDS_TLM_HDR
  uint16_t modes_on_count;                                      ///< [   16] (2 bytes)  
  uint16_t test_results_count;                                  ///< [   18] (2 bytes)  
  uint8_t modes_on[ACAWS_FD_MAX_MODES];                         ///< [   20] (ACAWS_FD_MAX_MODES x 1=2 bytes)  change to acaws_mode_type
  uint8_t test_results[ACAWS_FD_MAX_TESTS];                     ///< [   22] (ACAWS_FD_MAX_TESTS x 1=128 bytes)  change to acaws_fd_test_result_type
} acaws_fd_test_results_type;     ///<  Total size of 150 bytes

void byteswap_acaws_fd_test_results_type(acaws_fd_test_results_type *inPtr, acaws_fd_test_results_type *outPtr, int direction);
void bitswap_acaws_fd_test_results_type(acaws_fd_test_results_type *inPtr, acaws_fd_test_results_type *outPtr, int direction);
void byteswap_acaws_fd_test_results_msg_type(acaws_fd_test_results_msg_type *inPtr, acaws_fd_test_results_msg_type *outPtr, int direction);
void bitswap_acaws_fd_test_results_msg_type(acaws_fd_test_results_msg_type *inPtr, acaws_fd_test_results_msg_type *outPtr, int direction);
void byteswap_CCSDS_TLM_HDR(CCSDS_TLM_HDR *inPtr, CCSDS_TLM_HDR *outPtr, int direction);
void bitswap_CCSDS_TLM_HDR(CCSDS_TLM_HDR *inPtr, CCSDS_TLM_HDR *outPtr, int direction);
void byteswap_CCSDS_Primary(CCSDS_Primary *inPtr, CCSDS_Primary *outPtr, int direction);
void bitswap_CCSDS_Primary(CCSDS_Primary *inPtr, CCSDS_Primary *outPtr, int direction);
// Helper function to clear an acaws_fd_test_results_type. All
// fields and array values are set to 0.
void clear_acaws_fd_test_results_struct(
acaws_fd_test_results_type * const p_tr);

// Helper function to serialize a test results struct into a message
void acaws_fd_test_results_struct_to_msg(
acaws_fd_test_results_type const * const p_tr,
acaws_fd_test_results_msg_type * const p_msg);

// Helper function to deserialize a message into a test results struct
void acaws_fd_test_results_msg_to_struct(
acaws_fd_test_results_msg_type const * const p_msg,
acaws_fd_test_results_type * const p_tr);


/******************************************************************************
** Command Enumerations
*******************************************************************************/
#define CFS_ACAWS_FD_WAKEUP_PROCESS  0x2
#define CFS_ACAWS_FD_WAKEUP_SEND     0x3

/******************************************************************************
** Command Structure definitions
*******************************************************************************/

/**  CFS_ACAWS_FD_WAKEUP_PROCESS : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
}CFS_ACAWS_FD_WAKEUP_PROCESS_t;

/**  CFS_ACAWS_FD_WAKEUP_SEND : **/
typedef struct
{
 CCSDS_Primary   CmdHeader;  /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
 uint16_t  CCSDS_CmdSecHdr;  /**< \brief CCSDS Command Secondary Header #CCSDS_CmdSecHdr_t */
}CFS_ACAWS_FD_WAKEUP_SEND_t;

#ifdef __cplusplus
}
#endif
#endif /// #ifndef _ACAWS_FD_TYPES_H_
