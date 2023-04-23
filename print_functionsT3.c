#include "main.h"

/**
 * print_unsigned - prints unsigned decimal integer
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: number of characters to print
 */
int print_unsigned(va_list types, char buffer[],int flags,
		int width, int precision, int size)
{


