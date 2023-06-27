#include "main.h"

/**
 * _printf - Custom implementation of printf function
 * @format: Format string
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i, count = 0;
	char buffer[BUFF_SIZE] = {0};

	va_start(args, format);

	if (format == NULL)
		return (-1);

	for (i = 0; format && format[i]; i++)
	{
		if (format[i] != '%')
		{
			if (count == BUFF_SIZE - 1)
			{
				write(1, buffer, count);
				count = 0;
			}
			buffer[count++] = format[i];
		}
		else if (format[i + 1])
		{
			i++;
			count += handle_print(&format[i], &i, args, buffer, 0, 0, 0, 0);
		}
	}

	write(1, buffer, count);
	va_end(args);

	return (count);
}

/**
 * handle_print - Handles the conversion specifiers and prints the corresponding output
 * @fmt: Format specifier
 * @i: Current index in the format string
 * @list: va_list containing the arguments
 * @buffer: Character buffer to store the formatted output
 * @flags: Flags for the conversion specifier
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of characters printed
 */
int handle_print(const char *fmt, int *i, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int j, count = 0;

	fmt_t formats[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{0, NULL}
	};

	UNUSED(precision);
	UNUSED(size);

	for (j = 0; formats[j].fmt; j++)
	{
		if (*fmt == formats[j].fmt)
		{
			count += formats[j].fn(list, buffer, flags, width, precision, size);
			break;
		}
	}

	if (formats[j].fmt == 0)
	{
		if (count == BUFF_SIZE - 1)
		{
			write(1, buffer, count);
			count = 0;
		}
		buffer[count++] = '%';
		buffer[count++] = *fmt;
	}

	return (count);
}

