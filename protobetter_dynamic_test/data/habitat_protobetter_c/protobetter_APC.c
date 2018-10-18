#include "protobetter_APC.h"

static inline uint32_t PackpowerProfileRow(void *buffer, void *protobetter_type)
{

	powerProfileRow *mystruct = (powerProfileRow*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	PACK_UINT32(&bytes[0], &mystruct->timeUnit);
	PACK_FLOAT(&bytes[4], &mystruct->peakPower);
	PACK_FLOAT(&bytes[8], &mystruct->nominalPower);

	return 12;
}


static inline uint32_t UnpackpowerProfileRow(void *protobetter_type, void *buffer)
{

	powerProfileRow *mystruct = (powerProfileRow*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	UNPACK_UINT32(&mystruct->timeUnit, &bytes[0]);
	UNPACK_FLOAT(&mystruct->peakPower, &bytes[4]);
	UNPACK_FLOAT(&mystruct->nominalPower, &bytes[8]);

	return sizeof(powerProfileRow);
}


static inline uint32_t PackenergyAvailability(void *buffer, void *protobetter_type)
{

	energyAvailability *mystruct = (energyAvailability*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	{
		int ii = 0;
		for(ii = 0; ii < 24; ++ii) {
			PackpowerProfileRow(&bytes[0 + (ii*(12))], &mystruct->powerProfile[ii]);
		}
	}
	PACK_FLOAT(&bytes[288], &mystruct->energy_available);

	return 292;
}


static inline uint32_t UnpackenergyAvailability(void *protobetter_type, void *buffer)
{

	energyAvailability *mystruct = (energyAvailability*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	{
		int ii = 0;
		for(ii = 0; ii < 24; ++ii) {
			UnpackpowerProfileRow(&mystruct->powerProfile[ii], &bytes[0 + (ii*(12))]);
		}
	}
	UNPACK_FLOAT(&mystruct->energy_available, &bytes[288]);

	return sizeof(energyAvailability);
}


static inline uint32_t Packrequest_energy_return_t(void *buffer, void *protobetter_type)
{

	request_energy_return_t *mystruct = (request_energy_return_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	PACK_UINT32(&bytes[0], &mystruct->timestamp);
	PACK_UINT32(&bytes[4], &mystruct->return_code);
	PackenergyAvailability(&bytes[8], &mystruct->value);

	return 300;
}


static inline uint32_t Unpackrequest_energy_return_t(void *protobetter_type, void *buffer)
{

	request_energy_return_t *mystruct = (request_energy_return_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	UNPACK_UINT32(&mystruct->timestamp, &bytes[0]);
	UNPACK_UINT32(&mystruct->return_code, &bytes[4]);
	UnpackenergyAvailability(&mystruct->value, &bytes[8]);

	return sizeof(request_energy_return_t);
}


static inline uint32_t Packswitch_state(void *buffer, void *protobetter_type)
{

	switch_state *mystruct = (switch_state*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	PACK_UINT32(&bytes[0], &mystruct->oru_id);
	PACK_UINT32(&bytes[4], &mystruct->switch_id);
	PACK_UINT32(&bytes[8], &mystruct->state);

	return 12;
}


static inline uint32_t Unpackswitch_state(void *protobetter_type, void *buffer)
{

	switch_state *mystruct = (switch_state*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	UNPACK_UINT32(&mystruct->oru_id, &bytes[0]);
	UNPACK_UINT32(&mystruct->switch_id, &bytes[4]);
	UNPACK_UINT32(&mystruct->state, &bytes[8]);

	return sizeof(switch_state);
}


static inline uint32_t Packload_shed_state_t(void *buffer, void *protobetter_type)
{

	load_shed_state_t *mystruct = (load_shed_state_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	PACK_UINT32(&bytes[0], &mystruct->timestamp);
	{
		int ii = 0;
		for(ii = 0; ii < 16; ++ii) {
			Packswitch_state(&bytes[4 + (ii*(12))], &mystruct->states[ii]);
		}
	}

	return 196;
}


static inline uint32_t Unpackload_shed_state_t(void *protobetter_type, void *buffer)
{

	load_shed_state_t *mystruct = (load_shed_state_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	UNPACK_UINT32(&mystruct->timestamp, &bytes[0]);
	{
		int ii = 0;
		for(ii = 0; ii < 16; ++ii) {
			Unpackswitch_state(&mystruct->states[ii], &bytes[4 + (ii*(12))]);
		}
	}

	return sizeof(load_shed_state_t);
}


static inline uint32_t Packfault(void *buffer, void *protobetter_type)
{

	fault *mystruct = (fault*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	PACK_UINT32(&bytes[0], &mystruct->oru_id);
	PACK_UINT32(&bytes[4], &mystruct->switch_id);
	PACK_UINT32(&bytes[8], &mystruct->fault_type);

	return 12;
}


static inline uint32_t Unpackfault(void *protobetter_type, void *buffer)
{

	fault *mystruct = (fault*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	UNPACK_UINT32(&mystruct->oru_id, &bytes[0]);
	UNPACK_UINT32(&mystruct->switch_id, &bytes[4]);
	UNPACK_UINT32(&mystruct->fault_type, &bytes[8]);

	return sizeof(fault);
}


static inline uint32_t Packsystem_faults_t(void *buffer, void *protobetter_type)
{

	system_faults_t *mystruct = (system_faults_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	PACK_UINT32(&bytes[0], &mystruct->timestamp);
	PACK_UINT32(&bytes[4], &mystruct->number_of_faults);
	{
		int ii = 0;
		for(ii = 0; ii < 10; ++ii) {
			Packfault(&bytes[8 + (ii*(12))], &mystruct->faults[ii]);
		}
	}

	return 128;
}


static inline uint32_t Unpacksystem_faults_t(void *protobetter_type, void *buffer)
{

	system_faults_t *mystruct = (system_faults_t*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	UNPACK_UINT32(&mystruct->timestamp, &bytes[0]);
	UNPACK_UINT32(&mystruct->number_of_faults, &bytes[4]);
	{
		int ii = 0;
		for(ii = 0; ii < 10; ++ii) {
			Unpackfault(&mystruct->faults[ii], &bytes[8 + (ii*(12))]);
		}
	}

	return sizeof(system_faults_t);
}


static inline uint32_t Packapc_telemetry(void *buffer, void *protobetter_type)
{

	apc_telemetry *mystruct = (apc_telemetry*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	PACK_UINT32(&bytes[0], &mystruct->timestamp);
	Packsystem_faults_t(&bytes[4], &mystruct->system_faults);
	Packload_shed_state_t(&bytes[132], &mystruct->load_shed_state);
	Packrequest_energy_return_t(&bytes[328], &mystruct->request_energy_return);

	return 628;
}


static inline uint32_t Unpackapc_telemetry(void *protobetter_type, void *buffer)
{

	apc_telemetry *mystruct = (apc_telemetry*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	UNPACK_UINT32(&mystruct->timestamp, &bytes[0]);
	Unpacksystem_faults_t(&mystruct->system_faults, &bytes[4]);
	Unpackload_shed_state_t(&mystruct->load_shed_state, &bytes[132]);
	Unpackrequest_energy_return_t(&mystruct->request_energy_return, &bytes[328]);

	return sizeof(apc_telemetry);
}


uint32_t PackAPC_AVAILIBILITY(void *buffer, void *protobetter_type)
{

	APC_AVAILIBILITY *mystruct = (APC_AVAILIBILITY*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->cfsHeader, 16);
	Packapc_telemetry(&bytes[16], &mystruct->apc_availibility);

	return 644;
}


uint32_t UnpackAPC_AVAILIBILITY(void *protobetter_type, void *buffer)
{

	APC_AVAILIBILITY *mystruct = (APC_AVAILIBILITY*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->cfsHeader, &bytes[0], 16);
	Unpackapc_telemetry(&mystruct->apc_availibility, &bytes[16]);

	return sizeof(APC_AVAILIBILITY);
}


uint32_t PackAPC_EA_RESPONSE(void *buffer, void *protobetter_type)
{

	APC_EA_RESPONSE *mystruct = (APC_EA_RESPONSE*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->cfsHeader, 16);
	Packapc_telemetry(&bytes[16], &mystruct->apc_ea_response);

	return 644;
}


uint32_t UnpackAPC_EA_RESPONSE(void *protobetter_type, void *buffer)
{

	APC_EA_RESPONSE *mystruct = (APC_EA_RESPONSE*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->cfsHeader, &bytes[0], 16);
	Unpackapc_telemetry(&mystruct->apc_ea_response, &bytes[16]);

	return sizeof(APC_EA_RESPONSE);
}


uint32_t Packapc_load_schedule_response(void *buffer, void *protobetter_type)
{

	apc_load_schedule_response *mystruct = (apc_load_schedule_response*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->cfsHeader, 16);
	PACK_UINT32(&bytes[16], &mystruct->timestamp);
	PACK_UINT32(&bytes[20], &mystruct->return_code);

	return 24;
}


uint32_t Unpackapc_load_schedule_response(void *protobetter_type, void *buffer)
{

	apc_load_schedule_response *mystruct = (apc_load_schedule_response*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->cfsHeader, &bytes[0], 16);
	UNPACK_UINT32(&mystruct->timestamp, &bytes[16]);
	UNPACK_UINT32(&mystruct->return_code, &bytes[20]);

	return sizeof(apc_load_schedule_response);
}


