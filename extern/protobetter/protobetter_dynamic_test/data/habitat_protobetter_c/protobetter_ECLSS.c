#include "protobetter_ECLSS.h"

static inline uint32_t PackHAB_ECLSS_WMS_WW_TLM(void *buffer, void *protobetter_type)
{

	HAB_ECLSS_WMS_WW_TLM *mystruct = (HAB_ECLSS_WMS_WW_TLM*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	PACK_FLOAT(&bytes[0], &mystruct->TANK_QTY);
	PACK_FLOAT(&bytes[4], &mystruct->TANK_MASS);
	PACK_FLOAT(&bytes[8], &mystruct->VENT_FLOW_RATE);
	PACK_UINT8(&bytes[12], &mystruct->VENT_POS);
	PACK_FLOAT(&bytes[13], &mystruct->CONDENSE_FLOW_RATE);
	PACK_UINT8(&bytes[17], &mystruct->VENT_CMD_FEEDBACK);

	return 18;
}


static inline uint32_t UnpackHAB_ECLSS_WMS_WW_TLM(void *protobetter_type, void *buffer)
{

	HAB_ECLSS_WMS_WW_TLM *mystruct = (HAB_ECLSS_WMS_WW_TLM*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	UNPACK_FLOAT(&mystruct->TANK_QTY, &bytes[0]);
	UNPACK_FLOAT(&mystruct->TANK_MASS, &bytes[4]);
	UNPACK_FLOAT(&mystruct->VENT_FLOW_RATE, &bytes[8]);
	UNPACK_UINT8(&mystruct->VENT_POS, &bytes[12]);
	UNPACK_FLOAT(&mystruct->CONDENSE_FLOW_RATE, &bytes[13]);
	UNPACK_UINT8(&mystruct->VENT_CMD_FEEDBACK, &bytes[17]);

	return sizeof(HAB_ECLSS_WMS_WW_TLM);
}


static inline uint32_t PackHAB_ECLSS_WMS_PW_TLM(void *buffer, void *protobetter_type)
{

	HAB_ECLSS_WMS_PW_TLM *mystruct = (HAB_ECLSS_WMS_PW_TLM*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	PACK_FLOAT(&bytes[0], &mystruct->TANK_QTY);
	PACK_FLOAT(&bytes[4], &mystruct->TANK_MASS);
	PACK_FLOAT(&bytes[8], &mystruct->DISPENSE_FLOW_RATE);
	PACK_UINT8(&bytes[12], &mystruct->DISPENSE_POS);
	PACK_UINT8(&bytes[13], &mystruct->DISPENSE_CMD_FEEDBACK);

	return 14;
}


static inline uint32_t UnpackHAB_ECLSS_WMS_PW_TLM(void *protobetter_type, void *buffer)
{

	HAB_ECLSS_WMS_PW_TLM *mystruct = (HAB_ECLSS_WMS_PW_TLM*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	UNPACK_FLOAT(&mystruct->TANK_QTY, &bytes[0]);
	UNPACK_FLOAT(&mystruct->TANK_MASS, &bytes[4]);
	UNPACK_FLOAT(&mystruct->DISPENSE_FLOW_RATE, &bytes[8]);
	UNPACK_UINT8(&mystruct->DISPENSE_POS, &bytes[12]);
	UNPACK_UINT8(&mystruct->DISPENSE_CMD_FEEDBACK, &bytes[13]);

	return sizeof(HAB_ECLSS_WMS_PW_TLM);
}


static inline uint32_t PackHAB_ECLSS_PCS_FLUID_TLM(void *buffer, void *protobetter_type)
{

	HAB_ECLSS_PCS_FLUID_TLM *mystruct = (HAB_ECLSS_PCS_FLUID_TLM*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	PACK_FLOAT(&bytes[0], &mystruct->FLOW_RATE);
	PACK_FLOAT(&bytes[4], &mystruct->REG_VALVE_POS);
	PACK_FLOAT(&bytes[8], &mystruct->REG_P);
	PACK_FLOAT(&bytes[12], &mystruct->EXIT_T);
	PACK_UINT8(&bytes[16], &mystruct->SOL_HIGH_POS);
	PACK_UINT8(&bytes[17], &mystruct->SOL_LOW_POS);
	PACK_FLOAT(&bytes[18], &mystruct->TANK_P);
	PACK_FLOAT(&bytes[22], &mystruct->TANK_QTY);

	return 26;
}


static inline uint32_t UnpackHAB_ECLSS_PCS_FLUID_TLM(void *protobetter_type, void *buffer)
{

	HAB_ECLSS_PCS_FLUID_TLM *mystruct = (HAB_ECLSS_PCS_FLUID_TLM*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	UNPACK_FLOAT(&mystruct->FLOW_RATE, &bytes[0]);
	UNPACK_FLOAT(&mystruct->REG_VALVE_POS, &bytes[4]);
	UNPACK_FLOAT(&mystruct->REG_P, &bytes[8]);
	UNPACK_FLOAT(&mystruct->EXIT_T, &bytes[12]);
	UNPACK_UINT8(&mystruct->SOL_HIGH_POS, &bytes[16]);
	UNPACK_UINT8(&mystruct->SOL_LOW_POS, &bytes[17]);
	UNPACK_FLOAT(&mystruct->TANK_P, &bytes[18]);
	UNPACK_FLOAT(&mystruct->TANK_QTY, &bytes[22]);

	return sizeof(HAB_ECLSS_PCS_FLUID_TLM);
}


static inline uint32_t PackHAB_ECLSS_PCS_CNTLR_TLM(void *buffer, void *protobetter_type)
{

	HAB_ECLSS_PCS_CNTLR_TLM *mystruct = (HAB_ECLSS_PCS_CNTLR_TLM*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	PACK_UINT32(&bytes[0], &mystruct->STATE);
	PACK_FLOAT(&bytes[4], &mystruct->O2_SETPOINT_FEEDBACK);
	PACK_FLOAT(&bytes[8], &mystruct->P_SETPOINT_FEEDBACK);

	return 12;
}


static inline uint32_t UnpackHAB_ECLSS_PCS_CNTLR_TLM(void *protobetter_type, void *buffer)
{

	HAB_ECLSS_PCS_CNTLR_TLM *mystruct = (HAB_ECLSS_PCS_CNTLR_TLM*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	UNPACK_UINT32(&mystruct->STATE, &bytes[0]);
	UNPACK_FLOAT(&mystruct->O2_SETPOINT_FEEDBACK, &bytes[4]);
	UNPACK_FLOAT(&mystruct->P_SETPOINT_FEEDBACK, &bytes[8]);

	return sizeof(HAB_ECLSS_PCS_CNTLR_TLM);
}


static inline uint32_t PackHAB_ECLSS_ARS_CDRA_CO2BED_TLM(void *buffer, void *protobetter_type)
{

	HAB_ECLSS_ARS_CDRA_CO2BED_TLM *mystruct = (HAB_ECLSS_ARS_CDRA_CO2BED_TLM*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	PACK_FLOAT(&bytes[0], &mystruct->HTR_1_T);
	PACK_FLOAT(&bytes[4], &mystruct->HTR_2_T);
	PACK_FLOAT(&bytes[8], &mystruct->AIR_EXIT_T);
	PACK_FLOAT(&bytes[12], &mystruct->H2O_EXIT_T);
	PACK_FLOAT(&bytes[16], &mystruct->PRESSURE);
	PACK_UINT8(&bytes[20], &mystruct->HTR_1_PWR);
	PACK_UINT8(&bytes[21], &mystruct->HTR_2_PWR);

	return 22;
}


static inline uint32_t UnpackHAB_ECLSS_ARS_CDRA_CO2BED_TLM(void *protobetter_type, void *buffer)
{

	HAB_ECLSS_ARS_CDRA_CO2BED_TLM *mystruct = (HAB_ECLSS_ARS_CDRA_CO2BED_TLM*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	UNPACK_FLOAT(&mystruct->HTR_1_T, &bytes[0]);
	UNPACK_FLOAT(&mystruct->HTR_2_T, &bytes[4]);
	UNPACK_FLOAT(&mystruct->AIR_EXIT_T, &bytes[8]);
	UNPACK_FLOAT(&mystruct->H2O_EXIT_T, &bytes[12]);
	UNPACK_FLOAT(&mystruct->PRESSURE, &bytes[16]);
	UNPACK_UINT8(&mystruct->HTR_1_PWR, &bytes[20]);
	UNPACK_UINT8(&mystruct->HTR_2_PWR, &bytes[21]);

	return sizeof(HAB_ECLSS_ARS_CDRA_CO2BED_TLM);
}


static inline uint32_t PackHAB_ECLSS_ARS_CDRA_TLM(void *buffer, void *protobetter_type)
{

	HAB_ECLSS_ARS_CDRA_TLM *mystruct = (HAB_ECLSS_ARS_CDRA_TLM*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	PACK_FLOAT(&bytes[0], &mystruct->AIR_INLET_T);
	PACK_FLOAT(&bytes[4], &mystruct->AIR_EXIT_T);
	PACK_FLOAT(&bytes[8], &mystruct->AIR_EXIT_PPCO2);
	PACK_FLOAT(&bytes[12], &mystruct->DES_ASV_POS);
	PACK_FLOAT(&bytes[16], &mystruct->CO2_ASV_POS);
	PACK_FLOAT(&bytes[20], &mystruct->CO2_VENT_POS);
	PACK_FLOAT(&bytes[24], &mystruct->ARS_FAN_AIR_INLET_T);
	PACK_FLOAT(&bytes[28], &mystruct->ARS_FAN_T);
	PACK_FLOAT(&bytes[32], &mystruct->ARS_FAN_N);
	PACK_FLOAT(&bytes[36], &mystruct->ARS_FAN_I);
	PACK_FLOAT(&bytes[40], &mystruct->ARS_FAN_DP);
	PackHAB_ECLSS_ARS_CDRA_CO2BED_TLM(&bytes[44], &mystruct->CO2_BED_A);
	PackHAB_ECLSS_ARS_CDRA_CO2BED_TLM(&bytes[66], &mystruct->CO2_BED_B);
	PACK_FLOAT(&bytes[88], &mystruct->AIR_SAVE_PUMP_T);
	PACK_FLOAT(&bytes[92], &mystruct->AIR_SAVE_PUMP_N);
	PACK_FLOAT(&bytes[96], &mystruct->AIR_SAVE_PUMP_I);
	PACK_FLOAT(&bytes[100], &mystruct->DES_INLET_T);
	PACK_UINT8(&bytes[104], &mystruct->POWER_ON);
	PACK_UINT32(&bytes[105], &mystruct->ACTIVE_SEGMENT);
	PACK_UINT8(&bytes[109], &mystruct->OPERATE_CMD_FEEDBACK);

	return 110;
}


static inline uint32_t UnpackHAB_ECLSS_ARS_CDRA_TLM(void *protobetter_type, void *buffer)
{

	HAB_ECLSS_ARS_CDRA_TLM *mystruct = (HAB_ECLSS_ARS_CDRA_TLM*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	UNPACK_FLOAT(&mystruct->AIR_INLET_T, &bytes[0]);
	UNPACK_FLOAT(&mystruct->AIR_EXIT_T, &bytes[4]);
	UNPACK_FLOAT(&mystruct->AIR_EXIT_PPCO2, &bytes[8]);
	UNPACK_FLOAT(&mystruct->DES_ASV_POS, &bytes[12]);
	UNPACK_FLOAT(&mystruct->CO2_ASV_POS, &bytes[16]);
	UNPACK_FLOAT(&mystruct->CO2_VENT_POS, &bytes[20]);
	UNPACK_FLOAT(&mystruct->ARS_FAN_AIR_INLET_T, &bytes[24]);
	UNPACK_FLOAT(&mystruct->ARS_FAN_T, &bytes[28]);
	UNPACK_FLOAT(&mystruct->ARS_FAN_N, &bytes[32]);
	UNPACK_FLOAT(&mystruct->ARS_FAN_I, &bytes[36]);
	UNPACK_FLOAT(&mystruct->ARS_FAN_DP, &bytes[40]);
	UnpackHAB_ECLSS_ARS_CDRA_CO2BED_TLM(&mystruct->CO2_BED_A, &bytes[44]);
	UnpackHAB_ECLSS_ARS_CDRA_CO2BED_TLM(&mystruct->CO2_BED_B, &bytes[66]);
	UNPACK_FLOAT(&mystruct->AIR_SAVE_PUMP_T, &bytes[88]);
	UNPACK_FLOAT(&mystruct->AIR_SAVE_PUMP_N, &bytes[92]);
	UNPACK_FLOAT(&mystruct->AIR_SAVE_PUMP_I, &bytes[96]);
	UNPACK_FLOAT(&mystruct->DES_INLET_T, &bytes[100]);
	UNPACK_UINT8(&mystruct->POWER_ON, &bytes[104]);
	UNPACK_UINT32(&mystruct->ACTIVE_SEGMENT, &bytes[105]);
	UNPACK_UINT8(&mystruct->OPERATE_CMD_FEEDBACK, &bytes[109]);

	return sizeof(HAB_ECLSS_ARS_CDRA_TLM);
}


static inline uint32_t PackHAB_ECLSS_ARS_TCCS_TLM(void *buffer, void *protobetter_type)
{

	HAB_ECLSS_ARS_TCCS_TLM *mystruct = (HAB_ECLSS_ARS_TCCS_TLM*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	PACK_FLOAT(&bytes[0], &mystruct->BLOWER_T);
	PACK_FLOAT(&bytes[4], &mystruct->BLOWER_N);
	PACK_FLOAT(&bytes[8], &mystruct->EXIT_T_1);
	PACK_FLOAT(&bytes[12], &mystruct->EXIT_T_2);
	PACK_FLOAT(&bytes[16], &mystruct->FLOW_METER);
	PACK_UINT8(&bytes[20], &mystruct->HEATER_ON);
	PACK_FLOAT(&bytes[21], &mystruct->HTCO_T_1);
	PACK_FLOAT(&bytes[25], &mystruct->HTCO_T_2);
	PACK_UINT8(&bytes[29], &mystruct->POWER_ON);
	PACK_UINT8(&bytes[30], &mystruct->OPERATE_CMD_FEEDBACK);

	return 31;
}


static inline uint32_t UnpackHAB_ECLSS_ARS_TCCS_TLM(void *protobetter_type, void *buffer)
{

	HAB_ECLSS_ARS_TCCS_TLM *mystruct = (HAB_ECLSS_ARS_TCCS_TLM*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	UNPACK_FLOAT(&mystruct->BLOWER_T, &bytes[0]);
	UNPACK_FLOAT(&mystruct->BLOWER_N, &bytes[4]);
	UNPACK_FLOAT(&mystruct->EXIT_T_1, &bytes[8]);
	UNPACK_FLOAT(&mystruct->EXIT_T_2, &bytes[12]);
	UNPACK_FLOAT(&mystruct->FLOW_METER, &bytes[16]);
	UNPACK_UINT8(&mystruct->HEATER_ON, &bytes[20]);
	UNPACK_FLOAT(&mystruct->HTCO_T_1, &bytes[21]);
	UNPACK_FLOAT(&mystruct->HTCO_T_2, &bytes[25]);
	UNPACK_UINT8(&mystruct->POWER_ON, &bytes[29]);
	UNPACK_UINT8(&mystruct->OPERATE_CMD_FEEDBACK, &bytes[30]);

	return sizeof(HAB_ECLSS_ARS_TCCS_TLM);
}


static inline uint32_t PackHAB_ECLSS_ARS_CPM_TLM(void *buffer, void *protobetter_type)
{

	HAB_ECLSS_ARS_CPM_TLM *mystruct = (HAB_ECLSS_ARS_CPM_TLM*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	PACK_FLOAT(&bytes[0], &mystruct->PERCENT_O2);
	PACK_FLOAT(&bytes[4], &mystruct->PPM_HCN);
	PACK_FLOAT(&bytes[8], &mystruct->PPM_HCL);
	PACK_FLOAT(&bytes[12], &mystruct->PPM_CO);
	PACK_UINT8(&bytes[16], &mystruct->SMOKE_DETECTED);

	return 17;
}


static inline uint32_t UnpackHAB_ECLSS_ARS_CPM_TLM(void *protobetter_type, void *buffer)
{

	HAB_ECLSS_ARS_CPM_TLM *mystruct = (HAB_ECLSS_ARS_CPM_TLM*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	UNPACK_FLOAT(&mystruct->PERCENT_O2, &bytes[0]);
	UNPACK_FLOAT(&mystruct->PPM_HCN, &bytes[4]);
	UNPACK_FLOAT(&mystruct->PPM_HCL, &bytes[8]);
	UNPACK_FLOAT(&mystruct->PPM_CO, &bytes[12]);
	UNPACK_UINT8(&mystruct->SMOKE_DETECTED, &bytes[16]);

	return sizeof(HAB_ECLSS_ARS_CPM_TLM);
}


static inline uint32_t PackHAB_ECLSS_ARS_SAM_TLM(void *buffer, void *protobetter_type)
{

	HAB_ECLSS_ARS_SAM_TLM *mystruct = (HAB_ECLSS_ARS_SAM_TLM*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	PACK_FLOAT(&bytes[0], &mystruct->PRESSURE);
	PACK_FLOAT(&bytes[4], &mystruct->TEMPERATURE);
	PACK_FLOAT(&bytes[8], &mystruct->PP_N2);
	PACK_FLOAT(&bytes[12], &mystruct->PP_O2);
	PACK_FLOAT(&bytes[16], &mystruct->PP_CO2);
	PACK_FLOAT(&bytes[20], &mystruct->HUMIDITY);
	PACK_FLOAT(&bytes[24], &mystruct->DEWPOINT);
	PACK_FLOAT(&bytes[28], &mystruct->PPM_CH4);
	PACK_FLOAT(&bytes[32], &mystruct->PPM_H2);

	return 36;
}


static inline uint32_t UnpackHAB_ECLSS_ARS_SAM_TLM(void *protobetter_type, void *buffer)
{

	HAB_ECLSS_ARS_SAM_TLM *mystruct = (HAB_ECLSS_ARS_SAM_TLM*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	UNPACK_FLOAT(&mystruct->PRESSURE, &bytes[0]);
	UNPACK_FLOAT(&mystruct->TEMPERATURE, &bytes[4]);
	UNPACK_FLOAT(&mystruct->PP_N2, &bytes[8]);
	UNPACK_FLOAT(&mystruct->PP_O2, &bytes[12]);
	UNPACK_FLOAT(&mystruct->PP_CO2, &bytes[16]);
	UNPACK_FLOAT(&mystruct->HUMIDITY, &bytes[20]);
	UNPACK_FLOAT(&mystruct->DEWPOINT, &bytes[24]);
	UNPACK_FLOAT(&mystruct->PPM_CH4, &bytes[28]);
	UNPACK_FLOAT(&mystruct->PPM_H2, &bytes[32]);

	return sizeof(HAB_ECLSS_ARS_SAM_TLM);
}


static inline uint32_t PackECLSS_PPA_tlm_payload_t(void *buffer, void *protobetter_type)
{

	ECLSS_PPA_tlm_payload_t *mystruct = (ECLSS_PPA_tlm_payload_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	PACK_FLOAT(&bytes[0], &mystruct->GCA08_Hydrogen);
	PACK_FLOAT(&bytes[4], &mystruct->GCA09_Oxygen);
	PACK_FLOAT(&bytes[8], &mystruct->GCA10_Nitrogen);
	PACK_FLOAT(&bytes[12], &mystruct->GCA11_Carbon_Monoxide);
	PACK_FLOAT(&bytes[16], &mystruct->GCA12_Methane);
	PACK_FLOAT(&bytes[20], &mystruct->GCC13_CO2);
	PACK_FLOAT(&bytes[24], &mystruct->GCC14_Methane);
	PACK_FLOAT(&bytes[28], &mystruct->GCC15_Ethylene);
	PACK_FLOAT(&bytes[32], &mystruct->GCC16_Acetylene);
	PACK_UINT8(&bytes[36], &mystruct->PPASVC132);
	PACK_UINT8(&bytes[37], &mystruct->PPASVC133);
	PACK_UINT8(&bytes[38], &mystruct->PPASVC134);
	PACK_UINT8(&bytes[39], &mystruct->SABSV_220);
	PACK_UINT8(&bytes[40], &mystruct->SABSV_221);
	PACK_FLOAT(&bytes[41], &mystruct->PPA_CH4_CO2_cmd);
	PACK_FLOAT(&bytes[45], &mystruct->PPA_H2_main_cmd);
	PACK_FLOAT(&bytes[49], &mystruct->PPA_H2_viewport_cmd);
	PACK_FLOAT(&bytes[53], &mystruct->PPA_FC104);
	PACK_FLOAT(&bytes[57], &mystruct->PPA_FC105);
	PACK_FLOAT(&bytes[61], &mystruct->PPA_FC106);
	PACK_FLOAT(&bytes[65], &mystruct->PPA_FT104);
	PACK_FLOAT(&bytes[69], &mystruct->PPA_FT105);
	PACK_FLOAT(&bytes[73], &mystruct->PPA_FT106);
	PACK_FLOAT(&bytes[77], &mystruct->PPA_reactor_P_cmd);
	PACK_FLOAT(&bytes[81], &mystruct->PPA_PT110);
	PACK_FLOAT(&bytes[85], &mystruct->PPA_P115);
	PACK_FLOAT(&bytes[89], &mystruct->PPA_P116);
	PACK_UINT8(&bytes[93], &mystruct->PPA_CO2_regen_cmd);
	PACK_UINT8(&bytes[94], &mystruct->PPAuWstart);
	PACK_FLOAT(&bytes[95], &mystruct->PPA_CO2_plasma_uW_cmd);
	PACK_FLOAT(&bytes[99], &mystruct->PPA_MeP_uW_cmd);
	PACK_FLOAT(&bytes[103], &mystruct->PPA_Input_Power);
	PACK_FLOAT(&bytes[107], &mystruct->PPA_Refl_Power);
	PACK_UINT32(&bytes[111], &mystruct->PPAstub1posn);
	PACK_UINT32(&bytes[115], &mystruct->PPAstub2posn);
	PACK_UINT32(&bytes[119], &mystruct->PPAstub3posn);
	PACK_UINT8(&bytes[123], &mystruct->PPAuWabort);
	PACK_FLOAT(&bytes[124], &mystruct->PPA_T120);
	PACK_FLOAT(&bytes[128], &mystruct->PPA_T121);
	PACK_FLOAT(&bytes[132], &mystruct->PPA_T122);
	PACK_FLOAT(&bytes[136], &mystruct->PPA_T123);
	PACK_FLOAT(&bytes[140], &mystruct->PPA_T124);
	PACK_FLOAT(&bytes[144], &mystruct->PPA_T125);
	PACK_FLOAT(&bytes[148], &mystruct->PPA_T126);
	PACK_UINT8(&bytes[152], &mystruct->PPA_LEL_Alarm_State);
	PACK_UINT8(&bytes[153], &mystruct->PPA_Over_Pressure_Temp_State);
	PACK_UINT8(&bytes[154], &mystruct->CRA_SVC007);
	PACK_UINT8(&bytes[155], &mystruct->CRA_SVC102);
	PACK_UINT8(&bytes[156], &mystruct->CRA_SVO203);
	PACK_FLOAT(&bytes[157], &mystruct->CRA_P002);
	PACK_FLOAT(&bytes[161], &mystruct->CRA_P106);
	PACK_FLOAT(&bytes[165], &mystruct->CRA_P206);
	PACK_FLOAT(&bytes[169], &mystruct->CRA_MFC005_command);
	PACK_FLOAT(&bytes[173], &mystruct->CRA_MFC005_flow);
	PACK_FLOAT(&bytes[177], &mystruct->CRA_MFC103_command);
	PACK_FLOAT(&bytes[181], &mystruct->CRA_MFC103_flow);
	PACK_FLOAT(&bytes[185], &mystruct->CRA_Molar_Ratio);
	PACK_FLOAT(&bytes[189], &mystruct->CRA_P006_1);
	PACK_FLOAT(&bytes[193], &mystruct->CRA_P006_2);
	PACK_UINT8(&bytes[197], &mystruct->CRA_H402_1);
	PACK_UINT8(&bytes[198], &mystruct->CRA_H402_2);
	PACK_UINT8(&bytes[199], &mystruct->CRA_FAN503);
	PACK_FLOAT(&bytes[200], &mystruct->CRA_T403_1);
	PACK_FLOAT(&bytes[204], &mystruct->CRA_T403_2);
	PACK_FLOAT(&bytes[208], &mystruct->CRA_T404_1);
	PACK_FLOAT(&bytes[212], &mystruct->CRA_T404_2);
	PACK_FLOAT(&bytes[216], &mystruct->CRA_P601);
	PACK_FLOAT(&bytes[220], &mystruct->CRA_DP405);
	PACK_UINT8(&bytes[224], &mystruct->CRA_FAN502);
	PACK_FLOAT(&bytes[225], &mystruct->CRA_T407_1);
	PACK_FLOAT(&bytes[229], &mystruct->CRA_T407_2);
	PACK_FLOAT(&bytes[233], &mystruct->CRA_DP409);
	PACK_UINT8(&bytes[237], &mystruct->CRA_PUMP301);
	PACK_UINT8(&bytes[238], &mystruct->CRA_SVO608);
	PACK_UINT8(&bytes[239], &mystruct->CRA_SVO604);
	PACK_UINT8(&bytes[240], &mystruct->CRA_SVO610);
	PACK_FLOAT(&bytes[241], &mystruct->CRA_CG411);
	PACK_FLOAT(&bytes[245], &mystruct->CRA_CG412);
	PACK_FLOAT(&bytes[249], &mystruct->FT013);
	PACK_FLOAT(&bytes[253], &mystruct->PS704ampPV);
	PACK_FLOAT(&bytes[257], &mystruct->PS704voltPV);

	return 261;
}


static inline uint32_t UnpackECLSS_PPA_tlm_payload_t(void *protobetter_type, void *buffer)
{

	ECLSS_PPA_tlm_payload_t *mystruct = (ECLSS_PPA_tlm_payload_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	UNPACK_FLOAT(&mystruct->GCA08_Hydrogen, &bytes[0]);
	UNPACK_FLOAT(&mystruct->GCA09_Oxygen, &bytes[4]);
	UNPACK_FLOAT(&mystruct->GCA10_Nitrogen, &bytes[8]);
	UNPACK_FLOAT(&mystruct->GCA11_Carbon_Monoxide, &bytes[12]);
	UNPACK_FLOAT(&mystruct->GCA12_Methane, &bytes[16]);
	UNPACK_FLOAT(&mystruct->GCC13_CO2, &bytes[20]);
	UNPACK_FLOAT(&mystruct->GCC14_Methane, &bytes[24]);
	UNPACK_FLOAT(&mystruct->GCC15_Ethylene, &bytes[28]);
	UNPACK_FLOAT(&mystruct->GCC16_Acetylene, &bytes[32]);
	UNPACK_UINT8(&mystruct->PPASVC132, &bytes[36]);
	UNPACK_UINT8(&mystruct->PPASVC133, &bytes[37]);
	UNPACK_UINT8(&mystruct->PPASVC134, &bytes[38]);
	UNPACK_UINT8(&mystruct->SABSV_220, &bytes[39]);
	UNPACK_UINT8(&mystruct->SABSV_221, &bytes[40]);
	UNPACK_FLOAT(&mystruct->PPA_CH4_CO2_cmd, &bytes[41]);
	UNPACK_FLOAT(&mystruct->PPA_H2_main_cmd, &bytes[45]);
	UNPACK_FLOAT(&mystruct->PPA_H2_viewport_cmd, &bytes[49]);
	UNPACK_FLOAT(&mystruct->PPA_FC104, &bytes[53]);
	UNPACK_FLOAT(&mystruct->PPA_FC105, &bytes[57]);
	UNPACK_FLOAT(&mystruct->PPA_FC106, &bytes[61]);
	UNPACK_FLOAT(&mystruct->PPA_FT104, &bytes[65]);
	UNPACK_FLOAT(&mystruct->PPA_FT105, &bytes[69]);
	UNPACK_FLOAT(&mystruct->PPA_FT106, &bytes[73]);
	UNPACK_FLOAT(&mystruct->PPA_reactor_P_cmd, &bytes[77]);
	UNPACK_FLOAT(&mystruct->PPA_PT110, &bytes[81]);
	UNPACK_FLOAT(&mystruct->PPA_P115, &bytes[85]);
	UNPACK_FLOAT(&mystruct->PPA_P116, &bytes[89]);
	UNPACK_UINT8(&mystruct->PPA_CO2_regen_cmd, &bytes[93]);
	UNPACK_UINT8(&mystruct->PPAuWstart, &bytes[94]);
	UNPACK_FLOAT(&mystruct->PPA_CO2_plasma_uW_cmd, &bytes[95]);
	UNPACK_FLOAT(&mystruct->PPA_MeP_uW_cmd, &bytes[99]);
	UNPACK_FLOAT(&mystruct->PPA_Input_Power, &bytes[103]);
	UNPACK_FLOAT(&mystruct->PPA_Refl_Power, &bytes[107]);
	UNPACK_UINT32(&mystruct->PPAstub1posn, &bytes[111]);
	UNPACK_UINT32(&mystruct->PPAstub2posn, &bytes[115]);
	UNPACK_UINT32(&mystruct->PPAstub3posn, &bytes[119]);
	UNPACK_UINT8(&mystruct->PPAuWabort, &bytes[123]);
	UNPACK_FLOAT(&mystruct->PPA_T120, &bytes[124]);
	UNPACK_FLOAT(&mystruct->PPA_T121, &bytes[128]);
	UNPACK_FLOAT(&mystruct->PPA_T122, &bytes[132]);
	UNPACK_FLOAT(&mystruct->PPA_T123, &bytes[136]);
	UNPACK_FLOAT(&mystruct->PPA_T124, &bytes[140]);
	UNPACK_FLOAT(&mystruct->PPA_T125, &bytes[144]);
	UNPACK_FLOAT(&mystruct->PPA_T126, &bytes[148]);
	UNPACK_UINT8(&mystruct->PPA_LEL_Alarm_State, &bytes[152]);
	UNPACK_UINT8(&mystruct->PPA_Over_Pressure_Temp_State, &bytes[153]);
	UNPACK_UINT8(&mystruct->CRA_SVC007, &bytes[154]);
	UNPACK_UINT8(&mystruct->CRA_SVC102, &bytes[155]);
	UNPACK_UINT8(&mystruct->CRA_SVO203, &bytes[156]);
	UNPACK_FLOAT(&mystruct->CRA_P002, &bytes[157]);
	UNPACK_FLOAT(&mystruct->CRA_P106, &bytes[161]);
	UNPACK_FLOAT(&mystruct->CRA_P206, &bytes[165]);
	UNPACK_FLOAT(&mystruct->CRA_MFC005_command, &bytes[169]);
	UNPACK_FLOAT(&mystruct->CRA_MFC005_flow, &bytes[173]);
	UNPACK_FLOAT(&mystruct->CRA_MFC103_command, &bytes[177]);
	UNPACK_FLOAT(&mystruct->CRA_MFC103_flow, &bytes[181]);
	UNPACK_FLOAT(&mystruct->CRA_Molar_Ratio, &bytes[185]);
	UNPACK_FLOAT(&mystruct->CRA_P006_1, &bytes[189]);
	UNPACK_FLOAT(&mystruct->CRA_P006_2, &bytes[193]);
	UNPACK_UINT8(&mystruct->CRA_H402_1, &bytes[197]);
	UNPACK_UINT8(&mystruct->CRA_H402_2, &bytes[198]);
	UNPACK_UINT8(&mystruct->CRA_FAN503, &bytes[199]);
	UNPACK_FLOAT(&mystruct->CRA_T403_1, &bytes[200]);
	UNPACK_FLOAT(&mystruct->CRA_T403_2, &bytes[204]);
	UNPACK_FLOAT(&mystruct->CRA_T404_1, &bytes[208]);
	UNPACK_FLOAT(&mystruct->CRA_T404_2, &bytes[212]);
	UNPACK_FLOAT(&mystruct->CRA_P601, &bytes[216]);
	UNPACK_FLOAT(&mystruct->CRA_DP405, &bytes[220]);
	UNPACK_UINT8(&mystruct->CRA_FAN502, &bytes[224]);
	UNPACK_FLOAT(&mystruct->CRA_T407_1, &bytes[225]);
	UNPACK_FLOAT(&mystruct->CRA_T407_2, &bytes[229]);
	UNPACK_FLOAT(&mystruct->CRA_DP409, &bytes[233]);
	UNPACK_UINT8(&mystruct->CRA_PUMP301, &bytes[237]);
	UNPACK_UINT8(&mystruct->CRA_SVO608, &bytes[238]);
	UNPACK_UINT8(&mystruct->CRA_SVO604, &bytes[239]);
	UNPACK_UINT8(&mystruct->CRA_SVO610, &bytes[240]);
	UNPACK_FLOAT(&mystruct->CRA_CG411, &bytes[241]);
	UNPACK_FLOAT(&mystruct->CRA_CG412, &bytes[245]);
	UNPACK_FLOAT(&mystruct->FT013, &bytes[249]);
	UNPACK_FLOAT(&mystruct->PS704ampPV, &bytes[253]);
	UNPACK_FLOAT(&mystruct->PS704voltPV, &bytes[257]);

	return sizeof(ECLSS_PPA_tlm_payload_t);
}


uint32_t PackECLSS_PPA_tlm_packet_t(void *buffer, void *protobetter_type)
{

	ECLSS_PPA_tlm_packet_t *mystruct = (ECLSS_PPA_tlm_packet_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->cfsHeader, 16);
	PackECLSS_PPA_tlm_payload_t(&bytes[16], &mystruct->payload);

	return 277;
}


uint32_t UnpackECLSS_PPA_tlm_packet_t(void *protobetter_type, void *buffer)
{

	ECLSS_PPA_tlm_packet_t *mystruct = (ECLSS_PPA_tlm_packet_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->cfsHeader, &bytes[0], 16);
	UnpackECLSS_PPA_tlm_payload_t(&mystruct->payload, &bytes[16]);

	return sizeof(ECLSS_PPA_tlm_packet_t);
}


uint32_t PackHAB_ECLSS_ARS_TLM(void *buffer, void *protobetter_type)
{

	HAB_ECLSS_ARS_TLM *mystruct = (HAB_ECLSS_ARS_TLM*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->cfsHeader, 16);
	PackHAB_ECLSS_ARS_SAM_TLM(&bytes[16], &mystruct->SAM);
	PackHAB_ECLSS_ARS_CPM_TLM(&bytes[52], &mystruct->CPM);
	PackHAB_ECLSS_ARS_TCCS_TLM(&bytes[69], &mystruct->TCCS);
	PackHAB_ECLSS_ARS_CDRA_TLM(&bytes[100], &mystruct->CDRA);
	PACK_FLOAT(&bytes[210], &mystruct->CAB_FAN_DP);
	PACK_FLOAT(&bytes[214], &mystruct->CAB_FAN_T);
	PACK_FLOAT(&bytes[218], &mystruct->CAB_FAN_N);
	PACK_FLOAT(&bytes[222], &mystruct->CAB_FAN_I);
	PACK_FLOAT(&bytes[226], &mystruct->H2O_SEP_N);
	PACK_FLOAT(&bytes[230], &mystruct->H2O_SEP_P);
	PACK_UINT8(&bytes[234], &mystruct->H2O_SEP_LIQ);
	PACK_FLOAT(&bytes[235], &mystruct->INLET_T);
	PACK_FLOAT(&bytes[239], &mystruct->CHX_AIR_INLET_T);
	PACK_FLOAT(&bytes[243], &mystruct->CHX_AIR_EXIT_T);
	PACK_UINT8(&bytes[247], &mystruct->CHX_AIR_EXIT_LIQ);
	PACK_FLOAT(&bytes[248], &mystruct->CHX_H2O_INLET_T);
	PACK_FLOAT(&bytes[252], &mystruct->CHX_H2O_EXIT_T);
	PACK_FLOAT(&bytes[256], &mystruct->CHX_TCV_POS);
	PACK_FLOAT(&bytes[260], &mystruct->TCCV_POS);
	PACK_UINT8(&bytes[264], &mystruct->PORT_IMV_POS);
	PACK_UINT8(&bytes[265], &mystruct->STBD_IMV_POS);
	PACK_FLOAT(&bytes[266], &mystruct->STBD_IMV_FAN_N);
	PACK_UINT8(&bytes[270], &mystruct->AFT_IMV_POS);
	PACK_UINT8(&bytes[271], &mystruct->FWD_IMV_POS);
	PACK_UINT8(&bytes[272], &mystruct->CAB_FAN_ENA_CMD_FEEDBACK);
	PACK_FLOAT(&bytes[273], &mystruct->CAB_FAN_SPEED_CMD_FEEDBACK);
	PACK_UINT8(&bytes[277], &mystruct->H2O_SEP_ENA_CMD_FEEDBACK);
	PACK_FLOAT(&bytes[278], &mystruct->H2O_SEP_SPEED_CMD_FEEDBACK);
	PACK_FLOAT(&bytes[282], &mystruct->CAB_T_SETPOINT_CMD_FEEDBACK);
	PACK_UINT8(&bytes[286], &mystruct->PORT_IMV_POS_CMD_FEEDBACK);
	PACK_UINT8(&bytes[287], &mystruct->STBD_IMV_POS_CMD_FEEDBACK);
	PACK_UINT8(&bytes[288], &mystruct->STBD_IMV_FAN_ENA_CMD_FEEDBACK);
	PACK_UINT8(&bytes[289], &mystruct->AFT_IMV_POS_CMD_FEEDBACK);
	PACK_UINT8(&bytes[290], &mystruct->FWD_IMV_POS_CMD_FEEDBACK);

	return 291;
}


uint32_t UnpackHAB_ECLSS_ARS_TLM(void *protobetter_type, void *buffer)
{

	HAB_ECLSS_ARS_TLM *mystruct = (HAB_ECLSS_ARS_TLM*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->cfsHeader, &bytes[0], 16);
	UnpackHAB_ECLSS_ARS_SAM_TLM(&mystruct->SAM, &bytes[16]);
	UnpackHAB_ECLSS_ARS_CPM_TLM(&mystruct->CPM, &bytes[52]);
	UnpackHAB_ECLSS_ARS_TCCS_TLM(&mystruct->TCCS, &bytes[69]);
	UnpackHAB_ECLSS_ARS_CDRA_TLM(&mystruct->CDRA, &bytes[100]);
	UNPACK_FLOAT(&mystruct->CAB_FAN_DP, &bytes[210]);
	UNPACK_FLOAT(&mystruct->CAB_FAN_T, &bytes[214]);
	UNPACK_FLOAT(&mystruct->CAB_FAN_N, &bytes[218]);
	UNPACK_FLOAT(&mystruct->CAB_FAN_I, &bytes[222]);
	UNPACK_FLOAT(&mystruct->H2O_SEP_N, &bytes[226]);
	UNPACK_FLOAT(&mystruct->H2O_SEP_P, &bytes[230]);
	UNPACK_UINT8(&mystruct->H2O_SEP_LIQ, &bytes[234]);
	UNPACK_FLOAT(&mystruct->INLET_T, &bytes[235]);
	UNPACK_FLOAT(&mystruct->CHX_AIR_INLET_T, &bytes[239]);
	UNPACK_FLOAT(&mystruct->CHX_AIR_EXIT_T, &bytes[243]);
	UNPACK_UINT8(&mystruct->CHX_AIR_EXIT_LIQ, &bytes[247]);
	UNPACK_FLOAT(&mystruct->CHX_H2O_INLET_T, &bytes[248]);
	UNPACK_FLOAT(&mystruct->CHX_H2O_EXIT_T, &bytes[252]);
	UNPACK_FLOAT(&mystruct->CHX_TCV_POS, &bytes[256]);
	UNPACK_FLOAT(&mystruct->TCCV_POS, &bytes[260]);
	UNPACK_UINT8(&mystruct->PORT_IMV_POS, &bytes[264]);
	UNPACK_UINT8(&mystruct->STBD_IMV_POS, &bytes[265]);
	UNPACK_FLOAT(&mystruct->STBD_IMV_FAN_N, &bytes[266]);
	UNPACK_UINT8(&mystruct->AFT_IMV_POS, &bytes[270]);
	UNPACK_UINT8(&mystruct->FWD_IMV_POS, &bytes[271]);
	UNPACK_UINT8(&mystruct->CAB_FAN_ENA_CMD_FEEDBACK, &bytes[272]);
	UNPACK_FLOAT(&mystruct->CAB_FAN_SPEED_CMD_FEEDBACK, &bytes[273]);
	UNPACK_UINT8(&mystruct->H2O_SEP_ENA_CMD_FEEDBACK, &bytes[277]);
	UNPACK_FLOAT(&mystruct->H2O_SEP_SPEED_CMD_FEEDBACK, &bytes[278]);
	UNPACK_FLOAT(&mystruct->CAB_T_SETPOINT_CMD_FEEDBACK, &bytes[282]);
	UNPACK_UINT8(&mystruct->PORT_IMV_POS_CMD_FEEDBACK, &bytes[286]);
	UNPACK_UINT8(&mystruct->STBD_IMV_POS_CMD_FEEDBACK, &bytes[287]);
	UNPACK_UINT8(&mystruct->STBD_IMV_FAN_ENA_CMD_FEEDBACK, &bytes[288]);
	UNPACK_UINT8(&mystruct->AFT_IMV_POS_CMD_FEEDBACK, &bytes[289]);
	UNPACK_UINT8(&mystruct->FWD_IMV_POS_CMD_FEEDBACK, &bytes[290]);

	return sizeof(HAB_ECLSS_ARS_TLM);
}


uint32_t PackHAB_ECLSS_PCS_TLM(void *buffer, void *protobetter_type)
{

	HAB_ECLSS_PCS_TLM *mystruct = (HAB_ECLSS_PCS_TLM*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->cfsHeader, 16);
	PackHAB_ECLSS_PCS_CNTLR_TLM(&bytes[16], &mystruct->CONTROLLER);
	PackHAB_ECLSS_PCS_FLUID_TLM(&bytes[28], &mystruct->N2);
	PackHAB_ECLSS_PCS_FLUID_TLM(&bytes[54], &mystruct->O2);
	PACK_FLOAT(&bytes[80], &mystruct->VENT_FLOW_RATE);
	PACK_UINT8(&bytes[84], &mystruct->VENT_POS);

	return 85;
}


uint32_t UnpackHAB_ECLSS_PCS_TLM(void *protobetter_type, void *buffer)
{

	HAB_ECLSS_PCS_TLM *mystruct = (HAB_ECLSS_PCS_TLM*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->cfsHeader, &bytes[0], 16);
	UnpackHAB_ECLSS_PCS_CNTLR_TLM(&mystruct->CONTROLLER, &bytes[16]);
	UnpackHAB_ECLSS_PCS_FLUID_TLM(&mystruct->N2, &bytes[28]);
	UnpackHAB_ECLSS_PCS_FLUID_TLM(&mystruct->O2, &bytes[54]);
	UNPACK_FLOAT(&mystruct->VENT_FLOW_RATE, &bytes[80]);
	UNPACK_UINT8(&mystruct->VENT_POS, &bytes[84]);

	return sizeof(HAB_ECLSS_PCS_TLM);
}


uint32_t PackHAB_ECLSS_WMS_TLM(void *buffer, void *protobetter_type)
{

	HAB_ECLSS_WMS_TLM *mystruct = (HAB_ECLSS_WMS_TLM*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->cfsHeader, 16);
	PackHAB_ECLSS_WMS_PW_TLM(&bytes[16], &mystruct->POTABLE_WATER);
	PackHAB_ECLSS_WMS_WW_TLM(&bytes[30], &mystruct->WASTE_WATER);

	return 48;
}


uint32_t UnpackHAB_ECLSS_WMS_TLM(void *protobetter_type, void *buffer)
{

	HAB_ECLSS_WMS_TLM *mystruct = (HAB_ECLSS_WMS_TLM*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->cfsHeader, &bytes[0], 16);
	UnpackHAB_ECLSS_WMS_PW_TLM(&mystruct->POTABLE_WATER, &bytes[16]);
	UnpackHAB_ECLSS_WMS_WW_TLM(&mystruct->WASTE_WATER, &bytes[30]);

	return sizeof(HAB_ECLSS_WMS_TLM);
}


uint32_t PackARS_CAB_FAN_t(void *buffer, void *protobetter_type)
{

	ARS_CAB_FAN_t *mystruct = (ARS_CAB_FAN_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->PARAM_1_ENABLE);
	PACK_FLOAT(&bytes[13], &mystruct->PARAM_2_SPEED);

	return 17;
}


uint32_t UnpackARS_CAB_FAN_t(void *protobetter_type, void *buffer)
{

	ARS_CAB_FAN_t *mystruct = (ARS_CAB_FAN_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->PARAM_1_ENABLE, &bytes[12]);
	UNPACK_FLOAT(&mystruct->PARAM_2_SPEED, &bytes[13]);

	return sizeof(ARS_CAB_FAN_t);
}


uint32_t PackARS_CAB_T_t(void *buffer, void *protobetter_type)
{

	ARS_CAB_T_t *mystruct = (ARS_CAB_T_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_FLOAT(&bytes[12], &mystruct->PARAM_1_SETPOINT);

	return 16;
}


uint32_t UnpackARS_CAB_T_t(void *protobetter_type, void *buffer)
{

	ARS_CAB_T_t *mystruct = (ARS_CAB_T_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_FLOAT(&mystruct->PARAM_1_SETPOINT, &bytes[12]);

	return sizeof(ARS_CAB_T_t);
}


uint32_t PackARS_CDRA_OPER_t(void *buffer, void *protobetter_type)
{

	ARS_CDRA_OPER_t *mystruct = (ARS_CDRA_OPER_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->PARAM_1_OPERATE);

	return 13;
}


uint32_t UnpackARS_CDRA_OPER_t(void *protobetter_type, void *buffer)
{

	ARS_CDRA_OPER_t *mystruct = (ARS_CDRA_OPER_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->PARAM_1_OPERATE, &bytes[12]);

	return sizeof(ARS_CDRA_OPER_t);
}


uint32_t PackARS_H2O_SEP_t(void *buffer, void *protobetter_type)
{

	ARS_H2O_SEP_t *mystruct = (ARS_H2O_SEP_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->PARAM_1_ENABLE);
	PACK_FLOAT(&bytes[13], &mystruct->PARAM_2_SPEED);

	return 17;
}


uint32_t UnpackARS_H2O_SEP_t(void *protobetter_type, void *buffer)
{

	ARS_H2O_SEP_t *mystruct = (ARS_H2O_SEP_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->PARAM_1_ENABLE, &bytes[12]);
	UNPACK_FLOAT(&mystruct->PARAM_2_SPEED, &bytes[13]);

	return sizeof(ARS_H2O_SEP_t);
}


uint32_t PackARS_TCCS_OPER_t(void *buffer, void *protobetter_type)
{

	ARS_TCCS_OPER_t *mystruct = (ARS_TCCS_OPER_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->PARAM_1_OPERATE);

	return 13;
}


uint32_t UnpackARS_TCCS_OPER_t(void *protobetter_type, void *buffer)
{

	ARS_TCCS_OPER_t *mystruct = (ARS_TCCS_OPER_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->PARAM_1_OPERATE, &bytes[12]);

	return sizeof(ARS_TCCS_OPER_t);
}


uint32_t PackPORT_IMV_t(void *buffer, void *protobetter_type)
{

	PORT_IMV_t *mystruct = (PORT_IMV_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->PARAM_1_POSITION);

	return 13;
}


uint32_t UnpackPORT_IMV_t(void *protobetter_type, void *buffer)
{

	PORT_IMV_t *mystruct = (PORT_IMV_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->PARAM_1_POSITION, &bytes[12]);

	return sizeof(PORT_IMV_t);
}


uint32_t PackSTBD_IMV_t(void *buffer, void *protobetter_type)
{

	STBD_IMV_t *mystruct = (STBD_IMV_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->PARAM_1_POSITION);

	return 13;
}


uint32_t UnpackSTBD_IMV_t(void *protobetter_type, void *buffer)
{

	STBD_IMV_t *mystruct = (STBD_IMV_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->PARAM_1_POSITION, &bytes[12]);

	return sizeof(STBD_IMV_t);
}


uint32_t PackSTBD_IMV_FAN_t(void *buffer, void *protobetter_type)
{

	STBD_IMV_FAN_t *mystruct = (STBD_IMV_FAN_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->PARAM_1_ENABLE);

	return 13;
}


uint32_t UnpackSTBD_IMV_FAN_t(void *protobetter_type, void *buffer)
{

	STBD_IMV_FAN_t *mystruct = (STBD_IMV_FAN_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->PARAM_1_ENABLE, &bytes[12]);

	return sizeof(STBD_IMV_FAN_t);
}


uint32_t PackAFT_IMV_t(void *buffer, void *protobetter_type)
{

	AFT_IMV_t *mystruct = (AFT_IMV_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->PARAM_1_POSITION);

	return 13;
}


uint32_t UnpackAFT_IMV_t(void *protobetter_type, void *buffer)
{

	AFT_IMV_t *mystruct = (AFT_IMV_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->PARAM_1_POSITION, &bytes[12]);

	return sizeof(AFT_IMV_t);
}


uint32_t PackFWD_IMV_t(void *buffer, void *protobetter_type)
{

	FWD_IMV_t *mystruct = (FWD_IMV_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->PARAM_1_POSITION);

	return 13;
}


uint32_t UnpackFWD_IMV_t(void *protobetter_type, void *buffer)
{

	FWD_IMV_t *mystruct = (FWD_IMV_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->PARAM_1_POSITION, &bytes[12]);

	return sizeof(FWD_IMV_t);
}


uint32_t PackHAB_ECLSS_ARS_CMD(void *buffer, void *protobetter_type)
{
	unsigned char *msg = (unsigned char *) protobetter_type;

	uint16_t cmdCode = PROTOBETTER_READ_CCSDS_CODE(msg);

	switch (cmdCode)
	{
		case 0x5:

			return PackPORT_IMV_t(buffer, protobetter_type);

		case 0x0:

			return PackARS_CAB_FAN_t(buffer, protobetter_type);

		case 0x8:

			return PackAFT_IMV_t(buffer, protobetter_type);

		case 0x2:

			return PackARS_CDRA_OPER_t(buffer, protobetter_type);

		case 0x9:

			return PackFWD_IMV_t(buffer, protobetter_type);

		case 0x4:

			return PackARS_TCCS_OPER_t(buffer, protobetter_type);

		case 0x1:

			return PackARS_CAB_T_t(buffer, protobetter_type);

		case 0x7:

			return PackSTBD_IMV_FAN_t(buffer, protobetter_type);

		case 0x3:

			return PackARS_H2O_SEP_t(buffer, protobetter_type);

		case 0x6:

			return PackSTBD_IMV_t(buffer, protobetter_type);

		default:

			return 0;
	}
}


uint32_t UnpackHAB_ECLSS_ARS_CMD(void *protobetter_type, void *buffer)
{
	unsigned char *msg = (unsigned char *) buffer;

	uint16_t cmdCode = PROTOBETTER_READ_CCSDS_CODE(msg);

	switch (cmdCode)
	{
		case 0x5:

			return UnpackPORT_IMV_t(protobetter_type, buffer);

		case 0x0:

			return UnpackARS_CAB_FAN_t(protobetter_type, buffer);

		case 0x8:

			return UnpackAFT_IMV_t(protobetter_type, buffer);

		case 0x2:

			return UnpackARS_CDRA_OPER_t(protobetter_type, buffer);

		case 0x9:

			return UnpackFWD_IMV_t(protobetter_type, buffer);

		case 0x4:

			return UnpackARS_TCCS_OPER_t(protobetter_type, buffer);

		case 0x1:

			return UnpackARS_CAB_T_t(protobetter_type, buffer);

		case 0x7:

			return UnpackSTBD_IMV_FAN_t(protobetter_type, buffer);

		case 0x3:

			return UnpackARS_H2O_SEP_t(protobetter_type, buffer);

		case 0x6:

			return UnpackSTBD_IMV_t(protobetter_type, buffer);

		default:

			return 0;
	}
}


uint32_t PackDEPRESS_t(void *buffer, void *protobetter_type)
{

	DEPRESS_t *mystruct = (DEPRESS_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->PARAM_1_START);

	return 13;
}


uint32_t UnpackDEPRESS_t(void *protobetter_type, void *buffer)
{

	DEPRESS_t *mystruct = (DEPRESS_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->PARAM_1_START, &bytes[12]);

	return sizeof(DEPRESS_t);
}


uint32_t PackO2_SET_t(void *buffer, void *protobetter_type)
{

	O2_SET_t *mystruct = (O2_SET_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_FLOAT(&bytes[12], &mystruct->PARAM_1_SETPOINT);

	return 16;
}


uint32_t UnpackO2_SET_t(void *protobetter_type, void *buffer)
{

	O2_SET_t *mystruct = (O2_SET_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_FLOAT(&mystruct->PARAM_1_SETPOINT, &bytes[12]);

	return sizeof(O2_SET_t);
}


uint32_t PackP_SET_t(void *buffer, void *protobetter_type)
{

	P_SET_t *mystruct = (P_SET_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_FLOAT(&bytes[12], &mystruct->PARAM_1_SETPOINT);

	return 16;
}


uint32_t UnpackP_SET_t(void *protobetter_type, void *buffer)
{

	P_SET_t *mystruct = (P_SET_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_FLOAT(&mystruct->PARAM_1_SETPOINT, &bytes[12]);

	return sizeof(P_SET_t);
}


uint32_t PackREPRESS_t(void *buffer, void *protobetter_type)
{

	REPRESS_t *mystruct = (REPRESS_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->PARAM_1_START);

	return 13;
}


uint32_t UnpackREPRESS_t(void *protobetter_type, void *buffer)
{

	REPRESS_t *mystruct = (REPRESS_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->PARAM_1_START, &bytes[12]);

	return sizeof(REPRESS_t);
}


uint32_t PackHAB_ECLSS_PCS_CMD(void *buffer, void *protobetter_type)
{
	unsigned char *msg = (unsigned char *) protobetter_type;

	uint16_t cmdCode = PROTOBETTER_READ_CCSDS_CODE(msg);

	switch (cmdCode)
	{
		case 0x2:

			return PackP_SET_t(buffer, protobetter_type);

		case 0x0:

			return PackDEPRESS_t(buffer, protobetter_type);

		case 0x3:

			return PackREPRESS_t(buffer, protobetter_type);

		case 0x1:

			return PackO2_SET_t(buffer, protobetter_type);

		default:

			return 0;
	}
}


uint32_t UnpackHAB_ECLSS_PCS_CMD(void *protobetter_type, void *buffer)
{
	unsigned char *msg = (unsigned char *) buffer;

	uint16_t cmdCode = PROTOBETTER_READ_CCSDS_CODE(msg);

	switch (cmdCode)
	{
		case 0x2:

			return UnpackP_SET_t(protobetter_type, buffer);

		case 0x0:

			return UnpackDEPRESS_t(protobetter_type, buffer);

		case 0x3:

			return UnpackREPRESS_t(protobetter_type, buffer);

		case 0x1:

			return UnpackO2_SET_t(protobetter_type, buffer);

		default:

			return 0;
	}
}


uint32_t PackPW_DISP_t(void *buffer, void *protobetter_type)
{

	PW_DISP_t *mystruct = (PW_DISP_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->PARAM_1_POSITION);

	return 13;
}


uint32_t UnpackPW_DISP_t(void *protobetter_type, void *buffer)
{

	PW_DISP_t *mystruct = (PW_DISP_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->PARAM_1_POSITION, &bytes[12]);

	return sizeof(PW_DISP_t);
}


uint32_t PackWW_VENT_t(void *buffer, void *protobetter_type)
{

	WW_VENT_t *mystruct = (WW_VENT_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->PARAM_1_POSITION);

	return 13;
}


uint32_t UnpackWW_VENT_t(void *protobetter_type, void *buffer)
{

	WW_VENT_t *mystruct = (WW_VENT_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->PARAM_1_POSITION, &bytes[12]);

	return sizeof(WW_VENT_t);
}


uint32_t PackHAB_ECLSS_WMS_CMD(void *buffer, void *protobetter_type)
{
	unsigned char *msg = (unsigned char *) protobetter_type;

	uint16_t cmdCode = PROTOBETTER_READ_CCSDS_CODE(msg);

	switch (cmdCode)
	{
		case 0x1:

			return PackWW_VENT_t(buffer, protobetter_type);

		case 0x0:

			return PackPW_DISP_t(buffer, protobetter_type);

		default:

			return 0;
	}
}


uint32_t UnpackHAB_ECLSS_WMS_CMD(void *protobetter_type, void *buffer)
{
	unsigned char *msg = (unsigned char *) buffer;

	uint16_t cmdCode = PROTOBETTER_READ_CCSDS_CODE(msg);

	switch (cmdCode)
	{
		case 0x1:

			return UnpackWW_VENT_t(protobetter_type, buffer);

		case 0x0:

			return UnpackPW_DISP_t(protobetter_type, buffer);

		default:

			return 0;
	}
}


