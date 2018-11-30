#ifndef __PROTOBETTER_MPCV_H__
#define __PROTOBETTER_MPCV_H__

#ifdef __cplusplus
extern "C"
{
#endif
#include <stdint.h>
#include "protobetter_core.h"

#include "MPCV_types.h"


#define STRUCT_MPCV_NAV_STATE_TLM_PACKED_SIZE 144

uint32_t PackMPCV_NAV_STATE_TLM(void *buffer, void *protobetter_type);


uint32_t UnpackMPCV_NAV_STATE_TLM(void *protobetter_type, void *buffer);


#ifdef __cplusplus
}
#endif
#endif //__PROTOBETTER_MPCV_H__

