#include "main.h"

/**
 * print_argument - Prints an argument based on its type
 * @fmt: Formatted string in which to print the arguments
 * @list: List of arguments
 * @ind: index
 * @buffer: Buffer array
 * @flags: Calculates active flags
 * @width: width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 1 or 2
 */
int print_argument(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'i', print_int},
		{'d', print_int}, {'b', print_binary}, {'u', print_unsigned},
		{'o', print_octal}, {'x', print_hexa}, {'X', print_upper_hexa}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
	{
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(list, buffer, flags, width, precision, size));
	}
	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);

		if (fmt[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		unknow_len += write(1, &fmt[*ind], 1);
		return (unknow_len);
	return (printed_chars);
}

