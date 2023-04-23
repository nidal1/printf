#include "main.h"

/**
 * print_binary - prints an unsigned int
 * converted to binary
 * @types: List of arguments
 * @buffer: Buffer array
 * @flags:  Calculates "turn on" flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: numbers of charcter to print
 */
int print_binary(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	unsigned int num, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	num = va_arg(types, unsigned int);
	/*int = 4 bytes = 32 bits, the MSB 32, the max = 2^31 = 2147483648*/
	m = 2147483648;
	a[0] = num / m;

	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (num / m) % 2;
	}
	for (i = 0; sum = 0; count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
