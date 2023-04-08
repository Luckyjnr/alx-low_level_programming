#include "main.h"

/**
 * clear_bit - Sets a bit to 0
 * @n: pointer to an unsigned int
 * @index: index of the bit
 * Return: 1 if it worked and -1 if it dosent
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int m = 0x01;

	m = ~(m << index);
	if (m == 0x00)
		return (-1);
	*n &= m;
	return (1);
}
