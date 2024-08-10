#include "main.h"
#include <stdio.h>

/**
 * print_binary - Prints the binary representation of a number.
 * @n: The number to print as binary.
 */
void print_binary(unsigned long int n)
{
	unsigned long int current;
	int bit_position;

	if (n == 0)
	{
		putchar('0');
		return;
	}

	for (current = n, bit_position = 0; (current >>= 1) > 0; bit_position++)
		;

	for (; bit_position >= 0; bit_position--)
	{
		if ((n >> bit_position) & 1)
			putchar('1');
		else
			putchar('0');
	}
}
