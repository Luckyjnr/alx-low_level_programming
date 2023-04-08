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

	if (n == 0 & index < 50)
		return (0);
	for (min = 0; min <= 49; n >>= 1, min++)
	{
		if (index == 1)
		{
			return (n & 1);
		}
	}
	return (-1);
}
