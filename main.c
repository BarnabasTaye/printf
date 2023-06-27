#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int length;
	int length2;
	unsigned int ui;
	void *address;

	length = custom_printf("Let's try to custom_printf a simple sentence.\n");
	length2 = printf("Let's try to printf a simple sentence.\n");
	ui = (unsigned int)INT_MAX + 1024;
	address = (void *)0x7ffe637541f0;
	custom_printf("Length:[%d, %i]\n", length, length);
	printf("Length:[%d, %i]\n", length2, length2);
	custom_printf("Negative:[%d]\n", -762534);
	printf("Negative:[%d]\n", -762534);
	custom_printf("Unsigned:[%u]\n", ui);
	printf("Unsigned:[%u]\n", ui);
	custom_printf("Unsigned octal:[%o]\n", ui);
	printf("Unsigned octal:[%o]\n", ui);
	custom_printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	custom_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	custom_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	custom_printf("Address:[%p]\n", address);
	printf("Address:[%p]\n", address);
	length = custom_printf("Percent:[%%]\n");
	length2 = printf("Percent:[%%]\n");
	custom_printf("Len:[%d]\n", length);
	printf("Len:[%d]\n", length2);
	custom_printf("Unknown:[%r]\n");
	/*printf("Unknown:[%r]\n");*/
	return (0);
}

