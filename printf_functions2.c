#include "main.h"

/**
 * print_unsigned - Prints an unsigned integer
 * @args: List of arguments
 * @buffer: Buffer
 * @flags: Calculates active flags
 * @width: width
 * @prec: Precision specifier
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_unsigned(va_list args, char buffer[],
	int flags, int width, int prec, int size)
{
	int i = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);

	num = size_unsignd(num, size);

	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFFER_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (write_unsignd(0, i, buffer, flags, width, prec, size));
}

/**
 * print_octal - Prints an unsigned number in octal notation
 * @args: List of arguments
 * @buffer: Buffer
 * @flags: Calculates active flags
 * @width: width
 * @prec: Precision specifier
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_octal(va_list args, char buffer[],
	int flags, int width, int prec, int size)
{
	int i = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);
	unsigned long int int_num = num;

	UNUSED(width);

	num = size_unsignd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}
	if (flags & FLAG_HASH && int_num != 0)
		buffer[i--] = '0';
	i++;
	return (write_unsignd(0, i, buffer, flags, width, prec, size));
}

/**
 * print_hexa - Prints an unsigned int in hexadecimal notation
 * @args: List of arguments
 * @buffer: Buffer
 * @flags:  Calculates active flags
 * @width: width
 * @prec: Precision specifier
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexa(va_list args, char buffer[],
	int flags, int width, int prec, int size)
{
	return (print_HExa(args, "0123456789abcdef", buffer,
		flags, 'x', width, prec, size));
}

/**
 * print_HEXA - Prints an unsigned in hexadecimal upper
 * @args: List of arguments
 * @buffer: Buffer
 * @flags:  Calculates active flags
 * @width: width
 * @prec: Precision specifier
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_HEXA(va_list args, char buffer[],
	int flags, int width, int prec, int size)
{
	return (print_HExa(args, "0123456789ABCDEF", buffer,
		flags, 'X', width, prec, size));
}

/**
 * print_HExa - Prints a hexadecimal in lower or upper
 * @args: List of arguments
 * @a: Array of values which the number map to
 * @buffer: buffer
 * @flags: Calculates active flags
 * @flag_c: Calculates active flags
 * @width: width
 * @prec: Precision specifier
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_HExa(va_list args, char a[], char buffer[],
	int flags, char flag_c, int width, int prec, int size)
{
	int i = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);
	unsigned long int int_num = num;

	UNUSED(width);

	num = size_unsignd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = a[num % 16];
		num /= 16;
	}

	if (flags & FLAG_HASH && int_num != 0)
	{
		buffer[i--] = flag_c;
		buffer[i--] = '0';
	}
	i++;
	return (write_unsignd(0, i, buffer, flags, width, prec, size));
}
