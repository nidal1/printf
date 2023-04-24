#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>

int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list arg_list);
int print_string(va_list arg_list);
int print_int(va_list arg_list);
<<<<<<< HEAD
int print_binary(unsigned int num);
int print_unsigned(va_list arg_list, int base);
int print_octal(unsigned int num);
int print_hecadecimal(unsigned int num, char format);
int print_nonprintable(char *str);
=======
int print_percent(void);
int print_literal(void);
/* int print_binary(unsigned int num);*/
/* int print_unsigned(va_list arg_list, int base);*/
/* int print_octal(unsigned int num);*/
/* int print_hex(unsigned int num, int cap);*/
/* int print_hex_uppercase(unsigned int num);*/
/* int print_nonprintable(char *str);*/
>>>>>>> 83dbcbbe14b835aa429027969b001a063cd4d881

#endif /* MAIN_H */
