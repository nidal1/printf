#include "main.h"

/**
 * print_binary - prints an unsigned number
 * converted to binary
 * @args: list of arguments
 * Return: binary representation of unsingned int
 */
int print_binary(va_list args)
{
	int count;

	va_start(args, count);

	for (int i = 0; i < count; i++)
	{
		int num = va_arg(args, int);

		if (num == 0)
		{
			putchar('0');
			putchar('\n');
		}
		else
		{
			int binary[32];
			int index = 0;

			while (num > 0)
			{
				binary[index] = num % 2;
				num /= 2;
				index++;
			}
			for (int j = index - 1; j >= 0; j--)
			{
				putchar(binary[j] + '0');
			}
			putchar('\n');
		}
	}
	va_end(args);
}
