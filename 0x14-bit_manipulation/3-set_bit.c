#include "main.h"

/**
 * set_bit - Sets the value of a bit at a given index to 1.
 * at a given index
 * @n: Pointer of an unsigned long int
 * @index: The index of the bit
 * Return: 1 if it worked else -1 if it dosent
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	*n ^= (1 << index);

	return (1);
}
