#include "main.h"

/**
 * clear_bit - Sets a bit to 0 at given index
 * @n: pointer to an unsigned int
 * @index: The indexof the bit
 * Return: 1 if successful, else -1 if not
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	*n &= ~(1 << index);

	return (1);
}
