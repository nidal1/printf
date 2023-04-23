#include "main.h"

#include <stdio.h>
#include <stdarg.h>

/**
 * print_octal - prints an unsigned int
 * converted to octal notation
 * @num: unsigned int
 * Return: counter
 */
int print_octal(unsigned int num)
{
	int count = 0;
	/* initialize quotient and remainder */
	unsigned int q = num / 8;
	unsigned int r = num % 8;
	/* max 32 octal digits */
	char octal[32];

	octal[count++] = (char)(r + '0');
	while (q != 0)
	{
		r = q % 8;
		q /= 8;
		octal[count++] = (char)(r + '0');
	}
	while (count > 0)
	{
		putchar(octal[--count]);
	}
	return (count);
}
