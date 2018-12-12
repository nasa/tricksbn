/******************************************************************************
** File: cfe_sb_msg_id_util.c
**
**      Copyright (c) 2004-2012, United States government as represented by the
**      administrator of the National Aeronautics Space Administration.
**      All rights reserved. This software(cFE) was created at NASA's Goddard
**      Space Flight Center pursuant to government contracts.
**
**      This is governed by the NASA Open Source Agreement and may be used,
**      distributed and modified only pursuant to the terms of that agreement.
**
**
**
** Purpose:
**      This file contains 'access' macros and functions for reading and
**      writing message ID header fields.
**      
**      The function prototypes are in cfe_sb.h except for ConvertMsgIdToMsgKey
**      which is in cfe_sb_priv.h
*
**      The MsgId is a mission defined message identifier to publish or subscribe to that must be 
**      unique within the system(s). CFE_SB_MsgId_t is a uint32 that can be created from any 
**      combination of bits from the primary header SID (StreamId) and the secondary header APID Qualifiers
**      
**      Implementation is based on CCSDS Space Packet Protocol 133.0.B-1 with Technical Corrigendum 2, September 2012
**      The extended secondary header is expected in an upcoming revision of 133.0.B-1
**
**      For  MESSAGE_FORMAT_IS_CCSDS_VER_2 the default setup will combine:
**       1 bit for the command/telemetry flag 
**       7 bits from the primary header APID
**       0 bits from the Playback flag
**       8 bits from the secondary header APID qualifier (Subsystem)
**       0 bits from the secondary header APID qualifier as the System
**    = 16 bits total 
**     
**
**     The APID qualifier System field can be populated in the Secondary header but
**     but will be ignored in the default case for SB/SBN routing purposes. It is suggested 
**     that the CCSDS Spacecraft ID be used for that field.
**
** Notes: The following 4 terms have been or are used in the cFS architecture and implementation
**         
**      StreamId - First 16 bits of CCSDS Space Packet Protocol (SPP) 133.0-B.1c2 Blue Book 
**                 packet primary header. It contains the 3 bit Version Number, 1 bit Packet Type ID,
**                 1 bit Secondary Header flag, and 11 bit Application Process ID
**                 It was used in earlier cFS implementaions and defined here for historical reference
**                 It is NOT exposed to user applications.
**
**      MsgId    - Unique numeric message identifier within a mission namespace. It is used by cFS
**                 applications to the identify messages for publishing and subscribing
**                 It is used by the SB API and encoded in a mission defended way in the header of 
**                 all cFS messages.
**                 It is exposed to all cFS applications
**
**      ApId     - CCSDS Application Process Id field in the primary header. 
**                 It has default bit mask of 0x07FF and is part of the cFS message Id
**                 It should not be confused with the cFE Executive Services (ES) term appId which
**                 identifies the software application/component
**                 It is NOT exposed to user applications.
**
**      MsgIdkey - This is a unique numeric key within a mission namespace that is used with  
**                 cFS software bus internal structures. 
**                 It is algorithmically created in a mission defined way from the MsgId to support
**                 efficient lookup and mapping implementations 
**                 It is NOT exposed to user applications.
**
** Author:   J. Wilmot/NASA
**
******************************************************************************/


/*
** Include Files
*/
#include <string.h>

#include "ccsds_header_lib.h"

/******************************************************************************
**  Function:  CFE_SB_InitMsg()
**
**  Purpose:
**    Initialize the header fields of a message 
**
**  Arguments:
**    MsgPtr  - Pointer to the header of a message.
**    MsgId   - MsgId to use for the message.
**    Length  - Length of the message in bytes.
**    Clear   - Indicates whether to clear the entire message:
**                TRUE = fill sequence count and packet data with zeros
**                FALSE = leave sequence count and packet data unchanged
**  Return:
**    (none)
*/
void CFE_SB_InitMsg(void           *MsgPtr,
                    CFE_SB_MsgId_t MsgId,
                    uint16         Length,
                    boolean        Clear )
{
   uint16           SeqCount;
   CCSDS_PriHdr_t  *PktPtr;

   PktPtr = (CCSDS_PriHdr_t *) MsgPtr;

  /* Save the sequence count in case it must be preserved. */
   SeqCount = CCSDS_RD_SEQ(*PktPtr);

   /* Zero the entire packet if needed. */
   if (Clear)  
     { memset(MsgPtr, 0, Length); }
     else    /* Clear only the primary header. */
      {
        CCSDS_CLR_PRI_HDR(*PktPtr);
      }

   /* Set the length fields in the primary header. */
  CCSDS_WR_LEN(*PktPtr, Length);
  
  /* Always set the secondary header flag as CFS applications are required use it */
  CCSDS_WR_SHDR(*PktPtr, 1);

  CFE_SB_SetMsgId(MsgPtr, MsgId);
  
  /* Restore the sequence count if needed. */
   if (!Clear)  
      CCSDS_WR_SEQ(*PktPtr, SeqCount);
   else
      CCSDS_WR_SEQFLG(*PktPtr, CCSDS_INIT_SEQFLG);

} /* end CFE_SB_InitMsg */

