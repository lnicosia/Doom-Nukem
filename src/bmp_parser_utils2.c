#include "env.h"
#include "bmp_parser.h"

/*
**	Read a integer of 32 bits
**	TODO Better protection
*/

int32_t		read_int32_swaped(unsigned char *str, int index)
{
	int32_t		res;

	res = str[index + 3] >> 24
		| str[index + 2] >> 16
		| str[index + 1] >> 8
		| str[index + 0];
	return (res);
}

/*
**	Read a integer of 32 bits
**	TODO Better protection
*/

int32_t		read_int32(unsigned char *str, int index)
{
	int32_t		res;

	res = str[index + 3] << 24
		| str[index + 2] << 16
		| str[index + 1] << 8
		| str[index];
	return (res);
}

/*
**	Read a integer of 16 bits
**	TODO Better protection
*/

int32_t		read_int16(unsigned char *str, int index)
{
	int32_t		res;

	res = str[index + 1] << 8
		| str[index];
	return (res);
}

/*
**	Read a integer of 32 bits
**	TODO Better protection
*/

uint32_t		read_color32(unsigned char *str, int index)
{
	uint32_t		res;

	res = str[index + 3] << 24
		| str[index + 2] << 16
		| str[index + 1] << 8
		| str[index + 0];
	return (res);
}

/*
**	Read a integer of 24 bits
**	TODO Better protection
*/

uint32_t		read_color24(unsigned char *str, int index)
{
	uint32_t		res;

	res = 255 << 24
		| str[index + 2] << 16
		| str[index + 1] << 8
		| str[index + 0] << 0;
	return (res);
}
