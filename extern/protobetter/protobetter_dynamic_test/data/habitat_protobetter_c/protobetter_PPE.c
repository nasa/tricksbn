#include "protobetter_PPE.h"

static inline uint32_t Packsim_power_source(void *buffer, void *protobetter_type)
{

	sim_power_source *mystruct = (sim_power_source*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	PACK_UINT8(&bytes[0], &mystruct->UNITID);
	PACK_UINT8(&bytes[1], &mystruct->SAR_SWITCH_FEEDBACK);
	PACK_UINT8(&bytes[2], &mystruct->BATT_SWItCH_FEEDBACK);
	PACK_UINT8(&bytes[3], &mystruct->CROSS_CONNECT_SWITCH_FEEDBACK);
	PACK_UINT8(&bytes[4], &mystruct->SAR_FEEDBACK);
	PACK_DOUBLE(&bytes[5], &mystruct->SOLARARRAY_VOLTAGE);
	PACK_DOUBLE(&bytes[13], &mystruct->BATT_VOLTAGE);
	PACK_DOUBLE(&bytes[21], &mystruct->SAR_VOLTAGE);
	PACK_DOUBLE(&bytes[29], &mystruct->SOLARARRAY_CURRENT);
	PACK_DOUBLE(&bytes[37], &mystruct->BATT_CURRENT);
	PACK_DOUBLE(&bytes[45], &mystruct->SAR_CURRENT);
	PACK_DOUBLE(&bytes[53], &mystruct->BATT_SOC);

	return 61;
}


static inline uint32_t Unpacksim_power_source(void *protobetter_type, void *buffer)
{

	sim_power_source *mystruct = (sim_power_source*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	UNPACK_UINT8(&mystruct->UNITID, &bytes[0]);
	UNPACK_UINT8(&mystruct->SAR_SWITCH_FEEDBACK, &bytes[1]);
	UNPACK_UINT8(&mystruct->BATT_SWItCH_FEEDBACK, &bytes[2]);
	UNPACK_UINT8(&mystruct->CROSS_CONNECT_SWITCH_FEEDBACK, &bytes[3]);
	UNPACK_UINT8(&mystruct->SAR_FEEDBACK, &bytes[4]);
	UNPACK_DOUBLE(&mystruct->SOLARARRAY_VOLTAGE, &bytes[5]);
	UNPACK_DOUBLE(&mystruct->BATT_VOLTAGE, &bytes[13]);
	UNPACK_DOUBLE(&mystruct->SAR_VOLTAGE, &bytes[21]);
	UNPACK_DOUBLE(&mystruct->SOLARARRAY_CURRENT, &bytes[29]);
	UNPACK_DOUBLE(&mystruct->BATT_CURRENT, &bytes[37]);
	UNPACK_DOUBLE(&mystruct->SAR_CURRENT, &bytes[45]);
	UNPACK_DOUBLE(&mystruct->BATT_SOC, &bytes[53]);

	return sizeof(sim_power_source);
}


static inline uint32_t PackPDU_telemetry(void *buffer, void *protobetter_type)
{
	uint8_t buffer8 = 0;

	PDU_telemetry *mystruct = (PDU_telemetry*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	PACK_UINT8(&bytes[0], &mystruct->PDU_UNITID);

	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->STATUS_INPUTBUS1, 0, 0xfc);
	PACK_BIT_FIELD(buffer8, mystruct->STATUS_INPUTBUS2, 2, 0xf3);
	PACK_BIT_FIELD(buffer8, mystruct->STATUS_INPUTPAD, 4, 0xf);
	PACK_UINT8(&bytes[1], &buffer8);


	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->FEEDBACK_INPUTRELAY1, 0, 0xfc);
	PACK_BIT_FIELD(buffer8, mystruct->FEEDBACK_INPUTRELAY2, 2, 0xf3);
	PACK_BIT_FIELD(buffer8, mystruct->FEEDBACK_INPUT_PAD, 4, 0xf);
	PACK_UINT8(&bytes[2], &buffer8);

	PACK_UINT8(&bytes[3], &mystruct->PDU_INVALIDCOMMANDERROR);

	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->FEEDBACKSTATEMISMATCHERROR_INPUTBUS1, 0, 0xfc);
	PACK_BIT_FIELD(buffer8, mystruct->FEEDBACKSTATEMISMATCHERROR_INPUTBUS2, 2, 0xf3);
	PACK_BIT_FIELD(buffer8, mystruct->FEEDBACKSTATEMISMATCHERROR_PAD, 4, 0xf);
	PACK_UINT8(&bytes[4], &buffer8);


	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->POSNEGMISMATCHERROR_INPUT1, 0, 0xfe);
	PACK_BIT_FIELD(buffer8, mystruct->POSNEGMISMATCHERROR_INPUT2, 1, 0xfd);
	PACK_BIT_FIELD(buffer8, mystruct->POSNEGMISMATCHERROR_PAD, 2, 0x3);
	PACK_UINT8(&bytes[5], &buffer8);


	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->CHANNELSTATUS_RPC1, 0, 0xfe);
	PACK_BIT_FIELD(buffer8, mystruct->CHANNELSTATUS_RPC2, 1, 0xfd);
	PACK_BIT_FIELD(buffer8, mystruct->CHANNELSTATUS_RPC3, 2, 0xfb);
	PACK_BIT_FIELD(buffer8, mystruct->CHANNELSTATUS_RPC4, 3, 0xf7);
	PACK_BIT_FIELD(buffer8, mystruct->CHANNELSTATUS_RPC5, 4, 0xef);
	PACK_BIT_FIELD(buffer8, mystruct->CHANNELSTATUS_RPC6, 5, 0xdf);
	PACK_BIT_FIELD(buffer8, mystruct->CHANNELSTATUS_RPC7, 6, 0xbf);
	PACK_BIT_FIELD(buffer8, mystruct->CHANNELSTATUS_RPC8, 7, 0x7f);
	PACK_UINT8(&bytes[6], &buffer8);


	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATUS_RPC1, 0, 0xfe);
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATUS_RPC2, 1, 0xfd);
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATUS_RPC3, 2, 0xfb);
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATUS_RPC4, 3, 0xf7);
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATUS_RPC5, 4, 0xef);
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATUS_RPC6, 5, 0xdf);
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATUS_RPC7, 6, 0xbf);
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATUS_RPC8, 7, 0x7f);
	PACK_UINT8(&bytes[7], &buffer8);


	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->OUTSTATUS_RPC1, 0, 0xfe);
	PACK_BIT_FIELD(buffer8, mystruct->OUTSTATUS_RPC2, 1, 0xfd);
	PACK_BIT_FIELD(buffer8, mystruct->OUTSTATUS_RPC3, 2, 0xfb);
	PACK_BIT_FIELD(buffer8, mystruct->OUTSTATUS_RPC4, 3, 0xf7);
	PACK_BIT_FIELD(buffer8, mystruct->OUTSTATUS_RPC5, 4, 0xef);
	PACK_BIT_FIELD(buffer8, mystruct->OUTSTATUS_RPC6, 5, 0xdf);
	PACK_BIT_FIELD(buffer8, mystruct->OUTSTATUS_RPC7, 6, 0xbf);
	PACK_BIT_FIELD(buffer8, mystruct->OUTSTATUS_RPC8, 7, 0x7f);
	PACK_UINT8(&bytes[8], &buffer8);


	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->MISMATCHERROR_RPC1, 0, 0xfe);
	PACK_BIT_FIELD(buffer8, mystruct->MISMATCHERROR_RPC2, 1, 0xfd);
	PACK_BIT_FIELD(buffer8, mystruct->MISMATCHERROR_RPC3, 2, 0xfb);
	PACK_BIT_FIELD(buffer8, mystruct->MISMATCHERROR_RPC4, 3, 0xf7);
	PACK_BIT_FIELD(buffer8, mystruct->MISMATCHERROR_RPC5, 4, 0xef);
	PACK_BIT_FIELD(buffer8, mystruct->MISMATCHERROR_RPC6, 5, 0xdf);
	PACK_BIT_FIELD(buffer8, mystruct->MISMATCHERROR_RPC7, 6, 0xbf);
	PACK_BIT_FIELD(buffer8, mystruct->MISMATCHERROR_RPC8, 7, 0x7f);
	PACK_UINT8(&bytes[9], &buffer8);

	PACK_UINT8_ARRAY(&bytes[10], mystruct->PDU_PAD, 6);
	PACK_DOUBLE(&bytes[16], &mystruct->PDU_CURRENTBUS_1);
	PACK_DOUBLE(&bytes[24], &mystruct->PDU_CURRENTBUS_2);
	PACK_DOUBLE(&bytes[32], &mystruct->PDU_CURRENTINTERNALBUS);
	PACK_DOUBLE(&bytes[40], &mystruct->PDU_VOLTAGEBUS_1);
	PACK_DOUBLE(&bytes[48], &mystruct->PDU_VOLTAGEBUS_2);
	PACK_DOUBLE(&bytes[56], &mystruct->PDU_VOLTAGEINTERNAL);
	PACK_DOUBLE(&bytes[64], &mystruct->PDU_VOLTAGEHKPG);
	PACK_DOUBLE(&bytes[72], &mystruct->PDU_CURRENTRPC_1);
	PACK_DOUBLE(&bytes[80], &mystruct->PDU_CURRENTRPC_2);
	PACK_DOUBLE(&bytes[88], &mystruct->PDU_CURRENTRPC_3);
	PACK_DOUBLE(&bytes[96], &mystruct->PDU_CURRENTRPC_4);
	PACK_DOUBLE(&bytes[104], &mystruct->PDU_CURRENTRPC_5);
	PACK_DOUBLE(&bytes[112], &mystruct->PDU_CURRENTRPC_6);
	PACK_DOUBLE(&bytes[120], &mystruct->PDU_CURRENTRPC_7);
	PACK_DOUBLE(&bytes[128], &mystruct->PDU_CURRENTRPC_8);

	return 136;
}


