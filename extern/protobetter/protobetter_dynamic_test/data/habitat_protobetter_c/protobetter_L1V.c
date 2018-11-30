#include "protobetter_L1V.h"

uint32_t PackL1V_HAB_VOTE(void *buffer, void *protobetter_type)
{

	L1V_HAB_VOTE *mystruct = (L1V_HAB_VOTE*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->cfsHeader, 16);
	PACK_UINT32(&bytes[16], &mystruct->tbd);

	return 20;
}


uint32_t UnpackL1V_HAB_VOTE(void *protobetter_type, void *buffer)
{

	L1V_HAB_VOTE *mystruct = (L1V_HAB_VOTE*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->cfsHeader, &bytes[0], 16);
	UNPACK_UINT32(&mystruct->tbd, &bytes[16]);

	return sizeof(L1V_HAB_VOTE);
}


