#include "protobetter_AMPS.h"

uint32_t PackMBSU1(void *buffer, void *protobetter_type)
{
	uint8_t buffer8 = 0;

	MBSU1 *mystruct = (MBSU1*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->cfsHeader, 16);
	PACK_UINT8(&bytes[16], &mystruct->MBSU_ID);

	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->SOURCESELECT_STATUS_INPUT1, 0, 0xfc);
	PACK_BIT_FIELD(buffer8, mystruct->SOURCESELECT_STATUS_INPUT2, 2, 0xf3);
	PACK_BIT_FIELD(buffer8, mystruct->SOURCESELECT_STATUS_INPUT3, 4, 0xcf);
	PACK_BIT_FIELD(buffer8, mystruct->SOURCESELECT_STATUS_PAD, 6, 0x3f);
	PACK_UINT8(&bytes[17], &buffer8);


	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->FEEDBACK_STATUS_INPUTRELAY1, 0, 0xfc);
	PACK_BIT_FIELD(buffer8, mystruct->FEEDBACK_STATUS_INPUTRELAY2, 2, 0xf3);
	PACK_BIT_FIELD(buffer8, mystruct->FEEDBACK_STATUS_INPUTRELAY3, 4, 0xcf);
	PACK_BIT_FIELD(buffer8, mystruct->FEEDBACK_STATUS_PAD, 6, 0x3f);
	PACK_UINT8(&bytes[18], &buffer8);

	PACK_UINT8(&bytes[19], &mystruct->MBSU_INPUT_INVALIDBATTERY_ERROR);
	PACK_UINT8(&bytes[20], &mystruct->MBSU_INPUT_INVALIDSOLARARRAY_ERROR);
	PACK_UINT8(&bytes[21], &mystruct->MBSU_INPUT_INVALIDAUXMBSUINPUT_ERROR);
	PACK_UINT8(&bytes[22], &mystruct->MBSU_INPUT_INVALIDAUXMBSUOUTPUT_ERROR);

	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->STATEMISMATCH_ERROR_INPUT_RELAY1, 0, 0xfc);
	PACK_BIT_FIELD(buffer8, mystruct->STATEMISMATCH_ERROR_INPUT_RELAY2, 2, 0xf3);
	PACK_BIT_FIELD(buffer8, mystruct->STATEMISMATCH_ERROR_INPUT_RELAY3, 4, 0xcf);
	PACK_BIT_FIELD(buffer8, mystruct->STATEMISMATCH_ERROR_PAD, 6, 0x3f);
	PACK_UINT8(&bytes[23], &buffer8);


	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->POSNEGSTATEMISMATCH_ERROR_INPUT1, 0, 0xfe);
	PACK_BIT_FIELD(buffer8, mystruct->POSNEGSTATEMISMATCH_ERROR_INPUT2, 1, 0xfd);
	PACK_BIT_FIELD(buffer8, mystruct->POSNEGSTATEMISMATCH_ERROR_INPUT3, 2, 0xfb);
	PACK_BIT_FIELD(buffer8, mystruct->POSNEGSTATEMISMATCH_ERROR_PAD, 3, 0x7);
	PACK_UINT8(&bytes[24], &buffer8);


	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->OUTSTATUS_BUS1, 0, 0xfc);
	PACK_BIT_FIELD(buffer8, mystruct->OUTSTATUS_BUS2, 2, 0xf3);
	PACK_BIT_FIELD(buffer8, mystruct->OUTSTATUS_PAD, 4, 0xf);
	PACK_UINT8(&bytes[25], &buffer8);


	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->RELAYFEEDBACKSTATUS_BUSOUT1, 0, 0xfc);
	PACK_BIT_FIELD(buffer8, mystruct->RELAYFEEDBACKSTATUS_BUSOUT2, 2, 0xf3);
	PACK_BIT_FIELD(buffer8, mystruct->RELAYFEEDBACK_PAD, 4, 0xf);
	PACK_UINT8(&bytes[26], &buffer8);


	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->RELAYSTATEMISMATCHERROR_BUSOUT1, 0, 0xfc);
	PACK_BIT_FIELD(buffer8, mystruct->RELAYSTATEMISMATCHERROR_BUSOUT2, 2, 0xf3);
	PACK_BIT_FIELD(buffer8, mystruct->RELAYSTATE_PAD, 4, 0xf);
	PACK_UINT8(&bytes[27], &buffer8);


	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->MBSU_BUSOUTPPOSNEGSTATEMISMATCHERROR_CHAN1, 0, 0xfe);
	PACK_BIT_FIELD(buffer8, mystruct->MBSU_BUSOUTPPOSNEGSTATEMISMATCHERROR_CHAN2, 1, 0xfd);
	PACK_BIT_FIELD(buffer8, mystruct->MBSU_BUSOUTPPOSNEGSTATEMISMATCHERROR_CHAN3, 2, 0xfb);
	PACK_BIT_FIELD(buffer8, mystruct->MBSU_BUSOUTPPOSNEGSTATEMISMATCHERROR_CHAN4, 3, 0xf7);
	PACK_BIT_FIELD(buffer8, mystruct->MBSU_BUSOUTPPOSNEGSTATEMISMATCHERROR_PAD, 4, 0xf);
	PACK_UINT8(&bytes[28], &buffer8);


	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATE_INPUTRELAY1, 0, 0xfc);
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATE_INPUTRELAY2, 2, 0xf3);
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATE_INPUTRELAY3, 4, 0xcf);
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATE_INPUTRELAY_PAD, 6, 0x3f);
	PACK_UINT8(&bytes[29], &buffer8);


	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATE_OUTPUTRELAY1, 0, 0xfe);
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATE_OUTPUTRELAY2, 1, 0xfd);
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATE_OUTPUTRELAY3, 2, 0xfb);
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATE_OUTPUTRELAY4, 3, 0xf7);
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATE_PAD, 4, 0xf);
	PACK_UINT8(&bytes[30], &buffer8);

	PACK_UINT8(&bytes[31], &mystruct->MBSU_PAD);
	PACK_DOUBLE(&bytes[32], &mystruct->MBSU_SOLAR_ARRAY_INPUT_CURRENT);
	PACK_DOUBLE(&bytes[40], &mystruct->MBSU_BATTERY_BIDIRECTIONAL_CURRENT);
	PACK_DOUBLE(&bytes[48], &mystruct->MBSU_AUXMBSU_BIDIRECTIONAL_CURRENT);
	PACK_DOUBLE(&bytes[56], &mystruct->MBSU_AUX_VOLTAGE);
	PACK_DOUBLE(&bytes[64], &mystruct->MBSU_HKPS_VOLTAGE);
	PACK_DOUBLE(&bytes[72], &mystruct->MBSU_OUTPUT_CURRENT_1);
	PACK_DOUBLE(&bytes[80], &mystruct->MBSU_OUTPUT_CURRENT_2);
	PACK_DOUBLE(&bytes[88], &mystruct->MBSU_OUTPUT_CURRENT_3);
	PACK_DOUBLE(&bytes[96], &mystruct->MBSU_OUTPUT_CURRENT_4);
	PACK_DOUBLE(&bytes[104], &mystruct->MBSU_SARVOLTAGE);
	PACK_DOUBLE(&bytes[112], &mystruct->MBSU_BATTVOLTAGE);
	PACK_DOUBLE(&bytes[120], &mystruct->MBSU_INNERVOLTAGE);
	PACK_DOUBLE(&bytes[128], &mystruct->MBSU_SARCURRTRIPSP);
	PACK_DOUBLE(&bytes[136], &mystruct->MBSU_BATTCURRTRIPSP);
	PACK_DOUBLE(&bytes[144], &mystruct->MBSU_AUXCURRTRIPSP);
	PACK_DOUBLE(&bytes[152], &mystruct->MBSU_OUTPUTCURRTRIPSP_1);
	PACK_DOUBLE(&bytes[160], &mystruct->MBSU_OUTPUTCURRTRIPSP_2);
	PACK_DOUBLE(&bytes[168], &mystruct->MBSU_OUTPUTCURRTRIPSP_3);
	PACK_DOUBLE(&bytes[176], &mystruct->MBSU_OUTPUTCURRTRIPSP_4);

	return 184;
}


uint32_t UnpackMBSU1(void *protobetter_type, void *buffer)
{
	uint8_t buffer8 = 0;

	MBSU1 *mystruct = (MBSU1*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->cfsHeader, &bytes[0], 16);
	UNPACK_UINT8(&mystruct->MBSU_ID, &bytes[16]);

	UNPACK_UINT8(&buffer8, &bytes[17]);
	UNPACK_BIT_FIELD(mystruct->SOURCESELECT_STATUS_INPUT1, buffer8, 0, 0xfc);
	UNPACK_BIT_FIELD(mystruct->SOURCESELECT_STATUS_INPUT2, buffer8, 2, 0xf3);
	UNPACK_BIT_FIELD(mystruct->SOURCESELECT_STATUS_INPUT3, buffer8, 4, 0xcf);
	UNPACK_BIT_FIELD(mystruct->SOURCESELECT_STATUS_PAD, buffer8, 6, 0x3f);


	UNPACK_UINT8(&buffer8, &bytes[18]);
	UNPACK_BIT_FIELD(mystruct->FEEDBACK_STATUS_INPUTRELAY1, buffer8, 0, 0xfc);
	UNPACK_BIT_FIELD(mystruct->FEEDBACK_STATUS_INPUTRELAY2, buffer8, 2, 0xf3);
	UNPACK_BIT_FIELD(mystruct->FEEDBACK_STATUS_INPUTRELAY3, buffer8, 4, 0xcf);
	UNPACK_BIT_FIELD(mystruct->FEEDBACK_STATUS_PAD, buffer8, 6, 0x3f);

	UNPACK_UINT8(&mystruct->MBSU_INPUT_INVALIDBATTERY_ERROR, &bytes[19]);
	UNPACK_UINT8(&mystruct->MBSU_INPUT_INVALIDSOLARARRAY_ERROR, &bytes[20]);
	UNPACK_UINT8(&mystruct->MBSU_INPUT_INVALIDAUXMBSUINPUT_ERROR, &bytes[21]);
	UNPACK_UINT8(&mystruct->MBSU_INPUT_INVALIDAUXMBSUOUTPUT_ERROR, &bytes[22]);

	UNPACK_UINT8(&buffer8, &bytes[23]);
	UNPACK_BIT_FIELD(mystruct->STATEMISMATCH_ERROR_INPUT_RELAY1, buffer8, 0, 0xfc);
	UNPACK_BIT_FIELD(mystruct->STATEMISMATCH_ERROR_INPUT_RELAY2, buffer8, 2, 0xf3);
	UNPACK_BIT_FIELD(mystruct->STATEMISMATCH_ERROR_INPUT_RELAY3, buffer8, 4, 0xcf);
	UNPACK_BIT_FIELD(mystruct->STATEMISMATCH_ERROR_PAD, buffer8, 6, 0x3f);


	UNPACK_UINT8(&buffer8, &bytes[24]);
	UNPACK_BIT_FIELD(mystruct->POSNEGSTATEMISMATCH_ERROR_INPUT1, buffer8, 0, 0xfe);
	UNPACK_BIT_FIELD(mystruct->POSNEGSTATEMISMATCH_ERROR_INPUT2, buffer8, 1, 0xfd);
	UNPACK_BIT_FIELD(mystruct->POSNEGSTATEMISMATCH_ERROR_INPUT3, buffer8, 2, 0xfb);
	UNPACK_BIT_FIELD(mystruct->POSNEGSTATEMISMATCH_ERROR_PAD, buffer8, 3, 0x7);


	UNPACK_UINT8(&buffer8, &bytes[25]);
	UNPACK_BIT_FIELD(mystruct->OUTSTATUS_BUS1, buffer8, 0, 0xfc);
	UNPACK_BIT_FIELD(mystruct->OUTSTATUS_BUS2, buffer8, 2, 0xf3);
	UNPACK_BIT_FIELD(mystruct->OUTSTATUS_PAD, buffer8, 4, 0xf);


	UNPACK_UINT8(&buffer8, &bytes[26]);
	UNPACK_BIT_FIELD(mystruct->RELAYFEEDBACKSTATUS_BUSOUT1, buffer8, 0, 0xfc);
	UNPACK_BIT_FIELD(mystruct->RELAYFEEDBACKSTATUS_BUSOUT2, buffer8, 2, 0xf3);
	UNPACK_BIT_FIELD(mystruct->RELAYFEEDBACK_PAD, buffer8, 4, 0xf);


	UNPACK_UINT8(&buffer8, &bytes[27]);
	UNPACK_BIT_FIELD(mystruct->RELAYSTATEMISMATCHERROR_BUSOUT1, buffer8, 0, 0xfc);
	UNPACK_BIT_FIELD(mystruct->RELAYSTATEMISMATCHERROR_BUSOUT2, buffer8, 2, 0xf3);
	UNPACK_BIT_FIELD(mystruct->RELAYSTATE_PAD, buffer8, 4, 0xf);


	UNPACK_UINT8(&buffer8, &bytes[28]);
	UNPACK_BIT_FIELD(mystruct->MBSU_BUSOUTPPOSNEGSTATEMISMATCHERROR_CHAN1, buffer8, 0, 0xfe);
	UNPACK_BIT_FIELD(mystruct->MBSU_BUSOUTPPOSNEGSTATEMISMATCHERROR_CHAN2, buffer8, 1, 0xfd);
	UNPACK_BIT_FIELD(mystruct->MBSU_BUSOUTPPOSNEGSTATEMISMATCHERROR_CHAN3, buffer8, 2, 0xfb);
	UNPACK_BIT_FIELD(mystruct->MBSU_BUSOUTPPOSNEGSTATEMISMATCHERROR_CHAN4, buffer8, 3, 0xf7);
	UNPACK_BIT_FIELD(mystruct->MBSU_BUSOUTPPOSNEGSTATEMISMATCHERROR_PAD, buffer8, 4, 0xf);


	UNPACK_UINT8(&buffer8, &bytes[29]);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATE_INPUTRELAY1, buffer8, 0, 0xfc);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATE_INPUTRELAY2, buffer8, 2, 0xf3);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATE_INPUTRELAY3, buffer8, 4, 0xcf);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATE_INPUTRELAY_PAD, buffer8, 6, 0x3f);


	UNPACK_UINT8(&buffer8, &bytes[30]);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATE_OUTPUTRELAY1, buffer8, 0, 0xfe);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATE_OUTPUTRELAY2, buffer8, 1, 0xfd);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATE_OUTPUTRELAY3, buffer8, 2, 0xfb);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATE_OUTPUTRELAY4, buffer8, 3, 0xf7);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATE_PAD, buffer8, 4, 0xf);

	UNPACK_UINT8(&mystruct->MBSU_PAD, &bytes[31]);
	UNPACK_DOUBLE(&mystruct->MBSU_SOLAR_ARRAY_INPUT_CURRENT, &bytes[32]);
	UNPACK_DOUBLE(&mystruct->MBSU_BATTERY_BIDIRECTIONAL_CURRENT, &bytes[40]);
	UNPACK_DOUBLE(&mystruct->MBSU_AUXMBSU_BIDIRECTIONAL_CURRENT, &bytes[48]);
	UNPACK_DOUBLE(&mystruct->MBSU_AUX_VOLTAGE, &bytes[56]);
	UNPACK_DOUBLE(&mystruct->MBSU_HKPS_VOLTAGE, &bytes[64]);
	UNPACK_DOUBLE(&mystruct->MBSU_OUTPUT_CURRENT_1, &bytes[72]);
	UNPACK_DOUBLE(&mystruct->MBSU_OUTPUT_CURRENT_2, &bytes[80]);
	UNPACK_DOUBLE(&mystruct->MBSU_OUTPUT_CURRENT_3, &bytes[88]);
	UNPACK_DOUBLE(&mystruct->MBSU_OUTPUT_CURRENT_4, &bytes[96]);
	UNPACK_DOUBLE(&mystruct->MBSU_SARVOLTAGE, &bytes[104]);
	UNPACK_DOUBLE(&mystruct->MBSU_BATTVOLTAGE, &bytes[112]);
	UNPACK_DOUBLE(&mystruct->MBSU_INNERVOLTAGE, &bytes[120]);
	UNPACK_DOUBLE(&mystruct->MBSU_SARCURRTRIPSP, &bytes[128]);
	UNPACK_DOUBLE(&mystruct->MBSU_BATTCURRTRIPSP, &bytes[136]);
	UNPACK_DOUBLE(&mystruct->MBSU_AUXCURRTRIPSP, &bytes[144]);
	UNPACK_DOUBLE(&mystruct->MBSU_OUTPUTCURRTRIPSP_1, &bytes[152]);
	UNPACK_DOUBLE(&mystruct->MBSU_OUTPUTCURRTRIPSP_2, &bytes[160]);
	UNPACK_DOUBLE(&mystruct->MBSU_OUTPUTCURRTRIPSP_3, &bytes[168]);
	UNPACK_DOUBLE(&mystruct->MBSU_OUTPUTCURRTRIPSP_4, &bytes[176]);

	return sizeof(MBSU1);
}


