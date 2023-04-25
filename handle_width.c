#include "main.h"

/**
 * handle_width - Calculates the width
 * @format: Formatted string
 * @i: List of arguments to print
 * @arg_list: list of arguments
 * Return: width.
 */
int handle_width(const char *format, int *i, va_list arg_list)
{
	int i_printed;
	int width = 0;

	for (i_printed = *i + 1; format[i_printed] != '\0'; i_printed++)
	{
		if (_digit(format[i_printed]))
		{
			width *= 10;
			width += format[i_printed] - '0';
		}
		else if (format[i_printed] == '*')
		{
			i_printed++;
			width = va_arg(arg_list, int);
			break;
		}
		else
			break;
	}

	*i = i_printed - 1;

	return (width);
}

