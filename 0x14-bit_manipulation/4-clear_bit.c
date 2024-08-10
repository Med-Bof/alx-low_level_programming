#include "main.h"

/**
 * clear_bit - Sets the value of a bit to 0 at a given index.
 * @n: Pointer to the decimal number to change.
 * @index: Index of the bit to clear, starting from 0.
 * Return: 1 if it worked, -1 if an error occurred.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int bit_mask;

	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	bit_mask = 1UL << index;
	*n &= ~bit_mask;

	return (1);
}