/******************************************************************************
**  Function:  CFE_SB_GetMsgId
**
**  Purpose:
**    Convert the CCSDS SPP APID in the packet to the internal MsgId ID format
**       used for SB APIs and routing.
**
**    For backward compatability with the existing CCSDS SPP version 1 code base
**    the function name has not been changed
**
**  Arguments:
**    MsgPtr - Pointer to a CCSDS SPP message packet
**
**  Return:
**    The Message Id in the message packet converted to the cFS MsgId
*/
CFE_SB_MsgId_t CFE_SB_GetMsgId(CFE_SB_MsgPtr_t MsgPtr)
{
   CFE_SB_MsgId_t MsgId = 0;

#ifdef MESSAGE_FORMAT_IS_CCSDS

#ifndef MESSAGE_FORMAT_IS_CCSDS_VER_2  
    MsgId = CCSDS_RD_SID(MsgPtr->Hdr);
#else

    uint32            ApidId;
    uint32            SubSystemId;
    uint32            SystemId;
    uint32            Type;


    ApidId = CCSDS_RD_APID(MsgPtr->Hdr); /* Primary header APID  */
    MsgId = CFE_SB_WR_MSGID_FROM_APID(ApidId);

    Type = CCSDS_RD_TYPE(MsgPtr->Hdr);
    Type = CFE_SB_WR_MSGID_FROM_TYPE(Type);

    /* Add in the SubSystem ID as needed */
    SubSystemId = CCSDS_RD_SUBSYSTEM_ID(MsgPtr->SpacePacket.ApidQ);
    SubSystemId = CFE_SB_WR_MSGID_FROM_SUBSYS_ID(SubSystemId);

    SystemId = CCSDS_RD_SYSTEM_ID(MsgPtr->SpacePacket.ApidQ);
    SystemId = CFE_SB_WR_MSGID_FROM_SYSTEM_ID(SystemId);

    MsgId = MsgId | Type | SubSystemId | SystemId;

/* Example code to add in the System ID as needed. */
/*   The default is to init this field to the Spacecraft ID but ignore for routing.   */
/*   To fully implement this field would require significant SB optimization to avoid */
/*   prohibitively large routing and index tables. */
/*      uint16            SystemId;                              */
/*      SystemId = CCSDS_RD_SYSTEM_ID(HdrPtr->ApidQ);            */
/*      MsgId = (MsgId | (SystemId << 16)); */

#endif
#endif

return MsgId;

}/* end CFE_SB_GetMsgId */


/******************************************************************************
**  Function:  CFE_SB_SetMsgId
**
**  Purpose:
**    Set the message Id of a message in CCSDS header format
**
**  Arguments:
**    MsgPtr - Pointer to a CFE_SB_Msg_t
**    MsgId  - Message Id to be written
**
**
**  Return:
**    (none)
*/
void CFE_SB_SetMsgId(CFE_SB_MsgPtr_t MsgPtr,
                     CFE_SB_MsgId_t MsgId)
{

#ifndef MESSAGE_FORMAT_IS_CCSDS_VER_2  
    CCSDS_WR_SID(MsgPtr->Hdr, MsgId);
#else

  CCSDS_WR_VERS(MsgPtr->SpacePacket.Hdr, 1);

  /* Set the stream ID APID in the primary header. */
  CCSDS_WR_APID(MsgPtr->SpacePacket.Hdr, CFE_SB_RD_APID_FROM_MSGID(MsgId) );
  
  CCSDS_WR_TYPE(MsgPtr->SpacePacket.Hdr, CFE_SB_RD_TYPE_FROM_MSGID(MsgId) );
  
  
  CCSDS_CLR_SEC_APIDQ(MsgPtr->SpacePacket.ApidQ);
  
  CCSDS_WR_EDS_VER(MsgPtr->SpacePacket.ApidQ, 1);
  
  CCSDS_WR_ENDIAN(MsgPtr->SpacePacket.ApidQ, CFE_PLATFORM_ENDIAN);
  
  CCSDS_WR_PLAYBACK(MsgPtr->SpacePacket.ApidQ, FALSE);
  
  CCSDS_WR_SUBSYSTEM_ID(MsgPtr->SpacePacket.ApidQ, CFE_SB_RD_SUBSYS_ID_FROM_MSGID(MsgId));
  
  CCSDS_WR_SYSTEM_ID(MsgPtr->SpacePacket.ApidQ, CFE_SB_RD_SYSTEM_ID_FROM_MSGID(MsgId));

#endif 
}/* end CFE_SB_SetMsgId */

