#include "main.h"

/*print binary*/

/**
 * print_binary - converts an unsigned int to binary
 * @types: list of arguments
 * Return: numbers of char to print
 */
int print_binary(va_list types)
{
	unsigned int num, m, i, sum;
	unsigned int a[32];
	int count;

	num = va_arg(types, unsigned int);
	/*int(4bytes) = 32 bits, the MSB is 32, the max num is 2^31 = 2147483648*/
	m = 2147483648;
	a[0] = num / m;

	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (num / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
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

/*print usigned decimal integer*/

/**
 * print_unsigned - prints an unsigned decimamal integer
 * @types: list of arguments
 * @buffer: buffer to handle print
 * @flags: active flags
 * @width: width
 * @precision: precision specification
 * @size: size specifier
 * Return: numbers of char to print
 */
int print_unsigned(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{


