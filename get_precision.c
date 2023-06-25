#include "cif.h"

/**
 * get_precision - Extracts the field precision from the format string
 * @format: The format string
 * @i: Pointer to the current position in the format string
 * @list: Variable arguments list
 *
 * Return: The field precision
 */
int get_precision(const char *format, int *i, va_list list)
{
	int precision = -1;
	int done = 0;

	if (format[*i] == '.')
	{
		(*i)++;

		if (format[*i] == '*')
		{
			precision = va_arg(list, int);
			(*i)++;
		}
		else
		{
			precision = 0;

			while (!done)
			{
				if (is_digit(format[*i]))
				{
					precision = precision * 10 + (format[*i] - '0');
					(*i)++;
				}
				else
				{
					done = 1;
				}
			}
		}
	}

	return (precision);
}

