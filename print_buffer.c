#include "cif.h"

/**
 * print_buffer - Prints the contents of the buffer and resets it
 * @buffer: The buffer to print
 *
 * Return: Number of characters printed
 */
int print_buffer(char buffer[])
{
	int i, printed_chars = 0;

	for (i = 0; buffer[i] != '\0'; i++)
	{
		_putchar(buffer[i]);
		printed_chars++;
	}

	return (printed_chars);
}

