#include "shell.h"

/**
 * _strlen - count the length of a string
 * @str: string pointer
 *
 * Return: integer, the length of the string
 */

int _strlen(char *str)
{
	int length = 0;

	while (*str != '\0')
	{
		str++;
		length++;
	}
	return (length);
}

/**
 * _strcat - concatenates two strings
 * @dest: pointer to the first string
 * @src: pointer to the second string
 *
 * Return: pointer to the resulting string
 */

char *_strcat(char *dest, char *src)
{
	int dest_max, src_max, i;

	dest_max = _strlen(dest);
	src_max = _strlen(src);
	for (i = 0; i <= src_max; i++)
	{
		*(dest + dest_max + i) = *(src + i);
	}
	return (dest);
}

/**
 * _strcmp - compares two string length
 * @s1: pointer to the first string
 * @s2: pointer to the second string
 *
 * Return: 0 if the two strings have the same length.
 * 1 if the first string is longer
 * -1 if the second string is longer
 */

int _strcmp(char *s1, char *s2)
{
	int res;

	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 - *s2 == 0)
			res = 0;
		else
		{
			res = *s1 - *s2;
			break;
		}
		s1++;
		s2++;
	}
	return (res);
}

/**
 * _strncmp - compares two string length
 * @s1: pointer to the first string
 * @s2: pointer to the second string
 * @n: unsigned length
 *
 * Return: 0 if the two strings have the same length.
 * 1 if the first string is longer
 * -1 if the second string is longer
 */

int _strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i = 0;
	int res;

	while ((i < n) & (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] - s2[i] == 0)
			res = 0;
		else
		{
			res = s1[i] - s2[i];
			break;
		}
		i++;
	}
	return (res);
}

/**
 * _strcpy - copy string to the other
 * @dest: pointer to the first string
 * @src: pointer to the second string
 *
 * Return: pointer to the resulting string
 */

char *_strcpy(char *dest, char *src)
{
	int src_max, i;

	src_max = _strlen(src);

	for (i = 0; i <= src_max; i++)
	{
		*(dest + i) = *src;
		src++;
	}
	return (dest);
}
