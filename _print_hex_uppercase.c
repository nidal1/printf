#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_hex_uppercase - prints an unsigned integer in hexadecimal format (uppercase)
 * @num: the unsigned integer to print
 *
 * Return: the number of characters printed
 */
int print_hex_uppercase(unsigned int num)
{
        int count = 0, i, rem;
        char hex_num[100];

        while (num != 0)
        {
                rem = num % 16;
                if (rem < 10)
                        hex_num[count++] = 48 + rem;
                else
                        hex_num[count++] = 55 + rem;
                num /= 16;
        }

        if (count == 0)
        {
                count++;
                hex_num[count - 1] = '0';
        }

        for (i = count - 1; i >= 0; i--)
                _putchar(hex_num[i]);

        return (count);
}
