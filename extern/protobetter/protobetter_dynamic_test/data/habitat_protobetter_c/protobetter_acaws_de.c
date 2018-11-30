#include "protobetter_acaws_de.h"

static inline uint32_t PackTEAMS_failure_t(void *buffer, void *protobetter_type)
{

	TEAMS_failure_t *mystruct = (TEAMS_failure_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	PACK_UINT16(&bytes[0], &mystruct->failure_index);
	PACK_UINT16(&bytes[2], &mystruct->failure_certainty);

	return 4;
}


static inline uint32_t UnpackTEAMS_failure_t(void *protobetter_type, void *buffer)
{

	TEAMS_failure_t *mystruct = (TEAMS_failure_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	UNPACK_UINT16(&mystruct->failure_index, &bytes[0]);
	UNPACK_UINT16(&mystruct->failure_certainty, &bytes[2]);

	return sizeof(TEAMS_failure_t);
}


static inline uint32_t PackTEAMS_health_t(void *buffer, void *protobetter_type)
{
	uint16_t buffer16 = 0;

	TEAMS_health_t *mystruct = (TEAMS_health_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;


	buffer16 = 0;
	PACK_BIT_FIELD(buffer16, mystruct->unknown, 0, 0xfffe);
	PACK_BIT_FIELD(buffer16, mystruct->bad, 1, 0xfffd);
	PACK_BIT_FIELD(buffer16, mystruct->suspect, 2, 0xfffb);
	PACK_BIT_FIELD(buffer16, mystruct->minimal, 3, 0xfff7);
	PACK_BIT_FIELD(buffer16, mystruct->residual, 4, 0xffef);
	PACK_BIT_FIELD(buffer16, mystruct->minimal_group, 5, 0x801f);
	PACK_BIT_FIELD(buffer16, mystruct->minimal_group_ovrflw, 15, 0x7fff);
	PACK_UINT16(&bytes[0], &buffer16);


	return 2;
}


static inline uint32_t UnpackTEAMS_health_t(void *protobetter_type, void *buffer)
{
	uint16_t buffer16 = 0;

	TEAMS_health_t *mystruct = (TEAMS_health_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;


	UNPACK_UINT16(&buffer16, &bytes[0]);
	UNPACK_BIT_FIELD(mystruct->unknown, buffer16, 0, 0xfffe);
	UNPACK_BIT_FIELD(mystruct->bad, buffer16, 1, 0xfffd);
	UNPACK_BIT_FIELD(mystruct->suspect, buffer16, 2, 0xfffb);
	UNPACK_BIT_FIELD(mystruct->minimal, buffer16, 3, 0xfff7);
	UNPACK_BIT_FIELD(mystruct->residual, buffer16, 4, 0xffef);
	UNPACK_BIT_FIELD(mystruct->minimal_group, buffer16, 5, 0x801f);
	UNPACK_BIT_FIELD(mystruct->minimal_group_ovrflw, buffer16, 15, 0x7fff);


	return sizeof(TEAMS_health_t);
}


uint32_t PackACAWS_DE_DiagData_Msg_t(void *buffer, void *protobetter_type)
{

	ACAWS_DE_DiagData_Msg_t *mystruct = (ACAWS_DE_DiagData_Msg_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->cfsHeader, 16);
	PACK_UINT8_ARRAY(&bytes[16], mystruct->data, CFS_ACAWS_DE_DIAG_DATA_SERIALIZED_SIZE);

	return 16 + (1*CFS_ACAWS_DE_DIAG_DATA_SERIALIZED_SIZE);
}


uint32_t UnpackACAWS_DE_DiagData_Msg_t(void *protobetter_type, void *buffer)
{

	ACAWS_DE_DiagData_Msg_t *mystruct = (ACAWS_DE_DiagData_Msg_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->cfsHeader, &bytes[0], 16);
	UNPACK_UINT8_ARRAY(mystruct->data, &bytes[16], CFS_ACAWS_DE_DIAG_DATA_SERIALIZED_SIZE);

	return sizeof(ACAWS_DE_DiagData_Msg_t);
}


uint32_t PackACAWS_DE_DiagData_t(void *buffer, void *protobetter_type)
{

	ACAWS_DE_DiagData_t *mystruct = (ACAWS_DE_DiagData_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->cfsHeader, 16);
	PACK_UINT16(&bytes[16], &mystruct->source_id);
	PACK_UINT16(&bytes[18], &mystruct->session_id);
	PACK_UINT16(&bytes[20], &mystruct->unique_instance_id);
	PACK_UINT16(&bytes[22], &mystruct->aspect_count);
	{
		int ii = 0;
		for(ii = 0; ii < DIAG_MAX_ELEM_SIZE; ++ii) {
			PackTEAMS_health_t(&bytes[24 + (ii*(2))], &mystruct->aspect_diag[ii]);
		}
	}

	return 24 + ((2)*DIAG_MAX_ELEM_SIZE);
}


uint32_t UnpackACAWS_DE_DiagData_t(void *protobetter_type, void *buffer)
{

	ACAWS_DE_DiagData_t *mystruct = (ACAWS_DE_DiagData_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->cfsHeader, &bytes[0], 16);
	UNPACK_UINT16(&mystruct->source_id, &bytes[16]);
	UNPACK_UINT16(&mystruct->session_id, &bytes[18]);
	UNPACK_UINT16(&mystruct->unique_instance_id, &bytes[20]);
	UNPACK_UINT16(&mystruct->aspect_count, &bytes[22]);
	{
		int ii = 0;
		for(ii = 0; ii < DIAG_MAX_ELEM_SIZE; ++ii) {
			UnpackTEAMS_health_t(&mystruct->aspect_diag[ii], &bytes[24 + (ii*(2))]);
		}
	}

	return sizeof(ACAWS_DE_DiagData_t);
}


uint32_t PackACAWS_DE_ImpactReq_Msg_t(void *buffer, void *protobetter_type)
{

	ACAWS_DE_ImpactReq_Msg_t *mystruct = (ACAWS_DE_ImpactReq_Msg_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->cfsHeader, 16);
	PACK_UINT8_ARRAY(&bytes[16], mystruct->data, CFS_ACAWS_DE_IMPACT_REQ_SERIALIZED_SIZE);

	return 16 + (1*CFS_ACAWS_DE_IMPACT_REQ_SERIALIZED_SIZE);
}


uint32_t UnpackACAWS_DE_ImpactReq_Msg_t(void *protobetter_type, void *buffer)
{

	ACAWS_DE_ImpactReq_Msg_t *mystruct = (ACAWS_DE_ImpactReq_Msg_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->cfsHeader, &bytes[0], 16);
	UNPACK_UINT8_ARRAY(mystruct->data, &bytes[16], CFS_ACAWS_DE_IMPACT_REQ_SERIALIZED_SIZE);

	return sizeof(ACAWS_DE_ImpactReq_Msg_t);
}


uint32_t PackACAWS_DE_ImpactReq_t(void *buffer, void *protobetter_type)
{

	ACAWS_DE_ImpactReq_t *mystruct = (ACAWS_DE_ImpactReq_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->cfsHeader, 16);
	PACK_UINT16(&bytes[16], &mystruct->mode_aware);
	PACK_UINT16(&bytes[18], &mystruct->unique_instance_id);
	PACK_UINT16(&bytes[20], &mystruct->failure_list_cnt);
	{
		int ii = 0;
		for(ii = 0; ii < DIAG_MAX_IMPACT_REQ_SIZE; ++ii) {
			PackTEAMS_failure_t(&bytes[22 + (ii*(4))], &mystruct->failure_list[ii]);
		}
	}

	return 22 + ((4)*DIAG_MAX_IMPACT_REQ_SIZE);
}


uint32_t UnpackACAWS_DE_ImpactReq_t(void *protobetter_type, void *buffer)
{

	ACAWS_DE_ImpactReq_t *mystruct = (ACAWS_DE_ImpactReq_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->cfsHeader, &bytes[0], 16);
	UNPACK_UINT16(&mystruct->mode_aware, &bytes[16]);
	UNPACK_UINT16(&mystruct->unique_instance_id, &bytes[18]);
	UNPACK_UINT16(&mystruct->failure_list_cnt, &bytes[20]);
	{
		int ii = 0;
		for(ii = 0; ii < DIAG_MAX_IMPACT_REQ_SIZE; ++ii) {
			UnpackTEAMS_failure_t(&mystruct->failure_list[ii], &bytes[22 + (ii*(4))]);
		}
	}

	return sizeof(ACAWS_DE_ImpactReq_t);
}