// CFE_TIME_Micro2SubSecs
// CFE_TIME_Sub2MicroSecs

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                         */
/* CFE_TIME_Sub2MicroSecs() -- convert sub-seconds to micro-seconds        */
/*                                                                         */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

uint32  CFE_TIME_Sub2MicroSecs(uint32 SubSeconds)
{
    uint32 MicroSeconds;
	
    /* 0xffffdf00 subseconds = 999999 microseconds, so anything greater 
     * than that we set to 999999 microseconds, so it doesn't get to
     * a million microseconds */
    
	if (SubSeconds > 0xffffdf00)
	{
			MicroSeconds = 999999;
	}
    else
    {
        /*
        **  Convert a 1/2^32 clock tick count to a microseconds count
        **
        **  Conversion factor is  ( ( 2 ** -32 ) / ( 10 ** -6 ) ).
        **
        **  Logic is as follows:
        **    x * ( ( 2 ** -32 ) / ( 10 ** -6 ) )
        **  = x * ( ( 10 ** 6  ) / (  2 ** 32 ) )
        **  = x * ( ( 5 ** 6 ) ( 2 ** 6 ) / ( 2 ** 26 ) ( 2 ** 6) )
        **  = x * ( ( 5 ** 6 ) / ( 2 ** 26 ) )
        **  = x * ( ( 5 ** 3 ) ( 5 ** 3 ) / ( 2 ** 7 ) ( 2 ** 7 ) (2 ** 12) )
        **
        **  C code equivalent:
        **  = ( ( ( ( ( x >> 7) * 125) >> 7) * 125) >> 12 )
        */   

    	MicroSeconds = (((((SubSeconds >> 7) * 125) >> 7) * 125) >> 12);
    

        /* if the Subseconds % 0x4000000 != 0 then we will need to
         * add 1 to the result. the & is a faster way of doing the % */  
	    if ((SubSeconds & 0x3ffffff) != 0)
    	{
	    	MicroSeconds++;
    	}
    
        /* In the Micro2SubSecs conversion, we added an extra anomaly
         * to get the subseconds to bump up against the end point,
         * 0xFFFFF000. This must be accounted for here. Since we bumped
         * at the half way mark, we must "unbump" at the same mark 
         */
        if (MicroSeconds > 500000)
        {
            MicroSeconds --;
        }
        
    } /* end else */
    
    return(MicroSeconds);

} /* End of CFE_TIME_Sub2MicroSecs() */


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                         */
/* CFE_TIME_Micro2SubSecs() -- convert micro-seconds to sub-seconds        */
/*                                                                         */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

