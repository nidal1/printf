#include "main.h"

#include <stdio.h>

/**
 * print_hexadecimal - prints an unsigned int in hexa
 * lower if 'x' and upper if 'X'
 * @num: unsigned int
 * @format: format specifier
 * Return: the number of chars printed
 */
int print_hexadecimal(unsigned int num, char format)
{
	const char *hexa_chars = "0123456789abcdef";

	if (format == 'X')
	{
		hexa_chars = "0123456789ABCDEF";
	}

	char buff[32];
	int i = 0, count = 0;

	while (num)
	{
		buff[i++] = hexa_chars[num % 16];
		num /= 16;
	}
	do {
		putchar(buff[i]);
		count++;
	} while (i--);

	return (count);
}
