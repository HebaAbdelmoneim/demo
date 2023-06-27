#include "shell.h"

/**
 * rev_string - reverses a string
 *
 * @s: pointer to string
 *
 * Return: void
 */

void rev_string(char *s)
{
	int max = _strlen(s), i;
	char *sw1, *sw2, rev;

	sw1 = s;
	sw2 = s + max - 1;

	for (i = 0; i < max / 2; i++)
	{
		rev = *sw2;
		*sw2 = *sw1;
		*sw1 = rev;
		sw1++;
		sw2--;
	}
}

/**
 * _itoa - convert integer to string
 * @n: number to be converted
 * @str: pointer to string
 * @base: base of the number
 *
 * Return: pointer to the string
 */

char *_itoa(int n, char *str, int base)
{
	int i = 0;
	int sign = 0;

	if (n == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return (str);
	}

	if (n < 0 && base == 10)
	{
		sign = 1;
		n = -n;
	}

	while (n != 0)
	{
		int rem = n % base;

		str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		n = n / base;
	}

	if (sign)
		str[i++] = '-';

	str[i] = '\0';
	rev_string(str);
	return (str);
}
