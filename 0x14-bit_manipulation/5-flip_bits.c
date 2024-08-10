#include "main.h"

/**
 * flip_bits - Counts the num of bits to flip to convert one num to another.
 * @n: The first number.
 * @m: The second number to convert to.
 * Return: The number of bits needed to flip.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor_result;
	unsigned int bit_count;

	xor_result = n ^ m;
	bit_count = 0;

	while (xor_result)
	{
		bit_count++;
		xor_result &= (xor_result - 1);
	}

	return (bit_count);
}
