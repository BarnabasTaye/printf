#ifndef CIF_H
#define CIF_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAG */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct cisfun - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct cisfun
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct cisfun cisfun_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct cisfun cisfun_t;

int _cif(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

/****************** FUNCTIONS ******************/

/* Functions to print chars and strings */
int cisfun_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int cisfun_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int cisfun_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to print numbers */
int cisfun_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int cisfun_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int cisfun_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int cisfun_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int cisfun_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int cisfun_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int cisfun_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print non-printable characters */
int cisfun_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Function to print memory address */
int cisfun_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to handle other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

/* Function to print string in reverse */
int cisfun_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Function to print a string in ROT13 */
int cisfun_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Width handler */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

/****************** UTILS ******************/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif /* CIF_H */

