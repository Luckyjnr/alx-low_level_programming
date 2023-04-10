#include "main.h"

/**
 * flip_bits - returns the number needed to flip
 * @n: number of bit flips needed to equal num2 for num
 * @m: The number to set other equal
 * Return: The number of fliped bits
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor = n ^ m, bits = 0;

	while (xor > 0)
	{
		bits += (xor & 1);
		xor >>= 1;
	}

	return (bits);
}
