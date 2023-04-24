#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_string - print_string and get the length of the string
 * @arg_list: arguments list
 *
 * Return: length of given string
 */
int print_string(va_list arg_list)
{
	char *s = va_arg(arg_list, char *);
	int count = 0;

	while (*s != '\0')
	{
		_putchar(*s);
		s++;
		count++;
	}
	return (count);
}
