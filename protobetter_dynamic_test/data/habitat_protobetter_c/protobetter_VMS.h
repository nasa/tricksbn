#ifndef __PROTOBETTER_VMS_H__
#define __PROTOBETTER_VMS_H__

#ifdef __cplusplus
extern "C"
{
#endif
#include <stdint.h>
#include "protobetter_core.h"

#include "VMS_types.h"


#define STRUCT_LOADSCHEDULE_PACKED_SIZE 1808

uint32_t PackloadSchedule(void *buffer, void *protobetter_type);


uint32_t UnpackloadSchedule(void *protobetter_type, void *buffer);


#include "VMS_types.h"


#define STRUCT_REQUEST_ENERGY_PACKED_SIZE 17

uint32_t Packrequest_energy(void *buffer, void *protobetter_type);


uint32_t Unpackrequest_energy(void *protobetter_type, void *buffer);


#ifdef __cplusplus
}
#endif
#endif //__PROTOBETTER_VMS_H__

