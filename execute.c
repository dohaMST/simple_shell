#include "shell.h"

/**
 * _execute - a function to execute cmd
 * @cmd: para1
 * @argv: para2
 * @idx: para3
 * Return: int
 */
int _execute(char **cmd, char **argv, int idx)
{
	pid_t child;
	char *full_cmd;
	int status;

	full_cmd = _getpath(cmd[0]);

	if (!full_cmd)
	{
		print_error(argv[0], cmd[0], idx);
		freeArr2D(cmd);
		return (127);
	}

	child = fork();
	if (child == 0)
	{
		if (execve(full_cmd, cmd, environ) == -1)
		{
			free(full_cmd), full_cmd = NULL;
			freeArr2D(cmd);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		freeArr2D(cmd);
	}
	return (WEXITSTATUS(status));
}
