#include "protobetter_MPCV.h"

uint32_t PackMPCV_NAV_STATE_TLM(void *buffer, void *protobetter_type)
{

	MPCV_NAV_STATE_TLM *mystruct = (MPCV_NAV_STATE_TLM*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->cfsHeader, 16);
	PACK_DOUBLE(&bytes[16], &mystruct->TIME_TDB_SECONDS);
	PACK_DOUBLE(&bytes[24], &mystruct->INRTL_ATT_ROLL);
	PACK_DOUBLE(&bytes[32], &mystruct->INRTL_ATT_PITCH);
	PACK_DOUBLE(&bytes[40], &mystruct->INRTL_ATT_YAW);
	PACK_DOUBLE(&bytes[48], &mystruct->INRTL_POS_X);
	PACK_DOUBLE(&bytes[56], &mystruct->INRTL_POS_Y);
	PACK_DOUBLE(&bytes[64], &mystruct->INRTL_POS_Z);
	PACK_DOUBLE(&bytes[72], &mystruct->TGT_TO_VEH_ATT_ROLL);
	PACK_DOUBLE(&bytes[80], &mystruct->TGT_TO_VEH_ATT_PITCH);
	PACK_DOUBLE(&bytes[88], &mystruct->TGT_TO_VEH_ATT_YAW);
	PACK_DOUBLE(&bytes[96], &mystruct->TGT_TO_VEH_POS_X);
	PACK_DOUBLE(&bytes[104], &mystruct->TGT_TO_VEH_POS_Y);
	PACK_DOUBLE(&bytes[112], &mystruct->TGT_TO_VEH_POS_Z);
	PACK_DOUBLE(&bytes[120], &mystruct->CG_POS_X);
	PACK_DOUBLE(&bytes[128], &mystruct->CG_POS_Y);
	PACK_DOUBLE(&bytes[136], &mystruct->CG_POS_Z);

	return 144;
}


uint32_t UnpackMPCV_NAV_STATE_TLM(void *protobetter_type, void *buffer)
{

	MPCV_NAV_STATE_TLM *mystruct = (MPCV_NAV_STATE_TLM*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->cfsHeader, &bytes[0], 16);
	UNPACK_DOUBLE(&mystruct->TIME_TDB_SECONDS, &bytes[16]);
	UNPACK_DOUBLE(&mystruct->INRTL_ATT_ROLL, &bytes[24]);
	UNPACK_DOUBLE(&mystruct->INRTL_ATT_PITCH, &bytes[32]);
	UNPACK_DOUBLE(&mystruct->INRTL_ATT_YAW, &bytes[40]);
	UNPACK_DOUBLE(&mystruct->INRTL_POS_X, &bytes[48]);
	UNPACK_DOUBLE(&mystruct->INRTL_POS_Y, &bytes[56]);
	UNPACK_DOUBLE(&mystruct->INRTL_POS_Z, &bytes[64]);
	UNPACK_DOUBLE(&mystruct->TGT_TO_VEH_ATT_ROLL, &bytes[72]);
	UNPACK_DOUBLE(&mystruct->TGT_TO_VEH_ATT_PITCH, &bytes[80]);
	UNPACK_DOUBLE(&mystruct->TGT_TO_VEH_ATT_YAW, &bytes[88]);
	UNPACK_DOUBLE(&mystruct->TGT_TO_VEH_POS_X, &bytes[96]);
	UNPACK_DOUBLE(&mystruct->TGT_TO_VEH_POS_Y, &bytes[104]);
	UNPACK_DOUBLE(&mystruct->TGT_TO_VEH_POS_Z, &bytes[112]);
	UNPACK_DOUBLE(&mystruct->CG_POS_X, &bytes[120]);
	UNPACK_DOUBLE(&mystruct->CG_POS_Y, &bytes[128]);
	UNPACK_DOUBLE(&mystruct->CG_POS_Z, &bytes[136]);

	return sizeof(MPCV_NAV_STATE_TLM);
}


