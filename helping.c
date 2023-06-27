#include "shell.h"

/**
 * display_prompt - show prompt screen
 *
 * Return: void
 */

void display_prompt(void)
{
	int ft = 1;

	if (ft)
	{
		const char *CLEAR_SCREEN = "\033[2J";
		const char *CURSOR_TOP_LEFT = "\033[0;0f";

		write(STDOUT_FILENO, CLEAR_SCREEN, 5);
		write(STDOUT_FILENO, CURSOR_TOP_LEFT, 7);
		ft = 0;
	}
}

/**
 * command_start_message -  print $ and get command number
 * @str: pointer to string
 * @n: number of entry
 *
 * Return:  number of command
 */

unsigned int command_start_message(char *str, unsigned int n)
{
	unsigned int i = 1;

	if (write(STDOUT_FILENO, str, _strlen(str)) != _strlen(str))
	{
		perror("write");
	}
		return (i + n);
}