uint32_t PackMBSU2(void *buffer, void *protobetter_type)
{
	uint8_t buffer8 = 0;

	MBSU2 *mystruct = (MBSU2*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->cfsHeader, 16);
	PACK_UINT8(&bytes[16], &mystruct->MBSU_ID);

	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->SOURCESELECT_STATUS_INPUT1, 0, 0xfc);
	PACK_BIT_FIELD(buffer8, mystruct->SOURCESELECT_STATUS_INPUT2, 2, 0xf3);
	PACK_BIT_FIELD(buffer8, mystruct->SOURCESELECT_STATUS_INPUT3, 4, 0xcf);
	PACK_BIT_FIELD(buffer8, mystruct->SOURCESELECT_STATUS_PAD, 6, 0x3f);
	PACK_UINT8(&bytes[17], &buffer8);


	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->FEEDBACK_STATUS_INPUTRELAY1, 0, 0xfc);
	PACK_BIT_FIELD(buffer8, mystruct->FEEDBACK_STATUS_INPUTRELAY2, 2, 0xf3);
	PACK_BIT_FIELD(buffer8, mystruct->FEEDBACK_STATUS_INPUTRELAY3, 4, 0xcf);
	PACK_BIT_FIELD(buffer8, mystruct->FEEDBACK_STATUS_PAD, 6, 0x3f);
	PACK_UINT8(&bytes[18], &buffer8);

	PACK_UINT8(&bytes[19], &mystruct->MBSU_INPUT_INVALIDBATTERY_ERROR);
	PACK_UINT8(&bytes[20], &mystruct->MBSU_INPUT_INVALIDSOLARARRAY_ERROR);
	PACK_UINT8(&bytes[21], &mystruct->MBSU_INPUT_INVALIDAUXMBSUINPUT_ERROR);
	PACK_UINT8(&bytes[22], &mystruct->MBSU_INPUT_INVALIDAUXMBSUOUTPUT_ERROR);

	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->STATEMISMATCH_ERROR_INPUT_RELAY1, 0, 0xfc);
	PACK_BIT_FIELD(buffer8, mystruct->STATEMISMATCH_ERROR_INPUT_RELAY2, 2, 0xf3);
	PACK_BIT_FIELD(buffer8, mystruct->STATEMISMATCH_ERROR_INPUT_RELAY3, 4, 0xcf);
	PACK_BIT_FIELD(buffer8, mystruct->STATEMISMATCH_ERROR_PAD, 6, 0x3f);
	PACK_UINT8(&bytes[23], &buffer8);


	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->POSNEGSTATEMISMATCH_ERROR_INPUT1, 0, 0xfe);
	PACK_BIT_FIELD(buffer8, mystruct->POSNEGSTATEMISMATCH_ERROR_INPUT2, 1, 0xfd);
	PACK_BIT_FIELD(buffer8, mystruct->POSNEGSTATEMISMATCH_ERROR_INPUT3, 2, 0xfb);
	PACK_BIT_FIELD(buffer8, mystruct->POSNEGSTATEMISMATCH_ERROR_PAD, 3, 0x7);
	PACK_UINT8(&bytes[24], &buffer8);


	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->OUTSTATUS_BUS1, 0, 0xfc);
	PACK_BIT_FIELD(buffer8, mystruct->OUTSTATUS_BUS2, 2, 0xf3);
	PACK_BIT_FIELD(buffer8, mystruct->OUTSTATUS_PAD, 4, 0xf);
	PACK_UINT8(&bytes[25], &buffer8);


	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->RELAYFEEDBACKSTATUS_BUSOUT1, 0, 0xfc);
	PACK_BIT_FIELD(buffer8, mystruct->RELAYFEEDBACKSTATUS_BUSOUT2, 2, 0xf3);
	PACK_BIT_FIELD(buffer8, mystruct->RELAYFEEDBACK_PAD, 4, 0xf);
	PACK_UINT8(&bytes[26], &buffer8);


	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->RELAYSTATEMISMATCHERROR_BUSOUT1, 0, 0xfc);
	PACK_BIT_FIELD(buffer8, mystruct->RELAYSTATEMISMATCHERROR_BUSOUT2, 2, 0xf3);
	PACK_BIT_FIELD(buffer8, mystruct->RELAYSTATE_PAD, 4, 0xf);
	PACK_UINT8(&bytes[27], &buffer8);


	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->MBSU_BUSOUTPPOSNEGSTATEMISMATCHERROR_CHAN1, 0, 0xfe);
	PACK_BIT_FIELD(buffer8, mystruct->MBSU_BUSOUTPPOSNEGSTATEMISMATCHERROR_CHAN2, 1, 0xfd);
	PACK_BIT_FIELD(buffer8, mystruct->MBSU_BUSOUTPPOSNEGSTATEMISMATCHERROR_CHAN3, 2, 0xfb);
	PACK_BIT_FIELD(buffer8, mystruct->MBSU_BUSOUTPPOSNEGSTATEMISMATCHERROR_CHAN4, 3, 0xf7);
	PACK_BIT_FIELD(buffer8, mystruct->MBSU_BUSOUTPPOSNEGSTATEMISMATCHERROR_PAD, 4, 0xf);
	PACK_UINT8(&bytes[28], &buffer8);


	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATE_INPUTRELAY1, 0, 0xfc);
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATE_INPUTRELAY2, 2, 0xf3);
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATE_INPUTRELAY3, 4, 0xcf);
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATE_INPUTRELAY_PAD, 6, 0x3f);
	PACK_UINT8(&bytes[29], &buffer8);


	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATE_OUTPUTRELAY1, 0, 0xfe);
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATE_OUTPUTRELAY2, 1, 0xfd);
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATE_OUTPUTRELAY3, 2, 0xfb);
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATE_OUTPUTRELAY4, 3, 0xf7);
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATE_PAD, 4, 0xf);
	PACK_UINT8(&bytes[30], &buffer8);

	PACK_UINT8(&bytes[31], &mystruct->MBSU_PAD);
	PACK_DOUBLE(&bytes[32], &mystruct->MBSU_SOLAR_ARRAY_INPUT_CURRENT);
	PACK_DOUBLE(&bytes[40], &mystruct->MBSU_BATTERY_BIDIRECTIONAL_CURRENT);
	PACK_DOUBLE(&bytes[48], &mystruct->MBSU_AUXMBSU_BIDIRECTIONAL_CURRENT);
	PACK_DOUBLE(&bytes[56], &mystruct->MBSU_AUX_VOLTAGE);
	PACK_DOUBLE(&bytes[64], &mystruct->MBSU_HKPS_VOLTAGE);
	PACK_DOUBLE(&bytes[72], &mystruct->MBSU_OUTPUT_CURRENT_1);
	PACK_DOUBLE(&bytes[80], &mystruct->MBSU_OUTPUT_CURRENT_2);
	PACK_DOUBLE(&bytes[88], &mystruct->MBSU_OUTPUT_CURRENT_3);
	PACK_DOUBLE(&bytes[96], &mystruct->MBSU_OUTPUT_CURRENT_4);
	PACK_DOUBLE(&bytes[104], &mystruct->MBSU_SARVOLTAGE);
	PACK_DOUBLE(&bytes[112], &mystruct->MBSU_BATTVOLTAGE);
	PACK_DOUBLE(&bytes[120], &mystruct->MBSU_INNERVOLTAGE);
	PACK_DOUBLE(&bytes[128], &mystruct->MBSU_SARCURRTRIPSP);
	PACK_DOUBLE(&bytes[136], &mystruct->MBSU_BATTCURRTRIPSP);
	PACK_DOUBLE(&bytes[144], &mystruct->MBSU_AUXCURRTRIPSP);
	PACK_DOUBLE(&bytes[152], &mystruct->MBSU_OUTPUTCURRTRIPSP_1);
	PACK_DOUBLE(&bytes[160], &mystruct->MBSU_OUTPUTCURRTRIPSP_2);
	PACK_DOUBLE(&bytes[168], &mystruct->MBSU_OUTPUTCURRTRIPSP_3);
	PACK_DOUBLE(&bytes[176], &mystruct->MBSU_OUTPUTCURRTRIPSP_4);

	return 184;
}


uint32_t UnpackMBSU2(void *protobetter_type, void *buffer)
{
	uint8_t buffer8 = 0;

	MBSU2 *mystruct = (MBSU2*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->cfsHeader, &bytes[0], 16);
	UNPACK_UINT8(&mystruct->MBSU_ID, &bytes[16]);

	UNPACK_UINT8(&buffer8, &bytes[17]);
	UNPACK_BIT_FIELD(mystruct->SOURCESELECT_STATUS_INPUT1, buffer8, 0, 0xfc);
	UNPACK_BIT_FIELD(mystruct->SOURCESELECT_STATUS_INPUT2, buffer8, 2, 0xf3);
	UNPACK_BIT_FIELD(mystruct->SOURCESELECT_STATUS_INPUT3, buffer8, 4, 0xcf);
	UNPACK_BIT_FIELD(mystruct->SOURCESELECT_STATUS_PAD, buffer8, 6, 0x3f);


	UNPACK_UINT8(&buffer8, &bytes[18]);
	UNPACK_BIT_FIELD(mystruct->FEEDBACK_STATUS_INPUTRELAY1, buffer8, 0, 0xfc);
	UNPACK_BIT_FIELD(mystruct->FEEDBACK_STATUS_INPUTRELAY2, buffer8, 2, 0xf3);
	UNPACK_BIT_FIELD(mystruct->FEEDBACK_STATUS_INPUTRELAY3, buffer8, 4, 0xcf);
	UNPACK_BIT_FIELD(mystruct->FEEDBACK_STATUS_PAD, buffer8, 6, 0x3f);

	UNPACK_UINT8(&mystruct->MBSU_INPUT_INVALIDBATTERY_ERROR, &bytes[19]);
	UNPACK_UINT8(&mystruct->MBSU_INPUT_INVALIDSOLARARRAY_ERROR, &bytes[20]);
	UNPACK_UINT8(&mystruct->MBSU_INPUT_INVALIDAUXMBSUINPUT_ERROR, &bytes[21]);
	UNPACK_UINT8(&mystruct->MBSU_INPUT_INVALIDAUXMBSUOUTPUT_ERROR, &bytes[22]);

	UNPACK_UINT8(&buffer8, &bytes[23]);
	UNPACK_BIT_FIELD(mystruct->STATEMISMATCH_ERROR_INPUT_RELAY1, buffer8, 0, 0xfc);
	UNPACK_BIT_FIELD(mystruct->STATEMISMATCH_ERROR_INPUT_RELAY2, buffer8, 2, 0xf3);
	UNPACK_BIT_FIELD(mystruct->STATEMISMATCH_ERROR_INPUT_RELAY3, buffer8, 4, 0xcf);
	UNPACK_BIT_FIELD(mystruct->STATEMISMATCH_ERROR_PAD, buffer8, 6, 0x3f);


	UNPACK_UINT8(&buffer8, &bytes[24]);
	UNPACK_BIT_FIELD(mystruct->POSNEGSTATEMISMATCH_ERROR_INPUT1, buffer8, 0, 0xfe);
	UNPACK_BIT_FIELD(mystruct->POSNEGSTATEMISMATCH_ERROR_INPUT2, buffer8, 1, 0xfd);
	UNPACK_BIT_FIELD(mystruct->POSNEGSTATEMISMATCH_ERROR_INPUT3, buffer8, 2, 0xfb);
	UNPACK_BIT_FIELD(mystruct->POSNEGSTATEMISMATCH_ERROR_PAD, buffer8, 3, 0x7);


	UNPACK_UINT8(&buffer8, &bytes[25]);
	UNPACK_BIT_FIELD(mystruct->OUTSTATUS_BUS1, buffer8, 0, 0xfc);
	UNPACK_BIT_FIELD(mystruct->OUTSTATUS_BUS2, buffer8, 2, 0xf3);
	UNPACK_BIT_FIELD(mystruct->OUTSTATUS_PAD, buffer8, 4, 0xf);


	UNPACK_UINT8(&buffer8, &bytes[26]);
	UNPACK_BIT_FIELD(mystruct->RELAYFEEDBACKSTATUS_BUSOUT1, buffer8, 0, 0xfc);
	UNPACK_BIT_FIELD(mystruct->RELAYFEEDBACKSTATUS_BUSOUT2, buffer8, 2, 0xf3);
	UNPACK_BIT_FIELD(mystruct->RELAYFEEDBACK_PAD, buffer8, 4, 0xf);


	UNPACK_UINT8(&buffer8, &bytes[27]);
	UNPACK_BIT_FIELD(mystruct->RELAYSTATEMISMATCHERROR_BUSOUT1, buffer8, 0, 0xfc);
	UNPACK_BIT_FIELD(mystruct->RELAYSTATEMISMATCHERROR_BUSOUT2, buffer8, 2, 0xf3);
	UNPACK_BIT_FIELD(mystruct->RELAYSTATE_PAD, buffer8, 4, 0xf);


	UNPACK_UINT8(&buffer8, &bytes[28]);
	UNPACK_BIT_FIELD(mystruct->MBSU_BUSOUTPPOSNEGSTATEMISMATCHERROR_CHAN1, buffer8, 0, 0xfe);
	UNPACK_BIT_FIELD(mystruct->MBSU_BUSOUTPPOSNEGSTATEMISMATCHERROR_CHAN2, buffer8, 1, 0xfd);
	UNPACK_BIT_FIELD(mystruct->MBSU_BUSOUTPPOSNEGSTATEMISMATCHERROR_CHAN3, buffer8, 2, 0xfb);
	UNPACK_BIT_FIELD(mystruct->MBSU_BUSOUTPPOSNEGSTATEMISMATCHERROR_CHAN4, buffer8, 3, 0xf7);
	UNPACK_BIT_FIELD(mystruct->MBSU_BUSOUTPPOSNEGSTATEMISMATCHERROR_PAD, buffer8, 4, 0xf);


	UNPACK_UINT8(&buffer8, &bytes[29]);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATE_INPUTRELAY1, buffer8, 0, 0xfc);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATE_INPUTRELAY2, buffer8, 2, 0xf3);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATE_INPUTRELAY3, buffer8, 4, 0xcf);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATE_INPUTRELAY_PAD, buffer8, 6, 0x3f);


	UNPACK_UINT8(&buffer8, &bytes[30]);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATE_OUTPUTRELAY1, buffer8, 0, 0xfe);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATE_OUTPUTRELAY2, buffer8, 1, 0xfd);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATE_OUTPUTRELAY3, buffer8, 2, 0xfb);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATE_OUTPUTRELAY4, buffer8, 3, 0xf7);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATE_PAD, buffer8, 4, 0xf);

	UNPACK_UINT8(&mystruct->MBSU_PAD, &bytes[31]);
	UNPACK_DOUBLE(&mystruct->MBSU_SOLAR_ARRAY_INPUT_CURRENT, &bytes[32]);
	UNPACK_DOUBLE(&mystruct->MBSU_BATTERY_BIDIRECTIONAL_CURRENT, &bytes[40]);
	UNPACK_DOUBLE(&mystruct->MBSU_AUXMBSU_BIDIRECTIONAL_CURRENT, &bytes[48]);
	UNPACK_DOUBLE(&mystruct->MBSU_AUX_VOLTAGE, &bytes[56]);
	UNPACK_DOUBLE(&mystruct->MBSU_HKPS_VOLTAGE, &bytes[64]);
	UNPACK_DOUBLE(&mystruct->MBSU_OUTPUT_CURRENT_1, &bytes[72]);
	UNPACK_DOUBLE(&mystruct->MBSU_OUTPUT_CURRENT_2, &bytes[80]);
	UNPACK_DOUBLE(&mystruct->MBSU_OUTPUT_CURRENT_3, &bytes[88]);
	UNPACK_DOUBLE(&mystruct->MBSU_OUTPUT_CURRENT_4, &bytes[96]);
	UNPACK_DOUBLE(&mystruct->MBSU_SARVOLTAGE, &bytes[104]);
	UNPACK_DOUBLE(&mystruct->MBSU_BATTVOLTAGE, &bytes[112]);
	UNPACK_DOUBLE(&mystruct->MBSU_INNERVOLTAGE, &bytes[120]);
	UNPACK_DOUBLE(&mystruct->MBSU_SARCURRTRIPSP, &bytes[128]);
	UNPACK_DOUBLE(&mystruct->MBSU_BATTCURRTRIPSP, &bytes[136]);
	UNPACK_DOUBLE(&mystruct->MBSU_AUXCURRTRIPSP, &bytes[144]);
	UNPACK_DOUBLE(&mystruct->MBSU_OUTPUTCURRTRIPSP_1, &bytes[152]);
	UNPACK_DOUBLE(&mystruct->MBSU_OUTPUTCURRTRIPSP_2, &bytes[160]);
	UNPACK_DOUBLE(&mystruct->MBSU_OUTPUTCURRTRIPSP_3, &bytes[168]);
	UNPACK_DOUBLE(&mystruct->MBSU_OUTPUTCURRTRIPSP_4, &bytes[176]);

	return sizeof(MBSU2);
}


