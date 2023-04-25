#include "main.h"

/**
 * handle_size - Calculates the size
 * @format: Formatted string
 * @i: List of arguments printed
 * Return: Precision.
 */
int handle_size(const char *format, int *i)
{
	int i_printed = *i + 1;
	int size = 0;

	if (format[i_printed] == 'l')
		size = SIZE_LONG;
	else if (format[i_printed] == 'h')
		size = SIZE_SHORT;

	if (size == 0)
		*i = i_printed - 1;
	else
		*i = i_printed;

	return (size);
}
