#include "cif.h"

/**
 * get_size - Extracts the size modifier from the format string
 * @format: The format string
 * @i: Pointer to the current position in the format string
 *
 * Return: The size modifier
 */
int get_size(const char *format, int *i)
{
	int size = 0;

	switch (format[*i])
	{
	case 'h':
		if (format[*i + 1] == 'h')
		{
			size = S_SHORT;
			(*i)++;
		}
		else
		{
			size = S_SHORT;
		}
		break;
	case 'l':
		if (format[*i + 1] == 'l')
		{
			size = S_LONG;
			(*i)++;
		}
		else
		{
			size = S_LONG;
		}
		break;
	}

	(*i)++;

	return (size);
}

