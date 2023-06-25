#include "cif.h"

/**
 * cisfun_non_printable - Handles printing non-printable characters
 * @list: Variable arguments list
 * @buffer: The buffer to store the formatted string
 * @flags: Formatting flags
 * @width: Field width
 * @precision: Field precision
 * @size: Size modifier
 *
 * Return: Number of characters printed
 */
int cisfun_non_printable(va_list *list, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str = va_arg(*list, char *);
	int printed_chars = 0;

	if (str == NULL)
		str = "(null)";

	printed_chars += handle_write_non_printable(str, buffer, flags, width, precision, size);

	return (printed_chars);
}

