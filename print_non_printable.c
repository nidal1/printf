#include "main.h"

/**
 * print_nonprintable - prints string Non printable char printed:\x
 * followed by the ASCII code in hexa (upper case - 2 characters)
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
	return (count);
}
