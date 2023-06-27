#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: A character string containing directives.
 *
 * Return: The number of characters printed (excluding the null byte used to
 *         end output to strings).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;
	int i = 0;

	va_start(args, format);

	if (format == NULL)
		return (-1);

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				return (-1);
			else if (format[i] == '%')
				printed_chars += _putchar('%');
			else if (format[i] == 'c')
				printed_chars += _putchar(va_arg(args, int));
			else if (format[i] == 's')
				printed_chars += _puts(va_arg(args, char *));
			else if (format[i] == 'b')
				printed_chars += print_binary(va_arg(args, unsigned int));
			else
				printed_chars += _putchar('%');
		}
		else
			printed_chars += _putchar(format[i]);

		i++;
	}

	va_end(args);

	return (printed_chars);
}

