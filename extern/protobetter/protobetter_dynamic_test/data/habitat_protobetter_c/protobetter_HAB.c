#include "protobetter_HAB.h"

static inline uint32_t Packsim_power_source(void *buffer, void *protobetter_type)
{

	sim_power_source *mystruct = (sim_power_source*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	PACK_UINT8(&bytes[0], &mystruct->UNITID);
	PACK_UINT8(&bytes[1], &mystruct->SAR_SWITCH_FEEDBACK);
	PACK_UINT8(&bytes[2], &mystruct->BATT_SWItCH_FEEDBACK);
	PACK_UINT8(&bytes[3], &mystruct->CROSS_CONNECT_SWITCH_FEEDBACK);
	PACK_UINT8(&bytes[4], &mystruct->SAR_FEEDBACK);
	PACK_DOUBLE(&bytes[5], &mystruct->SOLARARRAY_VOLTAGE);
	PACK_DOUBLE(&bytes[13], &mystruct->BATT_VOLTAGE);
	PACK_DOUBLE(&bytes[21], &mystruct->SAR_VOLTAGE);
	PACK_DOUBLE(&bytes[29], &mystruct->SOLARARRAY_CURRENT);
	PACK_DOUBLE(&bytes[37], &mystruct->BATT_CURRENT);
	PACK_DOUBLE(&bytes[45], &mystruct->SAR_CURRENT);
	PACK_DOUBLE(&bytes[53], &mystruct->BATT_SOC);

	return 61;
}


static inline uint32_t Unpacksim_power_source(void *protobetter_type, void *buffer)
{

	sim_power_source *mystruct = (sim_power_source*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	UNPACK_UINT8(&mystruct->UNITID, &bytes[0]);
	UNPACK_UINT8(&mystruct->SAR_SWITCH_FEEDBACK, &bytes[1]);
	UNPACK_UINT8(&mystruct->BATT_SWItCH_FEEDBACK, &bytes[2]);
	UNPACK_UINT8(&mystruct->CROSS_CONNECT_SWITCH_FEEDBACK, &bytes[3]);
	UNPACK_UINT8(&mystruct->SAR_FEEDBACK, &bytes[4]);
	UNPACK_DOUBLE(&mystruct->SOLARARRAY_VOLTAGE, &bytes[5]);
	UNPACK_DOUBLE(&mystruct->BATT_VOLTAGE, &bytes[13]);
	UNPACK_DOUBLE(&mystruct->SAR_VOLTAGE, &bytes[21]);
	UNPACK_DOUBLE(&mystruct->SOLARARRAY_CURRENT, &bytes[29]);
	UNPACK_DOUBLE(&mystruct->BATT_CURRENT, &bytes[37]);
	UNPACK_DOUBLE(&mystruct->SAR_CURRENT, &bytes[45]);
	UNPACK_DOUBLE(&mystruct->BATT_SOC, &bytes[53]);

	return sizeof(sim_power_source);
}


uint32_t PackHAB_Power_Source1(void *buffer, void *protobetter_type)
{

	HAB_Power_Source1 *mystruct = (HAB_Power_Source1*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->cfsHeader, 16);
	Packsim_power_source(&bytes[16], &mystruct->hab_power_source1);

	return 77;
}


uint32_t UnpackHAB_Power_Source1(void *protobetter_type, void *buffer)
{

	HAB_Power_Source1 *mystruct = (HAB_Power_Source1*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->cfsHeader, &bytes[0], 16);
	Unpacksim_power_source(&mystruct->hab_power_source1, &bytes[16]);

	return sizeof(HAB_Power_Source1);
}


uint32_t PackHAB_Power_Source2(void *buffer, void *protobetter_type)
{

	HAB_Power_Source2 *mystruct = (HAB_Power_Source2*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->cfsHeader, 16);
	Packsim_power_source(&bytes[16], &mystruct->hab_power_source2);

	return 77;
}


uint32_t UnpackHAB_Power_Source2(void *protobetter_type, void *buffer)
{

	HAB_Power_Source2 *mystruct = (HAB_Power_Source2*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->cfsHeader, &bytes[0], 16);
	Unpacksim_power_source(&mystruct->hab_power_source2, &bytes[16]);

	return sizeof(HAB_Power_Source2);
}


uint32_t PackMAST(void *buffer, void *protobetter_type)
{

	MAST *mystruct = (MAST*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->cfsHeader, 16);
	PACK_UINT32(&bytes[16], &mystruct->systemHealth);
	PACK_UINT32(&bytes[20], &mystruct->vehicleMode);
	PACK_UINT32(&bytes[24], &mystruct->ppeHealth);
	PACK_UINT32(&bytes[28], &mystruct->habHealth);
	PACK_UINT32(&bytes[32], &mystruct->ppePowerMode);
	PACK_UINT32(&bytes[36], &mystruct->ppeElementMode);
	PACK_UINT32(&bytes[40], &mystruct->habPowerMode);
	PACK_UINT32(&bytes[44], &mystruct->habEclssMode);
	PACK_UINT32(&bytes[48], &mystruct->habElementMode);

	return 52;
}


uint32_t UnpackMAST(void *protobetter_type, void *buffer)
{

	MAST *mystruct = (MAST*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->cfsHeader, &bytes[0], 16);
	UNPACK_UINT32(&mystruct->systemHealth, &bytes[16]);
	UNPACK_UINT32(&mystruct->vehicleMode, &bytes[20]);
	UNPACK_UINT32(&mystruct->ppeHealth, &bytes[24]);
	UNPACK_UINT32(&mystruct->habHealth, &bytes[28]);
	UNPACK_UINT32(&mystruct->ppePowerMode, &bytes[32]);
	UNPACK_UINT32(&mystruct->ppeElementMode, &bytes[36]);
	UNPACK_UINT32(&mystruct->habPowerMode, &bytes[40]);
	UNPACK_UINT32(&mystruct->habEclssMode, &bytes[44]);
	UNPACK_UINT32(&mystruct->habElementMode, &bytes[48]);

	return sizeof(MAST);
}


uint32_t PackSET_HAB_PS1_OUTPUT_CHANNEL_STATE_t(void *buffer, void *protobetter_type)
{

	SET_HAB_PS1_OUTPUT_CHANNEL_STATE_t *mystruct = (SET_HAB_PS1_OUTPUT_CHANNEL_STATE_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->outSTATE);
	PACK_UINT8(&bytes[13], &mystruct->outCHANNEL);

	return 14;
}


uint32_t UnpackSET_HAB_PS1_OUTPUT_CHANNEL_STATE_t(void *protobetter_type, void *buffer)
{

	SET_HAB_PS1_OUTPUT_CHANNEL_STATE_t *mystruct = (SET_HAB_PS1_OUTPUT_CHANNEL_STATE_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->outSTATE, &bytes[12]);
	UNPACK_UINT8(&mystruct->outCHANNEL, &bytes[13]);

	return sizeof(SET_HAB_PS1_OUTPUT_CHANNEL_STATE_t);
}


uint32_t PackSET_HAB_PS1_SAR_STATE_t(void *buffer, void *protobetter_type)
{

	SET_HAB_PS1_SAR_STATE_t *mystruct = (SET_HAB_PS1_SAR_STATE_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->sarSTATE);

	return 13;
}


uint32_t UnpackSET_HAB_PS1_SAR_STATE_t(void *protobetter_type, void *buffer)
{

	SET_HAB_PS1_SAR_STATE_t *mystruct = (SET_HAB_PS1_SAR_STATE_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->sarSTATE, &bytes[12]);

	return sizeof(SET_HAB_PS1_SAR_STATE_t);
}


uint32_t PackHAB_Power_Source1_CMD(void *buffer, void *protobetter_type)
{
	unsigned char *msg = (unsigned char *) protobetter_type;

	uint16_t cmdCode = PROTOBETTER_READ_CCSDS_CODE(msg);

	switch (cmdCode)
	{
		case 0x0:

			return PackSET_HAB_PS1_OUTPUT_CHANNEL_STATE_t(buffer, protobetter_type);

		case 0x1:

			return PackSET_HAB_PS1_SAR_STATE_t(buffer, protobetter_type);

		default:

			return 0;
	}
}


uint32_t UnpackHAB_Power_Source1_CMD(void *protobetter_type, void *buffer)
{
	unsigned char *msg = (unsigned char *) buffer;

	uint16_t cmdCode = PROTOBETTER_READ_CCSDS_CODE(msg);

	switch (cmdCode)
	{
		case 0x0:

			return UnpackSET_HAB_PS1_OUTPUT_CHANNEL_STATE_t(protobetter_type, buffer);

		case 0x1:

			return UnpackSET_HAB_PS1_SAR_STATE_t(protobetter_type, buffer);

		default:

			return 0;
	}
}


uint32_t PackSET_HAB_PS2_OUTPUT_CHANNEL_STATE_t(void *buffer, void *protobetter_type)
{

	SET_HAB_PS2_OUTPUT_CHANNEL_STATE_t *mystruct = (SET_HAB_PS2_OUTPUT_CHANNEL_STATE_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->outSTATE);
	PACK_UINT8(&bytes[13], &mystruct->outCHANNEL);

	return 14;
}


uint32_t UnpackSET_HAB_PS2_OUTPUT_CHANNEL_STATE_t(void *protobetter_type, void *buffer)
{

	SET_HAB_PS2_OUTPUT_CHANNEL_STATE_t *mystruct = (SET_HAB_PS2_OUTPUT_CHANNEL_STATE_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->outSTATE, &bytes[12]);
	UNPACK_UINT8(&mystruct->outCHANNEL, &bytes[13]);

	return sizeof(SET_HAB_PS2_OUTPUT_CHANNEL_STATE_t);
}


uint32_t PackSET_HAB_PS2_SAR_STATE_t(void *buffer, void *protobetter_type)
{

	SET_HAB_PS2_SAR_STATE_t *mystruct = (SET_HAB_PS2_SAR_STATE_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->sarSTATE);

	return 13;
}


uint32_t UnpackSET_HAB_PS2_SAR_STATE_t(void *protobetter_type, void *buffer)
{

	SET_HAB_PS2_SAR_STATE_t *mystruct = (SET_HAB_PS2_SAR_STATE_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->sarSTATE, &bytes[12]);

	return sizeof(SET_HAB_PS2_SAR_STATE_t);
}


uint32_t PackHAB_Power_Source2_CMD(void *buffer, void *protobetter_type)
{
	unsigned char *msg = (unsigned char *) protobetter_type;

	uint16_t cmdCode = PROTOBETTER_READ_CCSDS_CODE(msg);

	switch (cmdCode)
	{
		case 0x0:

			return PackSET_HAB_PS2_OUTPUT_CHANNEL_STATE_t(buffer, protobetter_type);

		case 0x1:

			return PackSET_HAB_PS2_SAR_STATE_t(buffer, protobetter_type);

		default:

			return 0;
	}
}


uint32_t UnpackHAB_Power_Source2_CMD(void *protobetter_type, void *buffer)
{
	unsigned char *msg = (unsigned char *) buffer;

	uint16_t cmdCode = PROTOBETTER_READ_CCSDS_CODE(msg);

	switch (cmdCode)
	{
		case 0x0:

			return UnpackSET_HAB_PS2_OUTPUT_CHANNEL_STATE_t(protobetter_type, buffer);

		case 0x1:

			return UnpackSET_HAB_PS2_SAR_STATE_t(protobetter_type, buffer);

		default:

			return 0;
	}
}


