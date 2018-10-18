#ifndef __PROTOBETTER_TTE_H__
#define __PROTOBETTER_TTE_H__

#ifdef __cplusplus
extern "C"
{
#endif
#include <stdint.h>
#include "protobetter_core.h"

#include "tte_types.h"


#define STRUCT_TTE_DIAGPACKET_T_PACKED_SIZE 16 + ((200)*TTE_DATAPORT_COUNT_MAX)

uint32_t PackTTE_DiagPacket_t(void *buffer, void *protobetter_type);


uint32_t UnpackTTE_DiagPacket_t(void *protobetter_type, void *buffer);


#include "tte_types.h"


#define STRUCT_TTE_HKPACKET_T_PACKED_SIZE 24

uint32_t PackTTE_HkPacket_t(void *buffer, void *protobetter_type);


uint32_t UnpackTTE_HkPacket_t(void *protobetter_type, void *buffer);


#include "tte_types.h"


#define STRUCT_TTE_NOOP_CC_T_PACKED_SIZE 12

uint32_t PackTTE_NOOP_CC_t(void *buffer, void *protobetter_type);


uint32_t UnpackTTE_NOOP_CC_t(void *protobetter_type, void *buffer);


#include "tte_types.h"


#define STRUCT_TTE_RESET_CC_T_PACKED_SIZE 12

uint32_t PackTTE_RESET_CC_t(void *buffer, void *protobetter_type);


uint32_t UnpackTTE_RESET_CC_t(void *protobetter_type, void *buffer);


#include "tte_types.h"


#define STRUCT_TTE_SEND_DIAG_CC_T_PACKED_SIZE 12

uint32_t PackTTE_SEND_DIAG_CC_t(void *buffer, void *protobetter_type);


uint32_t UnpackTTE_SEND_DIAG_CC_t(void *protobetter_type, void *buffer);


#include "tte_types.h"


#define STRUCT_TTE_CMD_MID_PACKED_SIZE 12

uint32_t PackTTE_CMD_MID(void *buffer, void *protobetter_type);


uint32_t UnpackTTE_CMD_MID(void *protobetter_type, void *buffer);


#ifdef __cplusplus
}
#endif
#endif //__PROTOBETTER_TTE_H__

