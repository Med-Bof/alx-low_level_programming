#include "main.h"

/**
 * print_binary - Prints the binary representation of a number.
 * @n: The number to be printed in binary.
 */
void print_binary(unsigned long int n)
{
	unsigned long int num;
	int bit_index;

	if (n == 0)
	{
		putchar('0');
		return;
	}

	for (num = n, bit_index = 0; (num >>= 1) > 0; bit_index++)
		;

	for (; bit_index >= 0; bit_index--)
	{
		if ((n >> bit_index) & 1)
			putchar('1');
		else
			putchar('0');
	}
}
