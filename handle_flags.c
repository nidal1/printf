#include "main.h"

/**
 * handle_flags - Calculates active flags
 * @format: Formatted string
 * @i: parameter
 * Return: Flags
 */
int handle_flags(const char *format, int *i)
{
	int j, i_printed;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {FLAG_MINUS, FLAG_PLUS, FLAG_ZERO,
		FLAG_HASH, FLAG_SPACE, 0};

	for (i_printed = *i + 1; format[i_printed] != '\0'; i_printed++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[i_printed] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}
	*i = i_printed - 1;
	return (flags);
}

