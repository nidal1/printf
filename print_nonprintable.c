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

	for (; *str; str++, count++)
	{
		if (*str < 32 || *str >= 127)
		{
			count += putchar('\\');
			count += putchar('x');
			count += putchar("0123456789ABCDEF"[(*str >> 4) & 0xF]);
			count += putchar("0123456789ABCDEF"[*str & 0xF]);
		}
		else
		{
			count += putchar(*str);
		}
	}
	putchar('\n');
	return (count);
}
