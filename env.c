#include "shell.h"

/**
 * _getenv - get the value of environment variable
 * @envp: array of strings
 * @var: pointer to string
 *
 * Return: pointer to the variable string
 */

char *_getenv(char *envp[], char *var)
{
	char *value = NULL;
	int i = 0;

	while (envp[i] != NULL)
	{
		if (_strncmp(envp[i], var, _strlen(var)) == 0)
		{
			value = envp[i] + (_strlen(var) + 1);
			break;
		}
		i++;
	}
	return (value);
}

/**
 * print_env - print environment variables
 * @envp: pointer to array of strings
 *
 * Return: void
 */

void print_env(char *envp[])
{
	int y;

	for (y = 0; envp != NULL; y++)
	{
		_putstr(envp[y]);
		_putchar('\n');
	}
}
