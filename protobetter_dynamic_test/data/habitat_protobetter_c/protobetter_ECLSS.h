#ifndef __PROTOBETTER_ECLSS_H__
#define __PROTOBETTER_ECLSS_H__

#ifdef __cplusplus
extern "C"
{
#endif
#include <stdint.h>
#include "protobetter_core.h"

#include "ECLSS_types.h"


#define STRUCT_ECLSS_PPA_TLM_PACKET_T_PACKED_SIZE 277

uint32_t PackECLSS_PPA_tlm_packet_t(void *buffer, void *protobetter_type);


uint32_t UnpackECLSS_PPA_tlm_packet_t(void *protobetter_type, void *buffer);


#include "ECLSS_types.h"


#define STRUCT_HAB_ECLSS_ARS_TLM_PACKED_SIZE 291

uint32_t PackHAB_ECLSS_ARS_TLM(void *buffer, void *protobetter_type);


uint32_t UnpackHAB_ECLSS_ARS_TLM(void *protobetter_type, void *buffer);


#include "ECLSS_types.h"


#define STRUCT_HAB_ECLSS_PCS_TLM_PACKED_SIZE 85

uint32_t PackHAB_ECLSS_PCS_TLM(void *buffer, void *protobetter_type);


uint32_t UnpackHAB_ECLSS_PCS_TLM(void *protobetter_type, void *buffer);


#include "ECLSS_types.h"


#define STRUCT_HAB_ECLSS_WMS_TLM_PACKED_SIZE 48

uint32_t PackHAB_ECLSS_WMS_TLM(void *buffer, void *protobetter_type);


uint32_t UnpackHAB_ECLSS_WMS_TLM(void *protobetter_type, void *buffer);


#include "ECLSS_types.h"


#define STRUCT_ARS_CAB_FAN_T_PACKED_SIZE 17

uint32_t PackARS_CAB_FAN_t(void *buffer, void *protobetter_type);


uint32_t UnpackARS_CAB_FAN_t(void *protobetter_type, void *buffer);


#include "ECLSS_types.h"


#define STRUCT_ARS_CAB_T_T_PACKED_SIZE 16

uint32_t PackARS_CAB_T_t(void *buffer, void *protobetter_type);


uint32_t UnpackARS_CAB_T_t(void *protobetter_type, void *buffer);


#include "ECLSS_types.h"


#define STRUCT_ARS_CDRA_OPER_T_PACKED_SIZE 13

uint32_t PackARS_CDRA_OPER_t(void *buffer, void *protobetter_type);


uint32_t UnpackARS_CDRA_OPER_t(void *protobetter_type, void *buffer);


#include "ECLSS_types.h"


#define STRUCT_ARS_H2O_SEP_T_PACKED_SIZE 17

uint32_t PackARS_H2O_SEP_t(void *buffer, void *protobetter_type);


uint32_t UnpackARS_H2O_SEP_t(void *protobetter_type, void *buffer);


#include "ECLSS_types.h"


#define STRUCT_ARS_TCCS_OPER_T_PACKED_SIZE 13

uint32_t PackARS_TCCS_OPER_t(void *buffer, void *protobetter_type);


uint32_t UnpackARS_TCCS_OPER_t(void *protobetter_type, void *buffer);


#include "ECLSS_types.h"


#define STRUCT_PORT_IMV_T_PACKED_SIZE 13

uint32_t PackPORT_IMV_t(void *buffer, void *protobetter_type);


uint32_t UnpackPORT_IMV_t(void *protobetter_type, void *buffer);


#include "ECLSS_types.h"


#define STRUCT_STBD_IMV_T_PACKED_SIZE 13

uint32_t PackSTBD_IMV_t(void *buffer, void *protobetter_type);


uint32_t UnpackSTBD_IMV_t(void *protobetter_type, void *buffer);


#include "ECLSS_types.h"


#define STRUCT_STBD_IMV_FAN_T_PACKED_SIZE 13

uint32_t PackSTBD_IMV_FAN_t(void *buffer, void *protobetter_type);


uint32_t UnpackSTBD_IMV_FAN_t(void *protobetter_type, void *buffer);


#include "ECLSS_types.h"


#define STRUCT_AFT_IMV_T_PACKED_SIZE 13

uint32_t PackAFT_IMV_t(void *buffer, void *protobetter_type);


uint32_t UnpackAFT_IMV_t(void *protobetter_type, void *buffer);


#include "ECLSS_types.h"


#define STRUCT_FWD_IMV_T_PACKED_SIZE 13

uint32_t PackFWD_IMV_t(void *buffer, void *protobetter_type);


uint32_t UnpackFWD_IMV_t(void *protobetter_type, void *buffer);


#include "ECLSS_types.h"


#define STRUCT_HAB_ECLSS_ARS_CMD_PACKED_SIZE 17

uint32_t PackHAB_ECLSS_ARS_CMD(void *buffer, void *protobetter_type);


uint32_t UnpackHAB_ECLSS_ARS_CMD(void *protobetter_type, void *buffer);


#include "ECLSS_types.h"


#define STRUCT_DEPRESS_T_PACKED_SIZE 13

uint32_t PackDEPRESS_t(void *buffer, void *protobetter_type);


uint32_t UnpackDEPRESS_t(void *protobetter_type, void *buffer);


#include "ECLSS_types.h"


#define STRUCT_O2_SET_T_PACKED_SIZE 16

uint32_t PackO2_SET_t(void *buffer, void *protobetter_type);


uint32_t UnpackO2_SET_t(void *protobetter_type, void *buffer);


#include "ECLSS_types.h"


#define STRUCT_P_SET_T_PACKED_SIZE 16

uint32_t PackP_SET_t(void *buffer, void *protobetter_type);


uint32_t UnpackP_SET_t(void *protobetter_type, void *buffer);


#include "ECLSS_types.h"


#define STRUCT_REPRESS_T_PACKED_SIZE 13

uint32_t PackREPRESS_t(void *buffer, void *protobetter_type);


uint32_t UnpackREPRESS_t(void *protobetter_type, void *buffer);


#include "ECLSS_types.h"


#define STRUCT_HAB_ECLSS_PCS_CMD_PACKED_SIZE 16

uint32_t PackHAB_ECLSS_PCS_CMD(void *buffer, void *protobetter_type);


uint32_t UnpackHAB_ECLSS_PCS_CMD(void *protobetter_type, void *buffer);


#include "ECLSS_types.h"


#define STRUCT_PW_DISP_T_PACKED_SIZE 13

uint32_t PackPW_DISP_t(void *buffer, void *protobetter_type);


uint32_t UnpackPW_DISP_t(void *protobetter_type, void *buffer);


#include "ECLSS_types.h"


#define STRUCT_WW_VENT_T_PACKED_SIZE 13

uint32_t PackWW_VENT_t(void *buffer, void *protobetter_type);


uint32_t UnpackWW_VENT_t(void *protobetter_type, void *buffer);


#include "ECLSS_types.h"


#define STRUCT_HAB_ECLSS_WMS_CMD_PACKED_SIZE 13

uint32_t PackHAB_ECLSS_WMS_CMD(void *buffer, void *protobetter_type);


uint32_t UnpackHAB_ECLSS_WMS_CMD(void *protobetter_type, void *buffer);


#ifdef __cplusplus
}
#endif
#endif //__PROTOBETTER_ECLSS_H__

