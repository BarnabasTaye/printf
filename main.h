#ifndef MAIN_H_CUSTOM
#define MAIN_H_CUSTOM

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt_custom - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt_custom
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt_custom fmt_t_custom - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt_custom fmt_t_custom;

int _printf_custom(const char *format, ...);
int handle_print_custom(const char *fmt, int *i,
	va_list list, char buffer[], int flags, int width, int precision, int size);

/****************** FUNCTIONS ******************/

/* Functions to print chars and strings */
int print_char_custom(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_string_custom(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_percent_custom(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to print numbers */
int print_int_custom(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_binary_custom(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned_custom(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_octal_custom(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal_custom(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa_upper_custom(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_hexa_custom(va_list types, char map_to[],
	char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print non printable characters */
int print_non_printable_custom(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Function to print memory address */
int print_pointer_custom(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to handle other specifiers */
int get_flags_custom(const char *format, int *i);
int get_width_custom(const char *format, int *i, va_list list);
int get_precision_custom(const char *format, int *i, va_list list);
int get_size_custom(const char *format, int *i);

/* Function to print string in reverse */
int print_reverse_custom(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Function to print a string in rot 13 */
int print_rot13string_custom(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Width handler */
int handle_write_char_custom(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_number_custom(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num_custom(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_pointer_custom(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int write_unsgnd_custom(int is_negative, int ind,
	char buffer[], int flags, int width, int precision, int size);

/****************** UTILS ******************/
int is_printable_custom(char);
int append_hexa_code_custom(char, char[], int);
int is_digit_custom(char);

long int convert_size_number_custom(long int num, int size);
long int convert_size_unsgnd_custom(unsigned long int num, int size);

#endif /* MAIN_H_CUSTOM */

