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
    int i, count = 0;
    va_list arg_list;

    va_start(arg_list, format);

    for (i = 0; format && format[i]; i++)
    {
        if (format[i] == '%')
        {
            i++;
            if (!format[i])
                break;
            switch (format[i])
            {
            case 'c':
                count += _putchar(va_arg(arg_list, int));
                break;
            case 's':
                count += _putchar(*(va_arg(arg_list, char *)));
                break;
            case 'd':
            case 'i':
                count += print_int(arg_list);
                break;
            /*case 'u':
                count += print_unsigned(va_arg(arg_list, unsigned int), 10);
                break;
            case 'o':
                count += print_unsigned(va_arg(arg_list, unsigned int), 8);
                break;
            case 'x':
                count += print_hex(va_arg(arg_list, unsigned int), 0);
                break;
            case 'X':
                count += print_hex_uppercase(va_arg(arg_list, unsigned int));
                break;
            case 'b':
                count += print_binary(va_arg(arg_list, unsigned int));
                break;
			case 'S':
				count += print_nonprintable(va_arg(va_list, char*));
				break;*/
            default:
                count += _putchar('%');
                count += _putchar(format[i]);
                break;
            }
        }
        else
            count += _putchar(format[i]);
    }

    va_end(arg_list);

    return (count);
}
