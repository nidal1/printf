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
                count += print_char(arg_list);
                break;
            case 's':
                count += print_string(arg_list);
                break;
            case 'd':
            case 'i':
                count += print_int(arg_list);
                break;
            case 'b':
                count += print_binary(va_arg(arg_list, unsigned int));
                break;
            case 'x':
                count += print_hexadecimal(va_arg(arg_list, unsigned int), 'x');
                break;
            case 'X':
                count += print_hexadecimal(va_arg(arg_list, unsigned int), 'X');
                break;
            case 'o':
                count += print_octal(va_arg(arg_list, unsigned int));
                break;
            case 'u':
                count += print_unsigned(arg_list, 10);
                break;
            
			case 'S':
				count += print_nonprintable(va_arg(va_list, char*));
				break;
            case '%':
                    count += print_percent();
                break;
            default:
                count += print_literal();
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
