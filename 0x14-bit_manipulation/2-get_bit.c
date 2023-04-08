#include "main.h"

/**
 * get_bit -Returns the value of a bit at a given index
 * @n: unsigned long int input
 * @index: The index
 * Return: The value of the bit
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int i = 0x01;

	i <<= index;
	if (i == 0)
		return (-1);

	if ((n & i))
		return (1);
	else
		return (0);
}
