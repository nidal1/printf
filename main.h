#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>

int print_char(va_list arg_list);
int print_string(va_list arg_list);
int _putchar(char c);
int _printf(const char *format, ...);
void int_binary(int num);
void print_binary(int num);

#endif /* MAIN_H */