static inline uint32_t UnpackPDU_telemetry(void *protobetter_type, void *buffer)
{
	uint8_t buffer8 = 0;

	PDU_telemetry *mystruct = (PDU_telemetry*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	UNPACK_UINT8(&mystruct->PDU_UNITID, &bytes[0]);

	UNPACK_UINT8(&buffer8, &bytes[1]);
	UNPACK_BIT_FIELD(mystruct->STATUS_INPUTBUS1, buffer8, 0, 0xfc);
	UNPACK_BIT_FIELD(mystruct->STATUS_INPUTBUS2, buffer8, 2, 0xf3);
	UNPACK_BIT_FIELD(mystruct->STATUS_INPUTPAD, buffer8, 4, 0xf);


	UNPACK_UINT8(&buffer8, &bytes[2]);
	UNPACK_BIT_FIELD(mystruct->FEEDBACK_INPUTRELAY1, buffer8, 0, 0xfc);
	UNPACK_BIT_FIELD(mystruct->FEEDBACK_INPUTRELAY2, buffer8, 2, 0xf3);
	UNPACK_BIT_FIELD(mystruct->FEEDBACK_INPUT_PAD, buffer8, 4, 0xf);

	UNPACK_UINT8(&mystruct->PDU_INVALIDCOMMANDERROR, &bytes[3]);

	UNPACK_UINT8(&buffer8, &bytes[4]);
	UNPACK_BIT_FIELD(mystruct->FEEDBACKSTATEMISMATCHERROR_INPUTBUS1, buffer8, 0, 0xfc);
	UNPACK_BIT_FIELD(mystruct->FEEDBACKSTATEMISMATCHERROR_INPUTBUS2, buffer8, 2, 0xf3);
	UNPACK_BIT_FIELD(mystruct->FEEDBACKSTATEMISMATCHERROR_PAD, buffer8, 4, 0xf);


	UNPACK_UINT8(&buffer8, &bytes[5]);
	UNPACK_BIT_FIELD(mystruct->POSNEGMISMATCHERROR_INPUT1, buffer8, 0, 0xfe);
	UNPACK_BIT_FIELD(mystruct->POSNEGMISMATCHERROR_INPUT2, buffer8, 1, 0xfd);
	UNPACK_BIT_FIELD(mystruct->POSNEGMISMATCHERROR_PAD, buffer8, 2, 0x3);


	UNPACK_UINT8(&buffer8, &bytes[6]);
	UNPACK_BIT_FIELD(mystruct->CHANNELSTATUS_RPC1, buffer8, 0, 0xfe);
	UNPACK_BIT_FIELD(mystruct->CHANNELSTATUS_RPC2, buffer8, 1, 0xfd);
	UNPACK_BIT_FIELD(mystruct->CHANNELSTATUS_RPC3, buffer8, 2, 0xfb);
	UNPACK_BIT_FIELD(mystruct->CHANNELSTATUS_RPC4, buffer8, 3, 0xf7);
	UNPACK_BIT_FIELD(mystruct->CHANNELSTATUS_RPC5, buffer8, 4, 0xef);
	UNPACK_BIT_FIELD(mystruct->CHANNELSTATUS_RPC6, buffer8, 5, 0xdf);
	UNPACK_BIT_FIELD(mystruct->CHANNELSTATUS_RPC7, buffer8, 6, 0xbf);
	UNPACK_BIT_FIELD(mystruct->CHANNELSTATUS_RPC8, buffer8, 7, 0x7f);


	UNPACK_UINT8(&buffer8, &bytes[7]);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATUS_RPC1, buffer8, 0, 0xfe);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATUS_RPC2, buffer8, 1, 0xfd);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATUS_RPC3, buffer8, 2, 0xfb);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATUS_RPC4, buffer8, 3, 0xf7);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATUS_RPC5, buffer8, 4, 0xef);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATUS_RPC6, buffer8, 5, 0xdf);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATUS_RPC7, buffer8, 6, 0xbf);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATUS_RPC8, buffer8, 7, 0x7f);


	UNPACK_UINT8(&buffer8, &bytes[8]);
	UNPACK_BIT_FIELD(mystruct->OUTSTATUS_RPC1, buffer8, 0, 0xfe);
	UNPACK_BIT_FIELD(mystruct->OUTSTATUS_RPC2, buffer8, 1, 0xfd);
	UNPACK_BIT_FIELD(mystruct->OUTSTATUS_RPC3, buffer8, 2, 0xfb);
	UNPACK_BIT_FIELD(mystruct->OUTSTATUS_RPC4, buffer8, 3, 0xf7);
	UNPACK_BIT_FIELD(mystruct->OUTSTATUS_RPC5, buffer8, 4, 0xef);
	UNPACK_BIT_FIELD(mystruct->OUTSTATUS_RPC6, buffer8, 5, 0xdf);
	UNPACK_BIT_FIELD(mystruct->OUTSTATUS_RPC7, buffer8, 6, 0xbf);
	UNPACK_BIT_FIELD(mystruct->OUTSTATUS_RPC8, buffer8, 7, 0x7f);


	UNPACK_UINT8(&buffer8, &bytes[9]);
	UNPACK_BIT_FIELD(mystruct->MISMATCHERROR_RPC1, buffer8, 0, 0xfe);
	UNPACK_BIT_FIELD(mystruct->MISMATCHERROR_RPC2, buffer8, 1, 0xfd);
	UNPACK_BIT_FIELD(mystruct->MISMATCHERROR_RPC3, buffer8, 2, 0xfb);
	UNPACK_BIT_FIELD(mystruct->MISMATCHERROR_RPC4, buffer8, 3, 0xf7);
	UNPACK_BIT_FIELD(mystruct->MISMATCHERROR_RPC5, buffer8, 4, 0xef);
	UNPACK_BIT_FIELD(mystruct->MISMATCHERROR_RPC6, buffer8, 5, 0xdf);
	UNPACK_BIT_FIELD(mystruct->MISMATCHERROR_RPC7, buffer8, 6, 0xbf);
	UNPACK_BIT_FIELD(mystruct->MISMATCHERROR_RPC8, buffer8, 7, 0x7f);

	UNPACK_UINT8_ARRAY(mystruct->PDU_PAD, &bytes[10], 6);
	UNPACK_DOUBLE(&mystruct->PDU_CURRENTBUS_1, &bytes[16]);
	UNPACK_DOUBLE(&mystruct->PDU_CURRENTBUS_2, &bytes[24]);
	UNPACK_DOUBLE(&mystruct->PDU_CURRENTINTERNALBUS, &bytes[32]);
	UNPACK_DOUBLE(&mystruct->PDU_VOLTAGEBUS_1, &bytes[40]);
	UNPACK_DOUBLE(&mystruct->PDU_VOLTAGEBUS_2, &bytes[48]);
	UNPACK_DOUBLE(&mystruct->PDU_VOLTAGEINTERNAL, &bytes[56]);
	UNPACK_DOUBLE(&mystruct->PDU_VOLTAGEHKPG, &bytes[64]);
	UNPACK_DOUBLE(&mystruct->PDU_CURRENTRPC_1, &bytes[72]);
	UNPACK_DOUBLE(&mystruct->PDU_CURRENTRPC_2, &bytes[80]);
	UNPACK_DOUBLE(&mystruct->PDU_CURRENTRPC_3, &bytes[88]);
	UNPACK_DOUBLE(&mystruct->PDU_CURRENTRPC_4, &bytes[96]);
	UNPACK_DOUBLE(&mystruct->PDU_CURRENTRPC_5, &bytes[104]);
	UNPACK_DOUBLE(&mystruct->PDU_CURRENTRPC_6, &bytes[112]);
	UNPACK_DOUBLE(&mystruct->PDU_CURRENTRPC_7, &bytes[120]);
	UNPACK_DOUBLE(&mystruct->PDU_CURRENTRPC_8, &bytes[128]);

	return sizeof(PDU_telemetry);
}


