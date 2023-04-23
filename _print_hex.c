#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_hex - prints an unsigned int in hexadecimal notation
 * @num: the unsigned int to print
 * @cap: 1 to print capital letters, 0 for small letters
 *
 * Return: number of characters printed
 */
int print_hex(unsigned int num, int cap)
{
	char hex_digits[] = "0123456789abcdef";
	char hex_digits_cap[] = "0123456789ABCDEF";
	char buffer[1024];
	int i, j, rem;
	int count = 0;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	while (num > 0)
	{
		rem = num % 16;
		if (cap)
			buffer[count++] = hex_digits_cap[rem];
		else
			buffer[count++] = hex_digits[rem];
		num /= 16;
	}

	for (i = count - 1; i >= 0; i--)
	{
		_putchar(buffer[i]);
	}

	return (count);
}
