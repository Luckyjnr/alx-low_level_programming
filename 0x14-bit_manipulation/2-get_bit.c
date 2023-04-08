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
	unsigned long int f;

	if (n == 0 & index < 50)
		return (0);
	for (f = 0; f <= 49; n >>= 1, f++)
	{
		if (index == f)
		{
			return (n & 1);
		}
	}
	return (-1);
}
