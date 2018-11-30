#ifndef __PROTOBETTER_ACAWS_FIR_H__
#define __PROTOBETTER_ACAWS_FIR_H__

#ifdef __cplusplus
extern "C"
{
#endif
#include <stdint.h>
#include "protobetter_core.h"

#include "acaws_fir_types.h"


#define STRUCT_ACAWS_FIR_HKTLM_T_PACKED_SIZE 20

uint32_t PackACAWS_FIR_HkTlm_t(void *buffer, void *protobetter_type);


uint32_t UnpackACAWS_FIR_HkTlm_t(void *protobetter_type, void *buffer);


#include "acaws_fir_types.h"


#define STRUCT_ACAWS_FIR_OUTDATA_MSG_T_PACKED_SIZE 16 + (1*CFS_ACAWS_FIR_OUTDATA_SERIALIZED_SIZE)

uint32_t PackACAWS_FIR_OutData_Msg_t(void *buffer, void *protobetter_type);


uint32_t UnpackACAWS_FIR_OutData_Msg_t(void *protobetter_type, void *buffer);


#include "acaws_fir_types.h"


#define STRUCT_ACAWS_FIR_OUTDATA_T_PACKED_SIZE 22 + ((1)*FIR_MAX_ELEM_SIZE)

uint32_t PackACAWS_FIR_OutData_t(void *buffer, void *protobetter_type);


uint32_t UnpackACAWS_FIR_OutData_t(void *protobetter_type, void *buffer);


#ifdef __cplusplus
}
#endif
#endif //__PROTOBETTER_ACAWS_FIR_H__

