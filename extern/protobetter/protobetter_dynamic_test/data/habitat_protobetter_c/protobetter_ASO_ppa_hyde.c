#include "protobetter_ASO_ppa_hyde.h"

static inline uint32_t Packhyde_out_t(void *buffer, void *protobetter_type)
{

	hyde_out_t *mystruct = (hyde_out_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	PACK_UINT8(&bytes[0], &mystruct->isFaultless);
	PACK_UINT16(&bytes[1], &mystruct->candidateCount);
	PACK_UINT8_ARRAY(&bytes[3], mystruct->fault, 8);

	return 11;
}


static inline uint32_t Unpackhyde_out_t(void *protobetter_type, void *buffer)
{

	hyde_out_t *mystruct = (hyde_out_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	UNPACK_UINT8(&mystruct->isFaultless, &bytes[0]);
	UNPACK_UINT16(&mystruct->candidateCount, &bytes[1]);
	UNPACK_UINT8_ARRAY(mystruct->fault, &bytes[3], 8);

	return sizeof(hyde_out_t);
}


uint32_t PackPPA_HYDE_HkTlm_t(void *buffer, void *protobetter_type)
{

	PPA_HYDE_HkTlm_t *mystruct = (PPA_HYDE_HkTlm_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->cfsHeader, 16);
	PACK_UINT16(&bytes[16], &mystruct->usCmdCnt);
	PACK_UINT16(&bytes[18], &mystruct->usCmdErrCnt);

	return 20;
}


uint32_t UnpackPPA_HYDE_HkTlm_t(void *protobetter_type, void *buffer)
{

	PPA_HYDE_HkTlm_t *mystruct = (PPA_HYDE_HkTlm_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->cfsHeader, &bytes[0], 16);
	UNPACK_UINT16(&mystruct->usCmdCnt, &bytes[16]);
	UNPACK_UINT16(&mystruct->usCmdErrCnt, &bytes[18]);

	return sizeof(PPA_HYDE_HkTlm_t);
}


uint32_t PackPPA_HYDE_OutData_t(void *buffer, void *protobetter_type)
{

	PPA_HYDE_OutData_t *mystruct = (PPA_HYDE_OutData_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->cfsHeader, 16);
	PACK_UINT32(&bytes[16], &mystruct->uiCounter);
	Packhyde_out_t(&bytes[20], &mystruct->hyde_out);

	return 31;
}


uint32_t UnpackPPA_HYDE_OutData_t(void *protobetter_type, void *buffer)
{

	PPA_HYDE_OutData_t *mystruct = (PPA_HYDE_OutData_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->cfsHeader, &bytes[0], 16);
	UNPACK_UINT32(&mystruct->uiCounter, &bytes[16]);
	Unpackhyde_out_t(&mystruct->hyde_out, &bytes[20]);

	return sizeof(PPA_HYDE_OutData_t);
}


