#include "main.h"

/**
 * print_unsigned - prints unsigned integer
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: number of characters to print
 */
int print_unsigned(va_list types, char buffer[],int flags,
		int width, int precision, int size)
{
	int i = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	
	num = convert_size_unsigned(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsigned(0, i, buffer, flags, width, precision, size));
}

/**
 * convert_size_unsigned - assigns a number to the specified size
 * @num: Number to assign
 * @size: Number indicating the type to assign
 * Return: assigned value of num
 */
long int convert_size_unsigned(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}

/**
 * write_unsigned - Writes an unsigned
 * @is_negative: Number indicates if the num is negative
 * @ind: Index at which the number starts in the buffer
 * @buffer: Array of chars
 * @flags: Flags specifiers
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Number of chars
 */
int write_unsigned(int is_negative, int ind,
	char buffer[], int flags, int width, int precision, int size)
{
	int len = BUFFER_SIZE - ind - 1, i = 0;
	char p = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFFER_SIZE - 2 && buffer[ind] == '0')
	/* no chars is printed */
		return (0);

	if (precision > 0 && precision < len)
		p = ' ';

	while (precision > len)
	{
		buffer[--ind] = '0';
		len++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		p = '0';

	if (width > len)
	{
		for (i = 0; i < width - len; i++)
			buffer[i] = p;

		buffer[i] = '\0';

		if (flags & F_MINUS) 
		/* [buffer>p] */
		{
			return (write(1, &buffer[ind], len) + write(1, &buffer[0], i));
		}
		else 
		/*[p>buffer]*/
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[ind], len));
		}
	}

	return (write(1, &buffer[ind], len));
}

