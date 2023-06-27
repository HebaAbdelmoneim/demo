#include "shell.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _putstr - prints a string
 * @str: pointer to the char value of str
 *
 * Return: void
 */

void _putstr(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
}
