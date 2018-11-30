#include "protobetter_MDA.h"

uint32_t Packmda(void *buffer, void *protobetter_type)
{

	mda *mystruct = (mda*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->cfsHeader, 16);
	PACK_UINT8_ARRAY(&bytes[16], mystruct->device, 11);
	PACK_UINT64(&bytes[27], &mystruct->record);
	PACK_UINT32(&bytes[35], &mystruct->epoch);
	PACK_UINT32(&bytes[39], &mystruct->battery);
	PACK_UINT32(&bytes[43], &mystruct->ecg_status);
	PACK_UINT32(&bytes[47], &mystruct->resp_status);
	PACK_UINT32(&bytes[51], &mystruct->ppg_status);
	PACK_UINT32_ARRAY(&bytes[55], mystruct->ecg_I, 256);
	PACK_UINT32_ARRAY(&bytes[1079], mystruct->ecg_II, 256);
	PACK_UINT32_ARRAY(&bytes[2103], mystruct->abdo, 128);
	PACK_UINT32_ARRAY(&bytes[2615], mystruct->thor, 128);
	PACK_UINT32_ARRAY(&bytes[3127], mystruct->x, 64);
	PACK_UINT32_ARRAY(&bytes[3383], mystruct->y, 64);
	PACK_UINT32_ARRAY(&bytes[3639], mystruct->z, 64);
	PACK_UINT32_ARRAY(&bytes[3895], mystruct->ppg, 64);
	PACK_UINT32(&bytes[4151], &mystruct->temperatureSample);
	PACK_UINT32(&bytes[4155], &mystruct->e_hr);
	PACK_UINT32(&bytes[4159], &mystruct->br);
	PACK_UINT32(&bytes[4163], &mystruct->mv);
	PACK_UINT32(&bytes[4167], &mystruct->vt);
	PACK_UINT32(&bytes[4171], &mystruct->act);
	PACK_UINT32(&bytes[4175], &mystruct->cad);
	PACK_UINT32(&bytes[4179], &mystruct->p_hr);
	PACK_UINT32(&bytes[4183], &mystruct->spo2);
	PACK_FLOAT(&bytes[4187], &mystruct->temperature);
	PACK_UINT32(&bytes[4191], &mystruct->bp);

	return 4195;
}


uint32_t Unpackmda(void *protobetter_type, void *buffer)
{

	mda *mystruct = (mda*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->cfsHeader, &bytes[0], 16);
	UNPACK_UINT8_ARRAY(mystruct->device, &bytes[16], 11);
	UNPACK_UINT64(&mystruct->record, &bytes[27]);
	UNPACK_UINT32(&mystruct->epoch, &bytes[35]);
	UNPACK_UINT32(&mystruct->battery, &bytes[39]);
	UNPACK_UINT32(&mystruct->ecg_status, &bytes[43]);
	UNPACK_UINT32(&mystruct->resp_status, &bytes[47]);
	UNPACK_UINT32(&mystruct->ppg_status, &bytes[51]);
	UNPACK_UINT32_ARRAY(mystruct->ecg_I, &bytes[55], 256);
	UNPACK_UINT32_ARRAY(mystruct->ecg_II, &bytes[1079], 256);
	UNPACK_UINT32_ARRAY(mystruct->abdo, &bytes[2103], 128);
	UNPACK_UINT32_ARRAY(mystruct->thor, &bytes[2615], 128);
	UNPACK_UINT32_ARRAY(mystruct->x, &bytes[3127], 64);
	UNPACK_UINT32_ARRAY(mystruct->y, &bytes[3383], 64);
	UNPACK_UINT32_ARRAY(mystruct->z, &bytes[3639], 64);
	UNPACK_UINT32_ARRAY(mystruct->ppg, &bytes[3895], 64);
	UNPACK_UINT32(&mystruct->temperatureSample, &bytes[4151]);
	UNPACK_UINT32(&mystruct->e_hr, &bytes[4155]);
	UNPACK_UINT32(&mystruct->br, &bytes[4159]);
	UNPACK_UINT32(&mystruct->mv, &bytes[4163]);
	UNPACK_UINT32(&mystruct->vt, &bytes[4167]);
	UNPACK_UINT32(&mystruct->act, &bytes[4171]);
	UNPACK_UINT32(&mystruct->cad, &bytes[4175]);
	UNPACK_UINT32(&mystruct->p_hr, &bytes[4179]);
	UNPACK_UINT32(&mystruct->spo2, &bytes[4183]);
	UNPACK_FLOAT(&mystruct->temperature, &bytes[4187]);
	UNPACK_UINT32(&mystruct->bp, &bytes[4191]);

	return sizeof(mda);
}


