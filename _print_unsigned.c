#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_unsigned - prints an unsigned integer
 * @arg_list: argument list containing the unsigned int to print
 * @base: the base to use for conversion
 *
 * Return: the number of digits printed
 */
int print_unsigned(va_list arg_list, int base)
{
	unsigned int num = va_arg(arg_list, unsigned int);
	char buffer[20];
	char *ptr = &buffer[19];
	int count = 0;

	*ptr = '\0';

	do {
		*--ptr = "0123456789abcdef"[num % base];
		num /= base;
		count++;
	} while (num != 0);

	while (*ptr != '\0') {
		_putchar(*ptr++);
	}

	return count;
}

