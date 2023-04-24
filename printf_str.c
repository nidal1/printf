#include "main.h"

/**
 * _strlen - Returns the lenght of a string.
 * @s: type char pointer
 * Return: c
 */
int _strlen(char *s)
{
	int c;

	for (c = 0; s[c] != 0; c++)
		;
	return (c);
}

/**
 * _strlenc - Strlen function but applied
 * for constant char pointer s
 * @s: type char pointer
 * Return: c
 */
int _strlenc(const char *s)
{
	int c;

	for (c = 0; s[c] != 0; c++)
		;
	return (c);
}
