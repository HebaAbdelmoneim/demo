#include "main.h"

/**
 * _putstr - writes string to stdout
 * @str: The string to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putstr(char *str)
{
	while (*str)
		_putchar(*str++);
	return (strlen(str));
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(int c)
{
	static int len;
	static char buf[LOCAL_BUF];

	if (c != CLEAR_BUF)
		buf[len++] = c;
	if (c == CLEAR_BUF || len >= LOCAL_BUF)
	{
		write(1, buf, len);
		len = 0;
	}

	return (1);
}
