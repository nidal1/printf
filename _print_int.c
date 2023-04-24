#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_int - prints an integer
 * @args: arguments list containing the integer to print
 *
 * Return: number of characters printed
 */
int print_int(va_list args)
{
    int num = va_arg(args, int);
    int count = 0, divisor = 1;

    if (num < 0)
    {
        count += _putchar('-');
        num *= -1;
    }

    while (num / divisor > 9)
        divisor *= 10;

    while (divisor != 0)
    {
        count += _putchar('0' + num / divisor);
        num %= divisor;
        divisor /= 10;
    }

    return (count);
}
