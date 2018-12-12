/******************************************************************************
** File: cfe_sb.h
**
**      Copyright (c) 2004-2006, United States government as represented by the
**      administrator of the National Aeronautics Space Administration.
**      All rights reserved. This software(cFE) was created at NASA's Goddard
**      Space Flight Center pursuant to government contracts.
**
**      This is governed by the NASA Open Source Agreement and may be used,
**      distributed and modified only pursuant to the terms of that agreement.
**
** Purpose:
**      This header file contains all definitions for the cFE Software Bus
**      Application Programmer's Interface.
**
** Author:   R.McGraw/SSI
**
******************************************************************************/

#ifndef _cfe_sb_
#define _cfe_sb_

/*
** Includes
*/
#include "cfe/cfe_error.h"
#include "osal/common_types.h"
#include "cfe/ccsds.h"

/*
** Defines
*/
#define CFE_SB_POLL                     0      /**< \brief Option used with #CFE_SB_RcvMsg to request immediate pipe status */
#define CFE_SB_PEND_FOREVER            -1      /**< \brief Option used with #CFE_SB_RcvMsg to force a wait for next message */
#define CFE_SB_SUB_ENTRIES_PER_PKT      20     /**< \brief Configuration parameter used by SBN App */
#define CFE_SB_SUBSCRIPTION             0      /**< \brief Subtype specifier used in #CFE_SB_SingleSubscriptionTlm_t by SBN App */
#define CFE_SB_UNSUBSCRIPTION           1      /**< \brief Subtype specified used in #CFE_SB_SingleSubscriptionTlm_t by SBN App */

#define CFE_SB_INVALID_MSG_ID           0xFFFF /**< \brief Initializer for CFE_SB_MsgId_t values that will not match any real MsgId */

/*
** Macro Definitions
*/
#define CFE_BIT(x)   (1 << (x))               /**< \brief Places a one at bit positions 0 - 31*/
#define CFE_SET(i,x) ((i) |= CFE_BIT(x))      /**< \brief Sets bit x of i */
#define CFE_CLR(i,x) ((i) &= ~CFE_BIT(x))     /**< \brief Clears bit x of i */
#define CFE_TST(i,x) (((i) & CFE_BIT(x)) != 0)/**< \brief TRUE(non zero) if bit x of i is set */

/**
 * Macro that should be used to set memory addresses within software bus messages.
 * For now this does a straight copy, but in a future revision this may translate the
 * raw memory address into a "safe" integer value.  This is particularly important if
 * the message is to be sent off this CPU.
 */
#define CFE_SB_SET_MEMADDR(msgdst,src)       msgdst = (cpuaddr)src

/**
 * Macro that should be used to get memory addresses from software bus messages.
 * This is the inverse operation of CFE_SB_SET_MEMADDR.
 */
#define CFE_SB_GET_MEMADDR(msgsrc)           (cpuaddr)msgsrc

/*
** Pipe option bit fields.
*/
#define CFE_SB_PIPEOPTS_IGNOREMINE 0x00000001 /**< \brief Messages sent by the app that owns this pipe will not be sent to this pipe. */

/**
 * @brief  CFE_SB_MsgId_Atom_t primitive type definition
 *
 * This is an integer type capable of holding any Message ID value
 */
#ifdef MESSAGE_FORMAT_IS_CCSDS_VER_2
typedef uint32 CFE_SB_MsgId_Atom_t;
#else
typedef uint16 CFE_SB_MsgId_Atom_t;
#endif

/**
 * @brief  CFE_SB_MsgId_t type definition
 *
 * Software Bus message identifier used in many SB APIs
 *
 * Currently this is directly mapped to the underlying holding type (not wrapped) for
 * compatibility with existing usage semantics in apps (mainly switch/case statements)
 *
 * @note In a future version it could become a type-safe wrapper similar to the route index,
 * to avoid message IDs getting mixed between other integer values.
 */
