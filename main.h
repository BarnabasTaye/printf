#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>

/**
 * struct Flags - struct containing flags to enable specific options
 *               when a flag specifier is passed to print_formatted()
 * @plus: flag for the '+' character
 * @space: flag for the ' ' character
 * @hash: flag for the '#' character
 */
typedef struct Flags
{
	int plus;
	int space;
	int hash;
} Flags_t;

/**
 * struct PrintHandler - struct to choose the appropriate function based on
 *                       the format specifier passed to print_formatted()
 * @specifier: format specifier
 * @print_function: pointer to the correct printing function
 */
typedef struct PrintHandler
{
	char specifier;
	int (*print_function)(va_list args, Flags_t *flags);
} PrintHandler_t;

/* print_numbers */
int print_integer(va_list args, Flags_t *flags);
void print_number(int num);
int print_unsigned_integer(va_list args, Flags_t *flags);
int count_digits(int num);

/* print_bases */
int print_hexadecimal(va_list args, Flags_t *flags);
int print_hexadecimal_uppercase(va_list args, Flags_t *flags);
int print_binary(va_list args, Flags_t *flags);
int print_octal(va_list args, Flags_t *flags);

/* converter */
char *convert_to_base(unsigned long int num, int base, int lowercase);

/* print_formatted */
int print_formatted(const char *format, ...);

/* get_print_handler */
int (*get_print_handler(char specifier))(va_list args, Flags_t *flags);

/* get_flag */
int get_flag(char specifier, Flags_t *flags);

/* print_alphabet */
int print_string(va_list args, Flags_t *flags);
int print_character(va_list args, Flags_t *flags);

/* write_functions */
int _putchar(char c);
int _puts(char *str);

/* print_custom */
int print_rot13(va_list args, Flags_t *flags);
int print_reverse(va_list args, Flags_t *flags);
int print_string_uppercase(va_list args, Flags_t *flags);

/* print_address */
int print_address(va_list args, Flags_t *flags);

/* print_percent */
int print_percent(va_list args, Flags_t *flags);

#endif /* MAIN_H */

