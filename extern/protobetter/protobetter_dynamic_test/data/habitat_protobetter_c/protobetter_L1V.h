#ifndef __PROTOBETTER_L1V_H__
#define __PROTOBETTER_L1V_H__

#ifdef __cplusplus
extern "C"
{
#endif
#include <stdint.h>
#include "protobetter_core.h"

#include "L1V_types.h"


#define STRUCT_L1V_HAB_VOTE_PACKED_SIZE 20

uint32_t PackL1V_HAB_VOTE(void *buffer, void *protobetter_type);


uint32_t UnpackL1V_HAB_VOTE(void *protobetter_type, void *buffer);


#ifdef __cplusplus
}
#endif
#endif //__PROTOBETTER_L1V_H__

