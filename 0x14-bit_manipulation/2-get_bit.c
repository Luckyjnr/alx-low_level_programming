#include "main.h"

/**
 * get_bit - returns the value of a bit at a given
 * index.
 * @n: Number to get bit from
 * @index: index of a bit
 *
 * Return: value of a bit
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int min = 0x01;

	min <<= index;
	if (min == 0)
		return (-1);

	if ((n & min))
		return (1);
	else
		return (0);
}
