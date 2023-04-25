#include "main.h"

/**
 * print_char - Prints a character
 * @args: List of arguments
 * @buffer: Buffer
 * @flags:  Calculates active flags
 * @width: Width
 * @prec: Precision specifier
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_char(va_list args, char buffer[],
	int flags, int width, int prec, int size)
{
	char c = va_arg(args, int);

	return (write_char_handler(c, buffer, flags, width, prec, size));
}

/**
 * print_string - Prints a string
 * @args: List of arguments
 * @buffer: Buffer
 * @flags: Calculates active flags
 * @width: width
 * @prec: Precision specifier
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_string(va_list args, char buffer[],
	int flags, int width, int prec, int size)
{
	int len = 0, i;
	char *str = va_arg(args, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(prec);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (prec >= 6)
			str = "      ";
	}
	while (str[len] != '\0')
		len++;

	if (prec >= 0 && prec < len)
		len = prec;

	if (width > len)
	{
		if (flags & FLAG_MINUS)
		{
			write(1, &str[0], len);
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], len);
			return (width);
		}
	}
	return (write(1, str, len));
}

/**
 * print_percent - Prints the percent sign
 * @args: List of arguments
 * @buffer: Buffer
 * @flags: Calculates active flags
 * @width: width
 * @prec: Precision specifier
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_percent(va_list args, char buffer[],
	int flags, int width, int prec, int size)
{
	UNUSED(args);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(prec);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/**
 * print_int - Print an integer
 * @args: List of arguments
 * @buffer: Buffer
 * @flags: Calculates active flags
 * @width: width
 * @prec: Precision specifier
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_int(va_list args, char buffer[],
	int flags, int width, int prec, int size)
{
	int i = BUFFER_SIZE - 2;
	int _negative = 0;
	long int n = va_arg(args, long int);
	unsigned long int num;

	n = size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';
	num = (unsigned long int)n;
	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		_negative = 1;
	}
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (write_num_handler(_negative, i, buffer, flags, width, prec, size));
}

/**
 * print_binary - Prints an unsigned number converted to binary
 * @args: List of arguments
 * @buffer: Buffer
 * @flags: Calculates active flags
 * @width: width
 * @prec: Precision specifier
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int print_binary(va_list args, char buffer[],
	int flags, int width, int prec, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(prec);
	UNUSED(size);

	n = va_arg(args, unsigned int);
	m = 2147483648;
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
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
