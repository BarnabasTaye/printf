#include "cif.h"

/**
 * cisfun_unsigned - Handles printing an unsigned integer
 * @list: Variable arguments list
 * @buffer: The buffer to store the formatted string
 * @flags: Formatting flags
 * @width: Field width
 * @precision: Field precision
 * @size: Size modifier
 *
 * Return: Number of characters printed
 */
int cisfun_unsigned(va_list *list, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int num = va_arg(*list, unsigned int);
	int printed_chars = 0;

	printed_chars += write_unsgnd(num, buffer, flags, width, precision, size);

	return (printed_chars);
}

