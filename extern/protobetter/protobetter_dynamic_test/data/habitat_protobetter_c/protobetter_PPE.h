#ifndef __PROTOBETTER_PPE_H__
#define __PROTOBETTER_PPE_H__

#ifdef __cplusplus
extern "C"
{
#endif
#include <stdint.h>
#include "protobetter_core.h"

#include "PPE_types.h"


#define STRUCT_PPE_MBSU1_PACKED_SIZE 184

uint32_t PackPPE_MBSU1(void *buffer, void *protobetter_type);


uint32_t UnpackPPE_MBSU1(void *protobetter_type, void *buffer);


#include "PPE_types.h"


#define STRUCT_PPE_MBSU2_PACKED_SIZE 184

uint32_t PackPPE_MBSU2(void *buffer, void *protobetter_type);


uint32_t UnpackPPE_MBSU2(void *protobetter_type, void *buffer);


#include "PPE_types.h"


#define STRUCT_PPE_NAV_STATE_TLM_PACKED_SIZE 96

uint32_t PackPPE_NAV_STATE_TLM(void *buffer, void *protobetter_type);


uint32_t UnpackPPE_NAV_STATE_TLM(void *protobetter_type, void *buffer);


#include "PPE_types.h"


#define STRUCT_PPE_PDU1_PACKED_SIZE 152

uint32_t PackPPE_PDU1(void *buffer, void *protobetter_type);


uint32_t UnpackPPE_PDU1(void *protobetter_type, void *buffer);


#include "PPE_types.h"


#define STRUCT_PPE_PDU2_PACKED_SIZE 152

uint32_t PackPPE_PDU2(void *buffer, void *protobetter_type);


uint32_t UnpackPPE_PDU2(void *protobetter_type, void *buffer);


#include "PPE_types.h"


#define STRUCT_PPE_POWER_SOURCE1_PACKED_SIZE 77

uint32_t PackPPE_Power_Source1(void *buffer, void *protobetter_type);


uint32_t UnpackPPE_Power_Source1(void *protobetter_type, void *buffer);


#include "PPE_types.h"


#define STRUCT_PPE_POWER_SOURCE2_PACKED_SIZE 77

uint32_t PackPPE_Power_Source2(void *buffer, void *protobetter_type);


uint32_t UnpackPPE_Power_Source2(void *protobetter_type, void *buffer);


#include "PPE_types.h"


#define STRUCT_SET_PPE_MBSU1_INPUT_SOURCE_SELECT_T_PACKED_SIZE 14

uint32_t PackSET_PPE_MBSU1_INPUT_SOURCE_SELECT_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_PPE_MBSU1_INPUT_SOURCE_SELECT_t(void *protobetter_type, void *buffer);


#include "PPE_types.h"


#define STRUCT_SET_PPE_MBSU1_OUTPUT_CHANNEL_STATE_T_PACKED_SIZE 14

uint32_t PackSET_PPE_MBSU1_OUTPUT_CHANNEL_STATE_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_PPE_MBSU1_OUTPUT_CHANNEL_STATE_t(void *protobetter_type, void *buffer);


#include "PPE_types.h"


#define STRUCT_SET_PPE_MBSU1_INPUT_CURR_LIMIT_T_PACKED_SIZE 21

uint32_t PackSET_PPE_MBSU1_Input_Curr_Limit_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_PPE_MBSU1_Input_Curr_Limit_t(void *protobetter_type, void *buffer);


#include "PPE_types.h"


#define STRUCT_SET_PPE_MBSU1_OUTPUT_CURR_LIMIT_T_PACKED_SIZE 21

uint32_t PackSET_PPE_MBSU1_Output_Curr_Limit_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_PPE_MBSU1_Output_Curr_Limit_t(void *protobetter_type, void *buffer);


#include "PPE_types.h"


#define STRUCT_CLEAR_PPE_MBSU1_INPUT_CURR_TRIP_T_PACKED_SIZE 13

uint32_t PackCLEAR_PPE_MBSU1_Input_Curr_Trip_t(void *buffer, void *protobetter_type);


uint32_t UnpackCLEAR_PPE_MBSU1_Input_Curr_Trip_t(void *protobetter_type, void *buffer);


#include "PPE_types.h"


#define STRUCT_CLEAR_PPE_MBSU1_OUTPUT_CURR_TRIP_T_PACKED_SIZE 13

uint32_t PackCLEAR_PPE_MBSU1_Output_Curr_Trip_t(void *buffer, void *protobetter_type);


uint32_t UnpackCLEAR_PPE_MBSU1_Output_Curr_Trip_t(void *protobetter_type, void *buffer);


#include "PPE_types.h"


#define STRUCT_SET_PPE_MBSU1_RELAY_CHANNEL_OPEN_T_PACKED_SIZE 14

uint32_t PackSET_PPE_MBSU1_Relay_CHANNEL_OPEN_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_PPE_MBSU1_Relay_CHANNEL_OPEN_t(void *protobetter_type, void *buffer);


#include "PPE_types.h"


#define STRUCT_PPE_MBSU1_FAIL_INPUT_SOURCE_T_PACKED_SIZE 14

uint32_t PackPPE_MBSU1_FAIL_INPUT_SOURCE_t(void *buffer, void *protobetter_type);


uint32_t UnpackPPE_MBSU1_FAIL_INPUT_SOURCE_t(void *protobetter_type, void *buffer);


#include "PPE_types.h"


#define STRUCT_PPE_MBSU1_CMD_PACKED_SIZE 21

uint32_t PackPPE_MBSU1_CMD(void *buffer, void *protobetter_type);


uint32_t UnpackPPE_MBSU1_CMD(void *protobetter_type, void *buffer);


#include "PPE_types.h"


#define STRUCT_SET_PPE_MBSU2_INPUT_SOURCE_SELECT_T_PACKED_SIZE 14

uint32_t PackSET_PPE_MBSU2_INPUT_SOURCE_SELECT_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_PPE_MBSU2_INPUT_SOURCE_SELECT_t(void *protobetter_type, void *buffer);


#include "PPE_types.h"


#define STRUCT_SET_PPE_MBSU2_OUTPUT_CHANNEL_STATE_T_PACKED_SIZE 14

uint32_t PackSET_PPE_MBSU2_OUTPUT_CHANNEL_STATE_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_PPE_MBSU2_OUTPUT_CHANNEL_STATE_t(void *protobetter_type, void *buffer);


#include "PPE_types.h"


#define STRUCT_SET_PPE_MBSU2_INPUT_CURR_LIMIT_T_PACKED_SIZE 21

uint32_t PackSET_PPE_MBSU2_Input_Curr_Limit_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_PPE_MBSU2_Input_Curr_Limit_t(void *protobetter_type, void *buffer);


#include "PPE_types.h"


#define STRUCT_SET_PPE_MBSU2_OUTPUT_CURR_LIMIT_T_PACKED_SIZE 21

uint32_t PackSET_PPE_MBSU2_Output_Curr_Limit_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_PPE_MBSU2_Output_Curr_Limit_t(void *protobetter_type, void *buffer);


#include "PPE_types.h"


#define STRUCT_CLEAR_PPE_MBSU2_INPUT_CURR_TRIP_T_PACKED_SIZE 13

uint32_t PackCLEAR_PPE_MBSU2_Input_Curr_Trip_t(void *buffer, void *protobetter_type);


uint32_t UnpackCLEAR_PPE_MBSU2_Input_Curr_Trip_t(void *protobetter_type, void *buffer);


#include "PPE_types.h"


#define STRUCT_CLEAR_PPE_MBSU2_OUTPUT_CURR_TRIP_T_PACKED_SIZE 13

uint32_t PackCLEAR_PPE_MBSU2_Output_Curr_Trip_t(void *buffer, void *protobetter_type);


uint32_t UnpackCLEAR_PPE_MBSU2_Output_Curr_Trip_t(void *protobetter_type, void *buffer);


#include "PPE_types.h"


#define STRUCT_SET_PPE_MBSU2_RELAY_CHANNEL_OPEN_T_PACKED_SIZE 14

uint32_t PackSET_PPE_MBSU2_Relay_CHANNEL_OPEN_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_PPE_MBSU2_Relay_CHANNEL_OPEN_t(void *protobetter_type, void *buffer);


#include "PPE_types.h"


#define STRUCT_PPE_MBSU2_FAIL_INPUT_SOURCE_T_PACKED_SIZE 14

uint32_t PackPPE_MBSU2_FAIL_INPUT_SOURCE_t(void *buffer, void *protobetter_type);


uint32_t UnpackPPE_MBSU2_FAIL_INPUT_SOURCE_t(void *protobetter_type, void *buffer);


#include "PPE_types.h"


#define STRUCT_PPE_MBSU2_CMD_PACKED_SIZE 21

uint32_t PackPPE_MBSU2_CMD(void *buffer, void *protobetter_type);


uint32_t UnpackPPE_MBSU2_CMD(void *protobetter_type, void *buffer);


#include "PPE_types.h"


#define STRUCT_SET_PPE_PDU1_INPUT_BUS_SELECT_T_PACKED_SIZE 13

uint32_t PackSET_PPE_PDU1_INPUT_BUS_SELECT_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_PPE_PDU1_INPUT_BUS_SELECT_t(void *protobetter_type, void *buffer);


#include "PPE_types.h"


#define STRUCT_SET_PPE_PDU1_RPC_CHANNEL_STATE_T_PACKED_SIZE 14

uint32_t PackSET_PPE_PDU1_RPC_CHANNEL_STATE_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_PPE_PDU1_RPC_CHANNEL_STATE_t(void *protobetter_type, void *buffer);


#include "PPE_types.h"


#define STRUCT_SET_PPE_PDU1_RPC_CHANNEL_OPEN_T_PACKED_SIZE 14

uint32_t PackSET_PPE_PDU1_RPC_CHANNEL_OPEN_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_PPE_PDU1_RPC_CHANNEL_OPEN_t(void *protobetter_type, void *buffer);


#include "PPE_types.h"


#define STRUCT_PPE_PDU1_CMD_PACKED_SIZE 14

uint32_t PackPPE_PDU1_CMD(void *buffer, void *protobetter_type);


uint32_t UnpackPPE_PDU1_CMD(void *protobetter_type, void *buffer);


#include "PPE_types.h"


#define STRUCT_SET_PPE_PDU2_INPUT_BUS_SELECT_T_PACKED_SIZE 13

uint32_t PackSET_PPE_PDU2_INPUT_BUS_SELECT_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_PPE_PDU2_INPUT_BUS_SELECT_t(void *protobetter_type, void *buffer);


#include "PPE_types.h"


#define STRUCT_SET_PPE_PDU2_RPC_CHANNEL_STATE_T_PACKED_SIZE 14

uint32_t PackSET_PPE_PDU2_RPC_CHANNEL_STATE_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_PPE_PDU2_RPC_CHANNEL_STATE_t(void *protobetter_type, void *buffer);


#include "PPE_types.h"


#define STRUCT_SET_PPE_PDU2_RPC_CHANNEL_OPEN_T_PACKED_SIZE 14

uint32_t PackSET_PPE_PDU2_RPC_CHANNEL_OPEN_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_PPE_PDU2_RPC_CHANNEL_OPEN_t(void *protobetter_type, void *buffer);


#include "PPE_types.h"


#define STRUCT_PPE_PDU2_CMD_PACKED_SIZE 14

uint32_t PackPPE_PDU2_CMD(void *buffer, void *protobetter_type);


uint32_t UnpackPPE_PDU2_CMD(void *protobetter_type, void *buffer);


#include "PPE_types.h"


#define STRUCT_SET_PPE_PS1_OUTPUT_CHANNEL_STATE_T_PACKED_SIZE 14

uint32_t PackSET_PPE_PS1_OUTPUT_CHANNEL_STATE_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_PPE_PS1_OUTPUT_CHANNEL_STATE_t(void *protobetter_type, void *buffer);


#include "PPE_types.h"


#define STRUCT_SET_PPE_PS1_SAR_STATE_T_PACKED_SIZE 13

uint32_t PackSET_PPE_PS1_SAR_STATE_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_PPE_PS1_SAR_STATE_t(void *protobetter_type, void *buffer);


#include "PPE_types.h"


#define STRUCT_PPE_POWER_SOURCE1_CMD_PACKED_SIZE 14

uint32_t PackPPE_Power_Source1_CMD(void *buffer, void *protobetter_type);


uint32_t UnpackPPE_Power_Source1_CMD(void *protobetter_type, void *buffer);


#include "PPE_types.h"


#define STRUCT_SET_PPE_PS2_OUTPUT_CHANNEL_STATE_T_PACKED_SIZE 14

uint32_t PackSET_PPE_PS2_OUTPUT_CHANNEL_STATE_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_PPE_PS2_OUTPUT_CHANNEL_STATE_t(void *protobetter_type, void *buffer);


#include "PPE_types.h"


#define STRUCT_SET_PPE_PS2_SAR_STATE_T_PACKED_SIZE 13

uint32_t PackSET_PPE_PS2_SAR_STATE_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_PPE_PS2_SAR_STATE_t(void *protobetter_type, void *buffer);


#include "PPE_types.h"


#define STRUCT_PPE_POWER_SOURCE2_CMD_PACKED_SIZE 14

uint32_t PackPPE_Power_Source2_CMD(void *buffer, void *protobetter_type);


uint32_t UnpackPPE_Power_Source2_CMD(void *protobetter_type, void *buffer);


#ifdef __cplusplus
}
#endif
#endif //__PROTOBETTER_PPE_H__

