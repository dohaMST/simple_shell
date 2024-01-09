#include "shell.h"

int is_builtin (char *command)
{
	char *builtins[] = {
		"exit", "env", "setenv", "cd", NULL
	};
	int i;

	for (i = 0; builtins[i]; i++)
	{
		if (strcmp(command, builtins[i]) == 0)
			return (1);
	}
	return (0);
}

void handle_builtin(char **cmd, char **argv, int *status, int index)
{
	(void) argv;
	(void)index;

	if (strcmp(cmd[0], "exit") == 0)
		exit_shell(cmd, status);
	else if (strcmp(cmd[0], "env") == 0)
		print_env(cmd, status);
}

void print_env(char **cmd, int *status)
{
	int i;
	(void)status;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	freeArr2D(cmd);
	(*status) = 0;
}

void exit_shell(char **cmd, int *status)
{
	freeArr2D(cmd);
	exit(*status);
}