typedef CFE_SB_MsgId_Atom_t CFE_SB_MsgId_t;

/*
** Type Definitions
*/
#ifdef MESSAGE_FORMAT_IS_CCSDS

    /**< \brief Generic Software Bus Message Type Definition */
    typedef union {
        CCSDS_PriHdr_t      Hdr;   /**< \brief CCSDS Primary Header #CCSDS_PriHdr_t */
        CCSDS_SpacePacket_t SpacePacket;
        uint32              Dword; /**< \brief Forces minimum of 32-bit alignment for this object */
        uint8               Byte[sizeof(CCSDS_PriHdr_t)];   /**< \brief Allows byte-level access */
    }CFE_SB_Msg_t;
        
    /** \brief Generic Software Bus Command Header Type Definition */
    typedef CCSDS_CommandPacket_t   CFE_SB_CmdHdr_t;

    /** \brief Generic Software Bus Telemetry Header Type Definition */
    typedef CCSDS_TelemetryPacket_t CFE_SB_TlmHdr_t;

    #define CFE_SB_CMD_HDR_SIZE     (sizeof(CFE_SB_CmdHdr_t))/**< \brief Size of #CFE_SB_CmdHdr_t in bytes */
    #define CFE_SB_TLM_HDR_SIZE     (sizeof(CFE_SB_TlmHdr_t))/**< \brief Size of #CFE_SB_TlmHdr_t in bytes */

#endif /* MESSAGE_FORMAT_IS_CCSDS */

/**< \brief  CFE_SB_TimeOut_t to primitive type definition
** 
** Internally used by SB in the #CFE_SB_RcvMsg API. Translated from the
** input parmater named TimeOut which specifies the maximum time in 
** milliseconds that the caller wants to wait for a message.
*/
typedef uint32 CFE_SB_TimeOut_t;

/**< \brief  CFE_SB_PipeId_t to primitive type definition 
** 
** Software Bus pipe identifier used in many SB APIs
*/
typedef uint8  CFE_SB_PipeId_t;

/**< \brief  CFE_SB_MsgPtr_t defined as a pointer to an SB Message */
typedef CFE_SB_Msg_t *CFE_SB_MsgPtr_t;

/**< \brief  CFE_SB_MsgPayloadPtr_t defined as an opaque pointer to a message Payload portion */
typedef uint8 *CFE_SB_MsgPayloadPtr_t;

/**< \brief  CFE_SB_ZeroCopyId_t to primitive type definition 
** 
** Software Zero Copy handle used in many SB APIs
*/
typedef cpuaddr CFE_SB_ZeroCopyHandle_t;

/**< \brief Quality Of Service Type Definition
**
** Currently an unused parameter in #CFE_SB_SubscribeEx
** Intended to be used for interprocessor communication only
**/ 
typedef  struct {
    uint8 Priority;/**< \brief  Specify high(1) or low(0) message priority for off-board routing, currently unused */
    uint8 Reliability;/**< \brief  Specify high(1) or low(0) message transfer reliability for off-board routing, currently unused */
}CFE_SB_Qos_t;

extern CFE_SB_Qos_t CFE_SB_Default_Qos;/**< \brief  Defines a default priority and reliabilty for off-board routing */

/*
** Type definition (system time)...
*/
/** 
**  \brief Data structure used to hold system time values
**
**  \par Description
**       The #CFE_TIME_SysTime_t data structure is used to hold time
**       values.  Time is referred to as the elapsed time (in seconds
**       and subseconds) since a specified epoch time.  The subseconds
**       field contains the number of 2^(-32) second intervals that have
**       elapsed since the epoch.
**
*/
typedef struct
{
  uint32  Seconds;            /**< \brief Number of seconds since epoch */
  uint32  Subseconds;         /**< \brief Number of subseconds since epoch (LSB = 2^(-32) seconds) */
} CFE_TIME_SysTime_t;

