#include "main.h"

/**
 * set_bit - Sets a bit at given index to 1
 * at a given index
 * @n: pointer to an unsigned int.
 * @index: The index of the bit
 *
 * Return: return 1 if it worked and -1 if it didnt.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int m = 0x01;

	m <<= index;
	if (m == 0)
		return (-1);
	*n |= m;
	return (1);
}
