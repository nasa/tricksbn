#ifndef __PROTOBETTER_ACAWS_DE_H__
#define __PROTOBETTER_ACAWS_DE_H__

#ifdef __cplusplus
extern "C"
{
#endif
#include <stdint.h>
#include "protobetter_core.h"

#include "acaws_de_types.h"


#define STRUCT_ACAWS_DE_DIAGDATA_MSG_T_PACKED_SIZE 16 + (1*CFS_ACAWS_DE_DIAG_DATA_SERIALIZED_SIZE)

uint32_t PackACAWS_DE_DiagData_Msg_t(void *buffer, void *protobetter_type);


uint32_t UnpackACAWS_DE_DiagData_Msg_t(void *protobetter_type, void *buffer);


#include "acaws_de_types.h"


#define STRUCT_ACAWS_DE_DIAGDATA_T_PACKED_SIZE 24 + ((2)*DIAG_MAX_ELEM_SIZE)

uint32_t PackACAWS_DE_DiagData_t(void *buffer, void *protobetter_type);


uint32_t UnpackACAWS_DE_DiagData_t(void *protobetter_type, void *buffer);


#include "acaws_de_types.h"


#define STRUCT_ACAWS_DE_IMPACTREQ_MSG_T_PACKED_SIZE 16 + (1*CFS_ACAWS_DE_IMPACT_REQ_SERIALIZED_SIZE)

uint32_t PackACAWS_DE_ImpactReq_Msg_t(void *buffer, void *protobetter_type);


uint32_t UnpackACAWS_DE_ImpactReq_Msg_t(void *protobetter_type, void *buffer);


#include "acaws_de_types.h"


#define STRUCT_ACAWS_DE_IMPACTREQ_T_PACKED_SIZE 22 + ((4)*DIAG_MAX_IMPACT_REQ_SIZE)

uint32_t PackACAWS_DE_ImpactReq_t(void *buffer, void *protobetter_type);


uint32_t UnpackACAWS_DE_ImpactReq_t(void *protobetter_type, void *buffer);


#ifdef __cplusplus
}
#endif
#endif //__PROTOBETTER_ACAWS_DE_H__

