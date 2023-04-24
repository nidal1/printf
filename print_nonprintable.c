#include "main.h"

#include <stdio.h>

/**
 * print_nonprintable - prints the string
 * Non printable characters are printed \x
 * @str: string to print
 * Return: number of characters printed
 */
int print_nonprintable(char *str)
{
	int count = 0;
	int t = *str;
	int num_digits = 0;
	int d = (*str >> (4 * (num_digits - 1))) & 0xF;

	while (*str != '\0')
		if (*str < 32 || *str >= 127)
		{
			putchar('\\');
			putchar('x');
			if (*str < 16)
			{
				putchar('0');
				count++;
			}
			while (t > 0)
			{
				t /= 16;
				num_digits++;
			}
			int i;

			for (i = 0; i < 2 - num_digits; i++)
			{
				putchar('0');
				count++;
			}
			while (num_digits > 0)
			{
				putchar(d < 10 ? d + '0' : d - 10 + 'A');
				count++;
				num_digits--;
			}
		}
		else
		{
			putchar(*str);
			count++;
		}
		str++;
	return (count);
}
