#ifndef __PROTOBETTER_AMPS_H__
#define __PROTOBETTER_AMPS_H__

#ifdef __cplusplus
extern "C"
{
#endif
#include <stdint.h>
#include "protobetter_core.h"

#include "AMPS_types.h"


#define STRUCT_MBSU1_PACKED_SIZE 184

uint32_t PackMBSU1(void *buffer, void *protobetter_type);


uint32_t UnpackMBSU1(void *protobetter_type, void *buffer);


#include "AMPS_types.h"


#define STRUCT_MBSU2_PACKED_SIZE 184

uint32_t PackMBSU2(void *buffer, void *protobetter_type);


uint32_t UnpackMBSU2(void *protobetter_type, void *buffer);


#include "AMPS_types.h"


#define STRUCT_MPDU1_PACKED_SIZE 69

uint32_t PackmPDU1(void *buffer, void *protobetter_type);


uint32_t UnpackmPDU1(void *protobetter_type, void *buffer);


#include "AMPS_types.h"


#define STRUCT_PDU1_PACKED_SIZE 152

uint32_t PackPDU1(void *buffer, void *protobetter_type);


uint32_t UnpackPDU1(void *protobetter_type, void *buffer);


#include "AMPS_types.h"


#define STRUCT_PDU2_PACKED_SIZE 152

uint32_t PackPDU2(void *buffer, void *protobetter_type);


uint32_t UnpackPDU2(void *protobetter_type, void *buffer);


#include "AMPS_types.h"


#define STRUCT_PDU3_PACKED_SIZE 152

uint32_t PackPDU3(void *buffer, void *protobetter_type);


uint32_t UnpackPDU3(void *protobetter_type, void *buffer);


#include "AMPS_types.h"


#define STRUCT_PDU4_PACKED_SIZE 152

uint32_t PackPDU4(void *buffer, void *protobetter_type);


uint32_t UnpackPDU4(void *protobetter_type, void *buffer);


#include "AMPS_types.h"


#define STRUCT_AMPSDB_IO_NOOP_CC_T_PACKED_SIZE 12

uint32_t PackAMPSDB_IO_NOOP_CC_t(void *buffer, void *protobetter_type);


uint32_t UnpackAMPSDB_IO_NOOP_CC_t(void *protobetter_type, void *buffer);


#include "AMPS_types.h"


#define STRUCT_AMPSDB_IO_RESET_CC_T_PACKED_SIZE 12

uint32_t PackAMPSDB_IO_RESET_CC_t(void *buffer, void *protobetter_type);


uint32_t UnpackAMPSDB_IO_RESET_CC_t(void *protobetter_type, void *buffer);


#include "AMPS_types.h"


#define STRUCT_AMPSDB_IO_CMD_MID_PACKED_SIZE 12

uint32_t PackAMPSDB_IO_CMD_MID(void *buffer, void *protobetter_type);


uint32_t UnpackAMPSDB_IO_CMD_MID(void *protobetter_type, void *buffer);


#include "AMPS_types.h"


#define STRUCT_SET_MBSU1_INPUT_SOURCE_SELECT_T_PACKED_SIZE 14

uint32_t PackSET_MBSU1_INPUT_SOURCE_SELECT_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_MBSU1_INPUT_SOURCE_SELECT_t(void *protobetter_type, void *buffer);


#include "AMPS_types.h"


#define STRUCT_SET_MBSU1_OUTPUT_CHANNEL_STATE_T_PACKED_SIZE 14

uint32_t PackSET_MBSU1_OUTPUT_CHANNEL_STATE_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_MBSU1_OUTPUT_CHANNEL_STATE_t(void *protobetter_type, void *buffer);


#include "AMPS_types.h"


#define STRUCT_SET_MBSU1_INPUT_CURR_LIMIT_T_PACKED_SIZE 21

uint32_t PackSET_MBSU1_Input_Curr_Limit_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_MBSU1_Input_Curr_Limit_t(void *protobetter_type, void *buffer);


#include "AMPS_types.h"


#define STRUCT_SET_MBSU1_OUTPUT_CURR_LIMIT_T_PACKED_SIZE 21

uint32_t PackSET_MBSU1_Output_Curr_Limit_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_MBSU1_Output_Curr_Limit_t(void *protobetter_type, void *buffer);


#include "AMPS_types.h"


#define STRUCT_CLEAR_MBSU1_INPUT_CURR_TRIP_T_PACKED_SIZE 13

uint32_t PackCLEAR_MBSU1_Input_Curr_Trip_t(void *buffer, void *protobetter_type);


uint32_t UnpackCLEAR_MBSU1_Input_Curr_Trip_t(void *protobetter_type, void *buffer);


#include "AMPS_types.h"


#define STRUCT_CLEAR_MBSU1_OUTPUT_CURR_TRIP_T_PACKED_SIZE 13

uint32_t PackCLEAR_MBSU1_Output_Curr_Trip_t(void *buffer, void *protobetter_type);


uint32_t UnpackCLEAR_MBSU1_Output_Curr_Trip_t(void *protobetter_type, void *buffer);


#include "AMPS_types.h"


#define STRUCT_SET_MBSU1_RELAY_CHANNEL_OPEN_T_PACKED_SIZE 14

uint32_t PackSET_MBSU1_Relay_CHANNEL_OPEN_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_MBSU1_Relay_CHANNEL_OPEN_t(void *protobetter_type, void *buffer);


#include "AMPS_types.h"


#define STRUCT_MBSU1_FAIL_INPUT_SOURCE_T_PACKED_SIZE 14

uint32_t PackMBSU1_FAIL_INPUT_SOURCE_t(void *buffer, void *protobetter_type);


uint32_t UnpackMBSU1_FAIL_INPUT_SOURCE_t(void *protobetter_type, void *buffer);


#include "AMPS_types.h"


#define STRUCT_MBSU1_CMD_PACKED_SIZE 21

uint32_t PackMBSU1_CMD(void *buffer, void *protobetter_type);


uint32_t UnpackMBSU1_CMD(void *protobetter_type, void *buffer);


#include "AMPS_types.h"


#define STRUCT_SET_MBSU2_INPUT_SOURCE_SELECT_T_PACKED_SIZE 14

uint32_t PackSET_MBSU2_INPUT_SOURCE_SELECT_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_MBSU2_INPUT_SOURCE_SELECT_t(void *protobetter_type, void *buffer);


#include "AMPS_types.h"


#define STRUCT_SET_MBSU2_OUTPUT_CHANNEL_STATE_T_PACKED_SIZE 14

uint32_t PackSET_MBSU2_OUTPUT_CHANNEL_STATE_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_MBSU2_OUTPUT_CHANNEL_STATE_t(void *protobetter_type, void *buffer);


#include "AMPS_types.h"


#define STRUCT_SET_MBSU2_INPUT_CURR_LIMIT_T_PACKED_SIZE 21

uint32_t PackSET_MBSU2_Input_Curr_Limit_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_MBSU2_Input_Curr_Limit_t(void *protobetter_type, void *buffer);


#include "AMPS_types.h"


#define STRUCT_SET_MBSU2_OUTPUT_CURR_LIMIT_T_PACKED_SIZE 21

uint32_t PackSET_MBSU2_Output_Curr_Limit_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_MBSU2_Output_Curr_Limit_t(void *protobetter_type, void *buffer);


#include "AMPS_types.h"


#define STRUCT_CLEAR_MBSU2_INPUT_CURR_TRIP_T_PACKED_SIZE 13

uint32_t PackCLEAR_MBSU2_Input_Curr_Trip_t(void *buffer, void *protobetter_type);


uint32_t UnpackCLEAR_MBSU2_Input_Curr_Trip_t(void *protobetter_type, void *buffer);


#include "AMPS_types.h"


#define STRUCT_CLEAR_MBSU2_OUTPUT_CURR_TRIP_T_PACKED_SIZE 13

uint32_t PackCLEAR_MBSU2_Output_Curr_Trip_t(void *buffer, void *protobetter_type);


uint32_t UnpackCLEAR_MBSU2_Output_Curr_Trip_t(void *protobetter_type, void *buffer);


#include "AMPS_types.h"


#define STRUCT_SET_MBSU2_RELAY_CHANNEL_OPEN_T_PACKED_SIZE 14

uint32_t PackSET_MBSU2_Relay_CHANNEL_OPEN_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_MBSU2_Relay_CHANNEL_OPEN_t(void *protobetter_type, void *buffer);


#include "AMPS_types.h"


#define STRUCT_MBSU2_FAIL_INPUT_SOURCE_T_PACKED_SIZE 14

uint32_t PackMBSU2_FAIL_INPUT_SOURCE_t(void *buffer, void *protobetter_type);


uint32_t UnpackMBSU2_FAIL_INPUT_SOURCE_t(void *protobetter_type, void *buffer);


#include "AMPS_types.h"


#define STRUCT_MBSU2_CMD_PACKED_SIZE 21

uint32_t PackMBSU2_CMD(void *buffer, void *protobetter_type);


uint32_t UnpackMBSU2_CMD(void *protobetter_type, void *buffer);


#include "AMPS_types.h"


#define STRUCT_SET_PDU1_INPUT_BUS_SELECT_T_PACKED_SIZE 13

uint32_t PackSET_PDU1_INPUT_BUS_SELECT_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_PDU1_INPUT_BUS_SELECT_t(void *protobetter_type, void *buffer);


#include "AMPS_types.h"


#define STRUCT_SET_PDU1_RPC_CHANNEL_STATE_T_PACKED_SIZE 14

uint32_t PackSET_PDU1_RPC_CHANNEL_STATE_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_PDU1_RPC_CHANNEL_STATE_t(void *protobetter_type, void *buffer);


#include "AMPS_types.h"


#define STRUCT_SET_PDU1_RPC_CHANNEL_OPEN_T_PACKED_SIZE 14

uint32_t PackSET_PDU1_RPC_CHANNEL_OPEN_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_PDU1_RPC_CHANNEL_OPEN_t(void *protobetter_type, void *buffer);


#include "AMPS_types.h"


#define STRUCT_PDU1_CMD_PACKED_SIZE 14

uint32_t PackPDU1_CMD(void *buffer, void *protobetter_type);


uint32_t UnpackPDU1_CMD(void *protobetter_type, void *buffer);


#include "AMPS_types.h"


#define STRUCT_SET_PDU2_INPUT_BUS_SELECT_T_PACKED_SIZE 13

uint32_t PackSET_PDU2_INPUT_BUS_SELECT_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_PDU2_INPUT_BUS_SELECT_t(void *protobetter_type, void *buffer);


#include "AMPS_types.h"


#define STRUCT_SET_PDU2_RPC_CHANNEL_STATE_T_PACKED_SIZE 14

uint32_t PackSET_PDU2_RPC_CHANNEL_STATE_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_PDU2_RPC_CHANNEL_STATE_t(void *protobetter_type, void *buffer);


#include "AMPS_types.h"


#define STRUCT_SET_PDU2_RPC_CHANNEL_OPEN_T_PACKED_SIZE 14

uint32_t PackSET_PDU2_RPC_CHANNEL_OPEN_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_PDU2_RPC_CHANNEL_OPEN_t(void *protobetter_type, void *buffer);


#include "AMPS_types.h"


#define STRUCT_PDU2_CMD_PACKED_SIZE 14

uint32_t PackPDU2_CMD(void *buffer, void *protobetter_type);


uint32_t UnpackPDU2_CMD(void *protobetter_type, void *buffer);


#include "AMPS_types.h"


#define STRUCT_SET_PDU3_INPUT_BUS_SELECT_T_PACKED_SIZE 13

uint32_t PackSET_PDU3_INPUT_BUS_SELECT_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_PDU3_INPUT_BUS_SELECT_t(void *protobetter_type, void *buffer);


#include "AMPS_types.h"


#define STRUCT_SET_PDU3_RPC_CHANNEL_STATE_T_PACKED_SIZE 14

uint32_t PackSET_PDU3_RPC_CHANNEL_STATE_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_PDU3_RPC_CHANNEL_STATE_t(void *protobetter_type, void *buffer);


#include "AMPS_types.h"


#define STRUCT_SET_PDU3_RPC_CHANNEL_OPEN_T_PACKED_SIZE 14

uint32_t PackSET_PDU3_RPC_CHANNEL_OPEN_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_PDU3_RPC_CHANNEL_OPEN_t(void *protobetter_type, void *buffer);


#include "AMPS_types.h"


#define STRUCT_PDU3_CMD_PACKED_SIZE 14

uint32_t PackPDU3_CMD(void *buffer, void *protobetter_type);


uint32_t UnpackPDU3_CMD(void *protobetter_type, void *buffer);


#include "AMPS_types.h"


#define STRUCT_SET_PDU4_INPUT_BUS_SELECT_T_PACKED_SIZE 13

uint32_t PackSET_PDU4_INPUT_BUS_SELECT_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_PDU4_INPUT_BUS_SELECT_t(void *protobetter_type, void *buffer);


#include "AMPS_types.h"


#define STRUCT_SET_PDU4_RPC_CHANNEL_STATE_T_PACKED_SIZE 14

uint32_t PackSET_PDU4_RPC_CHANNEL_STATE_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_PDU4_RPC_CHANNEL_STATE_t(void *protobetter_type, void *buffer);


#include "AMPS_types.h"


#define STRUCT_SET_PDU4_RPC_CHANNEL_OPEN_T_PACKED_SIZE 14

uint32_t PackSET_PDU4_RPC_CHANNEL_OPEN_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_PDU4_RPC_CHANNEL_OPEN_t(void *protobetter_type, void *buffer);


#include "AMPS_types.h"


#define STRUCT_PDU4_CMD_PACKED_SIZE 14

uint32_t PackPDU4_CMD(void *buffer, void *protobetter_type);


uint32_t UnpackPDU4_CMD(void *protobetter_type, void *buffer);


#ifdef __cplusplus
}
#endif
#endif //__PROTOBETTER_AMPS_H__

