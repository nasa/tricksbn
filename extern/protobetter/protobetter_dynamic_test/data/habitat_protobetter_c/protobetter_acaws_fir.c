#include "protobetter_acaws_fir.h"

static inline uint32_t PackACAWS_FIR_ImpactType_t(void *buffer, void *protobetter_type)
{
	uint8_t buffer8 = 0;

	ACAWS_FIR_ImpactType_t *mystruct = (ACAWS_FIR_ImpactType_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;


	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->noImpact, 0, 0xfe);
	PACK_BIT_FIELD(buffer8, mystruct->lor, 1, 0xfd);
	PACK_BIT_FIELD(buffer8, mystruct->func, 2, 0xfb);
	PACK_BIT_FIELD(buffer8, mystruct->pad, 3, 0x7);
	PACK_UINT8(&bytes[0], &buffer8);


	return 1;
}


static inline uint32_t UnpackACAWS_FIR_ImpactType_t(void *protobetter_type, void *buffer)
{
	uint8_t buffer8 = 0;

	ACAWS_FIR_ImpactType_t *mystruct = (ACAWS_FIR_ImpactType_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;


	UNPACK_UINT8(&buffer8, &bytes[0]);
	UNPACK_BIT_FIELD(mystruct->noImpact, buffer8, 0, 0xfe);
	UNPACK_BIT_FIELD(mystruct->lor, buffer8, 1, 0xfd);
	UNPACK_BIT_FIELD(mystruct->func, buffer8, 2, 0xfb);
	UNPACK_BIT_FIELD(mystruct->pad, buffer8, 3, 0x7);


	return sizeof(ACAWS_FIR_ImpactType_t);
}


uint32_t PackACAWS_FIR_HkTlm_t(void *buffer, void *protobetter_type)
{

	ACAWS_FIR_HkTlm_t *mystruct = (ACAWS_FIR_HkTlm_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->cfsHeader, 16);
	PACK_UINT16(&bytes[16], &mystruct->usCmdCnt);
	PACK_UINT16(&bytes[18], &mystruct->usCmdErrCnt);

	return 20;
}


uint32_t UnpackACAWS_FIR_HkTlm_t(void *protobetter_type, void *buffer)
{

	ACAWS_FIR_HkTlm_t *mystruct = (ACAWS_FIR_HkTlm_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->cfsHeader, &bytes[0], 16);
	UNPACK_UINT16(&mystruct->usCmdCnt, &bytes[16]);
	UNPACK_UINT16(&mystruct->usCmdErrCnt, &bytes[18]);

	return sizeof(ACAWS_FIR_HkTlm_t);
}


uint32_t PackACAWS_FIR_OutData_Msg_t(void *buffer, void *protobetter_type)
{

	ACAWS_FIR_OutData_Msg_t *mystruct = (ACAWS_FIR_OutData_Msg_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->cfsHeader, 16);
	PACK_UINT8_ARRAY(&bytes[16], mystruct->data, CFS_ACAWS_FIR_OUTDATA_SERIALIZED_SIZE);

	return 16 + (1*CFS_ACAWS_FIR_OUTDATA_SERIALIZED_SIZE);
}


uint32_t UnpackACAWS_FIR_OutData_Msg_t(void *protobetter_type, void *buffer)
{

	ACAWS_FIR_OutData_Msg_t *mystruct = (ACAWS_FIR_OutData_Msg_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->cfsHeader, &bytes[0], 16);
	UNPACK_UINT8_ARRAY(mystruct->data, &bytes[16], CFS_ACAWS_FIR_OUTDATA_SERIALIZED_SIZE);

	return sizeof(ACAWS_FIR_OutData_Msg_t);
}


uint32_t PackACAWS_FIR_OutData_t(void *buffer, void *protobetter_type)
{

	ACAWS_FIR_OutData_t *mystruct = (ACAWS_FIR_OutData_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->cfsHeader, 16);
	PACK_UINT16(&bytes[16], &mystruct->unique_instance_id);
	PACK_UINT16(&bytes[18], &mystruct->failure_list_cnt);
	PACK_UINT16(&bytes[20], &mystruct->acaws_fir_effects_cnt);
	{
		int ii = 0;
		for(ii = 0; ii < FIR_MAX_ELEM_SIZE; ++ii) {
			PackACAWS_FIR_ImpactType_t(&bytes[22 + (ii*(1))], &mystruct->acaws_fir_effects[ii]);
		}
	}

	return 22 + ((1)*FIR_MAX_ELEM_SIZE);
}


uint32_t UnpackACAWS_FIR_OutData_t(void *protobetter_type, void *buffer)
{

	ACAWS_FIR_OutData_t *mystruct = (ACAWS_FIR_OutData_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->cfsHeader, &bytes[0], 16);
	UNPACK_UINT16(&mystruct->unique_instance_id, &bytes[16]);
	UNPACK_UINT16(&mystruct->failure_list_cnt, &bytes[18]);
	UNPACK_UINT16(&mystruct->acaws_fir_effects_cnt, &bytes[20]);
	{
		int ii = 0;
		for(ii = 0; ii < FIR_MAX_ELEM_SIZE; ++ii) {
			UnpackACAWS_FIR_ImpactType_t(&mystruct->acaws_fir_effects[ii], &bytes[22 + (ii*(1))]);
		}
	}

	return sizeof(ACAWS_FIR_OutData_t);
}


