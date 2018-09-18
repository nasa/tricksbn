#include "protobetter_generated.h"


uint32_t PackVector_c(void *buffer, void *protobetter_type)
{
	uint8_t buffer8 = 0;

	Vector_c *mystruct = (Vector_c*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;


	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->id, 0, 0xf0);
	PACK_UINT8(&bytes[0], &buffer8);

	PACK_FLOAT(&bytes[1], &mystruct->x);
	PACK_FLOAT(&bytes[5], &mystruct->y);
	PACK_FLOAT(&bytes[9], &mystruct->z);

	return 13;
}


uint32_t UnpackVector_c(void *protobetter_type, void *buffer)
{
	uint8_t buffer8 = 0;

	Vector_c *mystruct = (Vector_c*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;


	UNPACK_UINT8(&buffer8, &bytes[0]);
	UNPACK_BIT_FIELD(mystruct->id, buffer8, 0, 0xf0);

	UNPACK_FLOAT(&mystruct->x, &bytes[1]);
	UNPACK_FLOAT(&mystruct->y, &bytes[5]);
	UNPACK_FLOAT(&mystruct->z, &bytes[9]);

	return sizeof(Vector_c);
}


uint32_t PackLilBity_c(void *buffer, void *protobetter_type)
{
	uint16_t buffer16 = 0;
	uint32_t buffer32 = 0;

	LilBity_c *mystruct = (LilBity_c*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	PACK_FLOAT(&bytes[0], &mystruct->a);

	buffer32 = 0;
	PACK_BIT_FIELD(buffer32, mystruct->b, 0, 0x80000000);
	PACK_BIT_FIELD(buffer32, mystruct->c, 31, 0x7fffffff);
	PACK_UINT32(&bytes[4], &buffer32);


	buffer32 = 0;
	PACK_BIT_FIELD(buffer32, mystruct->d, 0, 0xfffffff0);
	PACK_UINT32(&bytes[8], &buffer32);

	{
		int ii = 0;
		for(ii = 0; ii < 3; ++ii) {
			PackVector_c(&bytes[12 + (ii*(13))], &mystruct->e[ii]);
		}
	}

	buffer16 = 0;
	PACK_BIT_FIELD(buffer16, mystruct->f, 0, 0x0);
	PACK_UINT16(&bytes[51], &buffer16);


	return 53;
}


uint32_t UnpackLilBity_c(void *protobetter_type, void *buffer)
{
	uint16_t buffer16 = 0;
	uint32_t buffer32 = 0;

	LilBity_c *mystruct = (LilBity_c*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	UNPACK_FLOAT(&mystruct->a, &bytes[0]);

	UNPACK_UINT32(&buffer32, &bytes[4]);
	UNPACK_BIT_FIELD(mystruct->b, buffer32, 0, 0x80000000);
	UNPACK_BIT_FIELD(mystruct->c, buffer32, 31, 0x7fffffff);


	UNPACK_UINT32(&buffer32, &bytes[8]);
	UNPACK_BIT_FIELD(mystruct->d, buffer32, 0, 0xfffffff0);

	{
		int ii = 0;
		for(ii = 0; ii < 3; ++ii) {
			UnpackVector_c(&mystruct->e[ii], &bytes[12 + (ii*(13))]);
		}
	}

	UNPACK_UINT16(&buffer16, &bytes[51]);
	UNPACK_BIT_FIELD(mystruct->f, buffer16, 0, 0x0);


	return sizeof(LilBity_c);
}


uint32_t PackBittylicious_c(void *buffer, void *protobetter_type)
{
	uint8_t buffer8 = 0;

	Bittylicious_c *mystruct = (Bittylicious_c*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&bytes[0], &mystruct->header, 16);
	PACK_DOUBLE(&bytes[16], &mystruct->a);
	{
		int ii = 0;
		for(ii = 0; ii < 2; ++ii) {
			PackLilBity_c(&bytes[24 + (ii*(53))], &mystruct->b[ii]);
		}
	}
	PACK_UINT16_ARRAY(&bytes[130], mystruct->c, 3);
	PackVector_c(&bytes[136], &mystruct->d);

	buffer8 = 0;
	PACK_BIT_FIELD(buffer8, mystruct->e, 0, 0xf8);
	PACK_UINT8(&bytes[149], &buffer8);


	return 150;
}


uint32_t UnpackBittylicious_c(void *protobetter_type, void *buffer)
{
	uint8_t buffer8 = 0;

	Bittylicious_c *mystruct = (Bittylicious_c*)protobetter_type;
	unsigned char *bytes = (unsigned char*)buffer;

	memcpy(&mystruct->header, &bytes[0], 16);
	UNPACK_DOUBLE(&mystruct->a, &bytes[16]);
	{
		int ii = 0;
		for(ii = 0; ii < 2; ++ii) {
			UnpackLilBity_c(&mystruct->b[ii], &bytes[24 + (ii*(53))]);
		}
	}
	UNPACK_UINT16_ARRAY(mystruct->c, &bytes[130], 3);
	UnpackVector_c(&mystruct->d, &bytes[136]);

	UNPACK_UINT8(&buffer8, &bytes[149]);
	UNPACK_BIT_FIELD(mystruct->e, buffer8, 0, 0xf8);


	return sizeof(Bittylicious_c);
}

void InitVector_cWithExpectedValues(Vector_c *v)
{
    v->id = 15;
    v->x = 1.2345;
    v->y = 97865.4321;
    v->z = 867.5309;
}

void InitLilBity_cWithExpectedValues(LilBity_c *lilBitty)
{
    lilBitty->a = 123.123;
    lilBitty->b = 134217728;
    lilBitty->c = 1;
    lilBitty->d = 7;
    InitVector_cWithExpectedValues(&lilBitty->e[0]);
    InitVector_cWithExpectedValues(&lilBitty->e[1]);
    InitVector_cWithExpectedValues(&lilBitty->e[2]);
    lilBitty->f = 25867;
}

void InitBittylicious_cWithExpectedValues(Bittylicious_c *mystruct)
{
    memcpy(mystruct->header, "The quick brown", 16);
    mystruct->a = 42.123456;
    InitLilBity_cWithExpectedValues(&mystruct->b[0]);
    InitLilBity_cWithExpectedValues(&mystruct->b[1]);
    mystruct->c[0] = 12;
    mystruct->c[1] = 9;
    mystruct->c[2] = 6;
    InitVector_cWithExpectedValues(&mystruct->d);
    mystruct->e = 3;
}









