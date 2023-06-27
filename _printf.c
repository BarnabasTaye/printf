#include "main.h"

/**
 * _printf - Produces output according to a format
 * @format: Character string containing zero or more directives
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					count += print_char(va_arg(args, int), NULL);
					break;
				case 's':
					count += print_string(va_arg(args, char *), NULL);
					break;
				case '%':
					count += print_percent(NULL, NULL);
					break;
				default:
					count += _putchar('%');
					count += _putchar(*format);
					break;
			}
		}
		else
		{
			count += _putchar(*format);
		}

		format++;
	}

	va_end(args);

	return count;
}

