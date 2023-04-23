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
#define F_HASH 8


#define S_LONG 2
#define S_SHORT 1


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

int get_flags(const char *format, int *i)
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
int print_unsigned(va_list types, char buffer[],int flags,
                int width, int precision, int size);
int print_octal(va_list types, char buffer[],
        int flags, int width, int precision, int size);
int print_hexa(va_list types, char buffer[],
        int flags, int width, int precision, int size);
int print_upper_hexa(va_list types, char buffer[],
        int flags, int width, int precision, int size);
int print_HExa(va_list types, char map_to[], char buffer[],
        int flags, char flag_ch, int width, int precision, int size);



#endif