uint32_t PackmPDU1(void *buffer, void *protobetter_type)
{

	mPDU1 *mystruct = (mPDU1*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->cfsHeader, 16);
	PACK_UINT8(&bytes[16], &mystruct->UID);
	PACK_UINT16(&bytes[17], &mystruct->TLM_VALID_FLAGS);
	PACK_UINT8(&bytes[19], &mystruct->INPUT1_STATUS);
	PACK_UINT8(&bytes[20], &mystruct->INPUT1_CURRENT_HIGH);
	PACK_UINT8(&bytes[21], &mystruct->INPUT1_CURRENT_LOW);
	PACK_UINT8(&bytes[22], &mystruct->INPUT1_VOLTAGE_EXTERNAL);
	PACK_UINT8(&bytes[23], &mystruct->INPUT1_VOLTAGE_INTERNAL);
	PACK_UINT8(&bytes[24], &mystruct->INPUT2_STATUS);
	PACK_UINT8(&bytes[25], &mystruct->INPUT2_CURRENT_HIGH);
	PACK_UINT8(&bytes[26], &mystruct->INPUT2_CURRENT_LOW);
	PACK_UINT8(&bytes[27], &mystruct->INPUT2_VOLTAGE_EXTERNAL);
	PACK_UINT8(&bytes[28], &mystruct->INPUT2_VOLTAGE_INTERNAL);
	PACK_UINT8(&bytes[29], &mystruct->OUTPUT1_STATUS);
	PACK_UINT8(&bytes[30], &mystruct->OUTPUT1_CURRENT_A);
	PACK_UINT8(&bytes[31], &mystruct->OUTPUT1_CURRENT_B);
	PACK_UINT8(&bytes[32], &mystruct->OUTPUT1_CURRENT_C);
	PACK_UINT8(&bytes[33], &mystruct->OUTPUT1_CURRENT_D);
	PACK_UINT8(&bytes[34], &mystruct->OUTPUT2_STATUS);
	PACK_UINT8(&bytes[35], &mystruct->OUTPUT2_CURRENT_A);
	PACK_UINT8(&bytes[36], &mystruct->OUTPUT2_CURRENT_B);
	PACK_UINT8(&bytes[37], &mystruct->OUTPUT2_CURRENT_C);
	PACK_UINT8(&bytes[38], &mystruct->OUTPUT2_CURRENT_D);
	PACK_UINT8(&bytes[39], &mystruct->OUTPUT3_STATUS);
	PACK_UINT8(&bytes[40], &mystruct->OUTPUT3_CURRENT_A);
	PACK_UINT8(&bytes[41], &mystruct->OUTPUT3_CURRENT_B);
	PACK_UINT8(&bytes[42], &mystruct->OUTPUT3_CURRENT_C);
	PACK_UINT8(&bytes[43], &mystruct->OUTPUT3_CURRENT_D);
	PACK_UINT8(&bytes[44], &mystruct->OUTPUT4_STATUS);
	PACK_UINT8(&bytes[45], &mystruct->OUTPUT4_CURRENT_A);
	PACK_UINT8(&bytes[46], &mystruct->OUTPUT4_CURRENT_B);
	PACK_UINT8(&bytes[47], &mystruct->OUTPUT4_CURRENT_C);
	PACK_UINT8(&bytes[48], &mystruct->OUTPUT4_CURRENT_D);
	PACK_UINT8(&bytes[49], &mystruct->OUTPUT5_STATUS);
	PACK_UINT8(&bytes[50], &mystruct->OUTPUT5_CURRENT_A);
	PACK_UINT8(&bytes[51], &mystruct->OUTPUT5_CURRENT_B);
	PACK_UINT8(&bytes[52], &mystruct->OUTPUT5_CURRENT_C);
	PACK_UINT8(&bytes[53], &mystruct->OUTPUT5_CURRENT_D);
	PACK_UINT8(&bytes[54], &mystruct->OUTPUT6_STATUS);
	PACK_UINT8(&bytes[55], &mystruct->OUTPUT6_CURRENT_A);
	PACK_UINT8(&bytes[56], &mystruct->OUTPUT6_CURRENT_B);
	PACK_UINT8(&bytes[57], &mystruct->OUTPUT6_CURRENT_C);
	PACK_UINT8(&bytes[58], &mystruct->OUTPUT6_CURRENT_D);
	PACK_UINT8(&bytes[59], &mystruct->OUTPUT7_STATUS);
	PACK_UINT8(&bytes[60], &mystruct->OUTPUT7_CURRENT_A);
	PACK_UINT8(&bytes[61], &mystruct->OUTPUT7_CURRENT_B);
	PACK_UINT8(&bytes[62], &mystruct->OUTPUT7_CURRENT_C);
	PACK_UINT8(&bytes[63], &mystruct->OUTPUT7_CURRENT_D);
	PACK_UINT8(&bytes[64], &mystruct->OUTPUT8_STATUS);
	PACK_UINT8(&bytes[65], &mystruct->OUTPUT8_CURRENT_A);
	PACK_UINT8(&bytes[66], &mystruct->OUTPUT8_CURRENT_B);
	PACK_UINT8(&bytes[67], &mystruct->OUTPUT8_CURRENT_C);
	PACK_UINT8(&bytes[68], &mystruct->OUTPUT8_CURRENT_D);

	return 69;
}


uint32_t UnpackmPDU1(void *protobetter_type, void *buffer)
{

	mPDU1 *mystruct = (mPDU1*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->cfsHeader, &bytes[0], 16);
	UNPACK_UINT8(&mystruct->UID, &bytes[16]);
	UNPACK_UINT16(&mystruct->TLM_VALID_FLAGS, &bytes[17]);
	UNPACK_UINT8(&mystruct->INPUT1_STATUS, &bytes[19]);
	UNPACK_UINT8(&mystruct->INPUT1_CURRENT_HIGH, &bytes[20]);
	UNPACK_UINT8(&mystruct->INPUT1_CURRENT_LOW, &bytes[21]);
	UNPACK_UINT8(&mystruct->INPUT1_VOLTAGE_EXTERNAL, &bytes[22]);
	UNPACK_UINT8(&mystruct->INPUT1_VOLTAGE_INTERNAL, &bytes[23]);
	UNPACK_UINT8(&mystruct->INPUT2_STATUS, &bytes[24]);
	UNPACK_UINT8(&mystruct->INPUT2_CURRENT_HIGH, &bytes[25]);
	UNPACK_UINT8(&mystruct->INPUT2_CURRENT_LOW, &bytes[26]);
	UNPACK_UINT8(&mystruct->INPUT2_VOLTAGE_EXTERNAL, &bytes[27]);
	UNPACK_UINT8(&mystruct->INPUT2_VOLTAGE_INTERNAL, &bytes[28]);
	UNPACK_UINT8(&mystruct->OUTPUT1_STATUS, &bytes[29]);
	UNPACK_UINT8(&mystruct->OUTPUT1_CURRENT_A, &bytes[30]);
	UNPACK_UINT8(&mystruct->OUTPUT1_CURRENT_B, &bytes[31]);
	UNPACK_UINT8(&mystruct->OUTPUT1_CURRENT_C, &bytes[32]);
	UNPACK_UINT8(&mystruct->OUTPUT1_CURRENT_D, &bytes[33]);
	UNPACK_UINT8(&mystruct->OUTPUT2_STATUS, &bytes[34]);
	UNPACK_UINT8(&mystruct->OUTPUT2_CURRENT_A, &bytes[35]);
	UNPACK_UINT8(&mystruct->OUTPUT2_CURRENT_B, &bytes[36]);
	UNPACK_UINT8(&mystruct->OUTPUT2_CURRENT_C, &bytes[37]);
	UNPACK_UINT8(&mystruct->OUTPUT2_CURRENT_D, &bytes[38]);
	UNPACK_UINT8(&mystruct->OUTPUT3_STATUS, &bytes[39]);
	UNPACK_UINT8(&mystruct->OUTPUT3_CURRENT_A, &bytes[40]);
	UNPACK_UINT8(&mystruct->OUTPUT3_CURRENT_B, &bytes[41]);
	UNPACK_UINT8(&mystruct->OUTPUT3_CURRENT_C, &bytes[42]);
	UNPACK_UINT8(&mystruct->OUTPUT3_CURRENT_D, &bytes[43]);
	UNPACK_UINT8(&mystruct->OUTPUT4_STATUS, &bytes[44]);
	UNPACK_UINT8(&mystruct->OUTPUT4_CURRENT_A, &bytes[45]);
	UNPACK_UINT8(&mystruct->OUTPUT4_CURRENT_B, &bytes[46]);
	UNPACK_UINT8(&mystruct->OUTPUT4_CURRENT_C, &bytes[47]);
	UNPACK_UINT8(&mystruct->OUTPUT4_CURRENT_D, &bytes[48]);
	UNPACK_UINT8(&mystruct->OUTPUT5_STATUS, &bytes[49]);
	UNPACK_UINT8(&mystruct->OUTPUT5_CURRENT_A, &bytes[50]);
	UNPACK_UINT8(&mystruct->OUTPUT5_CURRENT_B, &bytes[51]);
	UNPACK_UINT8(&mystruct->OUTPUT5_CURRENT_C, &bytes[52]);
	UNPACK_UINT8(&mystruct->OUTPUT5_CURRENT_D, &bytes[53]);
	UNPACK_UINT8(&mystruct->OUTPUT6_STATUS, &bytes[54]);
	UNPACK_UINT8(&mystruct->OUTPUT6_CURRENT_A, &bytes[55]);
	UNPACK_UINT8(&mystruct->OUTPUT6_CURRENT_B, &bytes[56]);
	UNPACK_UINT8(&mystruct->OUTPUT6_CURRENT_C, &bytes[57]);
	UNPACK_UINT8(&mystruct->OUTPUT6_CURRENT_D, &bytes[58]);
	UNPACK_UINT8(&mystruct->OUTPUT7_STATUS, &bytes[59]);
	UNPACK_UINT8(&mystruct->OUTPUT7_CURRENT_A, &bytes[60]);
	UNPACK_UINT8(&mystruct->OUTPUT7_CURRENT_B, &bytes[61]);
	UNPACK_UINT8(&mystruct->OUTPUT7_CURRENT_C, &bytes[62]);
	UNPACK_UINT8(&mystruct->OUTPUT7_CURRENT_D, &bytes[63]);
	UNPACK_UINT8(&mystruct->OUTPUT8_STATUS, &bytes[64]);
	UNPACK_UINT8(&mystruct->OUTPUT8_CURRENT_A, &bytes[65]);
	UNPACK_UINT8(&mystruct->OUTPUT8_CURRENT_B, &bytes[66]);
	UNPACK_UINT8(&mystruct->OUTPUT8_CURRENT_C, &bytes[67]);
	UNPACK_UINT8(&mystruct->OUTPUT8_CURRENT_D, &bytes[68]);

	return sizeof(mPDU1);
}


uint32_t PackPDU1(void *buffer, void *protobetter_type)
{
	uint8_t buffer8 = 0;

	PDU1 *mystruct = (PDU1*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->cfsHeader, 16);
	PACK_UINT8(&bytes[16], &mystruct->PDU_UNITID);

	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->STATUS_INPUTBUS1, 0, 0xfc);
	PACK_BIT_FIELD(buffer8, mystruct->STATUS_INPUTBUS2, 2, 0xf3);
	PACK_BIT_FIELD(buffer8, mystruct->STATUS_INPUTPAD, 4, 0xf);
	PACK_UINT8(&bytes[17], &buffer8);


	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->FEEDBACK_INPUTRELAY1, 0, 0xfc);
	PACK_BIT_FIELD(buffer8, mystruct->FEEDBACK_INPUTRELAY2, 2, 0xf3);
	PACK_BIT_FIELD(buffer8, mystruct->FEEDBACK_INPUT_PAD, 4, 0xf);
	PACK_UINT8(&bytes[18], &buffer8);

	PACK_UINT8(&bytes[19], &mystruct->PDU_INVALIDCOMMANDERROR);

	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->FEEDBACKSTATEMISMATCHERROR_INPUTBUS1, 0, 0xfc);
	PACK_BIT_FIELD(buffer8, mystruct->FEEDBACKSTATEMISMATCHERROR_INPUTBUS2, 2, 0xf3);
	PACK_BIT_FIELD(buffer8, mystruct->FEEDBACKSTATEMISMATCHERROR_PAD, 4, 0xf);
	PACK_UINT8(&bytes[20], &buffer8);


	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->POSNEGMISMATCHERROR_INPUT1, 0, 0xfe);
	PACK_BIT_FIELD(buffer8, mystruct->POSNEGMISMATCHERROR_INPUT2, 1, 0xfd);
	PACK_BIT_FIELD(buffer8, mystruct->POSNEGMISMATCHERROR_PAD, 2, 0x3);
	PACK_UINT8(&bytes[21], &buffer8);


	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->CHANNELSTATUS_RPC1, 0, 0xfe);
	PACK_BIT_FIELD(buffer8, mystruct->CHANNELSTATUS_RPC2, 1, 0xfd);
	PACK_BIT_FIELD(buffer8, mystruct->CHANNELSTATUS_RPC3, 2, 0xfb);
	PACK_BIT_FIELD(buffer8, mystruct->CHANNELSTATUS_RPC4, 3, 0xf7);
	PACK_BIT_FIELD(buffer8, mystruct->CHANNELSTATUS_RPC5, 4, 0xef);
	PACK_BIT_FIELD(buffer8, mystruct->CHANNELSTATUS_RPC6, 5, 0xdf);
	PACK_BIT_FIELD(buffer8, mystruct->CHANNELSTATUS_RPC7, 6, 0xbf);
	PACK_BIT_FIELD(buffer8, mystruct->CHANNELSTATUS_RPC8, 7, 0x7f);
	PACK_UINT8(&bytes[22], &buffer8);


	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATUS_RPC1, 0, 0xfe);
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATUS_RPC2, 1, 0xfd);
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATUS_RPC3, 2, 0xfb);
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATUS_RPC4, 3, 0xf7);
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATUS_RPC5, 4, 0xef);
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATUS_RPC6, 5, 0xdf);
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATUS_RPC7, 6, 0xbf);
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATUS_RPC8, 7, 0x7f);
	PACK_UINT8(&bytes[23], &buffer8);


	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->OUTSTATUS_RPC1, 0, 0xfe);
	PACK_BIT_FIELD(buffer8, mystruct->OUTSTATUS_RPC2, 1, 0xfd);
	PACK_BIT_FIELD(buffer8, mystruct->OUTSTATUS_RPC3, 2, 0xfb);
	PACK_BIT_FIELD(buffer8, mystruct->OUTSTATUS_RPC4, 3, 0xf7);
	PACK_BIT_FIELD(buffer8, mystruct->OUTSTATUS_RPC5, 4, 0xef);
	PACK_BIT_FIELD(buffer8, mystruct->OUTSTATUS_RPC6, 5, 0xdf);
	PACK_BIT_FIELD(buffer8, mystruct->OUTSTATUS_RPC7, 6, 0xbf);
	PACK_BIT_FIELD(buffer8, mystruct->OUTSTATUS_RPC8, 7, 0x7f);
	PACK_UINT8(&bytes[24], &buffer8);


	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->MISMATCHERROR_RPC1, 0, 0xfe);
	PACK_BIT_FIELD(buffer8, mystruct->MISMATCHERROR_RPC2, 1, 0xfd);
	PACK_BIT_FIELD(buffer8, mystruct->MISMATCHERROR_RPC3, 2, 0xfb);
	PACK_BIT_FIELD(buffer8, mystruct->MISMATCHERROR_RPC4, 3, 0xf7);
	PACK_BIT_FIELD(buffer8, mystruct->MISMATCHERROR_RPC5, 4, 0xef);
	PACK_BIT_FIELD(buffer8, mystruct->MISMATCHERROR_RPC6, 5, 0xdf);
	PACK_BIT_FIELD(buffer8, mystruct->MISMATCHERROR_RPC7, 6, 0xbf);
	PACK_BIT_FIELD(buffer8, mystruct->MISMATCHERROR_RPC8, 7, 0x7f);
	PACK_UINT8(&bytes[25], &buffer8);

	PACK_UINT8_ARRAY(&bytes[26], mystruct->PDU_PAD, 6);
	PACK_DOUBLE(&bytes[32], &mystruct->PDU_CURRENTBUS_1);
	PACK_DOUBLE(&bytes[40], &mystruct->PDU_CURRENTBUS_2);
	PACK_DOUBLE(&bytes[48], &mystruct->PDU_CURRENTINTERNALBUS);
	PACK_DOUBLE(&bytes[56], &mystruct->PDU_VOLTAGEBUS_1);
	PACK_DOUBLE(&bytes[64], &mystruct->PDU_VOLTAGEBUS_2);
	PACK_DOUBLE(&bytes[72], &mystruct->PDU_VOLTAGEINTERNAL);
	PACK_DOUBLE(&bytes[80], &mystruct->PDU_VOLTAGEHKPG);
	PACK_DOUBLE(&bytes[88], &mystruct->PDU_CURRENTRPC_1);
	PACK_DOUBLE(&bytes[96], &mystruct->PDU_CURRENTRPC_2);
	PACK_DOUBLE(&bytes[104], &mystruct->PDU_CURRENTRPC_3);
	PACK_DOUBLE(&bytes[112], &mystruct->PDU_CURRENTRPC_4);
	PACK_DOUBLE(&bytes[120], &mystruct->PDU_CURRENTRPC_5);
	PACK_DOUBLE(&bytes[128], &mystruct->PDU_CURRENTRPC_6);
	PACK_DOUBLE(&bytes[136], &mystruct->PDU_CURRENTRPC_7);
	PACK_DOUBLE(&bytes[144], &mystruct->PDU_CURRENTRPC_8);

	return 152;
}


