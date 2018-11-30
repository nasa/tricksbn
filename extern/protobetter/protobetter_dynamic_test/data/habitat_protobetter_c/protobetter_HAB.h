#ifndef __PROTOBETTER_HAB_H__
#define __PROTOBETTER_HAB_H__

#ifdef __cplusplus
extern "C"
{
#endif
#include <stdint.h>
#include "protobetter_core.h"

#include "HAB_types.h"


#define STRUCT_HAB_POWER_SOURCE1_PACKED_SIZE 77

uint32_t PackHAB_Power_Source1(void *buffer, void *protobetter_type);


uint32_t UnpackHAB_Power_Source1(void *protobetter_type, void *buffer);


#include "HAB_types.h"


#define STRUCT_HAB_POWER_SOURCE2_PACKED_SIZE 77

uint32_t PackHAB_Power_Source2(void *buffer, void *protobetter_type);


uint32_t UnpackHAB_Power_Source2(void *protobetter_type, void *buffer);


#include "HAB_types.h"


#define STRUCT_MAST_PACKED_SIZE 52

uint32_t PackMAST(void *buffer, void *protobetter_type);


uint32_t UnpackMAST(void *protobetter_type, void *buffer);


#include "HAB_types.h"


#define STRUCT_SET_HAB_PS1_OUTPUT_CHANNEL_STATE_T_PACKED_SIZE 14

uint32_t PackSET_HAB_PS1_OUTPUT_CHANNEL_STATE_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_HAB_PS1_OUTPUT_CHANNEL_STATE_t(void *protobetter_type, void *buffer);


#include "HAB_types.h"


#define STRUCT_SET_HAB_PS1_SAR_STATE_T_PACKED_SIZE 13

uint32_t PackSET_HAB_PS1_SAR_STATE_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_HAB_PS1_SAR_STATE_t(void *protobetter_type, void *buffer);


#include "HAB_types.h"


#define STRUCT_HAB_POWER_SOURCE1_CMD_PACKED_SIZE 14

uint32_t PackHAB_Power_Source1_CMD(void *buffer, void *protobetter_type);


uint32_t UnpackHAB_Power_Source1_CMD(void *protobetter_type, void *buffer);


#include "HAB_types.h"


#define STRUCT_SET_HAB_PS2_OUTPUT_CHANNEL_STATE_T_PACKED_SIZE 14

uint32_t PackSET_HAB_PS2_OUTPUT_CHANNEL_STATE_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_HAB_PS2_OUTPUT_CHANNEL_STATE_t(void *protobetter_type, void *buffer);


#include "HAB_types.h"


#define STRUCT_SET_HAB_PS2_SAR_STATE_T_PACKED_SIZE 13

uint32_t PackSET_HAB_PS2_SAR_STATE_t(void *buffer, void *protobetter_type);


uint32_t UnpackSET_HAB_PS2_SAR_STATE_t(void *protobetter_type, void *buffer);


#include "HAB_types.h"


#define STRUCT_HAB_POWER_SOURCE2_CMD_PACKED_SIZE 14

uint32_t PackHAB_Power_Source2_CMD(void *buffer, void *protobetter_type);


uint32_t UnpackHAB_Power_Source2_CMD(void *protobetter_type, void *buffer);


#ifdef __cplusplus
}
#endif
#endif //__PROTOBETTER_HAB_H__

