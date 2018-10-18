#ifndef __PROTOBETTER_APC_H__
#define __PROTOBETTER_APC_H__

#ifdef __cplusplus
extern "C"
{
#endif
#include <stdint.h>
#include "protobetter_core.h"

#include "APC_types.h"


#define STRUCT_APC_AVAILIBILITY_PACKED_SIZE 644

uint32_t PackAPC_AVAILIBILITY(void *buffer, void *protobetter_type);


uint32_t UnpackAPC_AVAILIBILITY(void *protobetter_type, void *buffer);


#include "APC_types.h"


#define STRUCT_APC_EA_RESPONSE_PACKED_SIZE 644

uint32_t PackAPC_EA_RESPONSE(void *buffer, void *protobetter_type);


uint32_t UnpackAPC_EA_RESPONSE(void *protobetter_type, void *buffer);


#include "APC_types.h"


#define STRUCT_APC_LOAD_SCHEDULE_RESPONSE_PACKED_SIZE 24

uint32_t Packapc_load_schedule_response(void *buffer, void *protobetter_type);


uint32_t Unpackapc_load_schedule_response(void *protobetter_type, void *buffer);


#ifdef __cplusplus
}
#endif
#endif //__PROTOBETTER_APC_H__