uint32  CFE_TIME_Micro2SubSecs(uint32 MicroSeconds)
{
    uint32 SubSeconds;

    /*
    ** Conversion amount must be less than one second
    */
    if (MicroSeconds > 999999)
    {
        SubSeconds = 0xFFFFFFFF;
    }
    else
    {
    /*
    **  Convert micro-seconds count to sub-seconds (1/2^32) count
    **
    **  Conversion factor is  ( ( 10 ** -6 ) / ( 2 ** -20 ).
    **
    **  Logic is as follows:
    **    x * ( ( 10 ** -6 ) / ( 2 ** -32 ) )
    **  = x * ( ( 2 ** 32 ) / ( 10 ** 6 ) )
    **  = x * ( ( ( 2 ** 26 ) ( 2 ** 6) ) / ( ( 5 ** 6 ) ( 2 ** 6 ) ) )
    **  = x * ( ( 2 ** 26 ) / ( 5 ** 6 ) )
    **  = x * ( ( ( 2 ** 11) ( 2 ** 3) (2 ** 12) ) / ( 5( 5 ** 5 ) ) )
    **  = x * ( ( ( ( ( 2 ** 11 ) / 5 ) * ( 2 ** 3 ) ) / ( 5 ** 5 ) ) * (2 ** 12) )
    **
    **  C code equivalent:
    **  = ( ( ( ( ( x << 11 ) / 5 ) << 3 ) / 3125 ) << 12 )
    **
    **  Conversion factor was reduced and factored accordingly
    **  to minimize precision loss and register overflow.
    */
        SubSeconds = ( ( ( ( MicroSeconds << 11 ) / 5 ) << 3 ) / 3125 ) << 12;

        /* To get the SubSeconds to "bump up" against 0xFFFFF000 when 
         * MicroSeconds = 9999999, we add in another anomaly to the 
         * conversion at the half-way point  (500000 us). This will bump
         * all of the subseconds up by 0x1000, so 999999 us == 0xFFFFF00,
         * 999998 == 0xFFFFE000, etc. This extra anomaly is accounted for
         * in the Sub2MicroSecs conversion as well.
         */
        
        if (SubSeconds > 0x80001000)
        {
           SubSeconds += 0x1000;
        }

    }

    return(SubSeconds);

} /* End of CFE_TIME_Micro2SubSecs() */

/******************************************************************************
**  Function:  CFE_SB_GetMsgTime()
**
**  Purpose:
**    Get the time field from a message.
**
**  Arguments:
**    MsgPtr - Pointer to a CFE_SB_Msg_t
**
**  Return:
**    Time field from message or
**    Time value of zero for msgs that do not have a Time field in header
*/
CFE_TIME_SysTime_t CFE_SB_GetMsgTime(CFE_SB_MsgPtr_t MsgPtr)
{
    CFE_TIME_SysTime_t TimeFromMsg;
    uint32 LocalSecs32 = 0;
    uint32 LocalSubs32 = 0;

    #if (CFE_MISSION_SB_PACKET_TIME_FORMAT == CFE_MISSION_SB_TIME_32_16_SUBS)
    uint16 LocalSubs16;
    #endif

    CFE_SB_TlmHdr_t *TlmHdrPtr;

    /* if msg type is a command or msg has no secondary hdr, time = 0 */
    if ((CCSDS_RD_TYPE(MsgPtr->Hdr) != CCSDS_CMD) && (CCSDS_RD_SHDR(MsgPtr->Hdr) != 0)) {

        /* copy time data to/from packets to eliminate alignment issues */
        TlmHdrPtr = (CFE_SB_TlmHdr_t *)MsgPtr;

        #if (CFE_MISSION_SB_PACKET_TIME_FORMAT == CFE_MISSION_SB_TIME_32_16_SUBS)

        memcpy(&LocalSecs32, &TlmHdrPtr->Sec.Time[0], 4);
        memcpy(&LocalSubs16, &TlmHdrPtr->Sec.Time[4], 2);
        /* convert packet data into CFE_TIME_SysTime_t format */
        LocalSubs32 = ((uint32) LocalSubs16) << 16;

        #elif (CFE_MISSION_SB_PACKET_TIME_FORMAT == CFE_MISSION_SB_TIME_32_32_SUBS)

        memcpy(&LocalSecs32, &TlmHdrPtr->Sec.Time[0], 4);
        memcpy(&LocalSubs32, &TlmHdrPtr->Sec.Time[4], 4);
        /* no conversion necessary -- packet format = CFE_TIME_SysTime_t format */

        #elif (CFE_MISSION_SB_PACKET_TIME_FORMAT == CFE_MISSION_SB_TIME_32_32_M_20)

        memcpy(&LocalSecs32, &TlmHdrPtr->Sec.Time[0], 4);
        memcpy(&LocalSubs32, &TlmHdrPtr->Sec.Time[4], 4);
        /* convert packet data into CFE_TIME_SysTime_t format */
        LocalSubs32 = CFE_TIME_Micro2SubSecs((LocalSubs32 >> 12));

        #endif
    }

    /* return the packet time converted to CFE_TIME_SysTime_t format */
    TimeFromMsg.Seconds    = LocalSecs32;
    TimeFromMsg.Subseconds = LocalSubs32;

    return TimeFromMsg;

}/* end CFE_SB_GetMsgTime */