static inline uint32_t PackMBSU_telemetry(void *buffer, void *protobetter_type)
{
	uint8_t buffer8 = 0;

	MBSU_telemetry *mystruct = (MBSU_telemetry*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	PACK_UINT8(&bytes[0], &mystruct->MBSU_ID);

	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->SOURCESELECT_STATUS_INPUT1, 0, 0xfc);
	PACK_BIT_FIELD(buffer8, mystruct->SOURCESELECT_STATUS_INPUT2, 2, 0xf3);
	PACK_BIT_FIELD(buffer8, mystruct->SOURCESELECT_STATUS_INPUT3, 4, 0xcf);
	PACK_BIT_FIELD(buffer8, mystruct->SOURCESELECT_STATUS_PAD, 6, 0x3f);
	PACK_UINT8(&bytes[1], &buffer8);


	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->FEEDBACK_STATUS_INPUTRELAY1, 0, 0xfc);
	PACK_BIT_FIELD(buffer8, mystruct->FEEDBACK_STATUS_INPUTRELAY2, 2, 0xf3);
	PACK_BIT_FIELD(buffer8, mystruct->FEEDBACK_STATUS_INPUTRELAY3, 4, 0xcf);
	PACK_BIT_FIELD(buffer8, mystruct->FEEDBACK_STATUS_PAD, 6, 0x3f);
	PACK_UINT8(&bytes[2], &buffer8);

	PACK_UINT8(&bytes[3], &mystruct->MBSU_INPUT_INVALIDBATTERY_ERROR);
	PACK_UINT8(&bytes[4], &mystruct->MBSU_INPUT_INVALIDSOLARARRAY_ERROR);
	PACK_UINT8(&bytes[5], &mystruct->MBSU_INPUT_INVALIDAUXMBSUINPUT_ERROR);
	PACK_UINT8(&bytes[6], &mystruct->MBSU_INPUT_INVALIDAUXMBSUOUTPUT_ERROR);

	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->STATEMISMATCH_ERROR_INPUT_RELAY1, 0, 0xfc);
	PACK_BIT_FIELD(buffer8, mystruct->STATEMISMATCH_ERROR_INPUT_RELAY2, 2, 0xf3);
	PACK_BIT_FIELD(buffer8, mystruct->STATEMISMATCH_ERROR_INPUT_RELAY3, 4, 0xcf);
	PACK_BIT_FIELD(buffer8, mystruct->STATEMISMATCH_ERROR_PAD, 6, 0x3f);
	PACK_UINT8(&bytes[7], &buffer8);


	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->POSNEGSTATEMISMATCH_ERROR_INPUT1, 0, 0xfe);
	PACK_BIT_FIELD(buffer8, mystruct->POSNEGSTATEMISMATCH_ERROR_INPUT2, 1, 0xfd);
	PACK_BIT_FIELD(buffer8, mystruct->POSNEGSTATEMISMATCH_ERROR_INPUT3, 2, 0xfb);
	PACK_BIT_FIELD(buffer8, mystruct->POSNEGSTATEMISMATCH_ERROR_PAD, 3, 0x7);
	PACK_UINT8(&bytes[8], &buffer8);


	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->OUTSTATUS_BUS1, 0, 0xfc);
	PACK_BIT_FIELD(buffer8, mystruct->OUTSTATUS_BUS2, 2, 0xf3);
	PACK_BIT_FIELD(buffer8, mystruct->OUTSTATUS_PAD, 4, 0xf);
	PACK_UINT8(&bytes[9], &buffer8);


	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->RELAYFEEDBACKSTATUS_BUSOUT1, 0, 0xfc);
	PACK_BIT_FIELD(buffer8, mystruct->RELAYFEEDBACKSTATUS_BUSOUT2, 2, 0xf3);
	PACK_BIT_FIELD(buffer8, mystruct->RELAYFEEDBACK_PAD, 4, 0xf);
	PACK_UINT8(&bytes[10], &buffer8);


	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->RELAYSTATEMISMATCHERROR_BUSOUT1, 0, 0xfc);
	PACK_BIT_FIELD(buffer8, mystruct->RELAYSTATEMISMATCHERROR_BUSOUT2, 2, 0xf3);
	PACK_BIT_FIELD(buffer8, mystruct->RELAYSTATE_PAD, 4, 0xf);
	PACK_UINT8(&bytes[11], &buffer8);


	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->MBSU_BUSOUTPPOSNEGSTATEMISMATCHERROR_CHAN1, 0, 0xfe);
	PACK_BIT_FIELD(buffer8, mystruct->MBSU_BUSOUTPPOSNEGSTATEMISMATCHERROR_CHAN2, 1, 0xfd);
	PACK_BIT_FIELD(buffer8, mystruct->MBSU_BUSOUTPPOSNEGSTATEMISMATCHERROR_CHAN3, 2, 0xfb);
	PACK_BIT_FIELD(buffer8, mystruct->MBSU_BUSOUTPPOSNEGSTATEMISMATCHERROR_CHAN4, 3, 0xf7);
	PACK_BIT_FIELD(buffer8, mystruct->MBSU_BUSOUTPPOSNEGSTATEMISMATCHERROR_PAD, 4, 0xf);
	PACK_UINT8(&bytes[12], &buffer8);


	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATE_INPUTRELAY1, 0, 0xfc);
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATE_INPUTRELAY2, 2, 0xf3);
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATE_INPUTRELAY3, 4, 0xcf);
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATE_INPUTRELAY_PAD, 6, 0x3f);
	PACK_UINT8(&bytes[13], &buffer8);


	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATE_OUTPUTRELAY1, 0, 0xfe);
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATE_OUTPUTRELAY2, 1, 0xfd);
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATE_OUTPUTRELAY3, 2, 0xfb);
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATE_OUTPUTRELAY4, 3, 0xf7);
	PACK_BIT_FIELD(buffer8, mystruct->TRIPSTATE_PAD, 4, 0xf);
	PACK_UINT8(&bytes[14], &buffer8);

	PACK_UINT8(&bytes[15], &mystruct->MBSU_PAD);
	PACK_DOUBLE(&bytes[16], &mystruct->MBSU_SOLAR_ARRAY_INPUT_CURRENT);
	PACK_DOUBLE(&bytes[24], &mystruct->MBSU_BATTERY_BIDIRECTIONAL_CURRENT);
	PACK_DOUBLE(&bytes[32], &mystruct->MBSU_AUXMBSU_BIDIRECTIONAL_CURRENT);
	PACK_DOUBLE(&bytes[40], &mystruct->MBSU_AUX_VOLTAGE);
	PACK_DOUBLE(&bytes[48], &mystruct->MBSU_HKPS_VOLTAGE);
	PACK_DOUBLE(&bytes[56], &mystruct->MBSU_OUTPUT_CURRENT_1);
	PACK_DOUBLE(&bytes[64], &mystruct->MBSU_OUTPUT_CURRENT_2);
	PACK_DOUBLE(&bytes[72], &mystruct->MBSU_OUTPUT_CURRENT_3);
	PACK_DOUBLE(&bytes[80], &mystruct->MBSU_OUTPUT_CURRENT_4);
	PACK_DOUBLE(&bytes[88], &mystruct->MBSU_SARVOLTAGE);
	PACK_DOUBLE(&bytes[96], &mystruct->MBSU_BATTVOLTAGE);
	PACK_DOUBLE(&bytes[104], &mystruct->MBSU_INNERVOLTAGE);
	PACK_DOUBLE(&bytes[112], &mystruct->MBSU_SARCURRTRIPSP);
	PACK_DOUBLE(&bytes[120], &mystruct->MBSU_BATTCURRTRIPSP);
	PACK_DOUBLE(&bytes[128], &mystruct->MBSU_AUXCURRTRIPSP);
	PACK_DOUBLE(&bytes[136], &mystruct->MBSU_OUTPUTCURRTRIPSP_1);
	PACK_DOUBLE(&bytes[144], &mystruct->MBSU_OUTPUTCURRTRIPSP_2);
	PACK_DOUBLE(&bytes[152], &mystruct->MBSU_OUTPUTCURRTRIPSP_3);
	PACK_DOUBLE(&bytes[160], &mystruct->MBSU_OUTPUTCURRTRIPSP_4);

	return 168;
}