uint32_t UnpackPDU1(void *protobetter_type, void *buffer)
{
	uint8_t buffer8 = 0;

	PDU1 *mystruct = (PDU1*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->cfsHeader, &bytes[0], 16);
	UNPACK_UINT8(&mystruct->PDU_UNITID, &bytes[16]);

	UNPACK_UINT8(&buffer8, &bytes[17]);
	UNPACK_BIT_FIELD(mystruct->STATUS_INPUTBUS1, buffer8, 0, 0xfc);
	UNPACK_BIT_FIELD(mystruct->STATUS_INPUTBUS2, buffer8, 2, 0xf3);
	UNPACK_BIT_FIELD(mystruct->STATUS_INPUTPAD, buffer8, 4, 0xf);


	UNPACK_UINT8(&buffer8, &bytes[18]);
	UNPACK_BIT_FIELD(mystruct->FEEDBACK_INPUTRELAY1, buffer8, 0, 0xfc);
	UNPACK_BIT_FIELD(mystruct->FEEDBACK_INPUTRELAY2, buffer8, 2, 0xf3);
	UNPACK_BIT_FIELD(mystruct->FEEDBACK_INPUT_PAD, buffer8, 4, 0xf);

	UNPACK_UINT8(&mystruct->PDU_INVALIDCOMMANDERROR, &bytes[19]);

	UNPACK_UINT8(&buffer8, &bytes[20]);
	UNPACK_BIT_FIELD(mystruct->FEEDBACKSTATEMISMATCHERROR_INPUTBUS1, buffer8, 0, 0xfc);
	UNPACK_BIT_FIELD(mystruct->FEEDBACKSTATEMISMATCHERROR_INPUTBUS2, buffer8, 2, 0xf3);
	UNPACK_BIT_FIELD(mystruct->FEEDBACKSTATEMISMATCHERROR_PAD, buffer8, 4, 0xf);


	UNPACK_UINT8(&buffer8, &bytes[21]);
	UNPACK_BIT_FIELD(mystruct->POSNEGMISMATCHERROR_INPUT1, buffer8, 0, 0xfe);
	UNPACK_BIT_FIELD(mystruct->POSNEGMISMATCHERROR_INPUT2, buffer8, 1, 0xfd);
	UNPACK_BIT_FIELD(mystruct->POSNEGMISMATCHERROR_PAD, buffer8, 2, 0x3);


	UNPACK_UINT8(&buffer8, &bytes[22]);
	UNPACK_BIT_FIELD(mystruct->CHANNELSTATUS_RPC1, buffer8, 0, 0xfe);
	UNPACK_BIT_FIELD(mystruct->CHANNELSTATUS_RPC2, buffer8, 1, 0xfd);
	UNPACK_BIT_FIELD(mystruct->CHANNELSTATUS_RPC3, buffer8, 2, 0xfb);
	UNPACK_BIT_FIELD(mystruct->CHANNELSTATUS_RPC4, buffer8, 3, 0xf7);
	UNPACK_BIT_FIELD(mystruct->CHANNELSTATUS_RPC5, buffer8, 4, 0xef);
	UNPACK_BIT_FIELD(mystruct->CHANNELSTATUS_RPC6, buffer8, 5, 0xdf);
	UNPACK_BIT_FIELD(mystruct->CHANNELSTATUS_RPC7, buffer8, 6, 0xbf);
	UNPACK_BIT_FIELD(mystruct->CHANNELSTATUS_RPC8, buffer8, 7, 0x7f);


	UNPACK_UINT8(&buffer8, &bytes[23]);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATUS_RPC1, buffer8, 0, 0xfe);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATUS_RPC2, buffer8, 1, 0xfd);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATUS_RPC3, buffer8, 2, 0xfb);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATUS_RPC4, buffer8, 3, 0xf7);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATUS_RPC5, buffer8, 4, 0xef);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATUS_RPC6, buffer8, 5, 0xdf);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATUS_RPC7, buffer8, 6, 0xbf);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATUS_RPC8, buffer8, 7, 0x7f);


	UNPACK_UINT8(&buffer8, &bytes[24]);
	UNPACK_BIT_FIELD(mystruct->OUTSTATUS_RPC1, buffer8, 0, 0xfe);
	UNPACK_BIT_FIELD(mystruct->OUTSTATUS_RPC2, buffer8, 1, 0xfd);
	UNPACK_BIT_FIELD(mystruct->OUTSTATUS_RPC3, buffer8, 2, 0xfb);
	UNPACK_BIT_FIELD(mystruct->OUTSTATUS_RPC4, buffer8, 3, 0xf7);
	UNPACK_BIT_FIELD(mystruct->OUTSTATUS_RPC5, buffer8, 4, 0xef);
	UNPACK_BIT_FIELD(mystruct->OUTSTATUS_RPC6, buffer8, 5, 0xdf);
	UNPACK_BIT_FIELD(mystruct->OUTSTATUS_RPC7, buffer8, 6, 0xbf);
	UNPACK_BIT_FIELD(mystruct->OUTSTATUS_RPC8, buffer8, 7, 0x7f);


	UNPACK_UINT8(&buffer8, &bytes[25]);
	UNPACK_BIT_FIELD(mystruct->MISMATCHERROR_RPC1, buffer8, 0, 0xfe);
	UNPACK_BIT_FIELD(mystruct->MISMATCHERROR_RPC2, buffer8, 1, 0xfd);
	UNPACK_BIT_FIELD(mystruct->MISMATCHERROR_RPC3, buffer8, 2, 0xfb);
	UNPACK_BIT_FIELD(mystruct->MISMATCHERROR_RPC4, buffer8, 3, 0xf7);
	UNPACK_BIT_FIELD(mystruct->MISMATCHERROR_RPC5, buffer8, 4, 0xef);
	UNPACK_BIT_FIELD(mystruct->MISMATCHERROR_RPC6, buffer8, 5, 0xdf);
	UNPACK_BIT_FIELD(mystruct->MISMATCHERROR_RPC7, buffer8, 6, 0xbf);
	UNPACK_BIT_FIELD(mystruct->MISMATCHERROR_RPC8, buffer8, 7, 0x7f);

	UNPACK_UINT8_ARRAY(mystruct->PDU_PAD, &bytes[26], 6);
	UNPACK_DOUBLE(&mystruct->PDU_CURRENTBUS_1, &bytes[32]);
	UNPACK_DOUBLE(&mystruct->PDU_CURRENTBUS_2, &bytes[40]);
	UNPACK_DOUBLE(&mystruct->PDU_CURRENTINTERNALBUS, &bytes[48]);
	UNPACK_DOUBLE(&mystruct->PDU_VOLTAGEBUS_1, &bytes[56]);
	UNPACK_DOUBLE(&mystruct->PDU_VOLTAGEBUS_2, &bytes[64]);
	UNPACK_DOUBLE(&mystruct->PDU_VOLTAGEINTERNAL, &bytes[72]);
	UNPACK_DOUBLE(&mystruct->PDU_VOLTAGEHKPG, &bytes[80]);
	UNPACK_DOUBLE(&mystruct->PDU_CURRENTRPC_1, &bytes[88]);
	UNPACK_DOUBLE(&mystruct->PDU_CURRENTRPC_2, &bytes[96]);
	UNPACK_DOUBLE(&mystruct->PDU_CURRENTRPC_3, &bytes[104]);
	UNPACK_DOUBLE(&mystruct->PDU_CURRENTRPC_4, &bytes[112]);
	UNPACK_DOUBLE(&mystruct->PDU_CURRENTRPC_5, &bytes[120]);
	UNPACK_DOUBLE(&mystruct->PDU_CURRENTRPC_6, &bytes[128]);
	UNPACK_DOUBLE(&mystruct->PDU_CURRENTRPC_7, &bytes[136]);
	UNPACK_DOUBLE(&mystruct->PDU_CURRENTRPC_8, &bytes[144]);

	return sizeof(PDU1);
}


uint32_t PackPDU2(void *buffer, void *protobetter_type)
{
	uint8_t buffer8 = 0;

	PDU2 *mystruct = (PDU2*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->cfsHeader, 16);
	PACK_UINT8(&bytes[16], &mystruct->PDU_UNITID);

	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->STATUS_INPUTBUS1, 0, 0xfc);
	PACK_BIT_FIELD(buffer8, mystruct->STATUS_INPUTBUS2, 2, 0xf3);
	PACK_BIT_FIELD(buffer8, mystruct->STATUS_INPUTPAD, 4, 0xf);
	PACK_UINT8(&bytes[17], &buffer8);


	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->FEEDBACK_INPUTRELAY1, 0, 0xfc);
	PACK_BIT_FIELD(buffer8, mystruct->FEEDBACK_INPUTRELAY2, 2, 0xf3);
	PACK_BIT_FIELD(buffer8, mystruct->FEEDBACK_INPUT_PAD, 4, 0xf);
	PACK_UINT8(&bytes[18], &buffer8);

	PACK_UINT8(&bytes[19], &mystruct->PDU_INVALIDCOMMANDERROR);

	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->FEEDBACKSTATEMISMATCHERROR_INPUTBUS1, 0, 0xfc);
	PACK_BIT_FIELD(buffer8, mystruct->FEEDBACKSTATEMISMATCHERROR_INPUTBUS2, 2, 0xf3);
	PACK_BIT_FIELD(buffer8, mystruct->FEEDBACKSTATEMISMATCHERROR_PAD, 4, 0xf);
	PACK_UINT8(&bytes[20], &buffer8);


	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->POSNEGMISMATCHERROR_INPUT1, 0, 0xfe);
	PACK_BIT_FIELD(buffer8, mystruct->POSNEGMISMATCHERROR_INPUT2, 1, 0xfd);
	PACK_BIT_FIELD(buffer8, mystruct->POSNEGMISMATCHERROR_PAD, 2, 0x3);
	PACK_UINT8(&bytes[21], &buffer8);


	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->CHANNELSTATUS_RPC1, 0, 0xfe);
	PACK_BIT_FIELD(buffer8, mystruct->CHANNELSTATUS_RPC2, 1, 0xfd);
	PACK_BIT_FIELD(buffer8, mystruct->CHANNELSTATUS_RPC3, 2, 0xfb);
	PACK_BIT_FIELD(buffer8, mystruct->CHANNELSTATUS_RPC4, 3, 0xf7);
	PACK_BIT_FIELD(buffer8, mystruct->CHANNELSTATUS_RPC5, 4, 0xef);
	PACK_BIT_FIELD(buffer8, mystruct->CHANNELSTATUS_RPC6, 5, 0xdf);
	PACK_BIT_FIELD(buffer8, mystruct->CHANNELSTATUS_RPC7, 6, 0xbf);
	PACK_BIT_FIELD(buffer8, mystruct->CHANNELSTATUS_RPC8, 7, 0x7f);
	PACK_UINT8(&bytes[22], &buffer8);


	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATUS_RPC1, 0, 0xfe);
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATUS_RPC2, 1, 0xfd);
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATUS_RPC3, 2, 0xfb);
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATUS_RPC4, 3, 0xf7);
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATUS_RPC5, 4, 0xef);
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATUS_RPC6, 5, 0xdf);
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATUS_RPC7, 6, 0xbf);
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATUS_RPC8, 7, 0x7f);
	PACK_UINT8(&bytes[23], &buffer8);


	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->OUTSTATUS_RPC1, 0, 0xfe);
	PACK_BIT_FIELD(buffer8, mystruct->OUTSTATUS_RPC2, 1, 0xfd);
	PACK_BIT_FIELD(buffer8, mystruct->OUTSTATUS_RPC3, 2, 0xfb);
	PACK_BIT_FIELD(buffer8, mystruct->OUTSTATUS_RPC4, 3, 0xf7);
	PACK_BIT_FIELD(buffer8, mystruct->OUTSTATUS_RPC5, 4, 0xef);
	PACK_BIT_FIELD(buffer8, mystruct->OUTSTATUS_RPC6, 5, 0xdf);
	PACK_BIT_FIELD(buffer8, mystruct->OUTSTATUS_RPC7, 6, 0xbf);
	PACK_BIT_FIELD(buffer8, mystruct->OUTSTATUS_RPC8, 7, 0x7f);
	PACK_UINT8(&bytes[24], &buffer8);


	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->MISMATCHERROR_RPC1, 0, 0xfe);
	PACK_BIT_FIELD(buffer8, mystruct->MISMATCHERROR_RPC2, 1, 0xfd);
	PACK_BIT_FIELD(buffer8, mystruct->MISMATCHERROR_RPC3, 2, 0xfb);
	PACK_BIT_FIELD(buffer8, mystruct->MISMATCHERROR_RPC4, 3, 0xf7);
	PACK_BIT_FIELD(buffer8, mystruct->MISMATCHERROR_RPC5, 4, 0xef);
	PACK_BIT_FIELD(buffer8, mystruct->MISMATCHERROR_RPC6, 5, 0xdf);
	PACK_BIT_FIELD(buffer8, mystruct->MISMATCHERROR_RPC7, 6, 0xbf);
	PACK_BIT_FIELD(buffer8, mystruct->MISMATCHERROR_RPC8, 7, 0x7f);
	PACK_UINT8(&bytes[25], &buffer8);

	PACK_UINT8_ARRAY(&bytes[26], mystruct->PDU_PAD, 6);
	PACK_DOUBLE(&bytes[32], &mystruct->PDU_CURRENTBUS_1);
	PACK_DOUBLE(&bytes[40], &mystruct->PDU_CURRENTBUS_2);
	PACK_DOUBLE(&bytes[48], &mystruct->PDU_CURRENTINTERNALBUS);
	PACK_DOUBLE(&bytes[56], &mystruct->PDU_VOLTAGEBUS_1);
	PACK_DOUBLE(&bytes[64], &mystruct->PDU_VOLTAGEBUS_2);
	PACK_DOUBLE(&bytes[72], &mystruct->PDU_VOLTAGEINTERNAL);
	PACK_DOUBLE(&bytes[80], &mystruct->PDU_VOLTAGEHKPG);
	PACK_DOUBLE(&bytes[88], &mystruct->PDU_CURRENTRPC_1);
	PACK_DOUBLE(&bytes[96], &mystruct->PDU_CURRENTRPC_2);
	PACK_DOUBLE(&bytes[104], &mystruct->PDU_CURRENTRPC_3);
	PACK_DOUBLE(&bytes[112], &mystruct->PDU_CURRENTRPC_4);
	PACK_DOUBLE(&bytes[120], &mystruct->PDU_CURRENTRPC_5);
	PACK_DOUBLE(&bytes[128], &mystruct->PDU_CURRENTRPC_6);
	PACK_DOUBLE(&bytes[136], &mystruct->PDU_CURRENTRPC_7);
	PACK_DOUBLE(&bytes[144], &mystruct->PDU_CURRENTRPC_8);

	return 152;
}


