#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>

/**
 * struct Flags - Struct containing flags to "turn on"
 * when a flag specifier is passed to custom_printf()
 * @plus: Flag for the '+' character
 * @space: Flag for the ' ' character
 * @hash: Flag for the '#' character
 */
typedef struct Flags
{
	int plus;
	int space;
	int hash;
} flags_t;

/**
 * struct PrintHandler - Struct to choose the right function depending
 * on the format specifier passed to custom_printf()
 * @specifier: Format specifier
 * @handler: Pointer to the correct printing function
 */
typedef struct PrintHandler
{
	char specifier;
	int (*handler)(va_list ap, flags_t *flags);
} print_handler_t;

/* print_numbers */
int print_integer(va_list arg, flags_t *flags);
void print_number(int n);
int print_unsigned_integer(va_list arg, flags_t *flags);
int count_digits(int num);

/* print_bases */
int print_hexadecimal(va_list arg, flags_t *flags);
int print_big_hexadecimal(va_list arg, flags_t *flags);
int print_binary(va_list arg, flags_t *flags);
int print_octal(va_list arg, flags_t *flags);

/* converter */
char *convert_to_base(unsigned long int num, int base, int lowercase);

/* custom_printf */
int custom_printf(const char *format, ...);

/* get_print_handler */
int (*get_print_handler(char specifier))(va_list, flags_t *);

/* get_flag */
int get_flag(char specifier, flags_t *flags);

/* print_alpha */
int print_string(va_list arg, flags_t *flags);
int print_character(va_list arg, flags_t *flags);

/* write_functions */
int custom_putchar(char c);
int custom_puts(char *str);

/* print_custom */
int print_rot13(va_list arg, flags_t *flags);
int print_reverse(va_list arg, flags_t *flags);
int print_big_string(va_list arg, flags_t *flags);

/* print_address */
int print_address(va_list arg, flags_t *flags);

/* print_percent */
int print_percent(va_list arg, flags_t *flags);

#endif /* MAIN_H */