static inline uint32_t UnpackMBSU_telemetry(void *protobetter_type, void *buffer)
{
	uint8_t buffer8 = 0;

	MBSU_telemetry *mystruct = (MBSU_telemetry*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	UNPACK_UINT8(&mystruct->MBSU_ID, &bytes[0]);

	UNPACK_UINT8(&buffer8, &bytes[1]);
	UNPACK_BIT_FIELD(mystruct->SOURCESELECT_STATUS_INPUT1, buffer8, 0, 0xfc);
	UNPACK_BIT_FIELD(mystruct->SOURCESELECT_STATUS_INPUT2, buffer8, 2, 0xf3);
	UNPACK_BIT_FIELD(mystruct->SOURCESELECT_STATUS_INPUT3, buffer8, 4, 0xcf);
	UNPACK_BIT_FIELD(mystruct->SOURCESELECT_STATUS_PAD, buffer8, 6, 0x3f);


	UNPACK_UINT8(&buffer8, &bytes[2]);
	UNPACK_BIT_FIELD(mystruct->FEEDBACK_STATUS_INPUTRELAY1, buffer8, 0, 0xfc);
	UNPACK_BIT_FIELD(mystruct->FEEDBACK_STATUS_INPUTRELAY2, buffer8, 2, 0xf3);
	UNPACK_BIT_FIELD(mystruct->FEEDBACK_STATUS_INPUTRELAY3, buffer8, 4, 0xcf);
	UNPACK_BIT_FIELD(mystruct->FEEDBACK_STATUS_PAD, buffer8, 6, 0x3f);

	UNPACK_UINT8(&mystruct->MBSU_INPUT_INVALIDBATTERY_ERROR, &bytes[3]);
	UNPACK_UINT8(&mystruct->MBSU_INPUT_INVALIDSOLARARRAY_ERROR, &bytes[4]);
	UNPACK_UINT8(&mystruct->MBSU_INPUT_INVALIDAUXMBSUINPUT_ERROR, &bytes[5]);
	UNPACK_UINT8(&mystruct->MBSU_INPUT_INVALIDAUXMBSUOUTPUT_ERROR, &bytes[6]);

	UNPACK_UINT8(&buffer8, &bytes[7]);
	UNPACK_BIT_FIELD(mystruct->STATEMISMATCH_ERROR_INPUT_RELAY1, buffer8, 0, 0xfc);
	UNPACK_BIT_FIELD(mystruct->STATEMISMATCH_ERROR_INPUT_RELAY2, buffer8, 2, 0xf3);
	UNPACK_BIT_FIELD(mystruct->STATEMISMATCH_ERROR_INPUT_RELAY3, buffer8, 4, 0xcf);
	UNPACK_BIT_FIELD(mystruct->STATEMISMATCH_ERROR_PAD, buffer8, 6, 0x3f);


	UNPACK_UINT8(&buffer8, &bytes[8]);
	UNPACK_BIT_FIELD(mystruct->POSNEGSTATEMISMATCH_ERROR_INPUT1, buffer8, 0, 0xfe);
	UNPACK_BIT_FIELD(mystruct->POSNEGSTATEMISMATCH_ERROR_INPUT2, buffer8, 1, 0xfd);
	UNPACK_BIT_FIELD(mystruct->POSNEGSTATEMISMATCH_ERROR_INPUT3, buffer8, 2, 0xfb);
	UNPACK_BIT_FIELD(mystruct->POSNEGSTATEMISMATCH_ERROR_PAD, buffer8, 3, 0x7);


	UNPACK_UINT8(&buffer8, &bytes[9]);
	UNPACK_BIT_FIELD(mystruct->OUTSTATUS_BUS1, buffer8, 0, 0xfc);
	UNPACK_BIT_FIELD(mystruct->OUTSTATUS_BUS2, buffer8, 2, 0xf3);
	UNPACK_BIT_FIELD(mystruct->OUTSTATUS_PAD, buffer8, 4, 0xf);


	UNPACK_UINT8(&buffer8, &bytes[10]);
	UNPACK_BIT_FIELD(mystruct->RELAYFEEDBACKSTATUS_BUSOUT1, buffer8, 0, 0xfc);
	UNPACK_BIT_FIELD(mystruct->RELAYFEEDBACKSTATUS_BUSOUT2, buffer8, 2, 0xf3);
	UNPACK_BIT_FIELD(mystruct->RELAYFEEDBACK_PAD, buffer8, 4, 0xf);


	UNPACK_UINT8(&buffer8, &bytes[11]);
	UNPACK_BIT_FIELD(mystruct->RELAYSTATEMISMATCHERROR_BUSOUT1, buffer8, 0, 0xfc);
	UNPACK_BIT_FIELD(mystruct->RELAYSTATEMISMATCHERROR_BUSOUT2, buffer8, 2, 0xf3);
	UNPACK_BIT_FIELD(mystruct->RELAYSTATE_PAD, buffer8, 4, 0xf);


	UNPACK_UINT8(&buffer8, &bytes[12]);
	UNPACK_BIT_FIELD(mystruct->MBSU_BUSOUTPPOSNEGSTATEMISMATCHERROR_CHAN1, buffer8, 0, 0xfe);
	UNPACK_BIT_FIELD(mystruct->MBSU_BUSOUTPPOSNEGSTATEMISMATCHERROR_CHAN2, buffer8, 1, 0xfd);
	UNPACK_BIT_FIELD(mystruct->MBSU_BUSOUTPPOSNEGSTATEMISMATCHERROR_CHAN3, buffer8, 2, 0xfb);
	UNPACK_BIT_FIELD(mystruct->MBSU_BUSOUTPPOSNEGSTATEMISMATCHERROR_CHAN4, buffer8, 3, 0xf7);
	UNPACK_BIT_FIELD(mystruct->MBSU_BUSOUTPPOSNEGSTATEMISMATCHERROR_PAD, buffer8, 4, 0xf);


	UNPACK_UINT8(&buffer8, &bytes[13]);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATE_INPUTRELAY1, buffer8, 0, 0xfc);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATE_INPUTRELAY2, buffer8, 2, 0xf3);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATE_INPUTRELAY3, buffer8, 4, 0xcf);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATE_INPUTRELAY_PAD, buffer8, 6, 0x3f);


	UNPACK_UINT8(&buffer8, &bytes[14]);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATE_OUTPUTRELAY1, buffer8, 0, 0xfe);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATE_OUTPUTRELAY2, buffer8, 1, 0xfd);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATE_OUTPUTRELAY3, buffer8, 2, 0xfb);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATE_OUTPUTRELAY4, buffer8, 3, 0xf7);
	UNPACK_BIT_FIELD(mystruct->TRIPSTATE_PAD, buffer8, 4, 0xf);

	UNPACK_UINT8(&mystruct->MBSU_PAD, &bytes[15]);
	UNPACK_DOUBLE(&mystruct->MBSU_SOLAR_ARRAY_INPUT_CURRENT, &bytes[16]);
	UNPACK_DOUBLE(&mystruct->MBSU_BATTERY_BIDIRECTIONAL_CURRENT, &bytes[24]);
	UNPACK_DOUBLE(&mystruct->MBSU_AUXMBSU_BIDIRECTIONAL_CURRENT, &bytes[32]);
	UNPACK_DOUBLE(&mystruct->MBSU_AUX_VOLTAGE, &bytes[40]);
	UNPACK_DOUBLE(&mystruct->MBSU_HKPS_VOLTAGE, &bytes[48]);
	UNPACK_DOUBLE(&mystruct->MBSU_OUTPUT_CURRENT_1, &bytes[56]);
	UNPACK_DOUBLE(&mystruct->MBSU_OUTPUT_CURRENT_2, &bytes[64]);
	UNPACK_DOUBLE(&mystruct->MBSU_OUTPUT_CURRENT_3, &bytes[72]);
	UNPACK_DOUBLE(&mystruct->MBSU_OUTPUT_CURRENT_4, &bytes[80]);
	UNPACK_DOUBLE(&mystruct->MBSU_SARVOLTAGE, &bytes[88]);
	UNPACK_DOUBLE(&mystruct->MBSU_BATTVOLTAGE, &bytes[96]);
	UNPACK_DOUBLE(&mystruct->MBSU_INNERVOLTAGE, &bytes[104]);
	UNPACK_DOUBLE(&mystruct->MBSU_SARCURRTRIPSP, &bytes[112]);
	UNPACK_DOUBLE(&mystruct->MBSU_BATTCURRTRIPSP, &bytes[120]);
	UNPACK_DOUBLE(&mystruct->MBSU_AUXCURRTRIPSP, &bytes[128]);
	UNPACK_DOUBLE(&mystruct->MBSU_OUTPUTCURRTRIPSP_1, &bytes[136]);
	UNPACK_DOUBLE(&mystruct->MBSU_OUTPUTCURRTRIPSP_2, &bytes[144]);
	UNPACK_DOUBLE(&mystruct->MBSU_OUTPUTCURRTRIPSP_3, &bytes[152]);
	UNPACK_DOUBLE(&mystruct->MBSU_OUTPUTCURRTRIPSP_4, &bytes[160]);

	return sizeof(MBSU_telemetry);
}


uint32_t PackPPE_MBSU1(void *buffer, void *protobetter_type)
{

	PPE_MBSU1 *mystruct = (PPE_MBSU1*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->cfsHeader, 16);
	PackMBSU_telemetry(&bytes[16], &mystruct->ppe_mbsu1);

	return 184;
}


uint32_t UnpackPPE_MBSU1(void *protobetter_type, void *buffer)
{

	PPE_MBSU1 *mystruct = (PPE_MBSU1*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->cfsHeader, &bytes[0], 16);
	UnpackMBSU_telemetry(&mystruct->ppe_mbsu1, &bytes[16]);

	return sizeof(PPE_MBSU1);
}


uint32_t PackPPE_MBSU2(void *buffer, void *protobetter_type)
{

	PPE_MBSU2 *mystruct = (PPE_MBSU2*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->cfsHeader, 16);
	PackMBSU_telemetry(&bytes[16], &mystruct->ppe_mbsu2);

	return 184;
}


uint32_t UnpackPPE_MBSU2(void *protobetter_type, void *buffer)
{

	PPE_MBSU2 *mystruct = (PPE_MBSU2*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->cfsHeader, &bytes[0], 16);
	UnpackMBSU_telemetry(&mystruct->ppe_mbsu2, &bytes[16]);

	return sizeof(PPE_MBSU2);
}


uint32_t PackPPE_NAV_STATE_TLM(void *buffer, void *protobetter_type)
{

	PPE_NAV_STATE_TLM *mystruct = (PPE_NAV_STATE_TLM*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->cfsHeader, 16);
	PACK_DOUBLE(&bytes[16], &mystruct->TIME_TDB_SECONDS);
	PACK_DOUBLE(&bytes[24], &mystruct->INRTL_ATT_ROLL);
	PACK_DOUBLE(&bytes[32], &mystruct->INRTL_ATT_PITCH);
	PACK_DOUBLE(&bytes[40], &mystruct->INRTL_ATT_YAW);
	PACK_DOUBLE(&bytes[48], &mystruct->INRTL_POS_X);
	PACK_DOUBLE(&bytes[56], &mystruct->INRTL_POS_Y);
	PACK_DOUBLE(&bytes[64], &mystruct->INRTL_POS_Z);
	PACK_DOUBLE(&bytes[72], &mystruct->CG_POS_X);
	PACK_DOUBLE(&bytes[80], &mystruct->CG_POS_Y);
	PACK_DOUBLE(&bytes[88], &mystruct->CG_POS_Z);

	return 96;
}