uint32_t UnpackPDU2(void *protobetter_type, void *buffer)
{
	uint8_t buffer8 = 0;

	PDU2 *mystruct = (PDU2*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->cfsHeader, &bytes[0], 16);
	UNPACK_UINT8(&mystruct->PDU_UNITID, &bytes[16]);

	UNPACK_UINT8(&buffer8, &bytes[17]);
	UNPACK_BIT_FIELD(mystruct->STATUS_INPUTBUS1, buffer8, 0, 0xfc);
	UNPACK_BIT_FIELD(mystruct->STATUS_INPUTBUS2, buffer8, 2, 0xf3);
	UNPACK_BIT_FIELD(mystruct->STATUS_INPUTPAD, buffer8, 4, 0xf);


	UNPACK_UINT8(&buffer8, &bytes[18]);
	UNPACK_BIT_FIELD(mystruct->FEEDBACK_INPUTRELAY1, buffer8, 0, 0xfc);
	UNPACK_BIT_FIELD(mystruct->FEEDBACK_INPUTRELAY2, buffer8, 2, 0xf3);
	UNPACK_BIT_FIELD(mystruct->FEEDBACK_INPUT_PAD, buffer8, 4, 0xf);

	UNPACK_UINT8(&mystruct->PDU_INVALIDCOMMANDERROR, &bytes[19]);

	UNPACK_UINT8(&buffer8, &bytes[20]);
	UNPACK_BIT_FIELD(mystruct->FEEDBACKSTATEMISMATCHERROR_INPUTBUS1, buffer8, 0, 0xfc);
	UNPACK_BIT_FIELD(mystruct->FEEDBACKSTATEMISMATCHERROR_INPUTBUS2, buffer8, 2, 0xf3);
	UNPACK_BIT_FIELD(mystruct->FEEDBACKSTATEMISMATCHERROR_PAD, buffer8, 4, 0xf);


	UNPACK_UINT8(&buffer8, &bytes[21]);
	UNPACK_BIT_FIELD(mystruct->POSNEGMISMATCHERROR_INPUT1, buffer8, 0, 0xfe);
	UNPACK_BIT_FIELD(mystruct->POSNEGMISMATCHERROR_INPUT2, buffer8, 1, 0xfd);
	UNPACK_BIT_FIELD(mystruct->POSNEGMISMATCHERROR_PAD, buffer8, 2, 0x3);


	UNPACK_UINT8(&buffer8, &bytes[22]);
	UNPACK_BIT_FIELD(mystruct->CHANNELSTATUS_RPC1, buffer8, 0, 0xfe);
	UNPACK_BIT_FIELD(mystruct->CHANNELSTATUS_RPC2, buffer8, 1, 0xfd);
	UNPACK_BIT_FIELD(mystruct->CHANNELSTATUS_RPC3, buffer8, 2, 0xfb);
	UNPACK_BIT_FIELD(mystruct->CHANNELSTATUS_RPC4, buffer8, 3, 0xf7);
	UNPACK_BIT_FIELD(mystruct->CHANNELSTATUS_RPC5, buffer8, 4, 0xef);
	UNPACK_BIT_FIELD(mystruct->CHANNELSTATUS_RPC6, buffer8, 5, 0xdf);
	UNPACK_BIT_FIELD(mystruct->CHANNELSTATUS_RPC7, buffer8, 6, 0xbf);
	UNPACK_BIT_FIELD(mystruct->CHANNELSTATUS_RPC8, buffer8, 7, 0x7f);


	UNPACK_UINT8(&buffer8, &bytes[23]);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATUS_RPC1, buffer8, 0, 0xfe);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATUS_RPC2, buffer8, 1, 0xfd);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATUS_RPC3, buffer8, 2, 0xfb);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATUS_RPC4, buffer8, 3, 0xf7);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATUS_RPC5, buffer8, 4, 0xef);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATUS_RPC6, buffer8, 5, 0xdf);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATUS_RPC7, buffer8, 6, 0xbf);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATUS_RPC8, buffer8, 7, 0x7f);


	UNPACK_UINT8(&buffer8, &bytes[24]);
	UNPACK_BIT_FIELD(mystruct->OUTSTATUS_RPC1, buffer8, 0, 0xfe);
	UNPACK_BIT_FIELD(mystruct->OUTSTATUS_RPC2, buffer8, 1, 0xfd);
	UNPACK_BIT_FIELD(mystruct->OUTSTATUS_RPC3, buffer8, 2, 0xfb);
	UNPACK_BIT_FIELD(mystruct->OUTSTATUS_RPC4, buffer8, 3, 0xf7);
	UNPACK_BIT_FIELD(mystruct->OUTSTATUS_RPC5, buffer8, 4, 0xef);
	UNPACK_BIT_FIELD(mystruct->OUTSTATUS_RPC6, buffer8, 5, 0xdf);
	UNPACK_BIT_FIELD(mystruct->OUTSTATUS_RPC7, buffer8, 6, 0xbf);
	UNPACK_BIT_FIELD(mystruct->OUTSTATUS_RPC8, buffer8, 7, 0x7f);


	UNPACK_UINT8(&buffer8, &bytes[25]);
	UNPACK_BIT_FIELD(mystruct->MISMATCHERROR_RPC1, buffer8, 0, 0xfe);
	UNPACK_BIT_FIELD(mystruct->MISMATCHERROR_RPC2, buffer8, 1, 0xfd);
	UNPACK_BIT_FIELD(mystruct->MISMATCHERROR_RPC3, buffer8, 2, 0xfb);
	UNPACK_BIT_FIELD(mystruct->MISMATCHERROR_RPC4, buffer8, 3, 0xf7);
	UNPACK_BIT_FIELD(mystruct->MISMATCHERROR_RPC5, buffer8, 4, 0xef);
	UNPACK_BIT_FIELD(mystruct->MISMATCHERROR_RPC6, buffer8, 5, 0xdf);
	UNPACK_BIT_FIELD(mystruct->MISMATCHERROR_RPC7, buffer8, 6, 0xbf);
	UNPACK_BIT_FIELD(mystruct->MISMATCHERROR_RPC8, buffer8, 7, 0x7f);

	UNPACK_UINT8_ARRAY(mystruct->PDU_PAD, &bytes[26], 6);
	UNPACK_DOUBLE(&mystruct->PDU_CURRENTBUS_1, &bytes[32]);
	UNPACK_DOUBLE(&mystruct->PDU_CURRENTBUS_2, &bytes[40]);
	UNPACK_DOUBLE(&mystruct->PDU_CURRENTINTERNALBUS, &bytes[48]);
	UNPACK_DOUBLE(&mystruct->PDU_VOLTAGEBUS_1, &bytes[56]);
	UNPACK_DOUBLE(&mystruct->PDU_VOLTAGEBUS_2, &bytes[64]);
	UNPACK_DOUBLE(&mystruct->PDU_VOLTAGEINTERNAL, &bytes[72]);
	UNPACK_DOUBLE(&mystruct->PDU_VOLTAGEHKPG, &bytes[80]);
	UNPACK_DOUBLE(&mystruct->PDU_CURRENTRPC_1, &bytes[88]);
	UNPACK_DOUBLE(&mystruct->PDU_CURRENTRPC_2, &bytes[96]);
	UNPACK_DOUBLE(&mystruct->PDU_CURRENTRPC_3, &bytes[104]);
	UNPACK_DOUBLE(&mystruct->PDU_CURRENTRPC_4, &bytes[112]);
	UNPACK_DOUBLE(&mystruct->PDU_CURRENTRPC_5, &bytes[120]);
	UNPACK_DOUBLE(&mystruct->PDU_CURRENTRPC_6, &bytes[128]);
	UNPACK_DOUBLE(&mystruct->PDU_CURRENTRPC_7, &bytes[136]);
	UNPACK_DOUBLE(&mystruct->PDU_CURRENTRPC_8, &bytes[144]);

	return sizeof(PDU2);
}


uint32_t PackPDU3(void *buffer, void *protobetter_type)
{
	uint8_t buffer8 = 0;

	PDU3 *mystruct = (PDU3*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->cfsHeader, 16);
	PACK_UINT8(&bytes[16], &mystruct->PDU_UNITID);

	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->STATUS_INPUTBUS1, 0, 0xfc);
	PACK_BIT_FIELD(buffer8, mystruct->STATUS_INPUTBUS2, 2, 0xf3);
	PACK_BIT_FIELD(buffer8, mystruct->STATUS_INPUTPAD, 4, 0xf);
	PACK_UINT8(&bytes[17], &buffer8);


	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->FEEDBACK_INPUTRELAY1, 0, 0xfc);
	PACK_BIT_FIELD(buffer8, mystruct->FEEDBACK_INPUTRELAY2, 2, 0xf3);
	PACK_BIT_FIELD(buffer8, mystruct->FEEDBACK_INPUT_PAD, 4, 0xf);
	PACK_UINT8(&bytes[18], &buffer8);

	PACK_UINT8(&bytes[19], &mystruct->PDU_INVALIDCOMMANDERROR);

	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->FEEDBACKSTATEMISMATCHERROR_INPUTBUS1, 0, 0xfc);
	PACK_BIT_FIELD(buffer8, mystruct->FEEDBACKSTATEMISMATCHERROR_INPUTBUS2, 2, 0xf3);
	PACK_BIT_FIELD(buffer8, mystruct->FEEDBACKSTATEMISMATCHERROR_PAD, 4, 0xf);
	PACK_UINT8(&bytes[20], &buffer8);


	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->POSNEGMISMATCHERROR_INPUT1, 0, 0xfe);
	PACK_BIT_FIELD(buffer8, mystruct->POSNEGMISMATCHERROR_INPUT2, 1, 0xfd);
	PACK_BIT_FIELD(buffer8, mystruct->POSNEGMISMATCHERROR_PAD, 2, 0x3);
	PACK_UINT8(&bytes[21], &buffer8);


	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->CHANNELSTATUS_RPC1, 0, 0xfe);
	PACK_BIT_FIELD(buffer8, mystruct->CHANNELSTATUS_RPC2, 1, 0xfd);
	PACK_BIT_FIELD(buffer8, mystruct->CHANNELSTATUS_RPC3, 2, 0xfb);
	PACK_BIT_FIELD(buffer8, mystruct->CHANNELSTATUS_RPC4, 3, 0xf7);
	PACK_BIT_FIELD(buffer8, mystruct->CHANNELSTATUS_RPC5, 4, 0xef);
	PACK_BIT_FIELD(buffer8, mystruct->CHANNELSTATUS_RPC6, 5, 0xdf);
	PACK_BIT_FIELD(buffer8, mystruct->CHANNELSTATUS_RPC7, 6, 0xbf);
	PACK_BIT_FIELD(buffer8, mystruct->CHANNELSTATUS_RPC8, 7, 0x7f);
	PACK_UINT8(&bytes[22], &buffer8);


	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATUS_RPC1, 0, 0xfe);
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATUS_RPC2, 1, 0xfd);
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATUS_RPC3, 2, 0xfb);
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATUS_RPC4, 3, 0xf7);
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATUS_RPC5, 4, 0xef);
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATUS_RPC6, 5, 0xdf);
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATUS_RPC7, 6, 0xbf);
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATUS_RPC8, 7, 0x7f);
	PACK_UINT8(&bytes[23], &buffer8);


	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->OUTSTATUS_RPC1, 0, 0xfe);
	PACK_BIT_FIELD(buffer8, mystruct->OUTSTATUS_RPC2, 1, 0xfd);
	PACK_BIT_FIELD(buffer8, mystruct->OUTSTATUS_RPC3, 2, 0xfb);
	PACK_BIT_FIELD(buffer8, mystruct->OUTSTATUS_RPC4, 3, 0xf7);
	PACK_BIT_FIELD(buffer8, mystruct->OUTSTATUS_RPC5, 4, 0xef);
	PACK_BIT_FIELD(buffer8, mystruct->OUTSTATUS_RPC6, 5, 0xdf);
	PACK_BIT_FIELD(buffer8, mystruct->OUTSTATUS_RPC7, 6, 0xbf);
	PACK_BIT_FIELD(buffer8, mystruct->OUTSTATUS_RPC8, 7, 0x7f);
	PACK_UINT8(&bytes[24], &buffer8);


	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->MISMATCHERROR_RPC1, 0, 0xfe);
	PACK_BIT_FIELD(buffer8, mystruct->MISMATCHERROR_RPC2, 1, 0xfd);
	PACK_BIT_FIELD(buffer8, mystruct->MISMATCHERROR_RPC3, 2, 0xfb);
	PACK_BIT_FIELD(buffer8, mystruct->MISMATCHERROR_RPC4, 3, 0xf7);
	PACK_BIT_FIELD(buffer8, mystruct->MISMATCHERROR_RPC5, 4, 0xef);
	PACK_BIT_FIELD(buffer8, mystruct->MISMATCHERROR_RPC6, 5, 0xdf);
	PACK_BIT_FIELD(buffer8, mystruct->MISMATCHERROR_RPC7, 6, 0xbf);
	PACK_BIT_FIELD(buffer8, mystruct->MISMATCHERROR_RPC8, 7, 0x7f);
	PACK_UINT8(&bytes[25], &buffer8);

	PACK_UINT8_ARRAY(&bytes[26], mystruct->PDU_PAD, 6);
	PACK_DOUBLE(&bytes[32], &mystruct->PDU_CURRENTBUS_1);
	PACK_DOUBLE(&bytes[40], &mystruct->PDU_CURRENTBUS_2);
	PACK_DOUBLE(&bytes[48], &mystruct->PDU_CURRENTINTERNALBUS);
	PACK_DOUBLE(&bytes[56], &mystruct->PDU_VOLTAGEBUS_1);
	PACK_DOUBLE(&bytes[64], &mystruct->PDU_VOLTAGEBUS_2);
	PACK_DOUBLE(&bytes[72], &mystruct->PDU_VOLTAGEINTERNAL);
	PACK_DOUBLE(&bytes[80], &mystruct->PDU_VOLTAGEHKPG);
	PACK_DOUBLE(&bytes[88], &mystruct->PDU_CURRENTRPC_1);
	PACK_DOUBLE(&bytes[96], &mystruct->PDU_CURRENTRPC_2);
	PACK_DOUBLE(&bytes[104], &mystruct->PDU_CURRENTRPC_3);
	PACK_DOUBLE(&bytes[112], &mystruct->PDU_CURRENTRPC_4);
	PACK_DOUBLE(&bytes[120], &mystruct->PDU_CURRENTRPC_5);
	PACK_DOUBLE(&bytes[128], &mystruct->PDU_CURRENTRPC_6);
	PACK_DOUBLE(&bytes[136], &mystruct->PDU_CURRENTRPC_7);
	PACK_DOUBLE(&bytes[144], &mystruct->PDU_CURRENTRPC_8);

	return 152;
}


uint32_t UnpackPDU3(void *protobetter_type, void *buffer)
{
	uint8_t buffer8 = 0;

	PDU3 *mystruct = (PDU3*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->cfsHeader, &bytes[0], 16);
	UNPACK_UINT8(&mystruct->PDU_UNITID, &bytes[16]);

	UNPACK_UINT8(&buffer8, &bytes[17]);
	UNPACK_BIT_FIELD(mystruct->STATUS_INPUTBUS1, buffer8, 0, 0xfc);
	UNPACK_BIT_FIELD(mystruct->STATUS_INPUTBUS2, buffer8, 2, 0xf3);
	UNPACK_BIT_FIELD(mystruct->STATUS_INPUTPAD, buffer8, 4, 0xf);


	UNPACK_UINT8(&buffer8, &bytes[18]);
	UNPACK_BIT_FIELD(mystruct->FEEDBACK_INPUTRELAY1, buffer8, 0, 0xfc);
	UNPACK_BIT_FIELD(mystruct->FEEDBACK_INPUTRELAY2, buffer8, 2, 0xf3);
	UNPACK_BIT_FIELD(mystruct->FEEDBACK_INPUT_PAD, buffer8, 4, 0xf);

	UNPACK_UINT8(&mystruct->PDU_INVALIDCOMMANDERROR, &bytes[19]);

	UNPACK_UINT8(&buffer8, &bytes[20]);
	UNPACK_BIT_FIELD(mystruct->FEEDBACKSTATEMISMATCHERROR_INPUTBUS1, buffer8, 0, 0xfc);
	UNPACK_BIT_FIELD(mystruct->FEEDBACKSTATEMISMATCHERROR_INPUTBUS2, buffer8, 2, 0xf3);
	UNPACK_BIT_FIELD(mystruct->FEEDBACKSTATEMISMATCHERROR_PAD, buffer8, 4, 0xf);


	UNPACK_UINT8(&buffer8, &bytes[21]);
	UNPACK_BIT_FIELD(mystruct->POSNEGMISMATCHERROR_INPUT1, buffer8, 0, 0xfe);
	UNPACK_BIT_FIELD(mystruct->POSNEGMISMATCHERROR_INPUT2, buffer8, 1, 0xfd);
	UNPACK_BIT_FIELD(mystruct->POSNEGMISMATCHERROR_PAD, buffer8, 2, 0x3);


	UNPACK_UINT8(&buffer8, &bytes[22]);
	UNPACK_BIT_FIELD(mystruct->CHANNELSTATUS_RPC1, buffer8, 0, 0xfe);
	UNPACK_BIT_FIELD(mystruct->CHANNELSTATUS_RPC2, buffer8, 1, 0xfd);
	UNPACK_BIT_FIELD(mystruct->CHANNELSTATUS_RPC3, buffer8, 2, 0xfb);
	UNPACK_BIT_FIELD(mystruct->CHANNELSTATUS_RPC4, buffer8, 3, 0xf7);
	UNPACK_BIT_FIELD(mystruct->CHANNELSTATUS_RPC5, buffer8, 4, 0xef);
	UNPACK_BIT_FIELD(mystruct->CHANNELSTATUS_RPC6, buffer8, 5, 0xdf);
	UNPACK_BIT_FIELD(mystruct->CHANNELSTATUS_RPC7, buffer8, 6, 0xbf);
	UNPACK_BIT_FIELD(mystruct->CHANNELSTATUS_RPC8, buffer8, 7, 0x7f);


	UNPACK_UINT8(&buffer8, &bytes[23]);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATUS_RPC1, buffer8, 0, 0xfe);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATUS_RPC2, buffer8, 1, 0xfd);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATUS_RPC3, buffer8, 2, 0xfb);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATUS_RPC4, buffer8, 3, 0xf7);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATUS_RPC5, buffer8, 4, 0xef);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATUS_RPC6, buffer8, 5, 0xdf);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATUS_RPC7, buffer8, 6, 0xbf);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATUS_RPC8, buffer8, 7, 0x7f);


	UNPACK_UINT8(&buffer8, &bytes[24]);
	UNPACK_BIT_FIELD(mystruct->OUTSTATUS_RPC1, buffer8, 0, 0xfe);
	UNPACK_BIT_FIELD(mystruct->OUTSTATUS_RPC2, buffer8, 1, 0xfd);
	UNPACK_BIT_FIELD(mystruct->OUTSTATUS_RPC3, buffer8, 2, 0xfb);
	UNPACK_BIT_FIELD(mystruct->OUTSTATUS_RPC4, buffer8, 3, 0xf7);
	UNPACK_BIT_FIELD(mystruct->OUTSTATUS_RPC5, buffer8, 4, 0xef);
	UNPACK_BIT_FIELD(mystruct->OUTSTATUS_RPC6, buffer8, 5, 0xdf);
	UNPACK_BIT_FIELD(mystruct->OUTSTATUS_RPC7, buffer8, 6, 0xbf);
	UNPACK_BIT_FIELD(mystruct->OUTSTATUS_RPC8, buffer8, 7, 0x7f);


	UNPACK_UINT8(&buffer8, &bytes[25]);
	UNPACK_BIT_FIELD(mystruct->MISMATCHERROR_RPC1, buffer8, 0, 0xfe);
	UNPACK_BIT_FIELD(mystruct->MISMATCHERROR_RPC2, buffer8, 1, 0xfd);
	UNPACK_BIT_FIELD(mystruct->MISMATCHERROR_RPC3, buffer8, 2, 0xfb);
	UNPACK_BIT_FIELD(mystruct->MISMATCHERROR_RPC4, buffer8, 3, 0xf7);
	UNPACK_BIT_FIELD(mystruct->MISMATCHERROR_RPC5, buffer8, 4, 0xef);
	UNPACK_BIT_FIELD(mystruct->MISMATCHERROR_RPC6, buffer8, 5, 0xdf);
	UNPACK_BIT_FIELD(mystruct->MISMATCHERROR_RPC7, buffer8, 6, 0xbf);
	UNPACK_BIT_FIELD(mystruct->MISMATCHERROR_RPC8, buffer8, 7, 0x7f);

	UNPACK_UINT8_ARRAY(mystruct->PDU_PAD, &bytes[26], 6);
	UNPACK_DOUBLE(&mystruct->PDU_CURRENTBUS_1, &bytes[32]);
	UNPACK_DOUBLE(&mystruct->PDU_CURRENTBUS_2, &bytes[40]);
	UNPACK_DOUBLE(&mystruct->PDU_CURRENTINTERNALBUS, &bytes[48]);
	UNPACK_DOUBLE(&mystruct->PDU_VOLTAGEBUS_1, &bytes[56]);
	UNPACK_DOUBLE(&mystruct->PDU_VOLTAGEBUS_2, &bytes[64]);
	UNPACK_DOUBLE(&mystruct->PDU_VOLTAGEINTERNAL, &bytes[72]);
	UNPACK_DOUBLE(&mystruct->PDU_VOLTAGEHKPG, &bytes[80]);
	UNPACK_DOUBLE(&mystruct->PDU_CURRENTRPC_1, &bytes[88]);
	UNPACK_DOUBLE(&mystruct->PDU_CURRENTRPC_2, &bytes[96]);
	UNPACK_DOUBLE(&mystruct->PDU_CURRENTRPC_3, &bytes[104]);
	UNPACK_DOUBLE(&mystruct->PDU_CURRENTRPC_4, &bytes[112]);
	UNPACK_DOUBLE(&mystruct->PDU_CURRENTRPC_5, &bytes[120]);
	UNPACK_DOUBLE(&mystruct->PDU_CURRENTRPC_6, &bytes[128]);
	UNPACK_DOUBLE(&mystruct->PDU_CURRENTRPC_7, &bytes[136]);
	UNPACK_DOUBLE(&mystruct->PDU_CURRENTRPC_8, &bytes[144]);

	return sizeof(PDU3);
}


