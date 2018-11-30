#ifndef __PROTOBETTER_GENERATED_H__
#define __PROTOBETTER_GENERATED_H__

#ifdef __cplusplus
extern "C"
{
#endif
#include <stdint.h>
#include "protobetter_core.h"

typedef struct
{
	uint8_t id : 4;
	float x;
	float y;
	float z;

} Vector_c;

#define STRUCT_VECTOR_C_PACKED_SIZE 13

uint32_t PackVector_c(void *buffer, void *protobetter_type);


uint32_t UnpackVector_c(void *protobetter_type, void *buffer);


typedef struct
{
	float a;
	uint32_t b : 31;
	uint32_t c : 1;
	uint32_t d : 4;
	Vector_c e[3];
	int16_t f : 16;

} LilBity_c;

#define STRUCT_LILBITY_C_PACKED_SIZE 53

uint32_t PackLilBity_c(void *buffer, void *protobetter_type);


uint32_t UnpackLilBity_c(void *protobetter_type, void *buffer);


typedef struct
{
	char header[16];
	double a;
	LilBity_c b[2];
	int16_t c[3];
	Vector_c d;
	int8_t e : 3;

} Bittylicious_c;

#define STRUCT_BITTYLICIOUS_C_PACKED_SIZE 150

uint32_t PackBittylicious_c(void *buffer, void *protobetter_type);


uint32_t UnpackBittylicious_c(void *protobetter_type, void *buffer);


void InitVector_cWithExpectedValues(Vector_c *v);
void InitLilBity_cWithExpectedValues(LilBity_c *lilBitty);
void InitBittylicious_cWithExpectedValues(Bittylicious_c *mystruct);

#ifdef __cplusplus
}
#endif
#endif //__PROTOBETTER_GENERATED_H__

