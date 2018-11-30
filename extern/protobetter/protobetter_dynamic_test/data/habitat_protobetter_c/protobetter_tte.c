#include "protobetter_tte.h"

static inline uint32_t PackTTE_PortInfo_t(void *buffer, void *protobetter_type)
{

	TTE_PortInfo_t *mystruct = (TTE_PortInfo_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	PACK_UINT8_ARRAY(&bytes[0], mystruct->port_name, 48);
	PACK_UINT8_ARRAY(&bytes[48], mystruct->port_dir, 16);
	PACK_UINT8_ARRAY(&bytes[64], mystruct->port_type, 16);
	PACK_UINT8_ARRAY(&bytes[80], mystruct->port_mode, 16);
	PACK_UINT8_ARRAY(&bytes[96], mystruct->task_name, 32);
	PACK_UINT32(&bytes[128], &mystruct->sent_msgs);
	PACK_UINT32(&bytes[132], &mystruct->recv_msgs);
	PACK_UINT32(&bytes[136], &mystruct->sent_msgs_err);
	PACK_UINT32(&bytes[140], &mystruct->recv_msgs_err);
	PACK_UINT32(&bytes[144], &mystruct->recv_channel);
	PACK_UINT32(&bytes[148], &mystruct->recv_drops);
	PACK_UINT8_ARRAY(&bytes[152], mystruct->time_sent, 24);
	PACK_UINT8_ARRAY(&bytes[176], mystruct->time_recv, 24);

	return 200;
}


static inline uint32_t UnpackTTE_PortInfo_t(void *protobetter_type, void *buffer)
{

	TTE_PortInfo_t *mystruct = (TTE_PortInfo_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	UNPACK_UINT8_ARRAY(mystruct->port_name, &bytes[0], 48);
	UNPACK_UINT8_ARRAY(mystruct->port_dir, &bytes[48], 16);
	UNPACK_UINT8_ARRAY(mystruct->port_type, &bytes[64], 16);
	UNPACK_UINT8_ARRAY(mystruct->port_mode, &bytes[80], 16);
	UNPACK_UINT8_ARRAY(mystruct->task_name, &bytes[96], 32);
	UNPACK_UINT32(&mystruct->sent_msgs, &bytes[128]);
	UNPACK_UINT32(&mystruct->recv_msgs, &bytes[132]);
	UNPACK_UINT32(&mystruct->sent_msgs_err, &bytes[136]);
	UNPACK_UINT32(&mystruct->recv_msgs_err, &bytes[140]);
	UNPACK_UINT32(&mystruct->recv_channel, &bytes[144]);
	UNPACK_UINT32(&mystruct->recv_drops, &bytes[148]);
	UNPACK_UINT8_ARRAY(mystruct->time_sent, &bytes[152], 24);
	UNPACK_UINT8_ARRAY(mystruct->time_recv, &bytes[176], 24);

	return sizeof(TTE_PortInfo_t);
}


uint32_t PackTTE_DiagPacket_t(void *buffer, void *protobetter_type)
{

	TTE_DiagPacket_t *mystruct = (TTE_DiagPacket_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->cfsHeader, 16);
	{
		int ii = 0;
		for(ii = 0; ii < TTE_DATAPORT_COUNT_MAX; ++ii) {
			PackTTE_PortInfo_t(&bytes[16 + (ii*(200))], &mystruct->ports[ii]);
		}
	}

	return 16 + ((200)*TTE_DATAPORT_COUNT_MAX);
}


uint32_t UnpackTTE_DiagPacket_t(void *protobetter_type, void *buffer)
{

	TTE_DiagPacket_t *mystruct = (TTE_DiagPacket_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->cfsHeader, &bytes[0], 16);
	{
		int ii = 0;
		for(ii = 0; ii < TTE_DATAPORT_COUNT_MAX; ++ii) {
			UnpackTTE_PortInfo_t(&mystruct->ports[ii], &bytes[16 + (ii*(200))]);
		}
	}

	return sizeof(TTE_DiagPacket_t);
}


uint32_t PackTTE_HkPacket_t(void *buffer, void *protobetter_type)
{

	TTE_HkPacket_t *mystruct = (TTE_HkPacket_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->cfsHeader, 16);
	PACK_UINT32(&bytes[16], &mystruct->app_state);
	PACK_UINT16(&bytes[20], &mystruct->cmd_count);
	PACK_UINT16(&bytes[22], &mystruct->cmd_err_count);

	return 24;
}


uint32_t UnpackTTE_HkPacket_t(void *protobetter_type, void *buffer)
{

	TTE_HkPacket_t *mystruct = (TTE_HkPacket_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->cfsHeader, &bytes[0], 16);
	UNPACK_UINT32(&mystruct->app_state, &bytes[16]);
	UNPACK_UINT16(&mystruct->cmd_count, &bytes[20]);
	UNPACK_UINT16(&mystruct->cmd_err_count, &bytes[22]);

	return sizeof(TTE_HkPacket_t);
}


uint32_t PackTTE_NOOP_CC_t(void *buffer, void *protobetter_type)
{

	TTE_NOOP_CC_t *mystruct = (TTE_NOOP_CC_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);

	return 12;
}


uint32_t UnpackTTE_NOOP_CC_t(void *protobetter_type, void *buffer)
{

	TTE_NOOP_CC_t *mystruct = (TTE_NOOP_CC_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);

	return sizeof(TTE_NOOP_CC_t);
}


uint32_t PackTTE_RESET_CC_t(void *buffer, void *protobetter_type)
{

	TTE_RESET_CC_t *mystruct = (TTE_RESET_CC_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);

	return 12;
}


uint32_t UnpackTTE_RESET_CC_t(void *protobetter_type, void *buffer)
{

	TTE_RESET_CC_t *mystruct = (TTE_RESET_CC_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);

	return sizeof(TTE_RESET_CC_t);
}


uint32_t PackTTE_SEND_DIAG_CC_t(void *buffer, void *protobetter_type)
{

	TTE_SEND_DIAG_CC_t *mystruct = (TTE_SEND_DIAG_CC_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);

	return 12;
}


uint32_t UnpackTTE_SEND_DIAG_CC_t(void *protobetter_type, void *buffer)
{

	TTE_SEND_DIAG_CC_t *mystruct = (TTE_SEND_DIAG_CC_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);

	return sizeof(TTE_SEND_DIAG_CC_t);
}


uint32_t PackTTE_CMD_MID(void *buffer, void *protobetter_type)
{
	unsigned char *msg = (unsigned char *) protobetter_type;

	uint16_t cmdCode = PROTOBETTER_READ_CCSDS_CODE(msg);

	switch (cmdCode)
	{
		case 0x0:

			return PackTTE_NOOP_CC_t(buffer, protobetter_type);

		case 0x2:

			return PackTTE_SEND_DIAG_CC_t(buffer, protobetter_type);

		case 0x1:

			return PackTTE_RESET_CC_t(buffer, protobetter_type);

		default:

			return 0;
	}
}


uint32_t UnpackTTE_CMD_MID(void *protobetter_type, void *buffer)
{
	unsigned char *msg = (unsigned char *) buffer;

	uint16_t cmdCode = PROTOBETTER_READ_CCSDS_CODE(msg);

	switch (cmdCode)
	{
		case 0x0:

			return UnpackTTE_NOOP_CC_t(protobetter_type, buffer);

		case 0x2:

			return UnpackTTE_SEND_DIAG_CC_t(protobetter_type, buffer);

		case 0x1:

			return UnpackTTE_RESET_CC_t(protobetter_type, buffer);

		default:

			return 0;
	}
}


