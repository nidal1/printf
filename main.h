#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>

int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list arg_list);
int print_string(va_list arg_list);
int print_int(va_list arg_list);
int print_binary(unsigned int num);
int print_unsigned(va_list arg_list, int base);
int print_octal(unsigned int num);
int print_hex(unsigned int num, int cap);
int print_hex_uppercase(unsigned int num);
int print_nonprintable(char *str);

#endif /* MAIN_H */
