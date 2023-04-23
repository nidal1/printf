#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>

int print_char(va_list arg_list);
int print_string(va_list arg_list);
int print_int(va_list arg_list);
int print_binary_test(va_list arg_list);
int print_unsigned(va_list arg_list, int base);
int print_hex(unsigned int num, int cap);
int print_hex_uppercase(unsigned int num);

int _putchar(char c);
int _printf(const char *format, ...);
int print_binary(va_list args);

#endif /* MAIN_H */
