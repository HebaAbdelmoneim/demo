#include "shell.h"

/**
 * _strcspn - gets the length of a prefix substring
 * @str: pointer to string
 * @rejc: pointer to string
 *
 * Return: length of str at which char not match
 *
 */

unsigned int _strcspn(char *str, char *rejc)
{
	unsigned int i, j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (rejc[j] != '\0')
		{
			if (*(str + i) == *(rejc + j))
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}
