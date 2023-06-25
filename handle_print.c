#include "cif.h"

/**
 * handle_print - Handles the printing of the format string
 * @format: Format string
 * @list: Variable arguments list
 *
 * Return: Number of characters printed
 */
int handle_print(const char *format, va_list *list)
{
	int i, j;
	int printed_chars = 0;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	for (i = 0, j = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[j++] = format[i];
			if (j == BUFF_SIZE - 1)
			{
				buffer[j] = '\0';
				printed_chars += print_buffer(buffer);
				j = 0;
			}
		}
		else
		{
			buffer[j] = '\0';
			printed_chars += print_buffer(buffer);
			j = 0;
			i++;
			if (format[i] == '%')
			{
				buffer[0] = '%';
				buffer[1] = '\0';
				printed_chars += print_buffer(buffer);
			}
			else if (format[i] != '\0')
				printed_chars += print_argument(format[i], list, buffer, &j);
		}
	}

	buffer[j] = '\0';
	printed_chars += print_buffer(buffer);

	return (printed_chars);
}

