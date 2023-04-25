#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
/*#define BUFFER_SIZE 1024 */

#define FLAG_MINUS 1
#define FLAG_PLUS 2
#define FLAG_ZERO 4
#define FLAG_HASH 8
#define FLAG_SPACE 16

#define SIZE_LONG 2
#define SIZE_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format
 * @fun: The function associated
 */
struct fmt
{
	char fmt;
	int (*fun)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fun_t - Struct op
 *
 * @fmt: The format.
 * @fun_t: The function associated
 */
typedef struct fmt fun_t;

/* printf prototype */
int _printf(const char *format, ...);
void print_buff(char buffer[], int *buff_ind);

/* to_print.c prototypes */
int to_print(const char *format, int *i, va_list arg_list, char buffer[],
		int flags, int width, int prec, int size);

/* printf_functions1.c prototypes */
int print_char(va_list args, char buffer[],
	int flags, int width, int prec, int size);
int print_string(va_list args, char buffer[],
	int flags, int width, int prec, int size);
int print_percent(va_list args, char buffer[],
	int flags, int width, int prec, int size);
int print_int(va_list args, char buffer[],
	int flags, int width, int prec, int size);
int print_binary(va_list args, char buffer[],
	int flags, int width, int prec, int size);
/* printf_functions2.c prototypes */
int print_unsigned(va_list args, char buffer[],
	int flags, int width, int prec, int size);
int print_octal(va_list args, char buffer[],
	int flags, int width, int prec, int size);
int print_hexa(va_list args, char buffer[],
	int flags, int width, int prec, int size);
int print_HEXA(va_list args, char buffer[],
	int flags, int width, int prec, int size);
int print_HExa(va_list args, char a[], char buffer[],
		int flags, char flag_c, int width, int prec, int size);
/* printf_functions3.c prototypes */
int print_nonprintable(va_list args, char buffer[],
	int flags, int width, int prec, int size);
int print_adress(va_list args, char buffer[],
	int flags, int width, int prec, int size);
int print_rot13(va_list args, char buffer[],
		int flags, int width, int prec, int size);
int print_rev(va_list args, char buffer[],
		int flags, int width, int prec, int size);
/* handlers prototypes */
int handle_flags(const char *formatt, int *i);
int handle_width(const char *format, int *i, va_list arg_list);
int handle_precision(const char *format, int *i, va_list arg_list);
int handle_size(const char *format, int *i);
int write_char_handler(char c, char buffer[],
	int flags, int width, int prec, int size);
int write_num_handler(int _negative, int ind, char buffer[],
	int flags, int width, int prec, int size);
int write_number(int ind, char buffer[], int flags, int width, int prec,
	int len, char p, char ex_c);
int write_pointer(char buffer[], int ind, int len,
	int width, int flags, char p, char ex_c, int p_start);
int write_unsignd(int _negative, int ind, char buffer[],
		int flags, int width, int prec, int size);
/* outils.c prototypes */
int _printable(char);
int add_acsii(char, char[], int);
int _digit(char);
long int size_number(long int num, int size);
long int size_unsignd(unsigned long int num, int size);

#endif /* MAIN_H */