uint32_t UnpackPPE_NAV_STATE_TLM(void *protobetter_type, void *buffer)
{

	PPE_NAV_STATE_TLM *mystruct = (PPE_NAV_STATE_TLM*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->cfsHeader, &bytes[0], 16);
	UNPACK_DOUBLE(&mystruct->TIME_TDB_SECONDS, &bytes[16]);
	UNPACK_DOUBLE(&mystruct->INRTL_ATT_ROLL, &bytes[24]);
	UNPACK_DOUBLE(&mystruct->INRTL_ATT_PITCH, &bytes[32]);
	UNPACK_DOUBLE(&mystruct->INRTL_ATT_YAW, &bytes[40]);
	UNPACK_DOUBLE(&mystruct->INRTL_POS_X, &bytes[48]);
	UNPACK_DOUBLE(&mystruct->INRTL_POS_Y, &bytes[56]);
	UNPACK_DOUBLE(&mystruct->INRTL_POS_Z, &bytes[64]);
	UNPACK_DOUBLE(&mystruct->CG_POS_X, &bytes[72]);
	UNPACK_DOUBLE(&mystruct->CG_POS_Y, &bytes[80]);
	UNPACK_DOUBLE(&mystruct->CG_POS_Z, &bytes[88]);

	return sizeof(PPE_NAV_STATE_TLM);
}


uint32_t PackPPE_PDU1(void *buffer, void *protobetter_type)
{

	PPE_PDU1 *mystruct = (PPE_PDU1*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->cfsHeader, 16);
	PackPDU_telemetry(&bytes[16], &mystruct->ppe_pdu1);

	return 152;
}


uint32_t UnpackPPE_PDU1(void *protobetter_type, void *buffer)
{

	PPE_PDU1 *mystruct = (PPE_PDU1*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->cfsHeader, &bytes[0], 16);
	UnpackPDU_telemetry(&mystruct->ppe_pdu1, &bytes[16]);

	return sizeof(PPE_PDU1);
}


uint32_t PackPPE_PDU2(void *buffer, void *protobetter_type)
{

	PPE_PDU2 *mystruct = (PPE_PDU2*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->cfsHeader, 16);
	PackPDU_telemetry(&bytes[16], &mystruct->ppe_pdu2);

	return 152;
}


uint32_t UnpackPPE_PDU2(void *protobetter_type, void *buffer)
{

	PPE_PDU2 *mystruct = (PPE_PDU2*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->cfsHeader, &bytes[0], 16);
	UnpackPDU_telemetry(&mystruct->ppe_pdu2, &bytes[16]);

	return sizeof(PPE_PDU2);
}


uint32_t PackPPE_Power_Source1(void *buffer, void *protobetter_type)
{

	PPE_Power_Source1 *mystruct = (PPE_Power_Source1*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->cfsHeader, 16);
	Packsim_power_source(&bytes[16], &mystruct->ppe_power_source1);

	return 77;
}


uint32_t UnpackPPE_Power_Source1(void *protobetter_type, void *buffer)
{

	PPE_Power_Source1 *mystruct = (PPE_Power_Source1*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->cfsHeader, &bytes[0], 16);
	Unpacksim_power_source(&mystruct->ppe_power_source1, &bytes[16]);

	return sizeof(PPE_Power_Source1);
}


uint32_t PackPPE_Power_Source2(void *buffer, void *protobetter_type)
{

	PPE_Power_Source2 *mystruct = (PPE_Power_Source2*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->cfsHeader, 16);
	Packsim_power_source(&bytes[16], &mystruct->ppe_power_source2);

	return 77;
}


uint32_t UnpackPPE_Power_Source2(void *protobetter_type, void *buffer)
{

	PPE_Power_Source2 *mystruct = (PPE_Power_Source2*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->cfsHeader, &bytes[0], 16);
	Unpacksim_power_source(&mystruct->ppe_power_source2, &bytes[16]);

	return sizeof(PPE_Power_Source2);
}


uint32_t PackSET_PPE_MBSU1_INPUT_SOURCE_SELECT_t(void *buffer, void *protobetter_type)
{

	SET_PPE_MBSU1_INPUT_SOURCE_SELECT_t *mystruct = (SET_PPE_MBSU1_INPUT_SOURCE_SELECT_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->CH_POS);
	PACK_UINT8(&bytes[13], &mystruct->INPUT_BUS);

	return 14;
}


uint32_t UnpackSET_PPE_MBSU1_INPUT_SOURCE_SELECT_t(void *protobetter_type, void *buffer)
{

	SET_PPE_MBSU1_INPUT_SOURCE_SELECT_t *mystruct = (SET_PPE_MBSU1_INPUT_SOURCE_SELECT_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->CH_POS, &bytes[12]);
	UNPACK_UINT8(&mystruct->INPUT_BUS, &bytes[13]);

	return sizeof(SET_PPE_MBSU1_INPUT_SOURCE_SELECT_t);
}


uint32_t PackSET_PPE_MBSU1_OUTPUT_CHANNEL_STATE_t(void *buffer, void *protobetter_type)
{

	SET_PPE_MBSU1_OUTPUT_CHANNEL_STATE_t *mystruct = (SET_PPE_MBSU1_OUTPUT_CHANNEL_STATE_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->CH_POS);
	PACK_UINT8(&bytes[13], &mystruct->OUTPUT_BUS);

	return 14;
}


uint32_t UnpackSET_PPE_MBSU1_OUTPUT_CHANNEL_STATE_t(void *protobetter_type, void *buffer)
{

	SET_PPE_MBSU1_OUTPUT_CHANNEL_STATE_t *mystruct = (SET_PPE_MBSU1_OUTPUT_CHANNEL_STATE_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->CH_POS, &bytes[12]);
	UNPACK_UINT8(&mystruct->OUTPUT_BUS, &bytes[13]);

	return sizeof(SET_PPE_MBSU1_OUTPUT_CHANNEL_STATE_t);
}


