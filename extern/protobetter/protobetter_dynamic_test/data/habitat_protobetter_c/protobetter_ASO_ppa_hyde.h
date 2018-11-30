#ifndef __PROTOBETTER_ASO_PPA_HYDE_H__
#define __PROTOBETTER_ASO_PPA_HYDE_H__

#ifdef __cplusplus
extern "C"
{
#endif
#include <stdint.h>
#include "protobetter_core.h"

#include "ASO_ppa_hyde_types.h"


#define STRUCT_PPA_HYDE_HKTLM_T_PACKED_SIZE 20

uint32_t PackPPA_HYDE_HkTlm_t(void *buffer, void *protobetter_type);


uint32_t UnpackPPA_HYDE_HkTlm_t(void *protobetter_type, void *buffer);


#include "ASO_ppa_hyde_types.h"


#define STRUCT_PPA_HYDE_OUTDATA_T_PACKED_SIZE 31

uint32_t PackPPA_HYDE_OutData_t(void *buffer, void *protobetter_type);


uint32_t UnpackPPA_HYDE_OutData_t(void *protobetter_type, void *buffer);


#ifdef __cplusplus
}
#endif
#endif //__PROTOBETTER_ASO_PPA_HYDE_H__