/*****************************************************************************/
/**
** \brief Converts a sub-seconds count to an equivalent number of microseconds
**
** \par Description
**        This routine converts from a sub-seconds count 
**        (each tick is 1 / 2^32 seconds) to microseconds (each tick is 1e-06 seconds).
**
** \par Assumptions, External Events, and Notes:
**          None
**
** \param[in] SubSeconds   The sub-seconds count to convert.
**
** \returns
** \retstmt The equivalent number of microseconds.    \endstmt            
** \endreturns
**
** \sa #CFE_TIME_MET2SCTime, #CFE_TIME_Micro2SubSecs, 
**     #CFE_TIME_CFE2FSSeconds, #CFE_TIME_FS2CFESeconds
**
******************************************************************************/
uint32  CFE_TIME_Sub2MicroSecs(uint32 SubSeconds);     /* convert sub-seconds (1/2^32) to micro-seconds (1/1000000) */

/*****************************************************************************/
/**
** \brief Converts a number of microseconds to an equivalent sub-seconds count.
**
** \par Description
**        This routine converts from microseconds (each tick is 1e-06 seconds) 
**        to a subseconds count (each tick is 1 / 2^32 seconds).
**
** \par Assumptions, External Events, and Notes:
**          None
**
** \param[in] MicroSeconds   The sub-seconds count to convert.
**
** \returns
** \retstmt The equivalent number of subseconds.  If the number of microseconds 
**         passed in is greater than one second, (i.e. > 999,999), the return 
**         value is equal to \c 0xffffffff.     \endstmt           
** \endreturns
**
** \sa #CFE_TIME_MET2SCTime, #CFE_TIME_Sub2MicroSecs, 
**     #CFE_TIME_CFE2FSSeconds, #CFE_TIME_FS2CFESeconds
**
******************************************************************************/
uint32  CFE_TIME_Micro2SubSecs(uint32 MicroSeconds);   /* convert micro-seconds (1/1000000) to sub-seconds (1/2^32) */

/*****************************************************************************/
/** 
** \brief Initialize a buffer for a software bus message.
**
** \par Description
**          This routine fills in the header information needed to create a 
**          valid software bus message.
**
** \par Assumptions, External Events, and Notes:
**          None  
**
** \param[in]  MsgPtr  A pointer to the buffer that will contain the message.  
**                     This will point to the first byte of the message header.  
**                     The \c void* data type allows the calling routine to use
**                     any data type when declaring its message buffer. 
**
** \param[in]  MsgId   The message ID to put in the message header.
**
** \param[in]  Length  The total number of bytes of message data, including the SB 
**                     message header  .
**
** \param[in]  Clear   A flag indicating whether to clear the rest of the message:
**                     \arg TRUE - fill sequence count and packet data with zeroes.
**                     \arg FALSE - leave sequence count and packet data unchanged.
**
** \sa #CFE_SB_SetMsgId, #CFE_SB_SetUserDataLength, #CFE_SB_SetTotalMsgLength,
**     #CFE_SB_SetMsgTime, #CFE_SB_TimeStampMsg, #CFE_SB_SetCmdCode 
**/
void CFE_SB_InitMsg(void           *MsgPtr,
                    CFE_SB_MsgId_t MsgId,
                    uint16         Length,
                    boolean        Clear );

/*****************************************************************************/
/** 
** \brief Get a pointer to the user data portion of a software bus message.
**
** \par Description
**          This routine returns a pointer to the user data portion of a software 
**          bus message.  SB message header formats can be different for each 
**          deployment of the cFE.  So, applications should use this function and 
**          avoid hard coding offsets into their SB message buffers.
**
** \par Assumptions, External Events, and Notes:
**          None  
**
** \param[in]  MsgPtr  A pointer to the buffer that contains the software bus message.
**
** \returns
** \retstmt A pointer to the first byte of user data within the software bus message. \endstmt
** \endreturns
**
** \sa #CFE_SB_GetMsgId, #CFE_SB_GetUserDataLength, #CFE_SB_GetTotalMsgLength,
**     #CFE_SB_GetMsgTime, #CFE_SB_GetCmdCode, #CFE_SB_GetChecksum, #CFE_SB_MsgHdrSize 
**/
void *CFE_SB_GetUserData(CFE_SB_MsgPtr_t MsgPtr);

