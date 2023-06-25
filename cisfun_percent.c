#include "cif.h"

/**
 * cisfun_percent - Handles printing a percent symbol
 * @list: Variable arguments list
 * @buffer: The buffer to store the formatted string
 * @flags: Formatting flags
 * @width: Field width
 * @precision: Field precision
 * @size: Size modifier
 *
 * Return: Number of characters printed
 */
int cisfun_percent(va_list *list, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(list);

	handle_write_char('%', buffer, flags, width, precision, size);

	return (1);
}

