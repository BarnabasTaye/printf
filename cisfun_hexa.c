#include "cif.h"

/**
 * cisfun_hexa - Handles printing a lowercase hexadecimal number with custom mapping
 * @list: Variable arguments list
 * @map_to: Mapping characters
 * @buffer: The buffer to store the formatted string
 * @flags: Formatting flags
 * @flag_ch: Flag character
 * @width: Field width
 * @precision: Field precision
 * @size: Size modifier
 *
 * Return: Number of characters printed
 */
int cisfun_hexa(va_list *list, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	unsigned int num = va_arg(*list, unsigned int);
	int printed_chars = 0;

	printed_chars += write_num(num, map_to, buffer, flags, width, precision, size);

	return (printed_chars);
}

