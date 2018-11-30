#ifndef __PROTOBETTER_TCS_H__
#define __PROTOBETTER_TCS_H__

#ifdef __cplusplus
extern "C"
{
#endif
#include <stdint.h>
#include "protobetter_core.h"

#include "TCS_types.h"


#define STRUCT_HAB_TCS_ETCS_TLM_PACKED_SIZE 280

uint32_t PackHAB_TCS_ETCS_TLM(void *buffer, void *protobetter_type);


uint32_t UnpackHAB_TCS_ETCS_TLM(void *protobetter_type, void *buffer);


#include "TCS_types.h"


#define STRUCT_HAB_TCS_ITCS_TLM_PACKED_SIZE 112

uint32_t PackHAB_TCS_ITCS_TLM(void *buffer, void *protobetter_type);


uint32_t UnpackHAB_TCS_ITCS_TLM(void *protobetter_type, void *buffer);


#include "TCS_types.h"


#define STRUCT_A_ISO_A_T_PACKED_SIZE 16

uint32_t PackA_ISO_A_t(void *buffer, void *protobetter_type);


uint32_t UnpackA_ISO_A_t(void *protobetter_type, void *buffer);


#include "TCS_types.h"


#define STRUCT_A_ISO_B_T_PACKED_SIZE 16

uint32_t PackA_ISO_B_t(void *buffer, void *protobetter_type);


uint32_t UnpackA_ISO_B_t(void *protobetter_type, void *buffer);


#include "TCS_types.h"


#define STRUCT_A_PUMP_1_T_PACKED_SIZE 13

uint32_t PackA_PUMP_1_t(void *buffer, void *protobetter_type);


uint32_t UnpackA_PUMP_1_t(void *protobetter_type, void *buffer);


#include "TCS_types.h"


#define STRUCT_A_PUMP_2_T_PACKED_SIZE 13

uint32_t PackA_PUMP_2_t(void *buffer, void *protobetter_type);


uint32_t UnpackA_PUMP_2_t(void *protobetter_type, void *buffer);


#include "TCS_types.h"


#define STRUCT_A_RAD_MIX_T_PACKED_SIZE 16

uint32_t PackA_RAD_MIX_t(void *buffer, void *protobetter_type);


uint32_t UnpackA_RAD_MIX_t(void *protobetter_type, void *buffer);


#include "TCS_types.h"


#define STRUCT_HAB_TCS_ETCS_A_CMD_PACKED_SIZE 16

uint32_t PackHAB_TCS_ETCS_A_CMD(void *buffer, void *protobetter_type);


uint32_t UnpackHAB_TCS_ETCS_A_CMD(void *protobetter_type, void *buffer);


#include "TCS_types.h"


#define STRUCT_B_ISO_A_T_PACKED_SIZE 16

uint32_t PackB_ISO_A_t(void *buffer, void *protobetter_type);


uint32_t UnpackB_ISO_A_t(void *protobetter_type, void *buffer);


#include "TCS_types.h"


#define STRUCT_B_ISO_B_T_PACKED_SIZE 16

uint32_t PackB_ISO_B_t(void *buffer, void *protobetter_type);


uint32_t UnpackB_ISO_B_t(void *protobetter_type, void *buffer);


#include "TCS_types.h"


#define STRUCT_B_PUMP_1_T_PACKED_SIZE 13

uint32_t PackB_PUMP_1_t(void *buffer, void *protobetter_type);


uint32_t UnpackB_PUMP_1_t(void *protobetter_type, void *buffer);


#include "TCS_types.h"


#define STRUCT_B_PUMP_2_T_PACKED_SIZE 13

uint32_t PackB_PUMP_2_t(void *buffer, void *protobetter_type);


uint32_t UnpackB_PUMP_2_t(void *protobetter_type, void *buffer);


#include "TCS_types.h"


#define STRUCT_B_RAD_MIX_T_PACKED_SIZE 16

uint32_t PackB_RAD_MIX_t(void *buffer, void *protobetter_type);


uint32_t UnpackB_RAD_MIX_t(void *protobetter_type, void *buffer);


#include "TCS_types.h"


#define STRUCT_HAB_TCS_ETCS_B_CMD_PACKED_SIZE 16

uint32_t PackHAB_TCS_ETCS_B_CMD(void *buffer, void *protobetter_type);


uint32_t UnpackHAB_TCS_ETCS_B_CMD(void *protobetter_type, void *buffer);


#include "TCS_types.h"


#define STRUCT_IFHX_SET_T_PACKED_SIZE 16

uint32_t PackIFHX_SET_t(void *buffer, void *protobetter_type);


uint32_t UnpackIFHX_SET_t(void *protobetter_type, void *buffer);


#include "TCS_types.h"


#define STRUCT_PUMP_1_T_PACKED_SIZE 13

uint32_t PackPUMP_1_t(void *buffer, void *protobetter_type);


uint32_t UnpackPUMP_1_t(void *protobetter_type, void *buffer);


#include "TCS_types.h"


#define STRUCT_PUMP_2_T_PACKED_SIZE 13

uint32_t PackPUMP_2_t(void *buffer, void *protobetter_type);


uint32_t UnpackPUMP_2_t(void *protobetter_type, void *buffer);


#include "TCS_types.h"


#define STRUCT_HAB_TCS_ITCS_CMD_PACKED_SIZE 16

uint32_t PackHAB_TCS_ITCS_CMD(void *buffer, void *protobetter_type);


uint32_t UnpackHAB_TCS_ITCS_CMD(void *protobetter_type, void *buffer);


#ifdef __cplusplus
}
#endif
#endif //__PROTOBETTER_TCS_H__