/*****************************************************************************/
/** 
** \brief Get the message ID of a software bus message.
**
** \par Description
**          This routine returns the message ID from a software bus message.
**
** \par Assumptions, External Events, and Notes:
**          None  
**
** \param[in]  MsgPtr  A pointer to the buffer that contains the software bus message.
**
** \returns
** \retstmt The software bus Message ID from the message header. \endstmt
** \endreturns
**
** \sa #CFE_SB_GetUserData, #CFE_SB_SetMsgId, #CFE_SB_GetUserDataLength, #CFE_SB_GetTotalMsgLength,
**     #CFE_SB_GetMsgTime, #CFE_SB_GetCmdCode, #CFE_SB_GetChecksum, #CFE_SB_MsgHdrSize 
**/
CFE_SB_MsgId_t CFE_SB_GetMsgId(CFE_SB_MsgPtr_t MsgPtr);

/*****************************************************************************/
/** 
** \brief Sets the message ID of a software bus message.
**
** \par Description
**          This routine sets the Message ID in a software bus message header.
**
** \par Assumptions, External Events, and Notes:
**          None  
**
** \param[in]  MsgPtr  A pointer to the buffer that contains the software bus message.
**                     This must point to the first byte of the message header.
**
** \param[in]  MsgId   The message ID to put into the message header. 
**
** \returns
** \retstmt The software bus Message ID from the message header. \endstmt
** \endreturns
**
** \sa #CFE_SB_GetMsgId, #CFE_SB_SetUserDataLength, #CFE_SB_SetTotalMsgLength,
**     #CFE_SB_SetMsgTime, #CFE_SB_TimeStampMsg, #CFE_SB_SetCmdCode, #CFE_SB_InitMsg 
**/
void CFE_SB_SetMsgId(CFE_SB_MsgPtr_t MsgPtr,
                     CFE_SB_MsgId_t MsgId);

/*****************************************************************************/
/** 
** \brief Gets the length of user data in a software bus message.
**
** \par Description
**          This routine returns the size of the user data in a software bus message.
**
** \par Assumptions, External Events, and Notes:
**          None  
**
** \param[in]  MsgPtr  A pointer to the buffer that contains the software bus message.
**                     This must point to the first byte of the message header. 
**
** \returns
** \retstmt The size (in bytes) of the user data in the software bus message. \endstmt
** \endreturns
**
** \sa #CFE_SB_GetUserData, #CFE_SB_GetMsgId, #CFE_SB_SetUserDataLength, #CFE_SB_GetTotalMsgLength,
**     #CFE_SB_GetMsgTime, #CFE_SB_GetCmdCode, #CFE_SB_GetChecksum, #CFE_SB_MsgHdrSize 
**/
uint16 CFE_SB_GetUserDataLength(CFE_SB_MsgPtr_t MsgPtr);

/*****************************************************************************/
/** 
** \brief Sets the length of user data in a software bus message.
**
** \par Description
**          This routine sets the field in the SB message header that determines 
**          the size of the user data in a software bus message.  SB message header 
**          formats can be different for each deployment of the cFE.  So, applications 
**          should use this function rather than trying to poke a length value directly 
**          into their SB message buffers. 
**
** \par Assumptions, External Events, and Notes:
**          - You must set a valid message ID in the SB message header before 
**            calling this function.  
**
** \param[in]  MsgPtr      A pointer to the buffer that contains the software bus message.
**                         This must point to the first byte of the message header.
**
** \param[in]  DataLength  The length to set (size of the user data, in bytes).
**
**
** \sa #CFE_SB_SetMsgId, #CFE_SB_GetUserDataLength, #CFE_SB_SetTotalMsgLength,
**     #CFE_SB_SetMsgTime, #CFE_SB_TimeStampMsg, #CFE_SB_SetCmdCode, #CFE_SB_InitMsg 
**/
void CFE_SB_SetUserDataLength(CFE_SB_MsgPtr_t MsgPtr,uint16 DataLength);

