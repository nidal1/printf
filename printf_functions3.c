#include "main.h"

/**
 * print_adress - Prints an adress to a pointer
 * @args: List a of arguments
 * @buffer: Buffer
 * @flags: Calculates active flags
 * @width: width
 * @prec: Precision specifier
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_adress(va_list args, char buffer[],
	int flags, int width, int prec, int size)
{
	char ex_c = 0, p = ' ';
	int ind = BUFFER_SIZE - 2, len = 2, p_start = 1;
	unsigned long num_adress;
	char map_to[] = "0123456789abcdef";
	void *adress = va_arg(args, void *);

	UNUSED(width);
	UNUSED(size);

	if (adress == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFFER_SIZE - 1] = '\0';
	UNUSED(prec);

	num_adress = (unsigned long)adress;

	while (num_adress > 0)
	{
		buffer[ind--] = map_to[num_adress % 16];
		num_adress /= 16;
		len++;
	}
	if ((flags & FLAG_ZERO) && !(flags & FLAG_MINUS))
		p = '0';
	if (flags & FLAG_PLUS)
		ex_c = '+', len++;
	else if (flags & FLAG_SPACE)
		ex_c = ' ', len++;

	ind++;
	return (write_pointer(buffer, ind, len,
		width, flags, p, ex_c, p_start));
}

/**
 * print_nonprintable - Prints a string and non printable: \x
 * followed by ASCII code (upper hexa 2 char)
 * @args: List of arguments
 * @buffer: Buffer
 * @flags: Calculates active flags
 * @width: width
 * @prec: Precision specifier
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_nonprintable(va_list args, char buffer[],
	int flags, int width, int prec, int size)
{
	int i = 0, s = 0;
	char *str = va_arg(args, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(prec);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (_printable(str[i]))
			buffer[i + s] = str[i];
		else
			s += add_acsii(str[i], buffer, i + s);
		i++;
	}
	buffer[i + s] = '\0';
	return (write(1, buffer, i + s));
}

/**
 * print_rev - Prints string in reverse
 * @args: List of arguments
 * @buffer: Buffer
 * @flags:  Calculates active flags
 * @width: width
 * @prec: Precision specifier
 * @size: Size specifier
 * Return: Numbers of chars printed
 */
int print_rev(va_list args, char buffer[],
	int flags, int width, int prec, int size)
{
	char *str;
	int i, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(args, char *);

	if (str == NULL)
	{
		UNUSED(prec);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}

/**
 * print_rot13 - Print a string in rot13
 * @args: List of arguments
 * @buffer: Buffer
 * @flags: Calculates active flags
 * @width: width
 * @prec: Precision specifier
 * @size: Size specifier
 * Return: Numbers of chars printed
 */
int print_rot13(va_list args, char buffer[],
	int flags, int width, int prec, int size)
{
	char k;
	char *str;
	unsigned int i, j;
	int count = 0;
	char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char beta[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(args, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(prec);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; alpha[j]; j++)
		{
			if (beta[j] == str[i])
			{
				k = beta[j];
				write(1, &k, 1);
				count++;
				break;
			}
		}
		if (!alpha[j])
		{
			k = str[i];
			write(1, &k, 1);
			count++;
		}
	}
	return (count);
}
