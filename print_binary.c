#include "main.h"
#include <stdarg.h>
#include <stdio.h>

void int_binary(int num);

/**
 * int_binary - converts an unsigned int to binary
 * @n: number
 * Return: void
 */
void int_binary(int num)
{
	int i;
	int avoiding_zero = 1;

	for (i = 31; i >= 0; i--)
	{
		if (num & (1 << i))
		{
			_putchar('1');
			avoiding_zero = 0;
		}
		else if (!avoiding_zero)
		{
			_putchar('0');
		}
	}
	if (avoiding_zero)
	{
		_putchar('0');
	}
}

/**
 * print_binary - prints binary representation
 * @num: input number
 * Return: void
 */
void print_binary(int num)
{
	int_binary(num);
	_putchar("\n");
}
