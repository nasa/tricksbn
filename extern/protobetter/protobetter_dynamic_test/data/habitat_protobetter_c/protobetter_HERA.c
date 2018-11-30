#include "protobetter_HERA.h"

static inline uint32_t PackTHERAHEADER(void *buffer, void *protobetter_type)
{

	THERAHEADER *mystruct = (THERAHEADER*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	PACK_UINT32(&bytes[0], &mystruct->uSync);
	PACK_UINT16(&bytes[4], &mystruct->usSource);
	PACK_UINT16(&bytes[6], &mystruct->usDestination);
	PACK_UINT16(&bytes[8], &mystruct->usSQUID);
	PACK_UINT16(&bytes[10], &mystruct->eCmd);
	PACK_UINT32(&bytes[12], &mystruct->uPlSize);
	PACK_UINT64(&bytes[16], &mystruct->ullOrionTime);

	return 24;
}


static inline uint32_t UnpackTHERAHEADER(void *protobetter_type, void *buffer)
{

	THERAHEADER *mystruct = (THERAHEADER*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	UNPACK_UINT32(&mystruct->uSync, &bytes[0]);
	UNPACK_UINT16(&mystruct->usSource, &bytes[4]);
	UNPACK_UINT16(&mystruct->usDestination, &bytes[6]);
	UNPACK_UINT16(&mystruct->usSQUID, &bytes[8]);
	UNPACK_UINT16(&mystruct->eCmd, &bytes[10]);
	UNPACK_UINT32(&mystruct->uPlSize, &bytes[12]);
	UNPACK_UINT64(&mystruct->ullOrionTime, &bytes[16]);

	return sizeof(THERAHEADER);
}


uint32_t PackHERA_CW_DATA(void *buffer, void *protobetter_type)
{

	HERA_CW_DATA *mystruct = (HERA_CW_DATA*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->cfsHeader, 16);
	PackTHERAHEADER(&bytes[16], &mystruct->hdr);
	PACK_UINT8(&bytes[40], &mystruct->ucHSUPwrSwitchStatus);
	PACK_UINT8(&bytes[41], &mystruct->ucHERASystemMode);
	PACK_UINT8(&bytes[42], &mystruct->ucHERASystemAlarm);
	PACK_UINT8(&bytes[43], &mystruct->ucHERAExecutionInd);
	PACK_UINT32(&bytes[44], &mystruct->uiBuiltInTestStatus);
	PACK_UINT8_ARRAY(&bytes[48], mystruct->ucSensorExecutionInd, MAX_SENSORS);
	PACK_UINT8_ARRAY(&bytes[48 + (1*MAX_SENSORS)], mystruct->ucSensorExecutionIndFlag, MAX_SENSORS);
	PACK_UINT8_ARRAY(&bytes[48 + (1*MAX_SENSORS) + (1*MAX_SENSORS)], mystruct->ucAbsDoseRateAlarm, MAX_SENSORS);
	PACK_UINT8(&bytes[48 + (1*MAX_SENSORS) + (1*MAX_SENSORS) + (1*MAX_SENSORS)], &mystruct->ucHERAExecutionIndFlag);
	PACK_UINT8(&bytes[49 + (1*MAX_SENSORS) + (1*MAX_SENSORS) + (1*MAX_SENSORS)], &mystruct->ucBITFlag);
	PACK_UINT16(&bytes[50 + (1*MAX_SENSORS) + (1*MAX_SENSORS) + (1*MAX_SENSORS)], &mystruct->usNumCmdRecv);
	PACK_UINT8(&bytes[52 + (1*MAX_SENSORS) + (1*MAX_SENSORS) + (1*MAX_SENSORS)], &mystruct->ucCmdFlag);
	PACK_UINT8_ARRAY(&bytes[53 + (1*MAX_SENSORS) + (1*MAX_SENSORS) + (1*MAX_SENSORS)], mystruct->UNUSED, 5);
	PACK_UINT16(&bytes[58 + (1*MAX_SENSORS) + (1*MAX_SENSORS) + (1*MAX_SENSORS)], &mystruct->usChecksum);

	return 60 + (1*MAX_SENSORS) + (1*MAX_SENSORS) + (1*MAX_SENSORS);
}


uint32_t UnpackHERA_CW_DATA(void *protobetter_type, void *buffer)
{

	HERA_CW_DATA *mystruct = (HERA_CW_DATA*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->cfsHeader, &bytes[0], 16);
	UnpackTHERAHEADER(&mystruct->hdr, &bytes[16]);
	UNPACK_UINT8(&mystruct->ucHSUPwrSwitchStatus, &bytes[40]);
	UNPACK_UINT8(&mystruct->ucHERASystemMode, &bytes[41]);
	UNPACK_UINT8(&mystruct->ucHERASystemAlarm, &bytes[42]);
	UNPACK_UINT8(&mystruct->ucHERAExecutionInd, &bytes[43]);
	UNPACK_UINT32(&mystruct->uiBuiltInTestStatus, &bytes[44]);
	UNPACK_UINT8_ARRAY(mystruct->ucSensorExecutionInd, &bytes[48], MAX_SENSORS);
	UNPACK_UINT8_ARRAY(mystruct->ucSensorExecutionIndFlag, &bytes[48 + (1*MAX_SENSORS)], MAX_SENSORS);
	UNPACK_UINT8_ARRAY(mystruct->ucAbsDoseRateAlarm, &bytes[48 + (1*MAX_SENSORS) + (1*MAX_SENSORS)], MAX_SENSORS);
	UNPACK_UINT8(&mystruct->ucHERAExecutionIndFlag, &bytes[48 + (1*MAX_SENSORS) + (1*MAX_SENSORS) + (1*MAX_SENSORS)]);
	UNPACK_UINT8(&mystruct->ucBITFlag, &bytes[49 + (1*MAX_SENSORS) + (1*MAX_SENSORS) + (1*MAX_SENSORS)]);
	UNPACK_UINT16(&mystruct->usNumCmdRecv, &bytes[50 + (1*MAX_SENSORS) + (1*MAX_SENSORS) + (1*MAX_SENSORS)]);
	UNPACK_UINT8(&mystruct->ucCmdFlag, &bytes[52 + (1*MAX_SENSORS) + (1*MAX_SENSORS) + (1*MAX_SENSORS)]);
	UNPACK_UINT8_ARRAY(mystruct->UNUSED, &bytes[53 + (1*MAX_SENSORS) + (1*MAX_SENSORS) + (1*MAX_SENSORS)], 5);
	UNPACK_UINT16(&mystruct->usChecksum, &bytes[58 + (1*MAX_SENSORS) + (1*MAX_SENSORS) + (1*MAX_SENSORS)]);

	return sizeof(HERA_CW_DATA);
}