/*****************************************************************************/
/** 
** \brief Gets the total length of a software bus message.
**
** \par Description
**          This routine returns the total size of the software bus message.   
**
** \par Assumptions, External Events, and Notes:
**          - For the CCSDS implementation of this API, the size is derived from
**            the message header.  
**
** \param[in]  MsgPtr      A pointer to the buffer that contains the software bus message.
**                         This must point to the first byte of the message header.
**
** \returns
** \retstmt The total size (in bytes) of the software bus message, including headers.  \endstmt
** \endreturns
**
** \sa #CFE_SB_GetUserData, #CFE_SB_GetMsgId, #CFE_SB_GetUserDataLength, #CFE_SB_SetTotalMsgLength,
**     #CFE_SB_GetMsgTime, #CFE_SB_GetCmdCode, #CFE_SB_GetChecksum, #CFE_SB_MsgHdrSize 
**/
uint16 CFE_SB_GetTotalMsgLength(CFE_SB_MsgPtr_t MsgPtr);

/*****************************************************************************/
/** 
** \brief Sets the total length of a software bus message.
**
** \par Description
**          This routine sets the field in the SB message header that determines 
**          the total length of the message.  SB message header formats can be 
**          different for each deployment of the cFE.  So, applications should 
**          use this function rather than trying to poke a length value directly 
**          into their SB message buffers.    
**
** \par Assumptions, External Events, and Notes:
**          None
**
** \param[in]  MsgPtr      A pointer to the buffer that contains the software bus message.
**                         This must point to the first byte of the message header.
**
** \param[in]  TotalLength The length to set (total size of the message, in bytes, 
**                         including headers).
**
** \sa #CFE_SB_SetMsgId, #CFE_SB_SetUserDataLength, #CFE_SB_GetTotalMsgLength,
**     #CFE_SB_SetMsgTime, #CFE_SB_TimeStampMsg, #CFE_SB_SetCmdCode, #CFE_SB_InitMsg 
**/
void CFE_SB_SetTotalMsgLength(CFE_SB_MsgPtr_t MsgPtr,uint16 TotalLength);

/*****************************************************************************/
/** 
** \brief Gets the time field from a software bus message.
**
** \par Description
**          This routine gets the time from a software bus message.    
**
** \par Assumptions, External Events, and Notes:
**          - If the underlying implementation of software bus messages does not 
**            include a time field, then this routine will return a zero time.  
**
** \param[in]  MsgPtr      A pointer to the buffer that contains the software bus message.
**                         This must point to the first byte of the message header. 
** \returns
** \retstmt The system time included in the software bus message header (if present), 
**         otherwise, returns a time value of zero.  \endstmt
** \endreturns
**
** \sa #CFE_SB_GetUserData, #CFE_SB_GetMsgId, #CFE_SB_GetUserDataLength, #CFE_SB_GetTotalMsgLength,
**     #CFE_SB_SetMsgTime, #CFE_SB_GetCmdCode, #CFE_SB_GetChecksum, #CFE_SB_MsgHdrSize 
**/
CFE_TIME_SysTime_t CFE_SB_GetMsgTime(CFE_SB_MsgPtr_t MsgPtr);

