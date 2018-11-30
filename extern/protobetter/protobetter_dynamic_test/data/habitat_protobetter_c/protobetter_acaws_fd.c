#include "protobetter_acaws_fd.h"

uint32_t Packacaws_fd_test_results_msg_type(void *buffer, void *protobetter_type)
{

	acaws_fd_test_results_msg_type *mystruct = (acaws_fd_test_results_msg_type*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->cfsHeader, 16);
	PACK_UINT8_ARRAY(&bytes[16], mystruct->data, CFS_ACAWS_FD_TEST_RESULTS_SERIALIZED_SIZE);

	return 16 + (1*CFS_ACAWS_FD_TEST_RESULTS_SERIALIZED_SIZE);
}


uint32_t Unpackacaws_fd_test_results_msg_type(void *protobetter_type, void *buffer)
{

	acaws_fd_test_results_msg_type *mystruct = (acaws_fd_test_results_msg_type*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->cfsHeader, &bytes[0], 16);
	UNPACK_UINT8_ARRAY(mystruct->data, &bytes[16], CFS_ACAWS_FD_TEST_RESULTS_SERIALIZED_SIZE);

	return sizeof(acaws_fd_test_results_msg_type);
}


uint32_t Packacaws_fd_test_results_type(void *buffer, void *protobetter_type)
{

	acaws_fd_test_results_type *mystruct = (acaws_fd_test_results_type*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->cfsHeader, 16);
	PACK_UINT16(&bytes[16], &mystruct->modes_on_count);
	PACK_UINT16(&bytes[18], &mystruct->test_results_count);
	PACK_UINT8_ARRAY(&bytes[20], mystruct->modes_on, ACAWS_FD_MAX_MODES);
	PACK_UINT8_ARRAY(&bytes[20 + (1*ACAWS_FD_MAX_MODES)], mystruct->test_results, ACAWS_FD_MAX_TESTS);

	return 20 + (1*ACAWS_FD_MAX_MODES) + (1*ACAWS_FD_MAX_TESTS);
}


uint32_t Unpackacaws_fd_test_results_type(void *protobetter_type, void *buffer)
{

	acaws_fd_test_results_type *mystruct = (acaws_fd_test_results_type*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->cfsHeader, &bytes[0], 16);
	UNPACK_UINT16(&mystruct->modes_on_count, &bytes[16]);
	UNPACK_UINT16(&mystruct->test_results_count, &bytes[18]);
	UNPACK_UINT8_ARRAY(mystruct->modes_on, &bytes[20], ACAWS_FD_MAX_MODES);
	UNPACK_UINT8_ARRAY(mystruct->test_results, &bytes[20 + (1*ACAWS_FD_MAX_MODES)], ACAWS_FD_MAX_TESTS);

	return sizeof(acaws_fd_test_results_type);
}


uint32_t PackCFS_ACAWS_FD_WAKEUP_PROCESS_t(void *buffer, void *protobetter_type)
{

	CFS_ACAWS_FD_WAKEUP_PROCESS_t *mystruct = (CFS_ACAWS_FD_WAKEUP_PROCESS_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);

	return 12;
}


uint32_t UnpackCFS_ACAWS_FD_WAKEUP_PROCESS_t(void *protobetter_type, void *buffer)
{

	CFS_ACAWS_FD_WAKEUP_PROCESS_t *mystruct = (CFS_ACAWS_FD_WAKEUP_PROCESS_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);

	return sizeof(CFS_ACAWS_FD_WAKEUP_PROCESS_t);
}


uint32_t PackCFS_ACAWS_FD_WAKEUP_SEND_t(void *buffer, void *protobetter_type)
{

	CFS_ACAWS_FD_WAKEUP_SEND_t *mystruct = (CFS_ACAWS_FD_WAKEUP_SEND_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);

	return 12;
}


uint32_t UnpackCFS_ACAWS_FD_WAKEUP_SEND_t(void *protobetter_type, void *buffer)
{

	CFS_ACAWS_FD_WAKEUP_SEND_t *mystruct = (CFS_ACAWS_FD_WAKEUP_SEND_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);

	return sizeof(CFS_ACAWS_FD_WAKEUP_SEND_t);
}


uint32_t PackACAWS_FD_WAKEUP_MID(void *buffer, void *protobetter_type)
{
	unsigned char *msg = (unsigned char *) protobetter_type;

	uint16_t cmdCode = PROTOBETTER_READ_CCSDS_CODE(msg);

	switch (cmdCode)
	{
		case 0x2:

			return PackCFS_ACAWS_FD_WAKEUP_PROCESS_t(buffer, protobetter_type);

		case 0x3:

			return PackCFS_ACAWS_FD_WAKEUP_SEND_t(buffer, protobetter_type);

		default:

			return 0;
	}
}


uint32_t UnpackACAWS_FD_WAKEUP_MID(void *protobetter_type, void *buffer)
{
	unsigned char *msg = (unsigned char *) buffer;

	uint16_t cmdCode = PROTOBETTER_READ_CCSDS_CODE(msg);

	switch (cmdCode)
	{
		case 0x2:

			return UnpackCFS_ACAWS_FD_WAKEUP_PROCESS_t(protobetter_type, buffer);

		case 0x3:

			return UnpackCFS_ACAWS_FD_WAKEUP_SEND_t(protobetter_type, buffer);

		default:

			return 0;
	}
}