uint32_t PackSET_PPE_MBSU1_Input_Curr_Limit_t(void *buffer, void *protobetter_type)
{

	SET_PPE_MBSU1_Input_Curr_Limit_t *mystruct = (SET_PPE_MBSU1_Input_Curr_Limit_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_DOUBLE(&bytes[12], &mystruct->Input_Curr_Limit_SP);
	PACK_UINT8(&bytes[20], &mystruct->INPUT_BUS);

	return 21;
}


uint32_t UnpackSET_PPE_MBSU1_Input_Curr_Limit_t(void *protobetter_type, void *buffer)
{

	SET_PPE_MBSU1_Input_Curr_Limit_t *mystruct = (SET_PPE_MBSU1_Input_Curr_Limit_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_DOUBLE(&mystruct->Input_Curr_Limit_SP, &bytes[12]);
	UNPACK_UINT8(&mystruct->INPUT_BUS, &bytes[20]);

	return sizeof(SET_PPE_MBSU1_Input_Curr_Limit_t);
}


uint32_t PackSET_PPE_MBSU1_Output_Curr_Limit_t(void *buffer, void *protobetter_type)
{

	SET_PPE_MBSU1_Output_Curr_Limit_t *mystruct = (SET_PPE_MBSU1_Output_Curr_Limit_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_DOUBLE(&bytes[12], &mystruct->Output_Curr_Limit_SP);
	PACK_UINT8(&bytes[20], &mystruct->OUTPUT_BUS);

	return 21;
}


uint32_t UnpackSET_PPE_MBSU1_Output_Curr_Limit_t(void *protobetter_type, void *buffer)
{

	SET_PPE_MBSU1_Output_Curr_Limit_t *mystruct = (SET_PPE_MBSU1_Output_Curr_Limit_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_DOUBLE(&mystruct->Output_Curr_Limit_SP, &bytes[12]);
	UNPACK_UINT8(&mystruct->OUTPUT_BUS, &bytes[20]);

	return sizeof(SET_PPE_MBSU1_Output_Curr_Limit_t);
}


uint32_t PackCLEAR_PPE_MBSU1_Input_Curr_Trip_t(void *buffer, void *protobetter_type)
{

	CLEAR_PPE_MBSU1_Input_Curr_Trip_t *mystruct = (CLEAR_PPE_MBSU1_Input_Curr_Trip_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->INPUT_BUS);

	return 13;
}


uint32_t UnpackCLEAR_PPE_MBSU1_Input_Curr_Trip_t(void *protobetter_type, void *buffer)
{

	CLEAR_PPE_MBSU1_Input_Curr_Trip_t *mystruct = (CLEAR_PPE_MBSU1_Input_Curr_Trip_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->INPUT_BUS, &bytes[12]);

	return sizeof(CLEAR_PPE_MBSU1_Input_Curr_Trip_t);
}


uint32_t PackCLEAR_PPE_MBSU1_Output_Curr_Trip_t(void *buffer, void *protobetter_type)
{

	CLEAR_PPE_MBSU1_Output_Curr_Trip_t *mystruct = (CLEAR_PPE_MBSU1_Output_Curr_Trip_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->OUTPUT_BUS);

	return 13;
}


uint32_t UnpackCLEAR_PPE_MBSU1_Output_Curr_Trip_t(void *protobetter_type, void *buffer)
{

	CLEAR_PPE_MBSU1_Output_Curr_Trip_t *mystruct = (CLEAR_PPE_MBSU1_Output_Curr_Trip_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->OUTPUT_BUS, &bytes[12]);

	return sizeof(CLEAR_PPE_MBSU1_Output_Curr_Trip_t);
}


uint32_t PackSET_PPE_MBSU1_Relay_CHANNEL_OPEN_t(void *buffer, void *protobetter_type)
{

	SET_PPE_MBSU1_Relay_CHANNEL_OPEN_t *mystruct = (SET_PPE_MBSU1_Relay_CHANNEL_OPEN_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->FORCERelayOFF);
	PACK_UINT8(&bytes[13], &mystruct->OUTPUT_BUS);

	return 14;
}


uint32_t UnpackSET_PPE_MBSU1_Relay_CHANNEL_OPEN_t(void *protobetter_type, void *buffer)
{

	SET_PPE_MBSU1_Relay_CHANNEL_OPEN_t *mystruct = (SET_PPE_MBSU1_Relay_CHANNEL_OPEN_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->FORCERelayOFF, &bytes[12]);
	UNPACK_UINT8(&mystruct->OUTPUT_BUS, &bytes[13]);

	return sizeof(SET_PPE_MBSU1_Relay_CHANNEL_OPEN_t);
}


uint32_t PackPPE_MBSU1_FAIL_INPUT_SOURCE_t(void *buffer, void *protobetter_type)
{

	PPE_MBSU1_FAIL_INPUT_SOURCE_t *mystruct = (PPE_MBSU1_FAIL_INPUT_SOURCE_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->FORCERelayOFF);
	PACK_UINT8(&bytes[13], &mystruct->INPUT_BUS);

	return 14;
}


uint32_t UnpackPPE_MBSU1_FAIL_INPUT_SOURCE_t(void *protobetter_type, void *buffer)
{

	PPE_MBSU1_FAIL_INPUT_SOURCE_t *mystruct = (PPE_MBSU1_FAIL_INPUT_SOURCE_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->FORCERelayOFF, &bytes[12]);
	UNPACK_UINT8(&mystruct->INPUT_BUS, &bytes[13]);

	return sizeof(PPE_MBSU1_FAIL_INPUT_SOURCE_t);
}


uint32_t PackPPE_MBSU1_CMD(void *buffer, void *protobetter_type)
{
	unsigned char *msg = (unsigned char *) protobetter_type;

	uint16_t cmdCode = PROTOBETTER_READ_CCSDS_CODE(msg);

	switch (cmdCode)
	{
		case 0x2:

			return PackSET_PPE_MBSU1_Input_Curr_Limit_t(buffer, protobetter_type);

		case 0x1:

			return PackSET_PPE_MBSU1_OUTPUT_CHANNEL_STATE_t(buffer, protobetter_type);

		case 0x3:

			return PackSET_PPE_MBSU1_Output_Curr_Limit_t(buffer, protobetter_type);

		case 0x0:

			return PackSET_PPE_MBSU1_INPUT_SOURCE_SELECT_t(buffer, protobetter_type);

		case 0x7:

			return PackPPE_MBSU1_FAIL_INPUT_SOURCE_t(buffer, protobetter_type);

		case 0x6:

			return PackSET_PPE_MBSU1_Relay_CHANNEL_OPEN_t(buffer, protobetter_type);

		case 0x4:

			return PackCLEAR_PPE_MBSU1_Input_Curr_Trip_t(buffer, protobetter_type);

		case 0x5:

			return PackCLEAR_PPE_MBSU1_Output_Curr_Trip_t(buffer, protobetter_type);

		default:

			return 0;
	}
}


uint32_t UnpackPPE_MBSU1_CMD(void *protobetter_type, void *buffer)
{
	unsigned char *msg = (unsigned char *) buffer;

	uint16_t cmdCode = PROTOBETTER_READ_CCSDS_CODE(msg);

	switch (cmdCode)
	{
		case 0x2:

			return UnpackSET_PPE_MBSU1_Input_Curr_Limit_t(protobetter_type, buffer);

		case 0x1:

			return UnpackSET_PPE_MBSU1_OUTPUT_CHANNEL_STATE_t(protobetter_type, buffer);

		case 0x3:

			return UnpackSET_PPE_MBSU1_Output_Curr_Limit_t(protobetter_type, buffer);

		case 0x0:

			return UnpackSET_PPE_MBSU1_INPUT_SOURCE_SELECT_t(protobetter_type, buffer);

		case 0x7:

			return UnpackPPE_MBSU1_FAIL_INPUT_SOURCE_t(protobetter_type, buffer);

		case 0x6:

			return UnpackSET_PPE_MBSU1_Relay_CHANNEL_OPEN_t(protobetter_type, buffer);

		case 0x4:

			return UnpackCLEAR_PPE_MBSU1_Input_Curr_Trip_t(protobetter_type, buffer);

		case 0x5:

			return UnpackCLEAR_PPE_MBSU1_Output_Curr_Trip_t(protobetter_type, buffer);

		default:

			return 0;
	}
}


uint32_t PackSET_PPE_MBSU2_INPUT_SOURCE_SELECT_t(void *buffer, void *protobetter_type)
{

	SET_PPE_MBSU2_INPUT_SOURCE_SELECT_t *mystruct = (SET_PPE_MBSU2_INPUT_SOURCE_SELECT_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->CH_POS);
	PACK_UINT8(&bytes[13], &mystruct->INPUT_BUS);

	return 14;
}


uint32_t UnpackSET_PPE_MBSU2_INPUT_SOURCE_SELECT_t(void *protobetter_type, void *buffer)
{

	SET_PPE_MBSU2_INPUT_SOURCE_SELECT_t *mystruct = (SET_PPE_MBSU2_INPUT_SOURCE_SELECT_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->CH_POS, &bytes[12]);
	UNPACK_UINT8(&mystruct->INPUT_BUS, &bytes[13]);

	return sizeof(SET_PPE_MBSU2_INPUT_SOURCE_SELECT_t);
}


uint32_t PackSET_PPE_MBSU2_OUTPUT_CHANNEL_STATE_t(void *buffer, void *protobetter_type)
{

	SET_PPE_MBSU2_OUTPUT_CHANNEL_STATE_t *mystruct = (SET_PPE_MBSU2_OUTPUT_CHANNEL_STATE_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->CH_POS);
	PACK_UINT8(&bytes[13], &mystruct->OUTPUT_BUS);

	return 14;
}


uint32_t UnpackSET_PPE_MBSU2_OUTPUT_CHANNEL_STATE_t(void *protobetter_type, void *buffer)
{

	SET_PPE_MBSU2_OUTPUT_CHANNEL_STATE_t *mystruct = (SET_PPE_MBSU2_OUTPUT_CHANNEL_STATE_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->CH_POS, &bytes[12]);
	UNPACK_UINT8(&mystruct->OUTPUT_BUS, &bytes[13]);

	return sizeof(SET_PPE_MBSU2_OUTPUT_CHANNEL_STATE_t);
}


uint32_t PackSET_PPE_MBSU2_Input_Curr_Limit_t(void *buffer, void *protobetter_type)
{

	SET_PPE_MBSU2_Input_Curr_Limit_t *mystruct = (SET_PPE_MBSU2_Input_Curr_Limit_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_DOUBLE(&bytes[12], &mystruct->Input_Curr_Limit_SP);
	PACK_UINT8(&bytes[20], &mystruct->INPUT_BUS);

	return 21;
}


uint32_t UnpackSET_PPE_MBSU2_Input_Curr_Limit_t(void *protobetter_type, void *buffer)
{

	SET_PPE_MBSU2_Input_Curr_Limit_t *mystruct = (SET_PPE_MBSU2_Input_Curr_Limit_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_DOUBLE(&mystruct->Input_Curr_Limit_SP, &bytes[12]);
	UNPACK_UINT8(&mystruct->INPUT_BUS, &bytes[20]);

	return sizeof(SET_PPE_MBSU2_Input_Curr_Limit_t);
}


uint32_t PackSET_PPE_MBSU2_Output_Curr_Limit_t(void *buffer, void *protobetter_type)
{

	SET_PPE_MBSU2_Output_Curr_Limit_t *mystruct = (SET_PPE_MBSU2_Output_Curr_Limit_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_DOUBLE(&bytes[12], &mystruct->Output_Curr_Limit_SP);
	PACK_UINT8(&bytes[20], &mystruct->OUTPUT_BUS);

	return 21;
}


uint32_t UnpackSET_PPE_MBSU2_Output_Curr_Limit_t(void *protobetter_type, void *buffer)
{

	SET_PPE_MBSU2_Output_Curr_Limit_t *mystruct = (SET_PPE_MBSU2_Output_Curr_Limit_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_DOUBLE(&mystruct->Output_Curr_Limit_SP, &bytes[12]);
	UNPACK_UINT8(&mystruct->OUTPUT_BUS, &bytes[20]);

	return sizeof(SET_PPE_MBSU2_Output_Curr_Limit_t);
}


uint32_t PackCLEAR_PPE_MBSU2_Input_Curr_Trip_t(void *buffer, void *protobetter_type)
{

	CLEAR_PPE_MBSU2_Input_Curr_Trip_t *mystruct = (CLEAR_PPE_MBSU2_Input_Curr_Trip_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->INPUT_BUS);

	return 13;
}


uint32_t UnpackCLEAR_PPE_MBSU2_Input_Curr_Trip_t(void *protobetter_type, void *buffer)
{

	CLEAR_PPE_MBSU2_Input_Curr_Trip_t *mystruct = (CLEAR_PPE_MBSU2_Input_Curr_Trip_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->INPUT_BUS, &bytes[12]);

	return sizeof(CLEAR_PPE_MBSU2_Input_Curr_Trip_t);
}


uint32_t PackCLEAR_PPE_MBSU2_Output_Curr_Trip_t(void *buffer, void *protobetter_type)
{

	CLEAR_PPE_MBSU2_Output_Curr_Trip_t *mystruct = (CLEAR_PPE_MBSU2_Output_Curr_Trip_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->OUTPUT_BUS);

	return 13;
}


uint32_t UnpackCLEAR_PPE_MBSU2_Output_Curr_Trip_t(void *protobetter_type, void *buffer)
{

	CLEAR_PPE_MBSU2_Output_Curr_Trip_t *mystruct = (CLEAR_PPE_MBSU2_Output_Curr_Trip_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->OUTPUT_BUS, &bytes[12]);

	return sizeof(CLEAR_PPE_MBSU2_Output_Curr_Trip_t);
}


uint32_t PackSET_PPE_MBSU2_Relay_CHANNEL_OPEN_t(void *buffer, void *protobetter_type)
{

	SET_PPE_MBSU2_Relay_CHANNEL_OPEN_t *mystruct = (SET_PPE_MBSU2_Relay_CHANNEL_OPEN_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->FORCERelayOFF);
	PACK_UINT8(&bytes[13], &mystruct->OUTPUT_BUS);

	return 14;
}


uint32_t UnpackSET_PPE_MBSU2_Relay_CHANNEL_OPEN_t(void *protobetter_type, void *buffer)
{

	SET_PPE_MBSU2_Relay_CHANNEL_OPEN_t *mystruct = (SET_PPE_MBSU2_Relay_CHANNEL_OPEN_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->FORCERelayOFF, &bytes[12]);
	UNPACK_UINT8(&mystruct->OUTPUT_BUS, &bytes[13]);

	return sizeof(SET_PPE_MBSU2_Relay_CHANNEL_OPEN_t);
}


uint32_t PackPPE_MBSU2_FAIL_INPUT_SOURCE_t(void *buffer, void *protobetter_type)
{

	PPE_MBSU2_FAIL_INPUT_SOURCE_t *mystruct = (PPE_MBSU2_FAIL_INPUT_SOURCE_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->FORCERelayOFF);
	PACK_UINT8(&bytes[13], &mystruct->INPUT_BUS);

	return 14;
}


uint32_t UnpackPPE_MBSU2_FAIL_INPUT_SOURCE_t(void *protobetter_type, void *buffer)
{

	PPE_MBSU2_FAIL_INPUT_SOURCE_t *mystruct = (PPE_MBSU2_FAIL_INPUT_SOURCE_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->FORCERelayOFF, &bytes[12]);
	UNPACK_UINT8(&mystruct->INPUT_BUS, &bytes[13]);

	return sizeof(PPE_MBSU2_FAIL_INPUT_SOURCE_t);
}


uint32_t PackPPE_MBSU2_CMD(void *buffer, void *protobetter_type)
{
	unsigned char *msg = (unsigned char *) protobetter_type;

	uint16_t cmdCode = PROTOBETTER_READ_CCSDS_CODE(msg);

	switch (cmdCode)
	{
		case 0x3:

			return PackSET_PPE_MBSU2_Output_Curr_Limit_t(buffer, protobetter_type);

		case 0x5:

			return PackCLEAR_PPE_MBSU2_Output_Curr_Trip_t(buffer, protobetter_type);

		case 0x1:

			return PackSET_PPE_MBSU2_OUTPUT_CHANNEL_STATE_t(buffer, protobetter_type);

		case 0x6:

			return PackSET_PPE_MBSU2_Relay_CHANNEL_OPEN_t(buffer, protobetter_type);

		case 0x7:

			return PackPPE_MBSU2_FAIL_INPUT_SOURCE_t(buffer, protobetter_type);

		case 0x4:

			return PackCLEAR_PPE_MBSU2_Input_Curr_Trip_t(buffer, protobetter_type);

		case 0x2:

			return PackSET_PPE_MBSU2_Input_Curr_Limit_t(buffer, protobetter_type);

		case 0x0:

			return PackSET_PPE_MBSU2_INPUT_SOURCE_SELECT_t(buffer, protobetter_type);

		default:

			return 0;
	}
}


uint32_t UnpackPPE_MBSU2_CMD(void *protobetter_type, void *buffer)
{
	unsigned char *msg = (unsigned char *) buffer;

	uint16_t cmdCode = PROTOBETTER_READ_CCSDS_CODE(msg);

	switch (cmdCode)
	{
		case 0x3:

			return UnpackSET_PPE_MBSU2_Output_Curr_Limit_t(protobetter_type, buffer);

		case 0x5:

			return UnpackCLEAR_PPE_MBSU2_Output_Curr_Trip_t(protobetter_type, buffer);

		case 0x1:

			return UnpackSET_PPE_MBSU2_OUTPUT_CHANNEL_STATE_t(protobetter_type, buffer);

		case 0x6:

			return UnpackSET_PPE_MBSU2_Relay_CHANNEL_OPEN_t(protobetter_type, buffer);

		case 0x7:

			return UnpackPPE_MBSU2_FAIL_INPUT_SOURCE_t(protobetter_type, buffer);

		case 0x4:

			return UnpackCLEAR_PPE_MBSU2_Input_Curr_Trip_t(protobetter_type, buffer);

		case 0x2:

			return UnpackSET_PPE_MBSU2_Input_Curr_Limit_t(protobetter_type, buffer);

		case 0x0:

			return UnpackSET_PPE_MBSU2_INPUT_SOURCE_SELECT_t(protobetter_type, buffer);

		default:

			return 0;
	}
}


uint32_t PackSET_PPE_PDU1_INPUT_BUS_SELECT_t(void *buffer, void *protobetter_type)
{

	SET_PPE_PDU1_INPUT_BUS_SELECT_t *mystruct = (SET_PPE_PDU1_INPUT_BUS_SELECT_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->INPUT_BUS);

	return 13;
}


uint32_t UnpackSET_PPE_PDU1_INPUT_BUS_SELECT_t(void *protobetter_type, void *buffer)
{

	SET_PPE_PDU1_INPUT_BUS_SELECT_t *mystruct = (SET_PPE_PDU1_INPUT_BUS_SELECT_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->INPUT_BUS, &bytes[12]);

	return sizeof(SET_PPE_PDU1_INPUT_BUS_SELECT_t);
}


uint32_t PackSET_PPE_PDU1_RPC_CHANNEL_STATE_t(void *buffer, void *protobetter_type)
{

	SET_PPE_PDU1_RPC_CHANNEL_STATE_t *mystruct = (SET_PPE_PDU1_RPC_CHANNEL_STATE_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->RPCONOFFSTATE);
	PACK_UINT8(&bytes[13], &mystruct->rpcCHANNEL);

	return 14;
}


uint32_t UnpackSET_PPE_PDU1_RPC_CHANNEL_STATE_t(void *protobetter_type, void *buffer)
{

	SET_PPE_PDU1_RPC_CHANNEL_STATE_t *mystruct = (SET_PPE_PDU1_RPC_CHANNEL_STATE_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->RPCONOFFSTATE, &bytes[12]);
	UNPACK_UINT8(&mystruct->rpcCHANNEL, &bytes[13]);

	return sizeof(SET_PPE_PDU1_RPC_CHANNEL_STATE_t);
}


uint32_t PackSET_PPE_PDU1_RPC_CHANNEL_OPEN_t(void *buffer, void *protobetter_type)
{

	SET_PPE_PDU1_RPC_CHANNEL_OPEN_t *mystruct = (SET_PPE_PDU1_RPC_CHANNEL_OPEN_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->FORCERPCOFF);
	PACK_UINT8(&bytes[13], &mystruct->rpcCHANNEL);

	return 14;
}


uint32_t UnpackSET_PPE_PDU1_RPC_CHANNEL_OPEN_t(void *protobetter_type, void *buffer)
{

	SET_PPE_PDU1_RPC_CHANNEL_OPEN_t *mystruct = (SET_PPE_PDU1_RPC_CHANNEL_OPEN_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->FORCERPCOFF, &bytes[12]);
	UNPACK_UINT8(&mystruct->rpcCHANNEL, &bytes[13]);

	return sizeof(SET_PPE_PDU1_RPC_CHANNEL_OPEN_t);
}


uint32_t PackPPE_PDU1_CMD(void *buffer, void *protobetter_type)
{
	unsigned char *msg = (unsigned char *) protobetter_type;

	uint16_t cmdCode = PROTOBETTER_READ_CCSDS_CODE(msg);

	switch (cmdCode)
	{
		case 0x2:

			return PackSET_PPE_PDU1_RPC_CHANNEL_OPEN_t(buffer, protobetter_type);

		case 0x0:

			return PackSET_PPE_PDU1_INPUT_BUS_SELECT_t(buffer, protobetter_type);

		case 0x1:

			return PackSET_PPE_PDU1_RPC_CHANNEL_STATE_t(buffer, protobetter_type);

		default:

			return 0;
	}
}


uint32_t UnpackPPE_PDU1_CMD(void *protobetter_type, void *buffer)
{
	unsigned char *msg = (unsigned char *) buffer;

	uint16_t cmdCode = PROTOBETTER_READ_CCSDS_CODE(msg);

	switch (cmdCode)
	{
		case 0x2:

			return UnpackSET_PPE_PDU1_RPC_CHANNEL_OPEN_t(protobetter_type, buffer);

		case 0x0:

			return UnpackSET_PPE_PDU1_INPUT_BUS_SELECT_t(protobetter_type, buffer);

		case 0x1:

			return UnpackSET_PPE_PDU1_RPC_CHANNEL_STATE_t(protobetter_type, buffer);

		default:

			return 0;
	}
}


uint32_t PackSET_PPE_PDU2_INPUT_BUS_SELECT_t(void *buffer, void *protobetter_type)
{

	SET_PPE_PDU2_INPUT_BUS_SELECT_t *mystruct = (SET_PPE_PDU2_INPUT_BUS_SELECT_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->INPUT_BUS);

	return 13;
}


uint32_t UnpackSET_PPE_PDU2_INPUT_BUS_SELECT_t(void *protobetter_type, void *buffer)
{

	SET_PPE_PDU2_INPUT_BUS_SELECT_t *mystruct = (SET_PPE_PDU2_INPUT_BUS_SELECT_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->INPUT_BUS, &bytes[12]);

	return sizeof(SET_PPE_PDU2_INPUT_BUS_SELECT_t);
}


uint32_t PackSET_PPE_PDU2_RPC_CHANNEL_STATE_t(void *buffer, void *protobetter_type)
{

	SET_PPE_PDU2_RPC_CHANNEL_STATE_t *mystruct = (SET_PPE_PDU2_RPC_CHANNEL_STATE_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->RPCONOFFSTATE);
	PACK_UINT8(&bytes[13], &mystruct->rpcCHANNEL);

	return 14;
}


uint32_t UnpackSET_PPE_PDU2_RPC_CHANNEL_STATE_t(void *protobetter_type, void *buffer)
{

	SET_PPE_PDU2_RPC_CHANNEL_STATE_t *mystruct = (SET_PPE_PDU2_RPC_CHANNEL_STATE_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->RPCONOFFSTATE, &bytes[12]);
	UNPACK_UINT8(&mystruct->rpcCHANNEL, &bytes[13]);

	return sizeof(SET_PPE_PDU2_RPC_CHANNEL_STATE_t);
}


uint32_t PackSET_PPE_PDU2_RPC_CHANNEL_OPEN_t(void *buffer, void *protobetter_type)
{

	SET_PPE_PDU2_RPC_CHANNEL_OPEN_t *mystruct = (SET_PPE_PDU2_RPC_CHANNEL_OPEN_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->FORCERPCOFF);
	PACK_UINT8(&bytes[13], &mystruct->rpcCHANNEL);

	return 14;
}


uint32_t UnpackSET_PPE_PDU2_RPC_CHANNEL_OPEN_t(void *protobetter_type, void *buffer)
{

	SET_PPE_PDU2_RPC_CHANNEL_OPEN_t *mystruct = (SET_PPE_PDU2_RPC_CHANNEL_OPEN_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->FORCERPCOFF, &bytes[12]);
	UNPACK_UINT8(&mystruct->rpcCHANNEL, &bytes[13]);

	return sizeof(SET_PPE_PDU2_RPC_CHANNEL_OPEN_t);
}


uint32_t PackPPE_PDU2_CMD(void *buffer, void *protobetter_type)
{
	unsigned char *msg = (unsigned char *) protobetter_type;

	uint16_t cmdCode = PROTOBETTER_READ_CCSDS_CODE(msg);

	switch (cmdCode)
	{
		case 0x0:

			return PackSET_PPE_PDU2_INPUT_BUS_SELECT_t(buffer, protobetter_type);

		case 0x2:

			return PackSET_PPE_PDU2_RPC_CHANNEL_OPEN_t(buffer, protobetter_type);

		case 0x1:

			return PackSET_PPE_PDU2_RPC_CHANNEL_STATE_t(buffer, protobetter_type);

		default:

			return 0;
	}
}


uint32_t UnpackPPE_PDU2_CMD(void *protobetter_type, void *buffer)
{
	unsigned char *msg = (unsigned char *) buffer;

	uint16_t cmdCode = PROTOBETTER_READ_CCSDS_CODE(msg);

	switch (cmdCode)
	{
		case 0x0:

			return UnpackSET_PPE_PDU2_INPUT_BUS_SELECT_t(protobetter_type, buffer);

		case 0x2:

			return UnpackSET_PPE_PDU2_RPC_CHANNEL_OPEN_t(protobetter_type, buffer);

		case 0x1:

			return UnpackSET_PPE_PDU2_RPC_CHANNEL_STATE_t(protobetter_type, buffer);

		default:

			return 0;
	}
}


uint32_t PackSET_PPE_PS1_OUTPUT_CHANNEL_STATE_t(void *buffer, void *protobetter_type)
{

	SET_PPE_PS1_OUTPUT_CHANNEL_STATE_t *mystruct = (SET_PPE_PS1_OUTPUT_CHANNEL_STATE_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->outSTATE);
	PACK_UINT8(&bytes[13], &mystruct->outCHANNEL);

	return 14;
}


uint32_t UnpackSET_PPE_PS1_OUTPUT_CHANNEL_STATE_t(void *protobetter_type, void *buffer)
{

	SET_PPE_PS1_OUTPUT_CHANNEL_STATE_t *mystruct = (SET_PPE_PS1_OUTPUT_CHANNEL_STATE_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->outSTATE, &bytes[12]);
	UNPACK_UINT8(&mystruct->outCHANNEL, &bytes[13]);

	return sizeof(SET_PPE_PS1_OUTPUT_CHANNEL_STATE_t);
}


uint32_t PackSET_PPE_PS1_SAR_STATE_t(void *buffer, void *protobetter_type)
{

	SET_PPE_PS1_SAR_STATE_t *mystruct = (SET_PPE_PS1_SAR_STATE_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->sarSTATE);

	return 13;
}


uint32_t UnpackSET_PPE_PS1_SAR_STATE_t(void *protobetter_type, void *buffer)
{

	SET_PPE_PS1_SAR_STATE_t *mystruct = (SET_PPE_PS1_SAR_STATE_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->sarSTATE, &bytes[12]);

	return sizeof(SET_PPE_PS1_SAR_STATE_t);
}


uint32_t PackPPE_Power_Source1_CMD(void *buffer, void *protobetter_type)
{
	unsigned char *msg = (unsigned char *) protobetter_type;

	uint16_t cmdCode = PROTOBETTER_READ_CCSDS_CODE(msg);

	switch (cmdCode)
	{
		case 0x0:

			return PackSET_PPE_PS1_OUTPUT_CHANNEL_STATE_t(buffer, protobetter_type);

		case 0x1:

			return PackSET_PPE_PS1_SAR_STATE_t(buffer, protobetter_type);

		default:

			return 0;
	}
}


uint32_t UnpackPPE_Power_Source1_CMD(void *protobetter_type, void *buffer)
{
	unsigned char *msg = (unsigned char *) buffer;

	uint16_t cmdCode = PROTOBETTER_READ_CCSDS_CODE(msg);

	switch (cmdCode)
	{
		case 0x0:

			return UnpackSET_PPE_PS1_OUTPUT_CHANNEL_STATE_t(protobetter_type, buffer);

		case 0x1:

			return UnpackSET_PPE_PS1_SAR_STATE_t(protobetter_type, buffer);

		default:

			return 0;
	}
}


uint32_t PackSET_PPE_PS2_OUTPUT_CHANNEL_STATE_t(void *buffer, void *protobetter_type)
{

	SET_PPE_PS2_OUTPUT_CHANNEL_STATE_t *mystruct = (SET_PPE_PS2_OUTPUT_CHANNEL_STATE_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->outSTATE);
	PACK_UINT8(&bytes[13], &mystruct->outCHANNEL);

	return 14;
}


uint32_t UnpackSET_PPE_PS2_OUTPUT_CHANNEL_STATE_t(void *protobetter_type, void *buffer)
{

	SET_PPE_PS2_OUTPUT_CHANNEL_STATE_t *mystruct = (SET_PPE_PS2_OUTPUT_CHANNEL_STATE_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->outSTATE, &bytes[12]);
	UNPACK_UINT8(&mystruct->outCHANNEL, &bytes[13]);

	return sizeof(SET_PPE_PS2_OUTPUT_CHANNEL_STATE_t);
}


uint32_t PackSET_PPE_PS2_SAR_STATE_t(void *buffer, void *protobetter_type)
{

	SET_PPE_PS2_SAR_STATE_t *mystruct = (SET_PPE_PS2_SAR_STATE_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->CmdHeader, 10);
	memcpy(&bytes[10], &mystruct->CCSDS_CmdSecHdr, 2);
	PACK_UINT8(&bytes[12], &mystruct->sarSTATE);

	return 13;
}


uint32_t UnpackSET_PPE_PS2_SAR_STATE_t(void *protobetter_type, void *buffer)
{

	SET_PPE_PS2_SAR_STATE_t *mystruct = (SET_PPE_PS2_SAR_STATE_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->CmdHeader, &bytes[0], 10);
	memcpy(&mystruct->CCSDS_CmdSecHdr, &bytes[10], 2);
	UNPACK_UINT8(&mystruct->sarSTATE, &bytes[12]);

	return sizeof(SET_PPE_PS2_SAR_STATE_t);
}


uint32_t PackPPE_Power_Source2_CMD(void *buffer, void *protobetter_type)
{
	unsigned char *msg = (unsigned char *) protobetter_type;

	uint16_t cmdCode = PROTOBETTER_READ_CCSDS_CODE(msg);

	switch (cmdCode)
	{
		case 0x1:

			return PackSET_PPE_PS2_SAR_STATE_t(buffer, protobetter_type);

		case 0x0:

			return PackSET_PPE_PS2_OUTPUT_CHANNEL_STATE_t(buffer, protobetter_type);

		default:

			return 0;
	}
}


uint32_t UnpackPPE_Power_Source2_CMD(void *protobetter_type, void *buffer)
{
	unsigned char *msg = (unsigned char *) buffer;

	uint16_t cmdCode = PROTOBETTER_READ_CCSDS_CODE(msg);

	switch (cmdCode)
	{
		case 0x1:

			return UnpackSET_PPE_PS2_SAR_STATE_t(protobetter_type, buffer);

		case 0x0:

			return UnpackSET_PPE_PS2_OUTPUT_CHANNEL_STATE_t(protobetter_type, buffer);

		default:

			return 0;
	}
}


