#ifndef __PROTOBETTER_MDA_H__
#define __PROTOBETTER_MDA_H__

#ifdef __cplusplus
extern "C"
{
#endif
#include <stdint.h>
#include "protobetter_core.h"

#include "MDA_types.h"


#define STRUCT_MDA_PACKED_SIZE 4195

uint32_t Packmda(void *buffer, void *protobetter_type);


uint32_t Unpackmda(void *protobetter_type, void *buffer);


#ifdef __cplusplus
}
#endif
#endif //__PROTOBETTER_MDA_H__