/******************************************************************************
**  Function:  CFE_SB_SetMsgTime()
**
**  Purpose:
**    Set the time field from a message.
**
**  Arguments:
**    MsgPtr  - Pointer to a CFE_SB_Msg_t
**    NewTime - Time to write in message
**
**  Return:
**    CFE_SUCCESS for no errors
**    CFE_SB_WRONG_MSG_TYPE if msg does not have a header field for time.
*/
int32 CFE_SB_SetMsgTime(CFE_SB_MsgPtr_t MsgPtr, CFE_TIME_SysTime_t NewTime)
{
    int32 Result = CFE_SB_WRONG_MSG_TYPE;

    CFE_SB_TlmHdr_t *TlmHdrPtr;

    /* declare format specific vars */
    #if (CFE_MISSION_SB_PACKET_TIME_FORMAT == CFE_MISSION_SB_TIME_32_16_SUBS)
    uint16 LocalSubs16;
    #elif (CFE_MISSION_SB_PACKET_TIME_FORMAT == CFE_MISSION_SB_TIME_32_32_M_20)
    uint32 LocalSubs32;
    #endif

    /* cannot set time if msg type is a command or msg has no secondary hdr */
    if ((CCSDS_RD_TYPE(MsgPtr->Hdr) != CCSDS_CMD) && (CCSDS_RD_SHDR(MsgPtr->Hdr) != 0)) {

        /* copy time data to/from packets to eliminate alignment issues */
        TlmHdrPtr = (CFE_SB_TlmHdr_t *) MsgPtr;

        #if (CFE_MISSION_SB_PACKET_TIME_FORMAT == CFE_MISSION_SB_TIME_32_16_SUBS)

        /* convert time from CFE_TIME_SysTime_t format to packet format */
        LocalSubs16 = (uint16) (NewTime.Subseconds >> 16);
        memcpy(&TlmHdrPtr->Sec.Time[0], &NewTime.Seconds, 4);
        memcpy(&TlmHdrPtr->Sec.Time[4], &LocalSubs16, 2);
        Result = CFE_SUCCESS;

        #elif (CFE_MISSION_SB_PACKET_TIME_FORMAT == CFE_MISSION_SB_TIME_32_32_SUBS)

        /* no conversion necessary -- packet format = CFE_TIME_SysTime_t format */
        memcpy(&TlmHdrPtr->Sec.Time[0], &NewTime.Seconds, 4);
        memcpy(&TlmHdrPtr->Sec.Time[4], &NewTime.Subseconds, 4);
        Result = CFE_SUCCESS;

        #elif (CFE_MISSION_SB_PACKET_TIME_FORMAT == CFE_MISSION_SB_TIME_32_32_M_20)

        /* convert time from CFE_TIME_SysTime_t format to packet format */
        LocalSubs32 = CFE_TIME_Sub2MicroSecs(NewTime.Subseconds) << 12;
        memcpy(&TlmHdrPtr->Sec.Time[0], &NewTime.Seconds, 4);
        memcpy(&TlmHdrPtr->Sec.Time[4], &LocalSubs32, 4);
        Result = CFE_SUCCESS;

        #endif
    }

    return Result;

}/* end CFE_SB_SetMsgTime */

/******************************************************************************
**  Function:  CFE_SB_GetCmdCode()
**
**  Purpose:
**    Get the opcode field of message.
**
**  Arguments:
**    MsgPtr - Pointer to a CFE_SB_Msg_t
**
**  Return:
**    CmdCode from the message (CCSDS Function Code)
*/
uint16 CFE_SB_GetCmdCode(CFE_SB_MsgPtr_t MsgPtr)
{
#ifdef MESSAGE_FORMAT_IS_CCSDS

    CFE_SB_CmdHdr_t     *CmdHdrPtr;

    /* if msg type is telemetry or there is no secondary hdr, return 0 */
    if((CCSDS_RD_TYPE(MsgPtr->Hdr) == CCSDS_TLM)||(CCSDS_RD_SHDR(MsgPtr->Hdr) == 0)){
        return 0;
    }/* end if */

    /* Cast the input pointer to a Cmd Msg pointer */
    CmdHdrPtr = (CFE_SB_CmdHdr_t *)MsgPtr;

    return CCSDS_RD_FC(CmdHdrPtr->Sec);

#endif
}/* end CFE_SB_GetCmdCode */

