#include "shell.h"

/**
 * get_process - handle child process
 * @envp: array of envp variables strings
 * @cmd: pointer of string
 * @args: array of args strings
 *
 * Return: void
 */
void  get_process(char *envp[], char *cmd, char *args[])
{
	pid_t id = fork();

	if (id == -1)
	{
		perror("fork");
		exit(98);
	}
	if (id == 0)
	{
		if (_strcmp(cmd, "env") == 0)
			print_env(envp);
		else
		{
			execve(args[0], args, envp);
			perror("execve");
			exit(99);
		}
	}
	else
		wait(NULL);
}

/**
 * handle_error - write error to stderr
 * @arg: pointer to string of the first argv
 * @entry: entry integer number
 * @cmd: pointer of string
 * @err: pointer to string of the error
 *
 * Return: void
 */

void handle_error(char *arg, int entry, char *cmd, char *err)
{
	char err_buf[BUFFER_SIZE];
	char entry_num[100];

	_strcpy(err_buf, arg);
	_strcat(err_buf, ": ");
	_strcat(err_buf, _itoa(entry, entry_num, 10));
	_strcat(err_buf, ": ");
	_strcat(err_buf, cmd);
	_strcat(err_buf, ": ");
	_strcat(err_buf, err);
	_strcat(err_buf, "\n");
	write(2, err_buf, _strlen(err_buf));
}

/**
 * is_builtin_command - check for some commands if they are builtin
 * @cmd: pointer to string
 *
 * Return: 1 on success, 0 on failure
 */

int is_builtin_command(char *cmd)
{
	int i = 0;
	char *commands[] = { "cd", "exit", NULL };

	while (commands[i] != NULL)
	{
		if (_strcmp(cmd, commands[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

/**
 * handle_cd - write error to stderr
 * @arg: pointer to string of the arg
 * @envp: array of strings
 *
 * Return: void
 */

void handle_cd(char *arg, char *envp[])
{
	char *prev_dir = NULL;
	char dir[BUFFER_SIZE];
	char *err = "No previous directory.\n";

	if (arg == NULL)
	{
		chdir(_getenv(envp, "HOME"));
		prev_dir = getcwd(dir, BUFFER_SIZE);
	}
	else if (_strcmp(arg, "-") == 0)
	{
		if (prev_dir == NULL)
			write(2, err, _strlen(err));
		else
		{
			chdir(prev_dir);
			_putstr(prev_dir);
			_putchar('\n');
		}
	}
	else
	{
		if (chdir(arg) != 0)
			perror("chdir");
		else
			prev_dir = getcwd(dir, BUFFER_SIZE);
	}
}