/*****************************************************************************/
/** 
** \brief Sets the time field in a software bus message.
**
** \par Description
**          This routine sets the time of a software bus message.  Most applications 
**          will want to use #CFE_SB_TimeStampMsg instead of this function.  But, 
**          when needed, #CFE_SB_SetMsgTime can be used to send a group of SB messages 
**          with identical time stamps.    
**
** \par Assumptions, External Events, and Notes:
**          - If the underlying implementation of software bus messages does not include 
**            a time field, then this routine will do nothing to the message contents 
**            and will return #CFE_SB_WRONG_MSG_TYPE.  
**
** \param[in]  MsgPtr      A pointer to the buffer that contains the software bus message.
**                         This must point to the first byte of the message header.
**
** \param[in]  Time        The time to include in the message.  This will usually be a time 
**                         returned by the function #CFE_TIME_GetTime().
**
** \returns
** \retcode #CFE_SUCCESS            \retdesc \copydoc CFE_SUCCESS            \endcode
** \retcode #CFE_SB_WRONG_MSG_TYPE  \retdesc \copydoc CFE_SB_WRONG_MSG_TYPE  \endcode
** \endreturns
**
** \sa #CFE_SB_SetMsgId, #CFE_SB_SetUserDataLength, #CFE_SB_SetTotalMsgLength,
**     #CFE_SB_GetMsgTime, #CFE_SB_TimeStampMsg, #CFE_SB_SetCmdCode, #CFE_SB_InitMsg 
**/
int32 CFE_SB_SetMsgTime(CFE_SB_MsgPtr_t MsgPtr,
                       CFE_TIME_SysTime_t Time);

/*****************************************************************************/
/** 
** \brief Sets the time field in a software bus message with the current spacecraft time.
**
** \par Description
**          This routine sets the time of a software bus message with the current 
**          spacecraft time.  This will be the same time that is returned by the 
**          function #CFE_TIME_GetTime.      
**
** \par Assumptions, External Events, and Notes:
**          - If the underlying implementation of software bus messages does not 
**            include a time field, then this routine will do nothing.  
**
** \param[in]  MsgPtr      A pointer to the buffer that contains the software bus message.
**                         This must point to the first byte of the message header. 
**
** \sa #CFE_SB_SetMsgId, #CFE_SB_SetUserDataLength, #CFE_SB_SetTotalMsgLength,
**     #CFE_SB_SetMsgTime, #CFE_SB_SetCmdCode, #CFE_SB_InitMsg 
**/
void CFE_SB_TimeStampMsg(CFE_SB_MsgPtr_t MsgPtr, CFE_TIME_SysTime_t Time);

/*****************************************************************************/
/** 
** \brief Gets the command code field from a software bus message.
**
** \par Description
**          This routine gets the command code from a software bus message (if 
**          SB messages are implemented as CCSDS packets, this will be the function 
**          code).      
**
** \par Assumptions, External Events, and Notes:
**          - If the underlying implementation of software bus messages does not 
**            include a command code field, then this routine will return a zero.  
**
** \param[in]  MsgPtr      A pointer to the buffer that contains the software bus message.
**                         This must point to the first byte of the message header.
**
** \returns
** \retstmt The command code included in the software bus message header (if present).
**         Otherwise, returns a command code value of zero.  \endstmt
** \endreturns
**
** \sa #CFE_SB_GetUserData, #CFE_SB_GetMsgId, #CFE_SB_GetUserDataLength, #CFE_SB_GetTotalMsgLength,
**     #CFE_SB_GetMsgTime, #CFE_SB_SetCmdCode, #CFE_SB_GetChecksum, #CFE_SB_MsgHdrSize 
**/
uint16 CFE_SB_GetCmdCode(CFE_SB_MsgPtr_t MsgPtr);

