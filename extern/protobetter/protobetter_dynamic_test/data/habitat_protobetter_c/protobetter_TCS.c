#include "protobetter_TCS.h"

static inline uint32_t PackHAB_TCS_ETCS_LOOP_TLM(void *buffer, void *protobetter_type)
{

	HAB_TCS_ETCS_LOOP_TLM *mystruct = (HAB_TCS_ETCS_LOOP_TLM*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	PACK_FLOAT(&bytes[0], &mystruct->ACCUM_QTY);
	PACK_FLOAT(&bytes[4], &mystruct->ACCUM_P);
	PACK_FLOAT(&bytes[8], &mystruct->PUMPS_INLET_T);
	PACK_FLOAT(&bytes[12], &mystruct->PUMPS_INLET_P);
	PACK_FLOAT(&bytes[16], &mystruct->PUMP_1_N);
	PACK_FLOAT(&bytes[20], &mystruct->PUMP_1_DP);
	PACK_FLOAT(&bytes[24], &mystruct->PUMP_1_FLOW);
	PACK_FLOAT(&bytes[28], &mystruct->PUMP_2_N);
	PACK_FLOAT(&bytes[32], &mystruct->PUMP_2_DP);
	PACK_FLOAT(&bytes[36], &mystruct->PUMP_2_FLOW);
	PACK_FLOAT(&bytes[40], &mystruct->IFHX_INLET_T);
	PACK_FLOAT(&bytes[44], &mystruct->IFHX_EXIT_T);
	PACK_FLOAT(&bytes[48], &mystruct->CP_1_T);
	PACK_FLOAT(&bytes[52], &mystruct->CP_2_T);
	PACK_FLOAT(&bytes[56], &mystruct->CP_3_T);
	PACK_FLOAT(&bytes[60], &mystruct->CP_4_T);
	PACK_FLOAT(&bytes[64], &mystruct->REGEN_HX_COLD_T);
	PACK_FLOAT(&bytes[68], &mystruct->REGEN_HX_HOT_T);
	PACK_FLOAT(&bytes[72], &mystruct->RAD_1_EXIT_T);
	PACK_FLOAT(&bytes[76], &mystruct->RAD_2_EXIT_T);
	PACK_FLOAT(&bytes[80], &mystruct->ISO_A_POS);
	PACK_FLOAT(&bytes[84], &mystruct->ISO_A_FLOW);
	PACK_FLOAT(&bytes[88], &mystruct->ISO_B_POS);
	PACK_FLOAT(&bytes[92], &mystruct->ISO_B_FLOW);
	PACK_FLOAT(&bytes[96], &mystruct->TCV_A_REGEN_FLOW);
	PACK_FLOAT(&bytes[100], &mystruct->TCV_A_BYPASS_FLOW);
	PACK_FLOAT(&bytes[104], &mystruct->TCV_B_REGEN_FLOW);
	PACK_FLOAT(&bytes[108], &mystruct->TCV_B_BYPASS_FLOW);
	PACK_FLOAT(&bytes[112], &mystruct->RAD_MIX_POS);
	PACK_UINT8(&bytes[116], &mystruct->PUMP_1_ENA_CMD_FEEDBACK);
	PACK_UINT8(&bytes[117], &mystruct->PUMP_2_ENA_CMD_FEEDBACK);
	PACK_UINT8_ARRAY(&bytes[118], mystruct->etcs_pad, 2);
	PACK_FLOAT(&bytes[120], &mystruct->ISO_A_POS_CMD_FEEDBACK);
	PACK_FLOAT(&bytes[124], &mystruct->ISO_B_POS_CMD_FEEDBACK);
	PACK_FLOAT(&bytes[128], &mystruct->RAD_MIX_POS_CMD_FEEDBACK);

	return 132;
}


static inline uint32_t UnpackHAB_TCS_ETCS_LOOP_TLM(void *protobetter_type, void *buffer)
{

	HAB_TCS_ETCS_LOOP_TLM *mystruct = (HAB_TCS_ETCS_LOOP_TLM*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	UNPACK_FLOAT(&mystruct->ACCUM_QTY, &bytes[0]);
	UNPACK_FLOAT(&mystruct->ACCUM_P, &bytes[4]);
	UNPACK_FLOAT(&mystruct->PUMPS_INLET_T, &bytes[8]);
	UNPACK_FLOAT(&mystruct->PUMPS_INLET_P, &bytes[12]);
	UNPACK_FLOAT(&mystruct->PUMP_1_N, &bytes[16]);
	UNPACK_FLOAT(&mystruct->PUMP_1_DP, &bytes[20]);
	UNPACK_FLOAT(&mystruct->PUMP_1_FLOW, &bytes[24]);
	UNPACK_FLOAT(&mystruct->PUMP_2_N, &bytes[28]);
	UNPACK_FLOAT(&mystruct->PUMP_2_DP, &bytes[32]);
	UNPACK_FLOAT(&mystruct->PUMP_2_FLOW, &bytes[36]);
	UNPACK_FLOAT(&mystruct->IFHX_INLET_T, &bytes[40]);
	UNPACK_FLOAT(&mystruct->IFHX_EXIT_T, &bytes[44]);
	UNPACK_FLOAT(&mystruct->CP_1_T, &bytes[48]);
	UNPACK_FLOAT(&mystruct->CP_2_T, &bytes[52]);
	UNPACK_FLOAT(&mystruct->CP_3_T, &bytes[56]);
	UNPACK_FLOAT(&mystruct->CP_4_T, &bytes[60]);
	UNPACK_FLOAT(&mystruct->REGEN_HX_COLD_T, &bytes[64]);
	UNPACK_FLOAT(&mystruct->REGEN_HX_HOT_T, &bytes[68]);
	UNPACK_FLOAT(&mystruct->RAD_1_EXIT_T, &bytes[72]);
	UNPACK_FLOAT(&mystruct->RAD_2_EXIT_T, &bytes[76]);
	UNPACK_FLOAT(&mystruct->ISO_A_POS, &bytes[80]);
	UNPACK_FLOAT(&mystruct->ISO_A_FLOW, &bytes[84]);
	UNPACK_FLOAT(&mystruct->ISO_B_POS, &bytes[88]);
	UNPACK_FLOAT(&mystruct->ISO_B_FLOW, &bytes[92]);
	UNPACK_FLOAT(&mystruct->TCV_A_REGEN_FLOW, &bytes[96]);
	UNPACK_FLOAT(&mystruct->TCV_A_BYPASS_FLOW, &bytes[100]);
	UNPACK_FLOAT(&mystruct->TCV_B_REGEN_FLOW, &bytes[104]);
	UNPACK_FLOAT(&mystruct->TCV_B_BYPASS_FLOW, &bytes[108]);
	UNPACK_FLOAT(&mystruct->RAD_MIX_POS, &bytes[112]);
	UNPACK_UINT8(&mystruct->PUMP_1_ENA_CMD_FEEDBACK, &bytes[116]);
	UNPACK_UINT8(&mystruct->PUMP_2_ENA_CMD_FEEDBACK, &bytes[117]);
	UNPACK_UINT8_ARRAY(mystruct->etcs_pad, &bytes[118], 2);
	UNPACK_FLOAT(&mystruct->ISO_A_POS_CMD_FEEDBACK, &bytes[120]);
	UNPACK_FLOAT(&mystruct->ISO_B_POS_CMD_FEEDBACK, &bytes[124]);
	UNPACK_FLOAT(&mystruct->RAD_MIX_POS_CMD_FEEDBACK, &bytes[128]);

	return sizeof(HAB_TCS_ETCS_LOOP_TLM);
}


uint32_t PackHAB_TCS_ETCS_TLM(void *buffer, void *protobetter_type)
{

	HAB_TCS_ETCS_TLM *mystruct = (HAB_TCS_ETCS_TLM*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->cfsHeader, 16);
	PackHAB_TCS_ETCS_LOOP_TLM(&bytes[16], &mystruct->A);
	PackHAB_TCS_ETCS_LOOP_TLM(&bytes[148], &mystruct->B);

	return 280;
}


uint32_t UnpackHAB_TCS_ETCS_TLM(void *protobetter_type, void *buffer)
{

	HAB_TCS_ETCS_TLM *mystruct = (HAB_TCS_ETCS_TLM*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->cfsHeader, &bytes[0], 16);
	UnpackHAB_TCS_ETCS_LOOP_TLM(&mystruct->A, &bytes[16]);
	UnpackHAB_TCS_ETCS_LOOP_TLM(&mystruct->B, &bytes[148]);

	return sizeof(HAB_TCS_ETCS_TLM);
}


uint32_t PackHAB_TCS_ITCS_TLM(void *buffer, void *protobetter_type)
{

	HAB_TCS_ITCS_TLM *mystruct = (HAB_TCS_ITCS_TLM*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->cfsHeader, 16);
	PACK_FLOAT(&bytes[16], &mystruct->PUMPS_INLET_T);
	PACK_FLOAT(&bytes[20], &mystruct->PUMPS_INLET_P);
	PACK_FLOAT(&bytes[24], &mystruct->CP_1_T);
	PACK_FLOAT(&bytes[28], &mystruct->CP_2_T);
	PACK_FLOAT(&bytes[32], &mystruct->CHX_INLET_T);
	PACK_FLOAT(&bytes[36], &mystruct->CHX_EXIT_T);
	PACK_FLOAT(&bytes[40], &mystruct->AVHX_INLET_T);
	PACK_FLOAT(&bytes[44], &mystruct->AVHX_EXIT_T);
	PACK_FLOAT(&bytes[48], &mystruct->IFHX_INLET_T);
	PACK_FLOAT(&bytes[52], &mystruct->IFHX_EXIT_T);
	PACK_FLOAT(&bytes[56], &mystruct->LINE_HTR_T);
	PACK_FLOAT(&bytes[60], &mystruct->LINE_HTR_PWR);
	PACK_FLOAT(&bytes[64], &mystruct->PUMP_1_N);
	PACK_FLOAT(&bytes[68], &mystruct->PUMP_1_DP);
	PACK_FLOAT(&bytes[72], &mystruct->PUMP_1_FLOW);
	PACK_FLOAT(&bytes[76], &mystruct->PUMP_2_N);
	PACK_FLOAT(&bytes[80], &mystruct->PUMP_2_DP);
	PACK_FLOAT(&bytes[84], &mystruct->PUMP_2_FLOW);
	PACK_FLOAT(&bytes[88], &mystruct->ACCUM_1_QTY);
	PACK_FLOAT(&bytes[92], &mystruct->ACCUM_1_P);
	PACK_FLOAT(&bytes[96], &mystruct->ACCUM_2_QTY);
	PACK_FLOAT(&bytes[100], &mystruct->ACCUM_2_P);
	PACK_FLOAT(&bytes[104], &mystruct->IFHX_SETPOINT_CMD_FEEDBACK);
	PACK_UINT8(&bytes[108], &mystruct->PUMP_1_CMD_FEEDBACK);
	PACK_UINT8(&bytes[109], &mystruct->PUMP_2_CMD_FEEDBACK);
	PACK_UINT8_ARRAY(&bytes[110], mystruct->itcs_pad, 2);

	return 112;
}


uint32_t UnpackHAB_TCS_ITCS_TLM(void *protobetter_type, void *buffer)
{

	HAB_TCS_ITCS_TLM *mystruct = (HAB_TCS_ITCS_TLM*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->cfsHeader, &bytes[0], 16);
	UNPACK_FLOAT(&mystruct->PUMPS_INLET_T, &bytes[16]);
	UNPACK_FLOAT(&mystruct->PUMPS_INLET_P, &bytes[20]);
	UNPACK_FLOAT(&mystruct->CP_1_T, &bytes[24]);
	UNPACK_FLOAT(&mystruct->CP_2_T, &bytes[28]);
	UNPACK_FLOAT(&mystruct->CHX_INLET_T, &bytes[32]);
	UNPACK_FLOAT(&mystruct->CHX_EXIT_T, &bytes[36]);
	UNPACK_FLOAT(&mystruct->AVHX_INLET_T, &bytes[40]);
	UNPACK_FLOAT(&mystruct->AVHX_EXIT_T, &bytes[44]);
	UNPACK_FLOAT(&mystruct->IFHX_INLET_T, &bytes[48]);
	UNPACK_FLOAT(&mystruct->IFHX_EXIT_T, &bytes[52]);
	UNPACK_FLOAT(&mystruct->LINE_HTR_T, &bytes[56]);
	UNPACK_FLOAT(&mystruct->LINE_HTR_PWR, &bytes[60]);
	UNPACK_FLOAT(&mystruct->PUMP_1_N, &bytes[64]);
	UNPACK_FLOAT(&mystruct->PUMP_1_DP, &bytes[68]);
	UNPACK_FLOAT(&mystruct->PUMP_1_FLOW, &bytes[72]);
	UNPACK_FLOAT(&mystruct->PUMP_2_N, &bytes[76]);
	UNPACK_FLOAT(&mystruct->PUMP_2_DP, &bytes[80]);
	UNPACK_FLOAT(&mystruct->PUMP_2_FLOW, &bytes[84]);
	UNPACK_FLOAT(&mystruct->ACCUM_1_QTY, &bytes[88]);
	UNPACK_FLOAT(&mystruct->ACCUM_1_P, &bytes[92]);
	UNPACK_FLOAT(&mystruct->ACCUM_2_QTY, &bytes[96]);
	UNPACK_FLOAT(&mystruct->ACCUM_2_P, &bytes[100]);
	UNPACK_FLOAT(&mystruct->IFHX_SETPOINT_CMD_FEEDBACK, &bytes[104]);
	UNPACK_UINT8(&mystruct->PUMP_1_CMD_FEEDBACK, &bytes[108]);
	UNPACK_UINT8(&mystruct->PUMP_2_CMD_FEEDBACK, &bytes[109]);
	UNPACK_UINT8_ARRAY(mystruct->itcs_pad, &bytes[110], 2);

	return sizeof(HAB_TCS_ITCS_TLM);
}


uint32_t PackA_ISO_A_t(void *buffer, void *protobetter_type)
{

	A_ISO_A_t *mystruct = (A_ISO_A_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_FLOAT(&bytes[12], &mystruct->PARAM_1_POS);

	return 16;
}


uint32_t UnpackA_ISO_A_t(void *protobetter_type, void *buffer)
{

	A_ISO_A_t *mystruct = (A_ISO_A_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_FLOAT(&mystruct->PARAM_1_POS, &bytes[12]);

	return sizeof(A_ISO_A_t);
}


uint32_t PackA_ISO_B_t(void *buffer, void *protobetter_type)
{

	A_ISO_B_t *mystruct = (A_ISO_B_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_FLOAT(&bytes[12], &mystruct->PARAM_1_POS);

	return 16;
}


uint32_t UnpackA_ISO_B_t(void *protobetter_type, void *buffer)
{

	A_ISO_B_t *mystruct = (A_ISO_B_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_FLOAT(&mystruct->PARAM_1_POS, &bytes[12]);

	return sizeof(A_ISO_B_t);
}


uint32_t PackA_PUMP_1_t(void *buffer, void *protobetter_type)
{

	A_PUMP_1_t *mystruct = (A_PUMP_1_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->PARAM_1_ENA);

	return 13;
}


uint32_t UnpackA_PUMP_1_t(void *protobetter_type, void *buffer)
{

	A_PUMP_1_t *mystruct = (A_PUMP_1_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->PARAM_1_ENA, &bytes[12]);

	return sizeof(A_PUMP_1_t);
}


uint32_t PackA_PUMP_2_t(void *buffer, void *protobetter_type)
{

	A_PUMP_2_t *mystruct = (A_PUMP_2_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->PARAM_1_ENA);

	return 13;
}


uint32_t UnpackA_PUMP_2_t(void *protobetter_type, void *buffer)
{

	A_PUMP_2_t *mystruct = (A_PUMP_2_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->PARAM_1_ENA, &bytes[12]);

	return sizeof(A_PUMP_2_t);
}


uint32_t PackA_RAD_MIX_t(void *buffer, void *protobetter_type)
{

	A_RAD_MIX_t *mystruct = (A_RAD_MIX_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_FLOAT(&bytes[12], &mystruct->PARAM_1_POS);

	return 16;
}


uint32_t UnpackA_RAD_MIX_t(void *protobetter_type, void *buffer)
{

	A_RAD_MIX_t *mystruct = (A_RAD_MIX_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_FLOAT(&mystruct->PARAM_1_POS, &bytes[12]);

	return sizeof(A_RAD_MIX_t);
}


uint32_t PackHAB_TCS_ETCS_A_CMD(void *buffer, void *protobetter_type)
{
	unsigned char *msg = (unsigned char *) protobetter_type;

	uint16_t cmdCode = PROTOBETTER_READ_CCSDS_CODE(msg);

	switch (cmdCode)
	{
		case 0x4:

			return PackA_RAD_MIX_t(buffer, protobetter_type);

		case 0x3:

			return PackA_PUMP_2_t(buffer, protobetter_type);

		case 0x2:

			return PackA_PUMP_1_t(buffer, protobetter_type);

		case 0x1:

			return PackA_ISO_B_t(buffer, protobetter_type);

		case 0x0:

			return PackA_ISO_A_t(buffer, protobetter_type);

		default:

			return 0;
	}
}


uint32_t UnpackHAB_TCS_ETCS_A_CMD(void *protobetter_type, void *buffer)
{
	unsigned char *msg = (unsigned char *) buffer;

	uint16_t cmdCode = PROTOBETTER_READ_CCSDS_CODE(msg);

	switch (cmdCode)
	{
		case 0x4:

			return UnpackA_RAD_MIX_t(protobetter_type, buffer);

		case 0x3:

			return UnpackA_PUMP_2_t(protobetter_type, buffer);

		case 0x2:

			return UnpackA_PUMP_1_t(protobetter_type, buffer);

		case 0x1:

			return UnpackA_ISO_B_t(protobetter_type, buffer);

		case 0x0:

			return UnpackA_ISO_A_t(protobetter_type, buffer);

		default:

			return 0;
	}
}


uint32_t PackB_ISO_A_t(void *buffer, void *protobetter_type)
{

	B_ISO_A_t *mystruct = (B_ISO_A_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_FLOAT(&bytes[12], &mystruct->PARAM_1_POS);

	return 16;
}


uint32_t UnpackB_ISO_A_t(void *protobetter_type, void *buffer)
{

	B_ISO_A_t *mystruct = (B_ISO_A_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_FLOAT(&mystruct->PARAM_1_POS, &bytes[12]);

	return sizeof(B_ISO_A_t);
}


uint32_t PackB_ISO_B_t(void *buffer, void *protobetter_type)
{

	B_ISO_B_t *mystruct = (B_ISO_B_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_FLOAT(&bytes[12], &mystruct->PARAM_1_POS);

	return 16;
}


uint32_t UnpackB_ISO_B_t(void *protobetter_type, void *buffer)
{

	B_ISO_B_t *mystruct = (B_ISO_B_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_FLOAT(&mystruct->PARAM_1_POS, &bytes[12]);

	return sizeof(B_ISO_B_t);
}


uint32_t PackB_PUMP_1_t(void *buffer, void *protobetter_type)
{

	B_PUMP_1_t *mystruct = (B_PUMP_1_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->PARAM_1_ENA);

	return 13;
}


uint32_t UnpackB_PUMP_1_t(void *protobetter_type, void *buffer)
{

	B_PUMP_1_t *mystruct = (B_PUMP_1_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->PARAM_1_ENA, &bytes[12]);

	return sizeof(B_PUMP_1_t);
}


uint32_t PackB_PUMP_2_t(void *buffer, void *protobetter_type)
{

	B_PUMP_2_t *mystruct = (B_PUMP_2_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->PARAM_1_ENA);

	return 13;
}


uint32_t UnpackB_PUMP_2_t(void *protobetter_type, void *buffer)
{

	B_PUMP_2_t *mystruct = (B_PUMP_2_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->PARAM_1_ENA, &bytes[12]);

	return sizeof(B_PUMP_2_t);
}


uint32_t PackB_RAD_MIX_t(void *buffer, void *protobetter_type)
{

	B_RAD_MIX_t *mystruct = (B_RAD_MIX_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_FLOAT(&bytes[12], &mystruct->PARAM_1_POS);

	return 16;
}


uint32_t UnpackB_RAD_MIX_t(void *protobetter_type, void *buffer)
{

	B_RAD_MIX_t *mystruct = (B_RAD_MIX_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_FLOAT(&mystruct->PARAM_1_POS, &bytes[12]);

	return sizeof(B_RAD_MIX_t);
}


uint32_t PackHAB_TCS_ETCS_B_CMD(void *buffer, void *protobetter_type)
{
	unsigned char *msg = (unsigned char *) protobetter_type;

	uint16_t cmdCode = PROTOBETTER_READ_CCSDS_CODE(msg);

	switch (cmdCode)
	{
		case 0x4:

			return PackB_RAD_MIX_t(buffer, protobetter_type);

		case 0x1:

			return PackB_ISO_B_t(buffer, protobetter_type);

		case 0x2:

			return PackB_PUMP_1_t(buffer, protobetter_type);

		case 0x0:

			return PackB_ISO_A_t(buffer, protobetter_type);

		case 0x3:

			return PackB_PUMP_2_t(buffer, protobetter_type);

		default:

			return 0;
	}
}


uint32_t UnpackHAB_TCS_ETCS_B_CMD(void *protobetter_type, void *buffer)
{
	unsigned char *msg = (unsigned char *) buffer;

	uint16_t cmdCode = PROTOBETTER_READ_CCSDS_CODE(msg);

	switch (cmdCode)
	{
		case 0x4:

			return UnpackB_RAD_MIX_t(protobetter_type, buffer);

		case 0x1:

			return UnpackB_ISO_B_t(protobetter_type, buffer);

		case 0x2:

			return UnpackB_PUMP_1_t(protobetter_type, buffer);

		case 0x0:

			return UnpackB_ISO_A_t(protobetter_type, buffer);

		case 0x3:

			return UnpackB_PUMP_2_t(protobetter_type, buffer);

		default:

			return 0;
	}
}


uint32_t PackIFHX_SET_t(void *buffer, void *protobetter_type)
{

	IFHX_SET_t *mystruct = (IFHX_SET_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_FLOAT(&bytes[12], &mystruct->PARAM_1_SETPOINT);

	return 16;
}


uint32_t UnpackIFHX_SET_t(void *protobetter_type, void *buffer)
{

	IFHX_SET_t *mystruct = (IFHX_SET_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_FLOAT(&mystruct->PARAM_1_SETPOINT, &bytes[12]);

	return sizeof(IFHX_SET_t);
}


uint32_t PackPUMP_1_t(void *buffer, void *protobetter_type)
{

	PUMP_1_t *mystruct = (PUMP_1_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->PARAM_1_ENA);

	return 13;
}


uint32_t UnpackPUMP_1_t(void *protobetter_type, void *buffer)
{

	PUMP_1_t *mystruct = (PUMP_1_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->PARAM_1_ENA, &bytes[12]);

	return sizeof(PUMP_1_t);
}


uint32_t PackPUMP_2_t(void *buffer, void *protobetter_type)
{

	PUMP_2_t *mystruct = (PUMP_2_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->PARAM_1_ENA);

	return 13;
}


uint32_t UnpackPUMP_2_t(void *protobetter_type, void *buffer)
{

	PUMP_2_t *mystruct = (PUMP_2_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->PARAM_1_ENA, &bytes[12]);

	return sizeof(PUMP_2_t);
}


uint32_t PackHAB_TCS_ITCS_CMD(void *buffer, void *protobetter_type)
{
	unsigned char *msg = (unsigned char *) protobetter_type;

	uint16_t cmdCode = PROTOBETTER_READ_CCSDS_CODE(msg);

	switch (cmdCode)
	{
		case 0x2:

			return PackPUMP_2_t(buffer, protobetter_type);

		case 0x1:

			return PackPUMP_1_t(buffer, protobetter_type);

		case 0x0:

			return PackIFHX_SET_t(buffer, protobetter_type);

		default:

			return 0;
	}
}


uint32_t UnpackHAB_TCS_ITCS_CMD(void *protobetter_type, void *buffer)
{
	unsigned char *msg = (unsigned char *) buffer;

	uint16_t cmdCode = PROTOBETTER_READ_CCSDS_CODE(msg);

	switch (cmdCode)
	{
		case 0x2:

			return UnpackPUMP_2_t(protobetter_type, buffer);

		case 0x1:

			return UnpackPUMP_1_t(protobetter_type, buffer);

		case 0x0:

			return UnpackIFHX_SET_t(protobetter_type, buffer);

		default:

			return 0;
	}
}