/******************************************************************************
**  Function:  CFE_SB_SetCmdCode()
**
**  Purpose:
**    Set the opcode field of message.
**
**  Arguments:
**    MsgPtr - Pointer to a CFE_SB_Msg_t
**    CmdCode - Command code for the message (CCSDS Function Code)
**
**  Return:
**    (none)
*/
int32 CFE_SB_SetCmdCode(CFE_SB_MsgPtr_t MsgPtr,
                      uint16 CmdCode)
{
#ifdef MESSAGE_FORMAT_IS_CCSDS

    CFE_SB_CmdHdr_t     *CmdHdrPtr;

    /* if msg type is telemetry or there is no secondary hdr... */
    if((CCSDS_RD_TYPE(MsgPtr->Hdr) == CCSDS_TLM)||(CCSDS_RD_SHDR(MsgPtr->Hdr) == 0)){
        return CFE_SB_WRONG_MSG_TYPE;
    }/* end if */

    /* Cast the input pointer to a Cmd Msg pointer */
    CmdHdrPtr = (CFE_SB_CmdHdr_t *)MsgPtr;

    CCSDS_WR_FC(CmdHdrPtr->Sec,CmdCode);

    return CFE_SUCCESS;

#endif

}/* end CFE_SB_SetCmdCode */

/******************************************************************************
**  Function:  CFE_SB_MsgHdrSize()
**
**  Purpose:
**    Get the size of a message header.
**
**  Arguments:
**    MsgPtr - Pointer to a SB message 
**
**  Return:
**     Size of Message Header.
*/
static uint16 CFE_SB_MsgHdrSize(CFE_SB_MsgPtr_t MsgPtr)
{
    uint16 size;

#ifdef MESSAGE_FORMAT_IS_CCSDS

    CCSDS_PriHdr_t  *HdrPtr;

    HdrPtr = (CCSDS_PriHdr_t *) MsgPtr;

    /* if secondary hdr is not present... */
    /* Since all cFE messages must have a secondary hdr this check is not needed */
    if(CCSDS_RD_SHDR(*HdrPtr) == 0){
        size = sizeof(CCSDS_PriHdr_t);

    }else if(CCSDS_RD_TYPE(*HdrPtr) == CCSDS_CMD){

        size = CFE_SB_CMD_HDR_SIZE;

    }else{

        size = CFE_SB_TLM_HDR_SIZE;
  
    }

   return size;

#endif

}/* end CFE_SB_MsgHdrSize */

/******************************************************************************
**  Function:  CFE_SB_GetUserData()
**
**  Purpose:
**    Get a pointer to the user data portion of a message.
**
**  Arguments:
**    MsgPtr - Pointer to a CFE_SB_Msg_t
**
**  Return:
**    Pointer to the first byte after the headers
*/
void *CFE_SB_GetUserData(CFE_SB_MsgPtr_t MsgPtr)
{
#ifdef MESSAGE_FORMAT_IS_CCSDS
    uint8           *BytePtr;
    uint16          HdrSize;

    BytePtr = (uint8 *)MsgPtr;
    HdrSize = CFE_SB_MsgHdrSize(MsgPtr);

    return (BytePtr + HdrSize);
#endif
}/* end CFE_SB_GetUserData */

/******************************************************************************
**  Function:  CFE_SB_GetUserDataLength()
**
**  Purpose:
**    Get the length of the user data of a message (total size - hdrs).
**
** Assumptions, External Events, and Notes:
**    Caller has already initialized the message header
**
**  Arguments:
**    MsgPtr - Pointer to a CFE_SB_Msg_t
**
**  Return:
**    Size of the message minus the headers
*/
uint16 CFE_SB_GetUserDataLength(CFE_SB_MsgPtr_t MsgPtr)
{
#ifdef MESSAGE_FORMAT_IS_CCSDS
    uint16 TotalMsgSize;
    uint16 HdrSize;

    TotalMsgSize = CFE_SB_GetTotalMsgLength(MsgPtr);
    HdrSize = CFE_SB_MsgHdrSize(MsgPtr);

    return (TotalMsgSize - HdrSize);
#endif
}/* end CFE_SB_GetUserDataLength */

