#include "main.h"
/**
 * write_char_handler - Prints a string
 * @c: char
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags.
 * @width: width.
 * @prec: precision specifier
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int write_char_handler(char c, char buffer[],
	int flags, int width, int prec, int size)
{
	int i = 0;
	char p = ' ';

	UNUSED(prec);
	UNUSED(size);

	if (flags & FLAG_ZERO)
		p = '0';

	buffer[i++] = c;
	buffer[i] = '\0';
	if (width > 1)
	{
		buffer[BUFFER_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFFER_SIZE - i - 2] = p;

		if (flags & FLAG_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFFER_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFFER_SIZE - i - 1], width - 1) +
					write(1, &buffer[0], 1));
	}
	return (write(1, &buffer[0], 1));
}

/**
 * write_num_handler - Prints a string
 * @_negative: List of arguments
 * @ind: index
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: width
 * @prec: precision specifier
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int write_num_handler(int _negative, int ind, char buffer[],
		int flags, int width, int prec, int size)
{
	int len = BUFFER_SIZE - ind - 1;
	char p = ' ', ex_c = 0;

	UNUSED(size);

	if ((flags & FLAG_ZERO) && !(flags & FLAG_MINUS))
		p = '0';
	if (_negative)
		ex_c = '-';
	else if (flags & FLAG_PLUS)
		ex_c = '+';
	else if (flags & FLAG_SPACE)
		ex_c = ' ';
	return (write_number(ind, buffer, flags, width, prec, len, p, ex_c));
}

/**
 * write_number - Writes a number with a bufffer
 * @ind: Index
 * @buffer: Buffer
 * @flags: Flags
 * @width: width
 * @prec: Precision specifier
 * @len: length
 * @p: Pading char
 * @ex_c: Extra char
 * Return: Number of printed chars.
 */
int write_number(int ind, char buffer[], int flags,
		int width, int prec, int len, char p, char ex_c)
{
	int i, p_start = 1;

	if (prec == 0 && ind == BUFFER_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0);
	if (prec == 0 && ind == BUFFER_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = p = ' ';
	if (prec > 0 && prec < len)
		p = ' ';
	while (prec > len)
		buffer[--ind] = '0', len++;
	if (ex_c != 0)
		len++;
	if (width > len)
	{
		for (i = 1; i < width - len + 1; i++)
			buffer[i] = p;
		buffer[i] = '\0';
		if (flags & FLAG_MINUS && p == ' ')
		{
			if (ex_c)
				buffer[--ind] = ex_c;
			return (write(1, &buffer[ind], len) + write(1, &buffer[1], i - 1));
		}
		else if (!(flags & FLAG_MINUS) && p == ' ')
		{
			if (ex_c)
				buffer[--ind] = ex_c;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], len));
		}
		else if (!(flags & FLAG_MINUS) && p == '0')
		{
			if (ex_c)
				buffer[--p_start] = ex_c;
			return (write(1, &buffer[p_start], i - p_start) +
				write(1, &buffer[ind], len - (1 - p_start)));
		}
	}
	if (ex_c)
		buffer[--ind] = ex_c;
	return (write(1, &buffer[ind], len));
}

/**
 * write_unsignd - Writes an unsigned integer
 * @_negative: indicates if the num is negative
 * @ind: Index
 * @buffer: Array of chars
 * @flags: Flags
 * @width: Width
 * @prec: Precision specifier
 * @size: Size specifier
 * Return: Number of written chars
 */
int write_unsignd(int _negative, int ind, char buffer[],
		int flags, int width, int prec, int size)
{
	int len = BUFFER_SIZE - ind - 1, i = 0;
	char p = ' ';

	UNUSED(_negative);
	UNUSED(size);

	if (prec == 0 && ind == BUFFER_SIZE - 2 && buffer[ind] == '0')
		return (0);

	if (prec > 0 && prec < len)
		p = ' ';

	while (prec > len)
	{
		buffer[--ind] = '0';
		len++;
	}

	if ((flags & FLAG_ZERO) && !(flags & FLAG_MINUS))
		p = '0';

	if (width > len)
	{
		for (i = 0; i < width - len; i++)
			buffer[i] = p;

		buffer[i] = '\0';

		if (flags & FLAG_MINUS)
		{
			return (write(1, &buffer[ind], len) + write(1, &buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[ind], len));
		}
	}
	return (write(1, &buffer[ind], len));
}

/**
 * write_pointer - Write an adress of memory
 * @buffer: buffer
 * @ind: Index
 * @len: Length of number
 * @width: Wwidth
 * @flags: Flags
 * @p: padding char
 * @ex_c: extra char
 * @p_start: Index at which padding start
 * Return: Number of written chars.
 */
int write_pointer(char buffer[], int ind, int len,
	int width, int flags, char p, char ex_c, int p_start)
{
	int i;

	if (width > len)
	{
		for (i = 3; i < width - len + 3; i++)
			buffer[i] = p;
		buffer[i] = '\0';
		if (flags & FLAG_MINUS && p == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (ex_c)
				buffer[--ind] = ex_c;
			return (write(1, &buffer[ind], len) + write(1, &buffer[3], i - 3));
		}
		else if (!(flags & FLAG_MINUS) && p == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (ex_c)
				buffer[--ind] = ex_c;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[ind], len));
		}
		else if (!(flags & FLAG_MINUS) && p == '0')
		{
			if (ex_c)
				buffer[--p_start] = ex_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[p_start], i - p_start) +
				write(1, &buffer[ind], len - (1 - p_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (ex_c)
		buffer[--ind] = ex_c;
	return (write(1, &buffer[ind], BUFFER_SIZE - ind - 1));
}