uint32_t PackPDU4(void *buffer, void *protobetter_type)
{
	uint8_t buffer8 = 0;

	PDU4 *mystruct = (PDU4*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->cfsHeader, 16);
	PACK_UINT8(&bytes[16], &mystruct->PDU_UNITID);

	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->STATUS_INPUTBUS1, 0, 0xfc);
	PACK_BIT_FIELD(buffer8, mystruct->STATUS_INPUTBUS2, 2, 0xf3);
	PACK_BIT_FIELD(buffer8, mystruct->STATUS_INPUTPAD, 4, 0xf);
	PACK_UINT8(&bytes[17], &buffer8);


	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->FEEDBACK_INPUTRELAY1, 0, 0xfc);
	PACK_BIT_FIELD(buffer8, mystruct->FEEDBACK_INPUTRELAY2, 2, 0xf3);
	PACK_BIT_FIELD(buffer8, mystruct->FEEDBACK_INPUT_PAD, 4, 0xf);
	PACK_UINT8(&bytes[18], &buffer8);

	PACK_UINT8(&bytes[19], &mystruct->PDU_INVALIDCOMMANDERROR);

	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->FEEDBACKSTATEMISMATCHERROR_INPUTBUS1, 0, 0xfc);
	PACK_BIT_FIELD(buffer8, mystruct->FEEDBACKSTATEMISMATCHERROR_INPUTBUS2, 2, 0xf3);
	PACK_BIT_FIELD(buffer8, mystruct->FEEDBACKSTATEMISMATCHERROR_PAD, 4, 0xf);
	PACK_UINT8(&bytes[20], &buffer8);


	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->POSNEGMISMATCHERROR_INPUT1, 0, 0xfe);
	PACK_BIT_FIELD(buffer8, mystruct->POSNEGMISMATCHERROR_INPUT2, 1, 0xfd);
	PACK_BIT_FIELD(buffer8, mystruct->POSNEGMISMATCHERROR_PAD, 2, 0x3);
	PACK_UINT8(&bytes[21], &buffer8);


	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->CHANNELSTATUS_RPC1, 0, 0xfe);
	PACK_BIT_FIELD(buffer8, mystruct->CHANNELSTATUS_RPC2, 1, 0xfd);
	PACK_BIT_FIELD(buffer8, mystruct->CHANNELSTATUS_RPC3, 2, 0xfb);
	PACK_BIT_FIELD(buffer8, mystruct->CHANNELSTATUS_RPC4, 3, 0xf7);
	PACK_BIT_FIELD(buffer8, mystruct->CHANNELSTATUS_RPC5, 4, 0xef);
	PACK_BIT_FIELD(buffer8, mystruct->CHANNELSTATUS_RPC6, 5, 0xdf);
	PACK_BIT_FIELD(buffer8, mystruct->CHANNELSTATUS_RPC7, 6, 0xbf);
	PACK_BIT_FIELD(buffer8, mystruct->CHANNELSTATUS_RPC8, 7, 0x7f);
	PACK_UINT8(&bytes[22], &buffer8);


	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATUS_RPC1, 0, 0xfe);
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATUS_RPC2, 1, 0xfd);
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATUS_RPC3, 2, 0xfb);
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATUS_RPC4, 3, 0xf7);
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATUS_RPC5, 4, 0xef);
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATUS_RPC6, 5, 0xdf);
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATUS_RPC7, 6, 0xbf);
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATUS_RPC8, 7, 0x7f);
	PACK_UINT8(&bytes[23], &buffer8);


	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->OUTSTATUS_RPC1, 0, 0xfe);
	PACK_BIT_FIELD(buffer8, mystruct->OUTSTATUS_RPC2, 1, 0xfd);
	PACK_BIT_FIELD(buffer8, mystruct->OUTSTATUS_RPC3, 2, 0xfb);
	PACK_BIT_FIELD(buffer8, mystruct->OUTSTATUS_RPC4, 3, 0xf7);
	PACK_BIT_FIELD(buffer8, mystruct->OUTSTATUS_RPC5, 4, 0xef);
	PACK_BIT_FIELD(buffer8, mystruct->OUTSTATUS_RPC6, 5, 0xdf);
	PACK_BIT_FIELD(buffer8, mystruct->OUTSTATUS_RPC7, 6, 0xbf);
	PACK_BIT_FIELD(buffer8, mystruct->OUTSTATUS_RPC8, 7, 0x7f);
	PACK_UINT8(&bytes[24], &buffer8);


	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->MISMATCHERROR_RPC1, 0, 0xfe);
	PACK_BIT_FIELD(buffer8, mystruct->MISMATCHERROR_RPC2, 1, 0xfd);
	PACK_BIT_FIELD(buffer8, mystruct->MISMATCHERROR_RPC3, 2, 0xfb);
	PACK_BIT_FIELD(buffer8, mystruct->MISMATCHERROR_RPC4, 3, 0xf7);
	PACK_BIT_FIELD(buffer8, mystruct->MISMATCHERROR_RPC5, 4, 0xef);
	PACK_BIT_FIELD(buffer8, mystruct->MISMATCHERROR_RPC6, 5, 0xdf);
	PACK_BIT_FIELD(buffer8, mystruct->MISMATCHERROR_RPC7, 6, 0xbf);
	PACK_BIT_FIELD(buffer8, mystruct->MISMATCHERROR_RPC8, 7, 0x7f);
	PACK_UINT8(&bytes[25], &buffer8);

	PACK_UINT8_ARRAY(&bytes[26], mystruct->PDU_PAD, 6);
	PACK_DOUBLE(&bytes[32], &mystruct->PDU_CURRENTBUS_1);
	PACK_DOUBLE(&bytes[40], &mystruct->PDU_CURRENTBUS_2);
	PACK_DOUBLE(&bytes[48], &mystruct->PDU_CURRENTINTERNALBUS);
	PACK_DOUBLE(&bytes[56], &mystruct->PDU_VOLTAGEBUS_1);
	PACK_DOUBLE(&bytes[64], &mystruct->PDU_VOLTAGEBUS_2);
	PACK_DOUBLE(&bytes[72], &mystruct->PDU_VOLTAGEINTERNAL);
	PACK_DOUBLE(&bytes[80], &mystruct->PDU_VOLTAGEHKPG);
	PACK_DOUBLE(&bytes[88], &mystruct->PDU_CURRENTRPC_1);
	PACK_DOUBLE(&bytes[96], &mystruct->PDU_CURRENTRPC_2);
	PACK_DOUBLE(&bytes[104], &mystruct->PDU_CURRENTRPC_3);
	PACK_DOUBLE(&bytes[112], &mystruct->PDU_CURRENTRPC_4);
	PACK_DOUBLE(&bytes[120], &mystruct->PDU_CURRENTRPC_5);
	PACK_DOUBLE(&bytes[128], &mystruct->PDU_CURRENTRPC_6);
	PACK_DOUBLE(&bytes[136], &mystruct->PDU_CURRENTRPC_7);
	PACK_DOUBLE(&bytes[144], &mystruct->PDU_CURRENTRPC_8);

	return 152;
}


uint32_t UnpackPDU4(void *protobetter_type, void *buffer)
{
	uint8_t buffer8 = 0;

	PDU4 *mystruct = (PDU4*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->cfsHeader, &bytes[0], 16);
	UNPACK_UINT8(&mystruct->PDU_UNITID, &bytes[16]);

	UNPACK_UINT8(&buffer8, &bytes[17]);
	UNPACK_BIT_FIELD(mystruct->STATUS_INPUTBUS1, buffer8, 0, 0xfc);
	UNPACK_BIT_FIELD(mystruct->STATUS_INPUTBUS2, buffer8, 2, 0xf3);
	UNPACK_BIT_FIELD(mystruct->STATUS_INPUTPAD, buffer8, 4, 0xf);


	UNPACK_UINT8(&buffer8, &bytes[18]);
	UNPACK_BIT_FIELD(mystruct->FEEDBACK_INPUTRELAY1, buffer8, 0, 0xfc);
	UNPACK_BIT_FIELD(mystruct->FEEDBACK_INPUTRELAY2, buffer8, 2, 0xf3);
	UNPACK_BIT_FIELD(mystruct->FEEDBACK_INPUT_PAD, buffer8, 4, 0xf);

	UNPACK_UINT8(&mystruct->PDU_INVALIDCOMMANDERROR, &bytes[19]);

	UNPACK_UINT8(&buffer8, &bytes[20]);
	UNPACK_BIT_FIELD(mystruct->FEEDBACKSTATEMISMATCHERROR_INPUTBUS1, buffer8, 0, 0xfc);
	UNPACK_BIT_FIELD(mystruct->FEEDBACKSTATEMISMATCHERROR_INPUTBUS2, buffer8, 2, 0xf3);
	UNPACK_BIT_FIELD(mystruct->FEEDBACKSTATEMISMATCHERROR_PAD, buffer8, 4, 0xf);


	UNPACK_UINT8(&buffer8, &bytes[21]);
	UNPACK_BIT_FIELD(mystruct->POSNEGMISMATCHERROR_INPUT1, buffer8, 0, 0xfe);
	UNPACK_BIT_FIELD(mystruct->POSNEGMISMATCHERROR_INPUT2, buffer8, 1, 0xfd);
	UNPACK_BIT_FIELD(mystruct->POSNEGMISMATCHERROR_PAD, buffer8, 2, 0x3);


	UNPACK_UINT8(&buffer8, &bytes[22]);
	UNPACK_BIT_FIELD(mystruct->CHANNELSTATUS_RPC1, buffer8, 0, 0xfe);
	UNPACK_BIT_FIELD(mystruct->CHANNELSTATUS_RPC2, buffer8, 1, 0xfd);
	UNPACK_BIT_FIELD(mystruct->CHANNELSTATUS_RPC3, buffer8, 2, 0xfb);
	UNPACK_BIT_FIELD(mystruct->CHANNELSTATUS_RPC4, buffer8, 3, 0xf7);
	UNPACK_BIT_FIELD(mystruct->CHANNELSTATUS_RPC5, buffer8, 4, 0xef);
	UNPACK_BIT_FIELD(mystruct->CHANNELSTATUS_RPC6, buffer8, 5, 0xdf);
	UNPACK_BIT_FIELD(mystruct->CHANNELSTATUS_RPC7, buffer8, 6, 0xbf);
	UNPACK_BIT_FIELD(mystruct->CHANNELSTATUS_RPC8, buffer8, 7, 0x7f);


	UNPACK_UINT8(&buffer8, &bytes[23]);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATUS_RPC1, buffer8, 0, 0xfe);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATUS_RPC2, buffer8, 1, 0xfd);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATUS_RPC3, buffer8, 2, 0xfb);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATUS_RPC4, buffer8, 3, 0xf7);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATUS_RPC5, buffer8, 4, 0xef);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATUS_RPC6, buffer8, 5, 0xdf);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATUS_RPC7, buffer8, 6, 0xbf);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATUS_RPC8, buffer8, 7, 0x7f);


	UNPACK_UINT8(&buffer8, &bytes[24]);
	UNPACK_BIT_FIELD(mystruct->OUTSTATUS_RPC1, buffer8, 0, 0xfe);
	UNPACK_BIT_FIELD(mystruct->OUTSTATUS_RPC2, buffer8, 1, 0xfd);
	UNPACK_BIT_FIELD(mystruct->OUTSTATUS_RPC3, buffer8, 2, 0xfb);
	UNPACK_BIT_FIELD(mystruct->OUTSTATUS_RPC4, buffer8, 3, 0xf7);
	UNPACK_BIT_FIELD(mystruct->OUTSTATUS_RPC5, buffer8, 4, 0xef);
	UNPACK_BIT_FIELD(mystruct->OUTSTATUS_RPC6, buffer8, 5, 0xdf);
	UNPACK_BIT_FIELD(mystruct->OUTSTATUS_RPC7, buffer8, 6, 0xbf);
	UNPACK_BIT_FIELD(mystruct->OUTSTATUS_RPC8, buffer8, 7, 0x7f);


	UNPACK_UINT8(&buffer8, &bytes[25]);
	UNPACK_BIT_FIELD(mystruct->MISMATCHERROR_RPC1, buffer8, 0, 0xfe);
	UNPACK_BIT_FIELD(mystruct->MISMATCHERROR_RPC2, buffer8, 1, 0xfd);
	UNPACK_BIT_FIELD(mystruct->MISMATCHERROR_RPC3, buffer8, 2, 0xfb);
	UNPACK_BIT_FIELD(mystruct->MISMATCHERROR_RPC4, buffer8, 3, 0xf7);
	UNPACK_BIT_FIELD(mystruct->MISMATCHERROR_RPC5, buffer8, 4, 0xef);
	UNPACK_BIT_FIELD(mystruct->MISMATCHERROR_RPC6, buffer8, 5, 0xdf);
	UNPACK_BIT_FIELD(mystruct->MISMATCHERROR_RPC7, buffer8, 6, 0xbf);
	UNPACK_BIT_FIELD(mystruct->MISMATCHERROR_RPC8, buffer8, 7, 0x7f);

	UNPACK_UINT8_ARRAY(mystruct->PDU_PAD, &bytes[26], 6);
	UNPACK_DOUBLE(&mystruct->PDU_CURRENTBUS_1, &bytes[32]);
	UNPACK_DOUBLE(&mystruct->PDU_CURRENTBUS_2, &bytes[40]);
	UNPACK_DOUBLE(&mystruct->PDU_CURRENTINTERNALBUS, &bytes[48]);
	UNPACK_DOUBLE(&mystruct->PDU_VOLTAGEBUS_1, &bytes[56]);
	UNPACK_DOUBLE(&mystruct->PDU_VOLTAGEBUS_2, &bytes[64]);
	UNPACK_DOUBLE(&mystruct->PDU_VOLTAGEINTERNAL, &bytes[72]);
	UNPACK_DOUBLE(&mystruct->PDU_VOLTAGEHKPG, &bytes[80]);
	UNPACK_DOUBLE(&mystruct->PDU_CURRENTRPC_1, &bytes[88]);
	UNPACK_DOUBLE(&mystruct->PDU_CURRENTRPC_2, &bytes[96]);
	UNPACK_DOUBLE(&mystruct->PDU_CURRENTRPC_3, &bytes[104]);
	UNPACK_DOUBLE(&mystruct->PDU_CURRENTRPC_4, &bytes[112]);
	UNPACK_DOUBLE(&mystruct->PDU_CURRENTRPC_5, &bytes[120]);
	UNPACK_DOUBLE(&mystruct->PDU_CURRENTRPC_6, &bytes[128]);
	UNPACK_DOUBLE(&mystruct->PDU_CURRENTRPC_7, &bytes[136]);
	UNPACK_DOUBLE(&mystruct->PDU_CURRENTRPC_8, &bytes[144]);

	return sizeof(PDU4);
}


uint32_t PackAMPSDB_IO_NOOP_CC_t(void *buffer, void *protobetter_type)
{

	AMPSDB_IO_NOOP_CC_t *mystruct = (AMPSDB_IO_NOOP_CC_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);

	return 12;
}


uint32_t UnpackAMPSDB_IO_NOOP_CC_t(void *protobetter_type, void *buffer)
{

	AMPSDB_IO_NOOP_CC_t *mystruct = (AMPSDB_IO_NOOP_CC_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);

	return sizeof(AMPSDB_IO_NOOP_CC_t);
}


uint32_t PackAMPSDB_IO_RESET_CC_t(void *buffer, void *protobetter_type)
{

	AMPSDB_IO_RESET_CC_t *mystruct = (AMPSDB_IO_RESET_CC_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);

	return 12;
}


uint32_t UnpackAMPSDB_IO_RESET_CC_t(void *protobetter_type, void *buffer)
{

	AMPSDB_IO_RESET_CC_t *mystruct = (AMPSDB_IO_RESET_CC_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);

	return sizeof(AMPSDB_IO_RESET_CC_t);
}


