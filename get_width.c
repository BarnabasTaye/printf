i#include "cif.h"

/**
 * get_width - Extracts the field width from the format string
 * @format: The format string
 * @i: Pointer to the current position in the format string
 * @list: Variable arguments list
 *
 * Return: The field width
 */
int get_width(const char *format, int *i, va_list list)
{
	int width = 0;
	int done = 0;

	if (format[*i] == '*')
	{
		width = va_arg(list, int);
		(*i)++;
	}
	else
	{
		while (!done)
		{
			if (is_digit(format[*i]))
			{
				width = width * 10 + (format[*i] - '0');
				(*i)++;
			}
			else
			{
				done = 1;
			}
		}
	}

	return (width);
}

