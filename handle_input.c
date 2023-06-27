#include "shell.h"

/**
 * _getline - read string from the stdin
 *
 * Return: pointer to string
 */

char *_getline(void)
{
	char *line = malloc(sizeof(char) * BUFFER_SIZE);

	if (read(0, line, BUFFER_SIZE) == 0)
	{
		_putchar('\n');
		exit(100);
	}
	return (line);
}

/**
 * get_tokens - read string from the stdin and divided it
 *
 * @command: pointer to string
 *
 * Return: array of strings
 */

char **get_tokens(char *command)
{
	int j = 0;
	char **token = malloc(BUFFER_SIZE * sizeof(char *));
	char *arg = strtok(command, " ");

	while (arg != NULL)
	{
		token[j++] = arg;
		arg = strtok(NULL, " ");
	}
	token[j] = NULL;
	return (token);
}
