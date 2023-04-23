#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_int - prints an integer
 * @arg_list: argument list
 *
 * Return: number of characters printed
 */
int print_int(va_list arg_list)
{
    int n = va_arg(arg_list, int);
    int count = 0;

    if (n < 0)
    {
        _putchar('-');
        n = -n;
        count++;
    }

    if (n / 10)
        count += print_int(arg_list);

    _putchar((n % 10) + '0');
    count++;

    return (count);
}