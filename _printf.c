#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - produces output according to a format
 * @format: format string containing the characters and the specifiers
 * Description: this function will call the get_print() function that will
 * determine which printing function to call depending on the conversion
 * specifiers contained into fmt
 * Return: length of the formatted output string
 */
int _printf(const char *format, ...)
{
    va_list arg_list;
    int count = 0;
    char c, *s;
    
    va_start(arg_list, format);
    
    while ((c = *format++) != '\0') {
        if (c == '%') {
            switch (*format++) {
                case 'c':
                    _putchar(va_arg(arg_list, int));
                    count++;
                    break;
                case 's':
                    s = va_arg(arg_list, char *);
                    while (*s != '\0') {
                        _putchar(*s++);
                        count++;
                    }
                    break;
                case '%':
                    _putchar('%');
                    count++;
                    break;
                default:
                    break;
            }
        } else {
            _putchar(c);
            count++;
        }
    }
    
    va_end(arg_list);
    
    return count;
}
