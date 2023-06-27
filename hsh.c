#include "shell.h"

/**
 * main - Entry point
 * @argc: number of argc
 * @argv: array of arg strings
 * @envp: array of envp variables strings
 *
 * Return: Always 0
 */

int main(int __attribute__((unused)) argc, char *argv[], char *envp[])
{
	display_prompt();
	while (1)
	{
		char **cmd;
		char *command;
		char dir[100] = "/bin/";
		char *args[BUFFER_SIZE];
		unsigned int entry;
		size_t len = 1024;

		entry = command_start_message("$", entry);
		if (getline(&command, &len, stdin) == -1)
		{
			_putchar('\n');
			exit(100);
		}
		command[_strcspn(command, "\n")] = '\0';
		if (_strlen(command) == 0)
			continue;
		else
			cmd = get_tokens(command);
		_strcat(dir, cmd[0]);
		args[0] = dir;
		args[1] = cmd[1];
		args[2] = cmd[2];
		args[3] = NULL;
		if (is_builtin_command(cmd[0]))
		{
			if (_strcmp(cmd[0], "exit") == 0)
				break;
			else if (_strcmp(cmd[0], "cd") == 0)
				handle_cd(cmd[1], envp);
		}
		else if (access(dir, X_OK) == -1)
			handle_error(argv[0], entry, cmd[0], strerror(errno));
		else
			get_process(envp, cmd[0], args);
	}
	return (0);
}