uint32_t PackAMPSDB_IO_CMD_MID(void *buffer, void *protobetter_type)
{
	unsigned char *msg = (unsigned char *) protobetter_type;

	uint16_t cmdCode = PROTOBETTER_READ_CCSDS_CODE(msg);

	switch (cmdCode)
	{
		case 0x0:

			return PackAMPSDB_IO_NOOP_CC_t(buffer, protobetter_type);

		case 0x1:

			return PackAMPSDB_IO_RESET_CC_t(buffer, protobetter_type);

		default:

			return 0;
	}
}


uint32_t UnpackAMPSDB_IO_CMD_MID(void *protobetter_type, void *buffer)
{
	unsigned char *msg = (unsigned char *) buffer;

	uint16_t cmdCode = PROTOBETTER_READ_CCSDS_CODE(msg);

	switch (cmdCode)
	{
		case 0x0:

			return UnpackAMPSDB_IO_NOOP_CC_t(protobetter_type, buffer);

		case 0x1:

			return UnpackAMPSDB_IO_RESET_CC_t(protobetter_type, buffer);

		default:

			return 0;
	}
}


uint32_t PackSET_MBSU1_INPUT_SOURCE_SELECT_t(void *buffer, void *protobetter_type)
{

	SET_MBSU1_INPUT_SOURCE_SELECT_t *mystruct = (SET_MBSU1_INPUT_SOURCE_SELECT_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->CH_POS);
	PACK_UINT8(&bytes[13], &mystruct->INPUT_BUS);

	return 14;
}


uint32_t UnpackSET_MBSU1_INPUT_SOURCE_SELECT_t(void *protobetter_type, void *buffer)
{

	SET_MBSU1_INPUT_SOURCE_SELECT_t *mystruct = (SET_MBSU1_INPUT_SOURCE_SELECT_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->CH_POS, &bytes[12]);
	UNPACK_UINT8(&mystruct->INPUT_BUS, &bytes[13]);

	return sizeof(SET_MBSU1_INPUT_SOURCE_SELECT_t);
}


uint32_t PackSET_MBSU1_OUTPUT_CHANNEL_STATE_t(void *buffer, void *protobetter_type)
{

	SET_MBSU1_OUTPUT_CHANNEL_STATE_t *mystruct = (SET_MBSU1_OUTPUT_CHANNEL_STATE_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->CH_POS);
	PACK_UINT8(&bytes[13], &mystruct->OUTPUT_BUS);

	return 14;
}


uint32_t UnpackSET_MBSU1_OUTPUT_CHANNEL_STATE_t(void *protobetter_type, void *buffer)
{

	SET_MBSU1_OUTPUT_CHANNEL_STATE_t *mystruct = (SET_MBSU1_OUTPUT_CHANNEL_STATE_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->CH_POS, &bytes[12]);
	UNPACK_UINT8(&mystruct->OUTPUT_BUS, &bytes[13]);

	return sizeof(SET_MBSU1_OUTPUT_CHANNEL_STATE_t);
}


