#include "protobetter_DUP.h"

uint32_t PackDUP_HkTlm_t(void *buffer, void *protobetter_type)
{

	DUP_HkTlm_t *mystruct = (DUP_HkTlm_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->cfsHeader, 16);
	PACK_UINT16(&bytes[16], &mystruct->usCmdCnt);
	PACK_UINT16(&bytes[18], &mystruct->usCmdErrCnt);

	return 20;
}


uint32_t UnpackDUP_HkTlm_t(void *protobetter_type, void *buffer)
{

	DUP_HkTlm_t *mystruct = (DUP_HkTlm_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->cfsHeader, &bytes[0], 16);
	UNPACK_UINT16(&mystruct->usCmdCnt, &bytes[16]);
	UNPACK_UINT16(&mystruct->usCmdErrCnt, &bytes[18]);

	return sizeof(DUP_HkTlm_t);
}


uint32_t PackDUP_NOOP_CC_t(void *buffer, void *protobetter_type)
{

	DUP_NOOP_CC_t *mystruct = (DUP_NOOP_CC_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);

	return 12;
}


uint32_t UnpackDUP_NOOP_CC_t(void *protobetter_type, void *buffer)
{

	DUP_NOOP_CC_t *mystruct = (DUP_NOOP_CC_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);

	return sizeof(DUP_NOOP_CC_t);
}


uint32_t PackDUP_PROCESS_CC_t(void *buffer, void *protobetter_type)
{

	DUP_PROCESS_CC_t *mystruct = (DUP_PROCESS_CC_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);

	return 12;
}


uint32_t UnpackDUP_PROCESS_CC_t(void *protobetter_type, void *buffer)
{

	DUP_PROCESS_CC_t *mystruct = (DUP_PROCESS_CC_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);

	return sizeof(DUP_PROCESS_CC_t);
}


uint32_t PackDUP_ADD_CC_t(void *buffer, void *protobetter_type)
{

	DUP_ADD_CC_t *mystruct = (DUP_ADD_CC_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT16(&bytes[12], &mystruct->MID);
	PACK_UINT16(&bytes[14], &mystruct->DupMID);
	PACK_UINT8(&bytes[16], &mystruct->DropPct);
	PACK_UINT8(&bytes[17], &mystruct->ExtraPct);
	PACK_UINT8(&bytes[18], &mystruct->SizeErrPct);
	PACK_UINT8(&bytes[19], &mystruct->DataCorruptErrPct);

	return 20;
}


uint32_t UnpackDUP_ADD_CC_t(void *protobetter_type, void *buffer)
{

	DUP_ADD_CC_t *mystruct = (DUP_ADD_CC_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT16(&mystruct->MID, &bytes[12]);
	UNPACK_UINT16(&mystruct->DupMID, &bytes[14]);
	UNPACK_UINT8(&mystruct->DropPct, &bytes[16]);
	UNPACK_UINT8(&mystruct->ExtraPct, &bytes[17]);
	UNPACK_UINT8(&mystruct->SizeErrPct, &bytes[18]);
	UNPACK_UINT8(&mystruct->DataCorruptErrPct, &bytes[19]);

	return sizeof(DUP_ADD_CC_t);
}


uint32_t PackDUP_DEL_CC_t(void *buffer, void *protobetter_type)
{

	DUP_DEL_CC_t *mystruct = (DUP_DEL_CC_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);

	return 12;
}


uint32_t UnpackDUP_DEL_CC_t(void *protobetter_type, void *buffer)
{

	DUP_DEL_CC_t *mystruct = (DUP_DEL_CC_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);

	return sizeof(DUP_DEL_CC_t);
}


uint32_t PackDUP_HK_CC_t(void *buffer, void *protobetter_type)
{

	DUP_HK_CC_t *mystruct = (DUP_HK_CC_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);

	return 12;
}


uint32_t UnpackDUP_HK_CC_t(void *protobetter_type, void *buffer)
{

	DUP_HK_CC_t *mystruct = (DUP_HK_CC_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);

	return sizeof(DUP_HK_CC_t);
}


uint32_t PackDUP_CMD(void *buffer, void *protobetter_type)
{
	unsigned char *msg = (unsigned char *) protobetter_type;

	uint16_t cmdCode = PROTOBETTER_READ_CCSDS_CODE(msg);

	switch (cmdCode)
	{
		case 0x4:

			return PackDUP_HK_CC_t(buffer, protobetter_type);

		case 0x0:

			return PackDUP_NOOP_CC_t(buffer, protobetter_type);

		case 0x3:

			return PackDUP_DEL_CC_t(buffer, protobetter_type);

		case 0x1:

			return PackDUP_PROCESS_CC_t(buffer, protobetter_type);

		case 0x2:

			return PackDUP_ADD_CC_t(buffer, protobetter_type);

		default:

			return 0;
	}
}


uint32_t UnpackDUP_CMD(void *protobetter_type, void *buffer)
{
	unsigned char *msg = (unsigned char *) buffer;

	uint16_t cmdCode = PROTOBETTER_READ_CCSDS_CODE(msg);

	switch (cmdCode)
	{
		case 0x4:

			return UnpackDUP_HK_CC_t(protobetter_type, buffer);

		case 0x0:

			return UnpackDUP_NOOP_CC_t(protobetter_type, buffer);

		case 0x3:

			return UnpackDUP_DEL_CC_t(protobetter_type, buffer);

		case 0x1:

			return UnpackDUP_PROCESS_CC_t(protobetter_type, buffer);

		case 0x2:

			return UnpackDUP_ADD_CC_t(protobetter_type, buffer);

		default:

			return 0;
	}
}


