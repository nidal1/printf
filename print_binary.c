#include "main.h"

#include <stdarg.h>
#include <stdio.h>

/**
 * print_binary - prints a converted unsigned int to binary
 * avoiding leading zeros
 * @num: input insigned integer
 * Return: the number of digits printed as a counter
 */
int print_binary(unsigned int num)
{
	int count = 0;
	unsigned int m = 1 << 31;
	int start = 0;

	while (m > 0)
	{
		if (num & m)
		{
			putchar('1');
			count++;
			start = 1;
		}
		else
		{
			if (start)
			{
				putchar('0');
				count++;
			}
		}
		m >>= 1;
	}
	if (!start)
	{
		putchar('0');
		count++;
	}
	return (count);
}