/*****************************************************************************/
/** 
** \brief Sets the command code field in a software bus message.
**
** \par Description
**          This routine sets the command code of a software bus message (if SB 
**          messages are implemented as CCSDS packets, this will be the function code).      
**
** \par Assumptions, External Events, and Notes:
**          - If the underlying implementation of software bus messages does not 
**            include a command code field, then this routine will do nothing to 
**            the message contents and will return #CFE_SB_WRONG_MSG_TYPE.  
**
** \param[in]  MsgPtr      A pointer to the buffer that contains the software bus message.
**                         This must point to the first byte of the message header.
**
** \param[in]  CmdCode     The command code to include in the message.
**
** \returns
** \retcode #CFE_SUCCESS           \retdesc \copydoc CFE_SUCCESS            \endcode
** \retcode #CFE_SB_WRONG_MSG_TYPE \retdesc \copydoc CFE_SB_WRONG_MSG_TYPE  \endcode
** \endreturns
**
** \sa #CFE_SB_SetMsgId, #CFE_SB_SetUserDataLength, #CFE_SB_SetTotalMsgLength,
**     #CFE_SB_SetMsgTime, #CFE_SB_TimeStampMsg, #CFE_SB_GetCmdCode, #CFE_SB_InitMsg 
**/
int32 CFE_SB_SetCmdCode(CFE_SB_MsgPtr_t MsgPtr,
                        uint16 CmdCode);

/*****************************************************************************/
/** 
** \brief Gets the checksum field from a software bus message.
**
** \par Description
**          This routine gets the checksum (or other message integrity check 
**          value) from a software bus message.  The contents and location of 
**          this field will depend on the underlying implementation of software 
**          bus messages.  It may be a checksum, a CRC, or some other algorithm.  
**          Users should not call this function as part of a message integrity 
**          check (call #CFE_SB_ValidateChecksum instead).      
**
** \par Assumptions, External Events, and Notes:
**          - If the underlying implementation of software bus messages does not 
**            include a checksum field, then this routine will return a zero.  
**
** \param[in]  MsgPtr      A pointer to the buffer that contains the software bus message.
**                         This must point to the first byte of the message header.
**
** \returns
** \retstmt The checksum included in the software bus message header (if present), otherwise,
**         returns a checksum value of zero.  \endstmt
** \endreturns
**
** \sa #CFE_SB_GetUserData, #CFE_SB_GetMsgId, #CFE_SB_GetUserDataLength, #CFE_SB_GetTotalMsgLength,
**     #CFE_SB_GetMsgTime, #CFE_SB_GetCmdCode, #CFE_SB_GetChecksum, #CFE_SB_MsgHdrSize,
**     #CFE_SB_ValidateChecksum, #CFE_SB_GenerateChecksum 
**/
uint16 CFE_SB_GetChecksum(CFE_SB_MsgPtr_t MsgPtr);

/*****************************************************************************/
/** 
** \brief Calculates and sets the checksum of a software bus message
**
** \par Description
**          This routine calculates the checksum of a software bus message according 
**          to an implementation-defined algorithm.  Then, it sets the checksum field 
**          in the message with the calculated value.  The contents and location of 
**          this field will depend on the underlying implementation of software bus 
**          messages.  It may be a checksum, a CRC, or some other algorithm.        
**
** \par Assumptions, External Events, and Notes:
**          - If the underlying implementation of software bus messages does not 
**            include a checksum field, then this routine will do nothing.  
**
** \param[in]  MsgPtr      A pointer to the buffer that contains the software bus message.
**                         This must point to the first byte of the message header.
**
** \sa #CFE_SB_ValidateChecksum, #CFE_SB_GetChecksum
**/
void CFE_SB_GenerateChecksum(CFE_SB_MsgPtr_t MsgPtr);

