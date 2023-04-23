#include "main.h"
#include <stdarg.h>

/**
 * print_char - print a character
 * @arg_list: arguments list
 *
 * Return: always 1
 */
int print_char(va_list arg_list)
{
	char c = va_arg(arg_list, int);

	_putchar(c);
	return (1);
}