/******************************************************************************
**  Function:  CFE_SB_SetUserDataLength()
**
**  Purpose:
**    Set the length field in the primary header.
**    Given the user data length add the length of the secondary header.
**
** Assumptions, External Events, and Notes:
**    Caller has already initialized the message header
**
**  Arguments:
**    MsgPtr     - Pointer to a CFE_SB_Msg_t
**    DataLength - Length of the user data
**
**  Return:
**    (none)
*/
void CFE_SB_SetUserDataLength(CFE_SB_MsgPtr_t MsgPtr, uint16 DataLength)
{
#ifdef MESSAGE_FORMAT_IS_CCSDS

    uint32 TotalMsgSize, HdrSize;

    HdrSize = CFE_SB_MsgHdrSize(MsgPtr);
    TotalMsgSize = HdrSize + DataLength;
    CCSDS_WR_LEN(MsgPtr->Hdr,TotalMsgSize);

#endif
}/* end CFE_SB_SetUserDataLength */

/******************************************************************************
**  Function:  CFE_SB_GetTotalMsgLength()
**
**  Purpose:
**    Get the total length of the message which includes the secondary header
**    and the user data field.
**    Does not include the Primary header.
**
**  Arguments:
**    MsgPtr - Pointer to a CFE_SB_Msg_t
**
**  Return:
**    Total Length of the message
*/
uint16 CFE_SB_GetTotalMsgLength(CFE_SB_MsgPtr_t MsgPtr)
{
#ifdef MESSAGE_FORMAT_IS_CCSDS

    return CCSDS_RD_LEN(MsgPtr->Hdr);

#endif
}/* end CFE_SB_GetTotalMsgLength */

/******************************************************************************
**  Function:  CFE_SB_SetTotalMsgLength()
**
**  Purpose:
**    Set the length field, given the total length of the message.
**    Includes both the secondary header and the user data field.
**    Does not include the Primary header.
**
**  Arguments:
**    MsgPtr      - Pointer to a CFE_SB_Msg_t
**    TotalLength - Total Length of the message
**
**  Return:
**    (none)
*/
void CFE_SB_SetTotalMsgLength(CFE_SB_MsgPtr_t MsgPtr,uint16 TotalLength)
{
#ifdef MESSAGE_FORMAT_IS_CCSDS

    CCSDS_WR_LEN(MsgPtr->Hdr,TotalLength);

#endif
}/* end CFE_SB_SetTotalMsgLength */

/******************************************************************************
**  Function:  CFE_SB_TimeStampMsg()
**
**  Purpose:
**    Set the time field to the current time.
**
**  Arguments:
**    MsgPtr - Pointer to a CFE_SB_Msg_t
**
**  Return:
**    (none)
*/
void CFE_SB_TimeStampMsg(CFE_SB_MsgPtr_t MsgPtr, CFE_TIME_SysTime_t Time)
{
    CFE_SB_SetMsgTime(MsgPtr,Time);

}/* end CFE_SB_TimeStampMsg */

/******************************************************************************
**  Function:  CFE_SB_GetChecksum()
**
**  Purpose:
**    Get the checksum field of message.
**
**  Arguments:
**    MsgPtr - Pointer to a CFE_SB_Msg_t
**
**  Return:
**
*/
uint16 CFE_SB_GetChecksum(CFE_SB_MsgPtr_t MsgPtr)
{
#ifdef MESSAGE_FORMAT_IS_CCSDS

    CFE_SB_CmdHdr_t     *CmdHdrPtr;

    /* if msg type is telemetry or there is no secondary hdr... */
    if((CCSDS_RD_TYPE(MsgPtr->Hdr) == CCSDS_TLM)||(CCSDS_RD_SHDR(MsgPtr->Hdr) == 0)){
        return 0;
    }/* end if */

    /* cast the input pointer to a Cmd Msg pointer */
    CmdHdrPtr = (CFE_SB_CmdHdr_t *)MsgPtr;

    return CCSDS_RD_CHECKSUM(CmdHdrPtr->Sec);

#endif
}/* end CFE_SB_GetChecksum */

/******************************************************************************
**  Function:  CCSDS_ComputeCheckSum()
**
**  Purpose:
**    Compute the checksum for a command packet.  The checksum is the XOR of
**    all bytes in the packet; a valid checksum is zero.
**
**  Arguments:
**    PktPtr   : Pointer to header of command packet.  The packet must
**               have a secondary header and the length in the primary
**               header must be correct.
**
**  Return:
**    TRUE if checksum of packet is valid; FALSE if not.
*/

