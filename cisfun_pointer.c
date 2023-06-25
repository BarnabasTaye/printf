#include "cif.h"

/**
 * cisfun_pointer - Handles printing a memory address
 * @list: Variable arguments list
 * @buffer: The buffer to store the formatted string
 * @flags: Formatting flags
 * @width: Field width
 * @precision: Field precision
 * @size: Size modifier
 *
 * Return: Number of characters printed
 */
int cisfun_pointer(va_list *list, char buffer[],
	int flags, int width, int precision, int size)
{
	void *ptr = va_arg(*list, void *);
	int printed_chars = 0;

	printed_chars += write_pointer(buffer, (uintptr_t)ptr, sizeof(uintptr_t) * 2,
		width, flags, ' ', 'x', 0);

	return (printed_chars);
}

