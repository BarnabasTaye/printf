#include "cif.h"

/**
 * cisfun_char - Handles printing a single character
 * @list: Variable arguments list
 * @buffer: The buffer to store the formatted string
 * @flags: Formatting flags
 * @width: Field width
 * @precision: Field precision
 * @size: Size modifier
 *
 * Return: Number of characters printed
 */
int cisfun_char(va_list *list, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = (char)va_arg(*list, int);
	int printed_chars = 0;

	printed_chars += handle_write_char(c, buffer, flags, width, precision, size);

	return (printed_chars);
}

