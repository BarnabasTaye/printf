#include "cif.h"

/**
 * cisfun_string - Handles printing a string
 * @list: Variable arguments list
 * @buffer: The buffer to store the formatted string
 * @flags: Formatting flags
 * @width: Field width
 * @precision: Field precision
 * @size: Size modifier
 *
 * Return: Number of characters printed
 */
int cisfun_string(va_list *list, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str = va_arg(*list, char *);
	int printed_chars = 0;

	if (str == NULL)
		str = "(null)";

	printed_chars += handle_write_string(str, buffer, flags, width, precision, size);

	return (printed_chars);
}

