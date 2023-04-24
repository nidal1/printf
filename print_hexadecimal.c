#include "main.h"

#include <stdio.h>

/**
 * print_hexadecimal - prints an unsigned int in hexadecimal
 * lower if 'x' and upper if 'X'
 * @num: unsigned int
 * @format: format specifier
 * Return: the number of chars printed
 */
int print_hexadecimal(unsigned int num, char format)
{
    char *hexa_chars;
    char buff[9];
    int i = 0, count = 0;

    hexa_chars = (format == 'X') ? "0123456789ABCDEF" : "0123456789abcdef";

    
    do {
        buff[i++] = hexa_chars[num % 16];
        num /= 16;
    } while (num && i < 8);
    buff[i] = hexa_chars[num % 16];

    
    while (i < 8) {
        buff[++i] = '0';
    }

    
    do {
        _putchar(buff[i]);
        count++;
    } while (i--);

    return (count);
}
