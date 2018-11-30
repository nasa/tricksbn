#ifndef __PROTOBETTER_HERA_H__
#define __PROTOBETTER_HERA_H__

#ifdef __cplusplus
extern "C"
{
#endif
#include <stdint.h>
#include "protobetter_core.h"

#include "HERA_types.h"


#define STRUCT_HERA_CW_DATA_PACKED_SIZE 60 + (1*MAX_SENSORS) + (1*MAX_SENSORS) + (1*MAX_SENSORS)

uint32_t PackHERA_CW_DATA(void *buffer, void *protobetter_type);


uint32_t UnpackHERA_CW_DATA(void *protobetter_type, void *buffer);


#ifdef __cplusplus
}
#endif
#endif //__PROTOBETTER_HERA_H__

