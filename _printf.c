#include "main.h"

/**
 * _printf - Printf function
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int i, pri = 0, char_printed = 0;
	int flags, width, prec, size, buff_ind = 0;
	va_list arg_list;
	const int BUFFER_SIZE = 1024;
	char buffer[BUFFER_SIZE];

	if (format == NULL)
		return (-1);

	va_start(arg_list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFFER_SIZE)
				print_buff(buffer, &buff_ind);
			char_printed++;
		}
		else
		{
			print_buff(buffer, &buff_ind);
			flags = handle_flags(format, &i);
			width = handle_width(format, &i, arg_list);
			prec = handle_precision(format, &i, arg_list);
			size = handle_size(format, &i);
			++i;
			pri = to_print(format, &i, arg_list, buffer,
				flags, width, prec, size);
			if (pri == -1)
				return (-1);
			char_printed += pri;
		}
	}
	print_buff(buffer, &buff_ind);
	va_end(arg_list);

	return (char_printed);
}

/**
 * print_buff - Prints the contents of the buffer
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char (lenght)
 */
void print_buff(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
