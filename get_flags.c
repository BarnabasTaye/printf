#include "cif.h"

/**
 * get_flags - Extracts the formatting flags from the format string
 * @format: The format string
 * @i: Pointer to the current position in the format string
 *
 * Return: The formatting flags
 */
int get_flags(const char *format, int *i)
{
	int flags = 0;
	int done = 0;

	while (!done)
	{
		switch (format[*i])
		{
		case '-':
			flags |= F_MINUS;
			break;
		case '+':
			flags |= F_PLUS;
			break;
		case '0':
			flags |= F_ZERO;
			break;
		case '#':
			flags |= F_HASH;
			break;
		case ' ':
			flags |= F_SPACE;
			break;
		default:
			done = 1;
			break;
		}

		if (!done)
			(*i)++;
	}

	return (flags);
}

