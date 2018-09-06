#ifndef __CCSDS_HEADER_LIB_H__
#define __CCSDS_HEADER_LIB_H__

/* user configurable parameters */

/**
**  \cfesbcfg Platform Endian Indicator
**
**  \par Description:
**       The value of this constant indicates the endianess of the target system
**
**  \par Limits
**       This parameter has a lower limit of 0 and an upper limit of 1.
*/
#define CFE_PLATFORM_ENDIAN CCSDS_LITTLE_ENDIAN

/**
**  \cfemissioncfg cFE SB message format
**
**  \par Description:
**      Dictates the message format used by the cFE.
**   
**  \par Limits
**      All versions of the cFE currently support only CCSDS as the message format
**      Defining only MESSAGE_FORMAT_IS_CCSDS implements the 11 bit APID format in the primary header
**      Also defining MESSAGE_FORMAT_IS_CCSDS_VER_2 implements the APID extended header format
**      MESSAGE_FORMAT_IS_CCSDS must be defined for all cFE deployments. MESSAGE_FORMAT_IS_CCSDS_VER_2 is optional
*/
#define MESSAGE_FORMAT_IS_CCSDS
#define MESSAGE_FORMAT_IS_CCSDS_VER_2
// #undef MESSAGE_FORMAT_IS_CCSDS_VER_2

/**
**  \cfemissioncfg Packet Timestamp Format Selection
**
**  \par Description:
**      Defines the size, format and contents of the telemetry packet timestamp.
**
**  \par Limits
**      Must be defined as one of the supported formats listed above
*/
#define CFE_MISSION_SB_PACKET_TIME_FORMAT  CFE_MISSION_SB_TIME_32_16_SUBS

/* 
 * Mission defined bit used to indicate message is a command type. A 0 in this bit position indicates 
 * a telemetry message type. This bit is included in the message id.
 */

#define CFE_SB_APID_COMPONENT          0x000001FF  /* 0-8(9) bits for Pri Hdr APID */
#define CFE_SB_APID_OFFSET                      0
#define CFE_SB_TYPE_COMPONENT          0x00008000  /* 1 Cmd/Tlm Bit (bit #15) */
#define CFE_SB_TYPE_OFFSET                     15
#define CFE_SB_SUBSYS_COMPONENT        0x00007E00  /* bits 9-14(6) bits for APID Subsystem ID */
#define CFE_SB_SUBSYS_OFFSET                    9
#define CFE_SB_SYSTEM_COMPONENT        0x00000000
#define CFE_SB_SYSTEM_OFFSET                   16



/* begin necessary includes */

#ifdef __cplusplus
   extern "C" {
#endif

#include "cfe/cfe_sb.h"
#include "cfe/cfe_sb_msg_id_util.h"

#ifdef __cplusplus
   }
#endif

#endif /* __CCSDS_HEADER_LIB_H__ */