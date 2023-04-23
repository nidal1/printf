#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_binary - prints an unsigned integer in binary
 * @arg_list: argument list containing the integer to be printed
 * Return: number of characters printed
 */
int print_binary(va_list arg_list)
{
	unsigned int n = va_arg(arg_list, unsigned int);
	int count = 0;
	int binary_digits[32];
	int i = 0;

	if (n == 0)
	{
		_putchar('0');
		count++;
		return (count);
	}

	while (n > 0)
	{
		binary_digits[i] = n % 2;
		n /= 2;
		i++;
	}

	for (i = i - 1; i >= 0; i--)
	{
		_putchar(binary_digits[i] + '0');
		count++;
	}

	return (count);
}
