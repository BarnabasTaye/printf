#include "cif.h"

/**
 * _cif - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed
 */
int _cif(const char *format, ...)
{
	va_list list;
	int printed_chars;

	va_start(list, format);
	printed_chars = handle_print(format, &list);
	va_end(list);

	return (printed_chars);
}

