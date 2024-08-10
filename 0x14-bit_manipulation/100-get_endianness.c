#include "main.h"

/**
 * get_endianness - Checks the endianness of the system.
 * Return: 0 if big endian, or 1 if little endian.
 */
int get_endianness(void)
{
	int test_num = 1;
	char *byte_ptr = (char *)&test_num;

	if (*byte_ptr == 1)
		return (1);
	else
		return (0);
}
