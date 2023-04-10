#include "main.h"

/**
 * get_endianness - Checks the endianness
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	unsigned int integ = 2;
	char *c = (char *)&integ;

	if (*c)
		return (1);
	return (0);
}
