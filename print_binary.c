#include "main.h"
#include <stdarg.h>
/**
 * print_binary - prints an unsigned number
 * converted to binary
 * @args: list of arguments
 * Return: binary representation of unsingned int
 * 0 if input int is 0
 */
int print_binary(va_list args)
{
	int i, j;
	int num = va_arg(args, int);

	for (i = 0; i < 32; i++)
	{
		if (num == 0)
		{
			_putchar('0');
			_putchar('\n');
		}
		else
		{
			int binary[32];

			i = 0;

			while (num > 0)
			{
				binary[i] = num % 2;
				num /= 2;
				i++;
			}
			for (j = i - 1; j >= 0; j--)
			{
				_putchar(binary[j] + '0');
			}
			_putchar('\n');
		}
	}

}
