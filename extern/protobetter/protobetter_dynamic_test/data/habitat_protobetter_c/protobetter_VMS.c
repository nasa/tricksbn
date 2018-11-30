#include "protobetter_VMS.h"

static inline uint32_t PackloadScheduleRow(void *buffer, void *protobetter_type)
{

	loadScheduleRow *mystruct = (loadScheduleRow*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	PACK_UINT32_ARRAY(&bytes[0], mystruct->component, 2);
	PACK_DOUBLE(&bytes[8], &mystruct->nominalPower);
	PACK_UINT32_ARRAY(&bytes[16], mystruct->priority, 24);

	return 112;
}


static inline uint32_t UnpackloadScheduleRow(void *protobetter_type, void *buffer)
{

	loadScheduleRow *mystruct = (loadScheduleRow*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	UNPACK_UINT32_ARRAY(mystruct->component, &bytes[0], 2);
	UNPACK_DOUBLE(&mystruct->nominalPower, &bytes[8]);
	UNPACK_UINT32_ARRAY(mystruct->priority, &bytes[16], 24);

	return sizeof(loadScheduleRow);
}


uint32_t PackloadSchedule(void *buffer, void *protobetter_type)
{

	loadSchedule *mystruct = (loadSchedule*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->cfsHeader, 16);
	{
		int ii = 0;
		for(ii = 0; ii < 16; ++ii) {
			PackloadScheduleRow(&bytes[16 + (ii*(112))], &mystruct->loadSched[ii]);
		}
	}

	return 1808;
}


uint32_t UnpackloadSchedule(void *protobetter_type, void *buffer)
{

	loadSchedule *mystruct = (loadSchedule*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->cfsHeader, &bytes[0], 16);
	{
		int ii = 0;
		for(ii = 0; ii < 16; ++ii) {
			UnpackloadScheduleRow(&mystruct->loadSched[ii], &bytes[16 + (ii*(112))]);
		}
	}

	return sizeof(loadSchedule);
}


uint32_t Packrequest_energy(void *buffer, void *protobetter_type)
{

	request_energy *mystruct = (request_energy*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->cfsHeader, 16);
	PACK_UINT8(&bytes[16], &mystruct->request_energy);

	return 17;
}


uint32_t Unpackrequest_energy(void *protobetter_type, void *buffer)
{

	request_energy *mystruct = (request_energy*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->cfsHeader, &bytes[0], 16);
	UNPACK_UINT8(&mystruct->request_energy, &bytes[16]);

	return sizeof(request_energy);
}