uint8 CCSDS_ComputeCheckSum (CCSDS_CommandPacket_t *PktPtr)
{
   uint16   PktLen   = CCSDS_RD_LEN(PktPtr->SpacePacket.Hdr);
   uint8   *BytePtr  = (uint8 *)PktPtr;
   uint8    CheckSum;

   CheckSum = 0xFF;
   while (PktLen--)  CheckSum ^= *(BytePtr++);

   return CheckSum;

} /* END CCSDS_ComputeCheckSum() */

/******************************************************************************
**  Function:  CCSDS_LoadCheckSum()
**
**  Purpose:
**    Compute and load a checksum for a CCSDS command packet that has a
**    secondary header.
**
**  Arguments:
**    PktPtr   : Pointer to header of command packet.  The packet must
**               have a secondary header and the length in the primary
**               header must be correct.  The checksum field in the packet
**               will be modified.
**
**  Return:
**    (none)
*/

void CCSDS_LoadCheckSum (CCSDS_CommandPacket_t *PktPtr)
{
   uint8    CheckSum;

   /* Clear the checksum field so the new checksum is correct. */
   CCSDS_WR_CHECKSUM(PktPtr->Sec, 0);

   /* Compute and load new checksum. */
   CheckSum = CCSDS_ComputeCheckSum(PktPtr);
   CCSDS_WR_CHECKSUM(PktPtr->Sec, CheckSum);

} /* END CCSDS_LoadCheckSum() */

/******************************************************************************
**  Function:  CCSDS_ValidCheckSum()
**
**  Purpose:
**    Determine whether a checksum in a command packet is valid.
**
**  Arguments:
**    PktPtr   : Pointer to header of command packet.  The packet must
**               have a secondary header and the length in the primary
**               header must be correct.
**
**  Return:
**    TRUE if checksum of packet is valid; FALSE if not.
**    A valid checksum is 0.
*/

boolean CCSDS_ValidCheckSum (CCSDS_CommandPacket_t *PktPtr)
{

   return (CCSDS_ComputeCheckSum(PktPtr) == 0);

} /* END CCSDS_ValidCheckSum() */


/******************************************************************************
**  Function:  CFE_SB_GenerateChecksum()
**
**  Purpose:
**    Calculate and Set the checksum field of message.
**
**  Arguments:
**    MsgPtr - Pointer to a CFE_SB_Msg_t
**
**  Note: If any header fields are changed after this call, the checksum will
**        no longer be valid.
**        Also, the packet length field dictates the number of iterations
**        used in the checksum algorithm and therefore must be properly set
**        before calling this function.
**
**  Return:
**    (none)
*/
void CFE_SB_GenerateChecksum(CFE_SB_MsgPtr_t MsgPtr)
{
#ifdef MESSAGE_FORMAT_IS_CCSDS

    CCSDS_CommandPacket_t    *CmdPktPtr;

    /* if msg type is telemetry or there is no secondary hdr... */
    if((CCSDS_RD_TYPE(MsgPtr->Hdr) == CCSDS_TLM)||(CCSDS_RD_SHDR(MsgPtr->Hdr) == 0)){
        return;
    }/* end if */

    CmdPktPtr = (CCSDS_CommandPacket_t *)MsgPtr;

    CCSDS_LoadCheckSum(CmdPktPtr);

#endif
}/* end CFE_SB_GenerateChecksum */

/******************************************************************************
**  Function:  CFE_SB_ValidateChecksum()
**
**  Purpose:
**    Validate the checksum field of message.
**
**  Arguments:
**    MsgPtr - Pointer to a CFE_SB_Msg_t
**
**  Return:
**    TRUE if checksum of packet is valid; FALSE if not.
*/
boolean CFE_SB_ValidateChecksum(CFE_SB_MsgPtr_t MsgPtr)
{
#ifdef MESSAGE_FORMAT_IS_CCSDS

    CCSDS_CommandPacket_t    *CmdPktPtr;

    /* if msg type is telemetry or there is no secondary hdr... */
    if((CCSDS_RD_TYPE(MsgPtr->Hdr) == CCSDS_TLM)||(CCSDS_RD_SHDR(MsgPtr->Hdr) == 0)){
        return FALSE;
    }/* end if */

    CmdPktPtr = (CCSDS_CommandPacket_t *)MsgPtr;

    return CCSDS_ValidCheckSum (CmdPktPtr);

#endif
}/* end CFE_SB_ValidateChecksum */





