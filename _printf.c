#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - produces output according to a format
 * @format: format string containing the characters and the specifiers
 *
 * Return: length of the formatted output string
 */
int _printf(const char *format, ...)
{
	va_list arg_list;
	int count = 0;
	char c;

	va_start(arg_list, format);
	while ((c = *format++) != '\0')
	{
		if (c == '%')
		{
			if (*format++ == 'c')
				count += print_char(arg_list);
			else if(*format++ == 's')
				count += print_string(arg_list);
			else if(*format++ == '%'){
				_putchar('%');
					count++;
			}
		}
		else
		{
			_putchar(c);
			count++;
		}
	}
	va_end(arg_list);
	return (count);
}
