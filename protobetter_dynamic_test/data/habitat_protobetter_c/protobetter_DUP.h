#ifndef __PROTOBETTER_DUP_H__
#define __PROTOBETTER_DUP_H__

#ifdef __cplusplus
extern "C"
{
#endif
#include <stdint.h>
#include "protobetter_core.h"

#include "DUP_types.h"


#define STRUCT_DUP_HKTLM_T_PACKED_SIZE 20

uint32_t PackDUP_HkTlm_t(void *buffer, void *protobetter_type);


uint32_t UnpackDUP_HkTlm_t(void *protobetter_type, void *buffer);


#include "DUP_types.h"


#define STRUCT_DUP_NOOP_CC_T_PACKED_SIZE 12

uint32_t PackDUP_NOOP_CC_t(void *buffer, void *protobetter_type);


uint32_t UnpackDUP_NOOP_CC_t(void *protobetter_type, void *buffer);


#include "DUP_types.h"


#define STRUCT_DUP_PROCESS_CC_T_PACKED_SIZE 12

uint32_t PackDUP_PROCESS_CC_t(void *buffer, void *protobetter_type);


uint32_t UnpackDUP_PROCESS_CC_t(void *protobetter_type, void *buffer);


#include "DUP_types.h"


#define STRUCT_DUP_ADD_CC_T_PACKED_SIZE 20

uint32_t PackDUP_ADD_CC_t(void *buffer, void *protobetter_type);


uint32_t UnpackDUP_ADD_CC_t(void *protobetter_type, void *buffer);


#include "DUP_types.h"


#define STRUCT_DUP_DEL_CC_T_PACKED_SIZE 12

uint32_t PackDUP_DEL_CC_t(void *buffer, void *protobetter_type);


uint32_t UnpackDUP_DEL_CC_t(void *protobetter_type, void *buffer);


#include "DUP_types.h"


#define STRUCT_DUP_HK_CC_T_PACKED_SIZE 12

uint32_t PackDUP_HK_CC_t(void *buffer, void *protobetter_type);


uint32_t UnpackDUP_HK_CC_t(void *protobetter_type, void *buffer);


#include "DUP_types.h"


#define STRUCT_DUP_CMD_PACKED_SIZE 20

uint32_t PackDUP_CMD(void *buffer, void *protobetter_type);


uint32_t UnpackDUP_CMD(void *protobetter_type, void *buffer);


#ifdef __cplusplus
}
#endif
#endif //__PROTOBETTER_DUP_H__

