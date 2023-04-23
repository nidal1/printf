#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>

#define UNUSED(x) (void)(x)
#define BUFFER_SIZE 1024

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int print_char(va_list arg_list);
int print_string(va_list arg_list);
int _putchar(char c);
int _printf(const char *format, ...);
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_upper_hexa(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_HExa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);
int get_flags(const char *format, int *i);
int get_size(const char *format, int *i);
int write_unsigned(int is_negative, int ind,
		char buffer[], int flags, int width, int precision, int size);
long int convert_size_number(long int num, int size);


#endif

