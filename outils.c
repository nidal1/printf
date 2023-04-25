#include "main.h"

/**
 * _printable - checks if a chararacter is printable
 * @c: Char
 * Return: 1 if c is printable, if not 0.
 */
int _printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}

/**
 * add_acsii - add ASCII in hexadecimal to buffer
 * @buffer: Array of chars.
 * @i: Index at which to start adding.
 * @ascii_code: ASSCI code
 * Return: 3
 */
int add_acsii(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
	{
		ascii_code *= -1;
	}
	buffer[i++] = '\\';
	buffer[i++] = 'x';
	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];
	return (3);
}

/**
 * _digit - checks if a char is a digit
 * @c: Char
 * Return: 1 if c is a digit, if no 0
 */
int _digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/**
 * size_number - assigns a number to a size
 * @num: Number
 * @size: Number indicating the type to assign
 *
 * Return: assigned value of num
 */
long int size_number(long int num, int size)
{
	if (size == SIZE_LONG)
		return (num);
	else if (size == SIZE_SHORT)
		return ((short)num);
	return ((int)num);
}

/**
 * size_unsigned - assigns a number to size
 * @num: Number
 * @size: Number indicating the type to be assigned
 * Return: Casted value of num
 */
long int size_unsignd(unsigned long int num, int size)
{
	if (size == SIZE_LONG)
		return (num);
	else if (size == SIZE_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
