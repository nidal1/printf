#include "main.h"

/**
 * to_print - Prints an argument according to its type
 * @fmt: Formatted string
 * @arg_list: list of  arguments
 * @ind: index
 * @buffer: Buffer
 * @flags: Calculates active flags
 * @width: width
 * @prec: Precision specifier
 * @size: Size specifier
 * Return: 1 or 2;
 */
int to_print(const char *fmt, int *ind, va_list arg_list, char buffer[],
	int flags, int width, int prec, int size)
{
	int i, un_len = 0, char_printed = -1;
	fun_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexa},
		{'X', print_HEXA}, {'p', print_adress}, {'S', print_nonprintable},
		{'r', print_rev}, {'R', print_rot13}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fun(arg_list, buffer, flags, width, prec, size));

	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		un_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			un_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		un_len += write(1, &fmt[*ind], 1);
		return (un_len);
	}
	return (char_printed);
}