/*****************************************************************************/
/** 
** \brief Validates the checksum of a software bus message.
**
** \par Description
**          This routine calculates the expected checksum of a software bus message 
**          according to an implementation-defined algorithm.  Then, it checks the 
**          calculated value against the value in the message's checksum.  If the 
**          checksums do not match, this routine will generate an event message 
**          reporting the error.        
**
** \par Assumptions, External Events, and Notes:
**          - If the underlying implementation of software bus messages does not 
**            include a checksum field, then this routine will always return \c TRUE.  
**
** \param[in]  MsgPtr      A pointer to the buffer that contains the software bus message.
**                         This must point to the first byte of the message header.
**
** \returns
** \retcode TRUE  \retdesc The checksum field in the packet is valid.   \endcode
** \retcode FALSE \retdesc The checksum field in the packet is not valid or the message type is wrong. \endcode
** \endreturns
**
** \sa #CFE_SB_GenerateChecksum, #CFE_SB_GetChecksum
**/
boolean CFE_SB_ValidateChecksum(CFE_SB_MsgPtr_t MsgPtr);

/**
 * @brief Identifies whether a two CFE_SB_MsgId_t values are equal
 *
 * @par Description
 *    In cases where the CFE_SB_MsgId_t type is not a simple integer
 *    type, it may not be possible to do a direct equality check.
 *    This inline function provides an abstraction for the equality
 *    check between two CFE_SB_MsgId_t values.
 *
 *    Applications should transition to using this function to compare
 *    MsgId values for equality to remain compatible with future versions
 *    of cFE.
 *
 * @return TRUE if equality checks passed, FALSE otherwise.
 */
static inline osalbool CFE_SB_MsgId_Equal(CFE_SB_MsgId_t MsgId1, CFE_SB_MsgId_t MsgId2)
{
    return (MsgId1 == MsgId2);
}

/*****************************************************************************/
/**
 * @brief Converts a CFE_SB_MsgId_t to a normal integer
 *
 * @par Description
 *    In cases where the CFE_SB_MsgId_t type is not a simple integer
 *    type, it is not possible to directly display the value in a
 *    printf-style statement, use it in a switch() statement, or other
 *    similar use cases.
 *
 *    This inline function provides the ability to map a CFE_SB_MsgId_t
 *    type back into a simple integer value.
 *
 *    Applications should transition to using this function wherever a
 *    CFE_SB_MsgId_t type needs to be used as an integer.
 *
 * @par Assumptions and Notes:
 *    This negates the type safety that was gained by using a non-
 *    integer type for the CFE_SB_MsgId_t value.  This should only be used
 *    in specific cases such as UI display (printf, events, etc) where the
 *    value is being sent externally.  Any internal API calls should be
 *    updated to use the CFE_SB_MsgId_t type directly, rather than an
 *    integer type.
 *
 * @return Integer representation of the CFE_SB_MsgId_t
 */
static inline CFE_SB_MsgId_Atom_t CFE_SB_MsgIdToValue(CFE_SB_MsgId_t MsgId)
{
    return MsgId;
}

/*****************************************************************************/
/**
 * @brief Converts a normal integer into a CFE_SB_MsgId_t
 *
 * @par Description:
 *    In cases where the CFE_SB_MsgId_t type is not a simple integer
 *    type, it is not possible to directly use an integer value
 *    supplied via a #define or similar method.
 *
 *    This inline function provides the ability to map an integer value
 *    into a corresponding CFE_SB_MsgId_t value.
 *
 *    Applications should transition to using this function wherever an
 *    integer needs to be used for a CFE_SB_MsgId_t.
 *
 * @par Assumptions and Notes:
 *    This negates the type safety that was gained by using a non-
 *    integer type for the CFE_SB_MsgId_t value.  This should only be
 *    used in specific cases where the value is coming from an external
 *    source.  Any internal API calls should be updated to return the
 *    CFE_SB_MsgId_t type directly, rather than an integer type.
 *
 * @return CFE_SB_MsgId_t representation of the integer
 */
static inline CFE_SB_MsgId_t CFE_SB_ValueToMsgId(CFE_SB_MsgId_Atom_t MsgIdValue)
{
    return MsgIdValue;
}


#endif  /* _cfesb_ */
/*****************************************************************************/
