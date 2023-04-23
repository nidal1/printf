#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFFER_SIZE 1024

#define F_MINUS 1
#define F_ZERO 4


#define S_LONG 2
#define S_SHORT 1

/**
 * struct flags - struct containing flags to "turn on"
 * when a flag specifier is passed to _printf()
 * @plus: flag for the '+' character
 * @space: flag for the ' ' character
 * @hash: flag for the '#' character
 */
typedef struct flags
{
	int plus;
	int space;
	int hash;
} flags_t;

/**
 * struct printHandler - struct to choose the right function depending
 * on the format specifier passed to _printf()
 * @c: format specifier
 * @f: pointer to the correct printing function
 */
typedef struct printHandler
{
	char c;
	int (*f)(va_list ap, flags_t *f);
} ph;

int get_flag(char s, flags_t *f);
int (*get_print(char s))(va_list, flags_t *);

int print_string(va_list l, flags_t *f);
int print_char(va_list l, flags_t *f);

int print_percent(va_list l, flags_t *f);

int _putchar(char c);
int _puts(char *str);
int _printf(const char *format, ...);
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
long int convert_size_unsigned(unsigned long int num, int size);
int write_unsigned(int is_negative, int ind,char buffer[],
		int flags, int width, int precision, int size);
nt print_unsigned(va_list types, char buffer[],int flags,
                int width, int precision, int size);




#endif
