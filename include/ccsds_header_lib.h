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

/* 
** The maxium length allowed for a object (task,queue....) name 
*/
#define OS_MAX_API_NAME     30

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

/* begin necessary includes */

#ifdef __cplusplus
   extern "C" {
#endif

#include "cfe_sb.h"
#include "cfe_sb_msg_id_util.h"

#ifdef __cplusplus
   }
#endif

#endif /* __CCSDS_HEADER_LIB_H__ */