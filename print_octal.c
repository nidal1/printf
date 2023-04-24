#include "main.h"

#include <stdio.h>
#include <stdarg.h>

/**
 * print_octal - prints an unsigned int
 * converted to octal notation
 * @num: unsigned int
 * Return: counter
 */
int print_octal(unsigned int num)
{
    int count = 0;
    unsigned int temp = num;
    char octal[100];

    do {
        octal[count++] = (temp % 8) + '0';
        temp /= 8;
    } while (temp != 0);

    while (count--)
        _putchar(octal[count]);

    return (count);
}
