#ifndef __PROTOBETTER_HAL_H__
#define __PROTOBETTER_HAL_H__

#ifdef __cplusplus
extern "C"
{
#endif
#include <stdint.h>
#include "protobetter_core.h"

#include "HAL_types.h"


#define STRUCT_HAL_MBSU1_PACKED_SIZE 184

uint32_t PackHAL_MBSU1(void *buffer, void *protobetter_type);


uint32_t UnpackHAL_MBSU1(void *protobetter_type, void *buffer);


#include "HAL_types.h"


#define STRUCT_HAL_MBSU2_PACKED_SIZE 184

uint32_t PackHAL_MBSU2(void *buffer, void *protobetter_type);


uint32_t UnpackHAL_MBSU2(void *protobetter_type, void *buffer);


#include "HAL_types.h"


#define STRUCT_HAL_PDU1_PACKED_SIZE 152

uint32_t PackHAL_PDU1(void *buffer, void *protobetter_type);


uint32_t UnpackHAL_PDU1(void *protobetter_type, void *buffer);


#include "HAL_types.h"


#define STRUCT_HAL_PDU2_PACKED_SIZE 152

uint32_t PackHAL_PDU2(void *buffer, void *protobetter_type);


uint32_t UnpackHAL_PDU2(void *protobetter_type, void *buffer);


#include "HAL_types.h"


#define STRUCT_HAL_PDU3_PACKED_SIZE 152

uint32_t PackHAL_PDU3(void *buffer, void *protobetter_type);


uint32_t UnpackHAL_PDU3(void *protobetter_type, void *buffer);


#include "HAL_types.h"


#define STRUCT_HAL_PDU4_PACKED_SIZE 152

uint32_t PackHAL_PDU4(void *buffer, void *protobetter_type);


uint32_t UnpackHAL_PDU4(void *protobetter_type, void *buffer);


#include "HAL_types.h"


#define STRUCT_HAL_POWER_SOURCE1_PACKED_SIZE 77

uint32_t PackHAL_Power_Source1(void *buffer, void *protobetter_type);


uint32_t UnpackHAL_Power_Source1(void *protobetter_type, void *buffer);


#include "HAL_types.h"


#define STRUCT_HAL_POWER_SOURCE2_PACKED_SIZE 77

uint32_t PackHAL_Power_Source2(void *buffer, void *protobetter_type);


uint32_t UnpackHAL_Power_Source2(void *protobetter_type, void *buffer);


#include "HAL_types.h"


#define STRUCT_SET_HAL_MBSU1_INPUT_SOURCE_SELECT_T_PACKED_SIZE 14

uint32_t PackSET_HAL_MBSU1_INPUT_SOURCE_SELECT_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_HAL_MBSU1_INPUT_SOURCE_SELECT_t(void *protobetter_type, void *buffer);


#include "HAL_types.h"


#define STRUCT_SET_HAL_MBSU1_OUTPUT_CHANNEL_STATE_T_PACKED_SIZE 14

uint32_t PackSET_HAL_MBSU1_OUTPUT_CHANNEL_STATE_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_HAL_MBSU1_OUTPUT_CHANNEL_STATE_t(void *protobetter_type, void *buffer);


#include "HAL_types.h"


#define STRUCT_SET_HAL_MBSU1_INPUT_CURR_LIMIT_T_PACKED_SIZE 21

uint32_t PackSET_HAL_MBSU1_Input_Curr_Limit_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_HAL_MBSU1_Input_Curr_Limit_t(void *protobetter_type, void *buffer);


#include "HAL_types.h"


#define STRUCT_SET_HAL_MBSU1_OUTPUT_CURR_LIMIT_T_PACKED_SIZE 21

uint32_t PackSET_HAL_MBSU1_Output_Curr_Limit_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_HAL_MBSU1_Output_Curr_Limit_t(void *protobetter_type, void *buffer);


#include "HAL_types.h"


#define STRUCT_CLEAR_HAL_MBSU1_INPUT_CURR_TRIP_T_PACKED_SIZE 13

uint32_t PackCLEAR_HAL_MBSU1_Input_Curr_Trip_t(void *buffer, void *protobetter_type);


uint32_t UnpackCLEAR_HAL_MBSU1_Input_Curr_Trip_t(void *protobetter_type, void *buffer);


#include "HAL_types.h"


#define STRUCT_CLEAR_HAL_MBSU1_OUTPUT_CURR_TRIP_T_PACKED_SIZE 13

uint32_t PackCLEAR_HAL_MBSU1_Output_Curr_Trip_t(void *buffer, void *protobetter_type);


uint32_t UnpackCLEAR_HAL_MBSU1_Output_Curr_Trip_t(void *protobetter_type, void *buffer);


#include "HAL_types.h"


#define STRUCT_SET_HAL_MBSU1_RELAY_CHANNEL_OPEN_T_PACKED_SIZE 14

uint32_t PackSET_HAL_MBSU1_Relay_CHANNEL_OPEN_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_HAL_MBSU1_Relay_CHANNEL_OPEN_t(void *protobetter_type, void *buffer);


#include "HAL_types.h"


#define STRUCT_HAL_MBSU1_FAIL_INPUT_SOURCE_T_PACKED_SIZE 14

uint32_t PackHAL_MBSU1_FAIL_INPUT_SOURCE_t(void *buffer, void *protobetter_type);


uint32_t UnpackHAL_MBSU1_FAIL_INPUT_SOURCE_t(void *protobetter_type, void *buffer);


#include "HAL_types.h"


#define STRUCT_HAL_MBSU1_CMD_PACKED_SIZE 21

uint32_t PackHAL_MBSU1_CMD(void *buffer, void *protobetter_type);


uint32_t UnpackHAL_MBSU1_CMD(void *protobetter_type, void *buffer);


#include "HAL_types.h"


#define STRUCT_SET_HAL_MBSU2_INPUT_SOURCE_SELECT_T_PACKED_SIZE 14

uint32_t PackSET_HAL_MBSU2_INPUT_SOURCE_SELECT_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_HAL_MBSU2_INPUT_SOURCE_SELECT_t(void *protobetter_type, void *buffer);


#include "HAL_types.h"


#define STRUCT_SET_HAL_MBSU2_OUTPUT_CHANNEL_STATE_T_PACKED_SIZE 14

uint32_t PackSET_HAL_MBSU2_OUTPUT_CHANNEL_STATE_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_HAL_MBSU2_OUTPUT_CHANNEL_STATE_t(void *protobetter_type, void *buffer);


#include "HAL_types.h"


#define STRUCT_SET_HAL_MBSU2_INPUT_CURR_LIMIT_T_PACKED_SIZE 21

uint32_t PackSET_HAL_MBSU2_Input_Curr_Limit_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_HAL_MBSU2_Input_Curr_Limit_t(void *protobetter_type, void *buffer);


#include "HAL_types.h"


#define STRUCT_SET_HAL_MBSU2_OUTPUT_CURR_LIMIT_T_PACKED_SIZE 21

uint32_t PackSET_HAL_MBSU2_Output_Curr_Limit_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_HAL_MBSU2_Output_Curr_Limit_t(void *protobetter_type, void *buffer);


#include "HAL_types.h"


#define STRUCT_CLEAR_HAL_MBSU2_INPUT_CURR_TRIP_T_PACKED_SIZE 13

uint32_t PackCLEAR_HAL_MBSU2_Input_Curr_Trip_t(void *buffer, void *protobetter_type);


uint32_t UnpackCLEAR_HAL_MBSU2_Input_Curr_Trip_t(void *protobetter_type, void *buffer);


#include "HAL_types.h"


#define STRUCT_CLEAR_HAL_MBSU2_OUTPUT_CURR_TRIP_T_PACKED_SIZE 13

uint32_t PackCLEAR_HAL_MBSU2_Output_Curr_Trip_t(void *buffer, void *protobetter_type);


uint32_t UnpackCLEAR_HAL_MBSU2_Output_Curr_Trip_t(void *protobetter_type, void *buffer);


#include "HAL_types.h"


#define STRUCT_SET_HAL_MBSU2_RELAY_CHANNEL_OPEN_T_PACKED_SIZE 14

uint32_t PackSET_HAL_MBSU2_Relay_CHANNEL_OPEN_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_HAL_MBSU2_Relay_CHANNEL_OPEN_t(void *protobetter_type, void *buffer);


#include "HAL_types.h"


#define STRUCT_HAL_MBSU2_FAIL_INPUT_SOURCE_T_PACKED_SIZE 14

uint32_t PackHAL_MBSU2_FAIL_INPUT_SOURCE_t(void *buffer, void *protobetter_type);


uint32_t UnpackHAL_MBSU2_FAIL_INPUT_SOURCE_t(void *protobetter_type, void *buffer);


#include "HAL_types.h"


#define STRUCT_HAL_MBSU2_CMD_PACKED_SIZE 21

uint32_t PackHAL_MBSU2_CMD(void *buffer, void *protobetter_type);


uint32_t UnpackHAL_MBSU2_CMD(void *protobetter_type, void *buffer);


#include "HAL_types.h"


#define STRUCT_SET_HAL_PDU1_INPUT_BUS_SELECT_T_PACKED_SIZE 13

uint32_t PackSET_HAL_PDU1_INPUT_BUS_SELECT_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_HAL_PDU1_INPUT_BUS_SELECT_t(void *protobetter_type, void *buffer);


#include "HAL_types.h"


#define STRUCT_SET_HAL_PDU1_RPC_CHANNEL_STATE_T_PACKED_SIZE 14

uint32_t PackSET_HAL_PDU1_RPC_CHANNEL_STATE_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_HAL_PDU1_RPC_CHANNEL_STATE_t(void *protobetter_type, void *buffer);


#include "HAL_types.h"


#define STRUCT_SET_HAL_PDU1_RPC_CHANNEL_OPEN_T_PACKED_SIZE 14

uint32_t PackSET_HAL_PDU1_RPC_CHANNEL_OPEN_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_HAL_PDU1_RPC_CHANNEL_OPEN_t(void *protobetter_type, void *buffer);


#include "HAL_types.h"


#define STRUCT_HAL_PDU1_CMD_PACKED_SIZE 14

uint32_t PackHAL_PDU1_CMD(void *buffer, void *protobetter_type);


uint32_t UnpackHAL_PDU1_CMD(void *protobetter_type, void *buffer);


#include "HAL_types.h"


#define STRUCT_SET_HAL_PDU2_INPUT_BUS_SELECT_T_PACKED_SIZE 13

uint32_t PackSET_HAL_PDU2_INPUT_BUS_SELECT_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_HAL_PDU2_INPUT_BUS_SELECT_t(void *protobetter_type, void *buffer);


#include "HAL_types.h"


#define STRUCT_SET_HAL_PDU2_RPC_CHANNEL_STATE_T_PACKED_SIZE 14

uint32_t PackSET_HAL_PDU2_RPC_CHANNEL_STATE_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_HAL_PDU2_RPC_CHANNEL_STATE_t(void *protobetter_type, void *buffer);


#include "HAL_types.h"


#define STRUCT_SET_HAL_PDU2_RPC_CHANNEL_OPEN_T_PACKED_SIZE 14

uint32_t PackSET_HAL_PDU2_RPC_CHANNEL_OPEN_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_HAL_PDU2_RPC_CHANNEL_OPEN_t(void *protobetter_type, void *buffer);


#include "HAL_types.h"


#define STRUCT_HAL_PDU2_CMD_PACKED_SIZE 14

uint32_t PackHAL_PDU2_CMD(void *buffer, void *protobetter_type);


uint32_t UnpackHAL_PDU2_CMD(void *protobetter_type, void *buffer);


#include "HAL_types.h"


#define STRUCT_SET_HAL_PDU3_INPUT_BUS_SELECT_T_PACKED_SIZE 13

uint32_t PackSET_HAL_PDU3_INPUT_BUS_SELECT_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_HAL_PDU3_INPUT_BUS_SELECT_t(void *protobetter_type, void *buffer);


#include "HAL_types.h"


#define STRUCT_SET_HAL_PDU3_RPC_CHANNEL_STATE_T_PACKED_SIZE 14

uint32_t PackSET_HAL_PDU3_RPC_CHANNEL_STATE_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_HAL_PDU3_RPC_CHANNEL_STATE_t(void *protobetter_type, void *buffer);


#include "HAL_types.h"


#define STRUCT_SET_HAL_PDU3_RPC_CHANNEL_OPEN_T_PACKED_SIZE 14

uint32_t PackSET_HAL_PDU3_RPC_CHANNEL_OPEN_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_HAL_PDU3_RPC_CHANNEL_OPEN_t(void *protobetter_type, void *buffer);


#include "HAL_types.h"


#define STRUCT_HAL_PDU3_CMD_PACKED_SIZE 14

uint32_t PackHAL_PDU3_CMD(void *buffer, void *protobetter_type);


uint32_t UnpackHAL_PDU3_CMD(void *protobetter_type, void *buffer);


#include "HAL_types.h"


#define STRUCT_SET_HAL_PDU4_INPUT_BUS_SELECT_T_PACKED_SIZE 13

uint32_t PackSET_HAL_PDU4_INPUT_BUS_SELECT_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_HAL_PDU4_INPUT_BUS_SELECT_t(void *protobetter_type, void *buffer);


#include "HAL_types.h"


#define STRUCT_SET_HAL_PDU4_RPC_CHANNEL_STATE_T_PACKED_SIZE 14

uint32_t PackSET_HAL_PDU4_RPC_CHANNEL_STATE_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_HAL_PDU4_RPC_CHANNEL_STATE_t(void *protobetter_type, void *buffer);


#include "HAL_types.h"


#define STRUCT_SET_HAL_PDU4_RPC_CHANNEL_OPEN_T_PACKED_SIZE 14

uint32_t PackSET_HAL_PDU4_RPC_CHANNEL_OPEN_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_HAL_PDU4_RPC_CHANNEL_OPEN_t(void *protobetter_type, void *buffer);


#include "HAL_types.h"


#define STRUCT_HAL_PDU4_CMD_PACKED_SIZE 14

uint32_t PackHAL_PDU4_CMD(void *buffer, void *protobetter_type);


uint32_t UnpackHAL_PDU4_CMD(void *protobetter_type, void *buffer);


#include "HAL_types.h"


#define STRUCT_SET_HAL_PS1_OUTPUT_CHANNEL_STATE_T_PACKED_SIZE 14

uint32_t PackSET_HAL_PS1_OUTPUT_CHANNEL_STATE_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_HAL_PS1_OUTPUT_CHANNEL_STATE_t(void *protobetter_type, void *buffer);


#include "HAL_types.h"


#define STRUCT_SET_HAL_PS1_SAR_STATE_T_PACKED_SIZE 13

uint32_t PackSET_HAL_PS1_SAR_STATE_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_HAL_PS1_SAR_STATE_t(void *protobetter_type, void *buffer);


#include "HAL_types.h"


#define STRUCT_HAL_POWER_SOURCE1_CMD_PACKED_SIZE 14

uint32_t PackHAL_Power_Source1_CMD(void *buffer, void *protobetter_type);


uint32_t UnpackHAL_Power_Source1_CMD(void *protobetter_type, void *buffer);


#include "HAL_types.h"


#define STRUCT_SET_HAL_PS2_OUTPUT_CHANNEL_STATE_T_PACKED_SIZE 14

uint32_t PackSET_HAL_PS2_OUTPUT_CHANNEL_STATE_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_HAL_PS2_OUTPUT_CHANNEL_STATE_t(void *protobetter_type, void *buffer);


#include "HAL_types.h"


#define STRUCT_SET_HAL_PS2_SAR_STATE_T_PACKED_SIZE 13

uint32_t PackSET_HAL_PS2_SAR_STATE_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_HAL_PS2_SAR_STATE_t(void *protobetter_type, void *buffer);


#include "HAL_types.h"


#define STRUCT_HAL_POWER_SOURCE2_CMD_PACKED_SIZE 14

uint32_t PackHAL_Power_Source2_CMD(void *buffer, void *protobetter_type);


uint32_t UnpackHAL_Power_Source2_CMD(void *protobetter_type, void *buffer);


#ifdef __cplusplus
}
#endif
#endif //__PROTOBETTER_HAL_H__