uint32_t PackSET_MBSU1_Input_Curr_Limit_t(void *buffer, void *protobetter_type)
{

	SET_MBSU1_Input_Curr_Limit_t *mystruct = (SET_MBSU1_Input_Curr_Limit_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_DOUBLE(&bytes[12], &mystruct->Input_Curr_Limit_SP);
	PACK_UINT8(&bytes[20], &mystruct->INPUT_BUS);

	return 21;
}


uint32_t UnpackSET_MBSU1_Input_Curr_Limit_t(void *protobetter_type, void *buffer)
{

	SET_MBSU1_Input_Curr_Limit_t *mystruct = (SET_MBSU1_Input_Curr_Limit_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_DOUBLE(&mystruct->Input_Curr_Limit_SP, &bytes[12]);
	UNPACK_UINT8(&mystruct->INPUT_BUS, &bytes[20]);

	return sizeof(SET_MBSU1_Input_Curr_Limit_t);
}


uint32_t PackSET_MBSU1_Output_Curr_Limit_t(void *buffer, void *protobetter_type)
{

	SET_MBSU1_Output_Curr_Limit_t *mystruct = (SET_MBSU1_Output_Curr_Limit_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_DOUBLE(&bytes[12], &mystruct->Output_Curr_Limit_SP);
	PACK_UINT8(&bytes[20], &mystruct->OUTPUT_BUS);

	return 21;
}


uint32_t UnpackSET_MBSU1_Output_Curr_Limit_t(void *protobetter_type, void *buffer)
{

	SET_MBSU1_Output_Curr_Limit_t *mystruct = (SET_MBSU1_Output_Curr_Limit_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_DOUBLE(&mystruct->Output_Curr_Limit_SP, &bytes[12]);
	UNPACK_UINT8(&mystruct->OUTPUT_BUS, &bytes[20]);

	return sizeof(SET_MBSU1_Output_Curr_Limit_t);
}


uint32_t PackCLEAR_MBSU1_Input_Curr_Trip_t(void *buffer, void *protobetter_type)
{

	CLEAR_MBSU1_Input_Curr_Trip_t *mystruct = (CLEAR_MBSU1_Input_Curr_Trip_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->INPUT_BUS);

	return 13;
}


uint32_t UnpackCLEAR_MBSU1_Input_Curr_Trip_t(void *protobetter_type, void *buffer)
{

	CLEAR_MBSU1_Input_Curr_Trip_t *mystruct = (CLEAR_MBSU1_Input_Curr_Trip_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->INPUT_BUS, &bytes[12]);

	return sizeof(CLEAR_MBSU1_Input_Curr_Trip_t);
}


uint32_t PackCLEAR_MBSU1_Output_Curr_Trip_t(void *buffer, void *protobetter_type)
{

	CLEAR_MBSU1_Output_Curr_Trip_t *mystruct = (CLEAR_MBSU1_Output_Curr_Trip_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->OUTPUT_BUS);

	return 13;
}


uint32_t UnpackCLEAR_MBSU1_Output_Curr_Trip_t(void *protobetter_type, void *buffer)
{

	CLEAR_MBSU1_Output_Curr_Trip_t *mystruct = (CLEAR_MBSU1_Output_Curr_Trip_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->OUTPUT_BUS, &bytes[12]);

	return sizeof(CLEAR_MBSU1_Output_Curr_Trip_t);
}


uint32_t PackSET_MBSU1_Relay_CHANNEL_OPEN_t(void *buffer, void *protobetter_type)
{

	SET_MBSU1_Relay_CHANNEL_OPEN_t *mystruct = (SET_MBSU1_Relay_CHANNEL_OPEN_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->FORCERelayOFF);
	PACK_UINT8(&bytes[13], &mystruct->OUTPUT_BUS);

	return 14;
}


uint32_t UnpackSET_MBSU1_Relay_CHANNEL_OPEN_t(void *protobetter_type, void *buffer)
{

	SET_MBSU1_Relay_CHANNEL_OPEN_t *mystruct = (SET_MBSU1_Relay_CHANNEL_OPEN_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->FORCERelayOFF, &bytes[12]);
	UNPACK_UINT8(&mystruct->OUTPUT_BUS, &bytes[13]);

	return sizeof(SET_MBSU1_Relay_CHANNEL_OPEN_t);
}


uint32_t PackMBSU1_FAIL_INPUT_SOURCE_t(void *buffer, void *protobetter_type)
{

	MBSU1_FAIL_INPUT_SOURCE_t *mystruct = (MBSU1_FAIL_INPUT_SOURCE_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->FORCERelayOFF);
	PACK_UINT8(&bytes[13], &mystruct->INPUT_BUS);

	return 14;
}


uint32_t UnpackMBSU1_FAIL_INPUT_SOURCE_t(void *protobetter_type, void *buffer)
{

	MBSU1_FAIL_INPUT_SOURCE_t *mystruct = (MBSU1_FAIL_INPUT_SOURCE_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->FORCERelayOFF, &bytes[12]);
	UNPACK_UINT8(&mystruct->INPUT_BUS, &bytes[13]);

	return sizeof(MBSU1_FAIL_INPUT_SOURCE_t);
}


uint32_t PackMBSU1_CMD(void *buffer, void *protobetter_type)
{
	unsigned char *msg = (unsigned char *) protobetter_type;

	uint16_t cmdCode = PROTOBETTER_READ_CCSDS_CODE(msg);

	switch (cmdCode)
	{
		case 0x5:

			return PackCLEAR_MBSU1_Output_Curr_Trip_t(buffer, protobetter_type);

		case 0x3:

			return PackSET_MBSU1_Output_Curr_Limit_t(buffer, protobetter_type);

		case 0x1:

			return PackSET_MBSU1_OUTPUT_CHANNEL_STATE_t(buffer, protobetter_type);

		case 0x7:

			return PackMBSU1_FAIL_INPUT_SOURCE_t(buffer, protobetter_type);

		case 0x0:

			return PackSET_MBSU1_INPUT_SOURCE_SELECT_t(buffer, protobetter_type);

		case 0x4:

			return PackCLEAR_MBSU1_Input_Curr_Trip_t(buffer, protobetter_type);

		case 0x6:

			return PackSET_MBSU1_Relay_CHANNEL_OPEN_t(buffer, protobetter_type);

		case 0x2:

			return PackSET_MBSU1_Input_Curr_Limit_t(buffer, protobetter_type);

		default:

			return 0;
	}
}


uint32_t UnpackMBSU1_CMD(void *protobetter_type, void *buffer)
{
	unsigned char *msg = (unsigned char *) buffer;

	uint16_t cmdCode = PROTOBETTER_READ_CCSDS_CODE(msg);

	switch (cmdCode)
	{
		case 0x5:

			return UnpackCLEAR_MBSU1_Output_Curr_Trip_t(protobetter_type, buffer);

		case 0x3:

			return UnpackSET_MBSU1_Output_Curr_Limit_t(protobetter_type, buffer);

		case 0x1:

			return UnpackSET_MBSU1_OUTPUT_CHANNEL_STATE_t(protobetter_type, buffer);

		case 0x7:

			return UnpackMBSU1_FAIL_INPUT_SOURCE_t(protobetter_type, buffer);

		case 0x0:

			return UnpackSET_MBSU1_INPUT_SOURCE_SELECT_t(protobetter_type, buffer);

		case 0x4:

			return UnpackCLEAR_MBSU1_Input_Curr_Trip_t(protobetter_type, buffer);

		case 0x6:

			return UnpackSET_MBSU1_Relay_CHANNEL_OPEN_t(protobetter_type, buffer);

		case 0x2:

			return UnpackSET_MBSU1_Input_Curr_Limit_t(protobetter_type, buffer);

		default:

			return 0;
	}
}


uint32_t PackSET_MBSU2_INPUT_SOURCE_SELECT_t(void *buffer, void *protobetter_type)
{

	SET_MBSU2_INPUT_SOURCE_SELECT_t *mystruct = (SET_MBSU2_INPUT_SOURCE_SELECT_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->CH_POS);
	PACK_UINT8(&bytes[13], &mystruct->INPUT_BUS);

	return 14;
}


uint32_t UnpackSET_MBSU2_INPUT_SOURCE_SELECT_t(void *protobetter_type, void *buffer)
{

	SET_MBSU2_INPUT_SOURCE_SELECT_t *mystruct = (SET_MBSU2_INPUT_SOURCE_SELECT_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->CH_POS, &bytes[12]);
	UNPACK_UINT8(&mystruct->INPUT_BUS, &bytes[13]);

	return sizeof(SET_MBSU2_INPUT_SOURCE_SELECT_t);
}


uint32_t PackSET_MBSU2_OUTPUT_CHANNEL_STATE_t(void *buffer, void *protobetter_type)
{

	SET_MBSU2_OUTPUT_CHANNEL_STATE_t *mystruct = (SET_MBSU2_OUTPUT_CHANNEL_STATE_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->CH_POS);
	PACK_UINT8(&bytes[13], &mystruct->OUTPUT_BUS);

	return 14;
}


uint32_t UnpackSET_MBSU2_OUTPUT_CHANNEL_STATE_t(void *protobetter_type, void *buffer)
{

	SET_MBSU2_OUTPUT_CHANNEL_STATE_t *mystruct = (SET_MBSU2_OUTPUT_CHANNEL_STATE_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->CH_POS, &bytes[12]);
	UNPACK_UINT8(&mystruct->OUTPUT_BUS, &bytes[13]);

	return sizeof(SET_MBSU2_OUTPUT_CHANNEL_STATE_t);
}


uint32_t PackSET_MBSU2_Input_Curr_Limit_t(void *buffer, void *protobetter_type)
{

	SET_MBSU2_Input_Curr_Limit_t *mystruct = (SET_MBSU2_Input_Curr_Limit_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_DOUBLE(&bytes[12], &mystruct->Input_Curr_Limit_SP);
	PACK_UINT8(&bytes[20], &mystruct->INPUT_BUS);

	return 21;
}


uint32_t UnpackSET_MBSU2_Input_Curr_Limit_t(void *protobetter_type, void *buffer)
{

	SET_MBSU2_Input_Curr_Limit_t *mystruct = (SET_MBSU2_Input_Curr_Limit_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_DOUBLE(&mystruct->Input_Curr_Limit_SP, &bytes[12]);
	UNPACK_UINT8(&mystruct->INPUT_BUS, &bytes[20]);

	return sizeof(SET_MBSU2_Input_Curr_Limit_t);
}


uint32_t PackSET_MBSU2_Output_Curr_Limit_t(void *buffer, void *protobetter_type)
{

	SET_MBSU2_Output_Curr_Limit_t *mystruct = (SET_MBSU2_Output_Curr_Limit_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_DOUBLE(&bytes[12], &mystruct->Output_Curr_Limit_SP);
	PACK_UINT8(&bytes[20], &mystruct->OUTPUT_BUS);

	return 21;
}


uint32_t UnpackSET_MBSU2_Output_Curr_Limit_t(void *protobetter_type, void *buffer)
{

	SET_MBSU2_Output_Curr_Limit_t *mystruct = (SET_MBSU2_Output_Curr_Limit_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_DOUBLE(&mystruct->Output_Curr_Limit_SP, &bytes[12]);
	UNPACK_UINT8(&mystruct->OUTPUT_BUS, &bytes[20]);

	return sizeof(SET_MBSU2_Output_Curr_Limit_t);
}


uint32_t PackCLEAR_MBSU2_Input_Curr_Trip_t(void *buffer, void *protobetter_type)
{

	CLEAR_MBSU2_Input_Curr_Trip_t *mystruct = (CLEAR_MBSU2_Input_Curr_Trip_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->INPUT_BUS);

	return 13;
}


uint32_t UnpackCLEAR_MBSU2_Input_Curr_Trip_t(void *protobetter_type, void *buffer)
{

	CLEAR_MBSU2_Input_Curr_Trip_t *mystruct = (CLEAR_MBSU2_Input_Curr_Trip_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->INPUT_BUS, &bytes[12]);

	return sizeof(CLEAR_MBSU2_Input_Curr_Trip_t);
}


uint32_t PackCLEAR_MBSU2_Output_Curr_Trip_t(void *buffer, void *protobetter_type)
{

	CLEAR_MBSU2_Output_Curr_Trip_t *mystruct = (CLEAR_MBSU2_Output_Curr_Trip_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->OUTPUT_BUS);

	return 13;
}


uint32_t UnpackCLEAR_MBSU2_Output_Curr_Trip_t(void *protobetter_type, void *buffer)
{

	CLEAR_MBSU2_Output_Curr_Trip_t *mystruct = (CLEAR_MBSU2_Output_Curr_Trip_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->OUTPUT_BUS, &bytes[12]);

	return sizeof(CLEAR_MBSU2_Output_Curr_Trip_t);
}


uint32_t PackSET_MBSU2_Relay_CHANNEL_OPEN_t(void *buffer, void *protobetter_type)
{

	SET_MBSU2_Relay_CHANNEL_OPEN_t *mystruct = (SET_MBSU2_Relay_CHANNEL_OPEN_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->FORCERelayOFF);
	PACK_UINT8(&bytes[13], &mystruct->OUTPUT_BUS);

	return 14;
}


uint32_t UnpackSET_MBSU2_Relay_CHANNEL_OPEN_t(void *protobetter_type, void *buffer)
{

	SET_MBSU2_Relay_CHANNEL_OPEN_t *mystruct = (SET_MBSU2_Relay_CHANNEL_OPEN_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->FORCERelayOFF, &bytes[12]);
	UNPACK_UINT8(&mystruct->OUTPUT_BUS, &bytes[13]);

	return sizeof(SET_MBSU2_Relay_CHANNEL_OPEN_t);
}


uint32_t PackMBSU2_FAIL_INPUT_SOURCE_t(void *buffer, void *protobetter_type)
{

	MBSU2_FAIL_INPUT_SOURCE_t *mystruct = (MBSU2_FAIL_INPUT_SOURCE_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->FORCERelayOFF);
	PACK_UINT8(&bytes[13], &mystruct->INPUT_BUS);

	return 14;
}


uint32_t UnpackMBSU2_FAIL_INPUT_SOURCE_t(void *protobetter_type, void *buffer)
{

	MBSU2_FAIL_INPUT_SOURCE_t *mystruct = (MBSU2_FAIL_INPUT_SOURCE_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->FORCERelayOFF, &bytes[12]);
	UNPACK_UINT8(&mystruct->INPUT_BUS, &bytes[13]);

	return sizeof(MBSU2_FAIL_INPUT_SOURCE_t);
}


uint32_t PackMBSU2_CMD(void *buffer, void *protobetter_type)
{
	unsigned char *msg = (unsigned char *) protobetter_type;

	uint16_t cmdCode = PROTOBETTER_READ_CCSDS_CODE(msg);

	switch (cmdCode)
	{
		case 0x5:

			return PackCLEAR_MBSU2_Output_Curr_Trip_t(buffer, protobetter_type);

		case 0x3:

			return PackSET_MBSU2_Output_Curr_Limit_t(buffer, protobetter_type);

		case 0x2:

			return PackSET_MBSU2_Input_Curr_Limit_t(buffer, protobetter_type);

		case 0x1:

			return PackSET_MBSU2_OUTPUT_CHANNEL_STATE_t(buffer, protobetter_type);

		case 0x7:

			return PackMBSU2_FAIL_INPUT_SOURCE_t(buffer, protobetter_type);

		case 0x6:

			return PackSET_MBSU2_Relay_CHANNEL_OPEN_t(buffer, protobetter_type);

		case 0x4:

			return PackCLEAR_MBSU2_Input_Curr_Trip_t(buffer, protobetter_type);

		case 0x0:

			return PackSET_MBSU2_INPUT_SOURCE_SELECT_t(buffer, protobetter_type);

		default:

			return 0;
	}
}


uint32_t UnpackMBSU2_CMD(void *protobetter_type, void *buffer)
{
	unsigned char *msg = (unsigned char *) buffer;

	uint16_t cmdCode = PROTOBETTER_READ_CCSDS_CODE(msg);

	switch (cmdCode)
	{
		case 0x5:

			return UnpackCLEAR_MBSU2_Output_Curr_Trip_t(protobetter_type, buffer);

		case 0x3:

			return UnpackSET_MBSU2_Output_Curr_Limit_t(protobetter_type, buffer);

		case 0x2:

			return UnpackSET_MBSU2_Input_Curr_Limit_t(protobetter_type, buffer);

		case 0x1:

			return UnpackSET_MBSU2_OUTPUT_CHANNEL_STATE_t(protobetter_type, buffer);

		case 0x7:

			return UnpackMBSU2_FAIL_INPUT_SOURCE_t(protobetter_type, buffer);

		case 0x6:

			return UnpackSET_MBSU2_Relay_CHANNEL_OPEN_t(protobetter_type, buffer);

		case 0x4:

			return UnpackCLEAR_MBSU2_Input_Curr_Trip_t(protobetter_type, buffer);

		case 0x0:

			return UnpackSET_MBSU2_INPUT_SOURCE_SELECT_t(protobetter_type, buffer);

		default:

			return 0;
	}
}


uint32_t PackSET_PDU1_INPUT_BUS_SELECT_t(void *buffer, void *protobetter_type)
{

	SET_PDU1_INPUT_BUS_SELECT_t *mystruct = (SET_PDU1_INPUT_BUS_SELECT_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->INPUT_BUS);

	return 13;
}


uint32_t UnpackSET_PDU1_INPUT_BUS_SELECT_t(void *protobetter_type, void *buffer)
{

	SET_PDU1_INPUT_BUS_SELECT_t *mystruct = (SET_PDU1_INPUT_BUS_SELECT_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->INPUT_BUS, &bytes[12]);

	return sizeof(SET_PDU1_INPUT_BUS_SELECT_t);
}


uint32_t PackSET_PDU1_RPC_CHANNEL_STATE_t(void *buffer, void *protobetter_type)
{

	SET_PDU1_RPC_CHANNEL_STATE_t *mystruct = (SET_PDU1_RPC_CHANNEL_STATE_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->RPCONOFFSTATE);
	PACK_UINT8(&bytes[13], &mystruct->rpcCHANNEL);

	return 14;
}


uint32_t UnpackSET_PDU1_RPC_CHANNEL_STATE_t(void *protobetter_type, void *buffer)
{

	SET_PDU1_RPC_CHANNEL_STATE_t *mystruct = (SET_PDU1_RPC_CHANNEL_STATE_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->RPCONOFFSTATE, &bytes[12]);
	UNPACK_UINT8(&mystruct->rpcCHANNEL, &bytes[13]);

	return sizeof(SET_PDU1_RPC_CHANNEL_STATE_t);
}


uint32_t PackSET_PDU1_RPC_CHANNEL_OPEN_t(void *buffer, void *protobetter_type)
{

	SET_PDU1_RPC_CHANNEL_OPEN_t *mystruct = (SET_PDU1_RPC_CHANNEL_OPEN_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->FORCERPCOFF);
	PACK_UINT8(&bytes[13], &mystruct->rpcCHANNEL);

	return 14;
}


uint32_t UnpackSET_PDU1_RPC_CHANNEL_OPEN_t(void *protobetter_type, void *buffer)
{

	SET_PDU1_RPC_CHANNEL_OPEN_t *mystruct = (SET_PDU1_RPC_CHANNEL_OPEN_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->FORCERPCOFF, &bytes[12]);
	UNPACK_UINT8(&mystruct->rpcCHANNEL, &bytes[13]);

	return sizeof(SET_PDU1_RPC_CHANNEL_OPEN_t);
}


uint32_t PackPDU1_CMD(void *buffer, void *protobetter_type)
{
	unsigned char *msg = (unsigned char *) protobetter_type;

	uint16_t cmdCode = PROTOBETTER_READ_CCSDS_CODE(msg);

	switch (cmdCode)
	{
		case 0x0:

			return PackSET_PDU1_INPUT_BUS_SELECT_t(buffer, protobetter_type);

		case 0x2:

			return PackSET_PDU1_RPC_CHANNEL_OPEN_t(buffer, protobetter_type);

		case 0x1:

			return PackSET_PDU1_RPC_CHANNEL_STATE_t(buffer, protobetter_type);

		default:

			return 0;
	}
}


uint32_t UnpackPDU1_CMD(void *protobetter_type, void *buffer)
{
	unsigned char *msg = (unsigned char *) buffer;

	uint16_t cmdCode = PROTOBETTER_READ_CCSDS_CODE(msg);

	switch (cmdCode)
	{
		case 0x0:

			return UnpackSET_PDU1_INPUT_BUS_SELECT_t(protobetter_type, buffer);

		case 0x2:

			return UnpackSET_PDU1_RPC_CHANNEL_OPEN_t(protobetter_type, buffer);

		case 0x1:

			return UnpackSET_PDU1_RPC_CHANNEL_STATE_t(protobetter_type, buffer);

		default:

			return 0;
	}
}


uint32_t PackSET_PDU2_INPUT_BUS_SELECT_t(void *buffer, void *protobetter_type)
{

	SET_PDU2_INPUT_BUS_SELECT_t *mystruct = (SET_PDU2_INPUT_BUS_SELECT_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->INPUT_BUS);

	return 13;
}


uint32_t UnpackSET_PDU2_INPUT_BUS_SELECT_t(void *protobetter_type, void *buffer)
{

	SET_PDU2_INPUT_BUS_SELECT_t *mystruct = (SET_PDU2_INPUT_BUS_SELECT_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->INPUT_BUS, &bytes[12]);

	return sizeof(SET_PDU2_INPUT_BUS_SELECT_t);
}


uint32_t PackSET_PDU2_RPC_CHANNEL_STATE_t(void *buffer, void *protobetter_type)
{

	SET_PDU2_RPC_CHANNEL_STATE_t *mystruct = (SET_PDU2_RPC_CHANNEL_STATE_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->RPCONOFFSTATE);
	PACK_UINT8(&bytes[13], &mystruct->rpcCHANNEL);

	return 14;
}


uint32_t UnpackSET_PDU2_RPC_CHANNEL_STATE_t(void *protobetter_type, void *buffer)
{

	SET_PDU2_RPC_CHANNEL_STATE_t *mystruct = (SET_PDU2_RPC_CHANNEL_STATE_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->RPCONOFFSTATE, &bytes[12]);
	UNPACK_UINT8(&mystruct->rpcCHANNEL, &bytes[13]);

	return sizeof(SET_PDU2_RPC_CHANNEL_STATE_t);
}


uint32_t PackSET_PDU2_RPC_CHANNEL_OPEN_t(void *buffer, void *protobetter_type)
{

	SET_PDU2_RPC_CHANNEL_OPEN_t *mystruct = (SET_PDU2_RPC_CHANNEL_OPEN_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->FORCERPCOFF);
	PACK_UINT8(&bytes[13], &mystruct->rpcCHANNEL);

	return 14;
}


uint32_t UnpackSET_PDU2_RPC_CHANNEL_OPEN_t(void *protobetter_type, void *buffer)
{

	SET_PDU2_RPC_CHANNEL_OPEN_t *mystruct = (SET_PDU2_RPC_CHANNEL_OPEN_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->FORCERPCOFF, &bytes[12]);
	UNPACK_UINT8(&mystruct->rpcCHANNEL, &bytes[13]);

	return sizeof(SET_PDU2_RPC_CHANNEL_OPEN_t);
}


uint32_t PackPDU2_CMD(void *buffer, void *protobetter_type)
{
	unsigned char *msg = (unsigned char *) protobetter_type;

	uint16_t cmdCode = PROTOBETTER_READ_CCSDS_CODE(msg);

	switch (cmdCode)
	{
		case 0x2:

			return PackSET_PDU2_RPC_CHANNEL_OPEN_t(buffer, protobetter_type);

		case 0x1:

			return PackSET_PDU2_RPC_CHANNEL_STATE_t(buffer, protobetter_type);

		case 0x0:

			return PackSET_PDU2_INPUT_BUS_SELECT_t(buffer, protobetter_type);

		default:

			return 0;
	}
}


uint32_t UnpackPDU2_CMD(void *protobetter_type, void *buffer)
{
	unsigned char *msg = (unsigned char *) buffer;

	uint16_t cmdCode = PROTOBETTER_READ_CCSDS_CODE(msg);

	switch (cmdCode)
	{
		case 0x2:

			return UnpackSET_PDU2_RPC_CHANNEL_OPEN_t(protobetter_type, buffer);

		case 0x1:

			return UnpackSET_PDU2_RPC_CHANNEL_STATE_t(protobetter_type, buffer);

		case 0x0:

			return UnpackSET_PDU2_INPUT_BUS_SELECT_t(protobetter_type, buffer);

		default:

			return 0;
	}
}


uint32_t PackSET_PDU3_INPUT_BUS_SELECT_t(void *buffer, void *protobetter_type)
{

	SET_PDU3_INPUT_BUS_SELECT_t *mystruct = (SET_PDU3_INPUT_BUS_SELECT_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->INPUT_BUS);

	return 13;
}


uint32_t UnpackSET_PDU3_INPUT_BUS_SELECT_t(void *protobetter_type, void *buffer)
{

	SET_PDU3_INPUT_BUS_SELECT_t *mystruct = (SET_PDU3_INPUT_BUS_SELECT_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->INPUT_BUS, &bytes[12]);

	return sizeof(SET_PDU3_INPUT_BUS_SELECT_t);
}


uint32_t PackSET_PDU3_RPC_CHANNEL_STATE_t(void *buffer, void *protobetter_type)
{

	SET_PDU3_RPC_CHANNEL_STATE_t *mystruct = (SET_PDU3_RPC_CHANNEL_STATE_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->RPCONOFFSTATE);
	PACK_UINT8(&bytes[13], &mystruct->rpcCHANNEL);

	return 14;
}


uint32_t UnpackSET_PDU3_RPC_CHANNEL_STATE_t(void *protobetter_type, void *buffer)
{

	SET_PDU3_RPC_CHANNEL_STATE_t *mystruct = (SET_PDU3_RPC_CHANNEL_STATE_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->RPCONOFFSTATE, &bytes[12]);
	UNPACK_UINT8(&mystruct->rpcCHANNEL, &bytes[13]);

	return sizeof(SET_PDU3_RPC_CHANNEL_STATE_t);
}


uint32_t PackSET_PDU3_RPC_CHANNEL_OPEN_t(void *buffer, void *protobetter_type)
{

	SET_PDU3_RPC_CHANNEL_OPEN_t *mystruct = (SET_PDU3_RPC_CHANNEL_OPEN_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->FORCERPCOFF);
	PACK_UINT8(&bytes[13], &mystruct->rpcCHANNEL);

	return 14;
}


uint32_t UnpackSET_PDU3_RPC_CHANNEL_OPEN_t(void *protobetter_type, void *buffer)
{

	SET_PDU3_RPC_CHANNEL_OPEN_t *mystruct = (SET_PDU3_RPC_CHANNEL_OPEN_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->FORCERPCOFF, &bytes[12]);
	UNPACK_UINT8(&mystruct->rpcCHANNEL, &bytes[13]);

	return sizeof(SET_PDU3_RPC_CHANNEL_OPEN_t);
}


uint32_t PackPDU3_CMD(void *buffer, void *protobetter_type)
{
	unsigned char *msg = (unsigned char *) protobetter_type;

	uint16_t cmdCode = PROTOBETTER_READ_CCSDS_CODE(msg);

	switch (cmdCode)
	{
		case 0x0:

			return PackSET_PDU3_INPUT_BUS_SELECT_t(buffer, protobetter_type);

		case 0x2:

			return PackSET_PDU3_RPC_CHANNEL_OPEN_t(buffer, protobetter_type);

		case 0x1:

			return PackSET_PDU3_RPC_CHANNEL_STATE_t(buffer, protobetter_type);

		default:

			return 0;
	}
}


uint32_t UnpackPDU3_CMD(void *protobetter_type, void *buffer)
{
	unsigned char *msg = (unsigned char *) buffer;

	uint16_t cmdCode = PROTOBETTER_READ_CCSDS_CODE(msg);

	switch (cmdCode)
	{
		case 0x0:

			return UnpackSET_PDU3_INPUT_BUS_SELECT_t(protobetter_type, buffer);

		case 0x2:

			return UnpackSET_PDU3_RPC_CHANNEL_OPEN_t(protobetter_type, buffer);

		case 0x1:

			return UnpackSET_PDU3_RPC_CHANNEL_STATE_t(protobetter_type, buffer);

		default:

			return 0;
	}
}


uint32_t PackSET_PDU4_INPUT_BUS_SELECT_t(void *buffer, void *protobetter_type)
{

	SET_PDU4_INPUT_BUS_SELECT_t *mystruct = (SET_PDU4_INPUT_BUS_SELECT_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->INPUT_BUS);

	return 13;
}


uint32_t UnpackSET_PDU4_INPUT_BUS_SELECT_t(void *protobetter_type, void *buffer)
{

	SET_PDU4_INPUT_BUS_SELECT_t *mystruct = (SET_PDU4_INPUT_BUS_SELECT_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->INPUT_BUS, &bytes[12]);

	return sizeof(SET_PDU4_INPUT_BUS_SELECT_t);
}


uint32_t PackSET_PDU4_RPC_CHANNEL_STATE_t(void *buffer, void *protobetter_type)
{

	SET_PDU4_RPC_CHANNEL_STATE_t *mystruct = (SET_PDU4_RPC_CHANNEL_STATE_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->RPCONOFFSTATE);
	PACK_UINT8(&bytes[13], &mystruct->rpcCHANNEL);

	return 14;
}


uint32_t UnpackSET_PDU4_RPC_CHANNEL_STATE_t(void *protobetter_type, void *buffer)
{

	SET_PDU4_RPC_CHANNEL_STATE_t *mystruct = (SET_PDU4_RPC_CHANNEL_STATE_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->RPCONOFFSTATE, &bytes[12]);
	UNPACK_UINT8(&mystruct->rpcCHANNEL, &bytes[13]);

	return sizeof(SET_PDU4_RPC_CHANNEL_STATE_t);
}


uint32_t PackSET_PDU4_RPC_CHANNEL_OPEN_t(void *buffer, void *protobetter_type)
{

	SET_PDU4_RPC_CHANNEL_OPEN_t *mystruct = (SET_PDU4_RPC_CHANNEL_OPEN_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->FORCERPCOFF);
	PACK_UINT8(&bytes[13], &mystruct->rpcCHANNEL);

	return 14;
}


uint32_t UnpackSET_PDU4_RPC_CHANNEL_OPEN_t(void *protobetter_type, void *buffer)
{

	SET_PDU4_RPC_CHANNEL_OPEN_t *mystruct = (SET_PDU4_RPC_CHANNEL_OPEN_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->FORCERPCOFF, &bytes[12]);
	UNPACK_UINT8(&mystruct->rpcCHANNEL, &bytes[13]);

	return sizeof(SET_PDU4_RPC_CHANNEL_OPEN_t);
}


uint32_t PackPDU4_CMD(void *buffer, void *protobetter_type)
{
	unsigned char *msg = (unsigned char *) protobetter_type;

	uint16_t cmdCode = PROTOBETTER_READ_CCSDS_CODE(msg);

	switch (cmdCode)
	{
		case 0x2:

			return PackSET_PDU4_RPC_CHANNEL_OPEN_t(buffer, protobetter_type);

		case 0x1:

			return PackSET_PDU4_RPC_CHANNEL_STATE_t(buffer, protobetter_type);

		case 0x0:

			return PackSET_PDU4_INPUT_BUS_SELECT_t(buffer, protobetter_type);

		default:

			return 0;
	}
}


uint32_t UnpackPDU4_CMD(void *protobetter_type, void *buffer)
{
	unsigned char *msg = (unsigned char *) buffer;

	uint16_t cmdCode = PROTOBETTER_READ_CCSDS_CODE(msg);

	switch (cmdCode)
	{
		case 0x2:

			return UnpackSET_PDU4_RPC_CHANNEL_OPEN_t(protobetter_type, buffer);

		case 0x1:

			return UnpackSET_PDU4_RPC_CHANNEL_STATE_t(protobetter_type, buffer);

		case 0x0:

			return UnpackSET_PDU4_INPUT_BUS_SELECT_t(protobetter_type, buffer);

		default:

			return 0;
	}
}


