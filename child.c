#include "shell.h"

/**
 * execute_handler - This function is designed to be called when executing a
 * @full_path: Full path of the executable.
 * @cmd: Tokenized user input.
 * Return: 0 on success, -1 on failure.
 */
int execute_handler(char *full_path, char **cmd)
{
	pid_t child_pid;
	int sts, x;

	/* creating child to execute the command */
	child_pid = fork();
	/*check if the fork fails */
	if (child_pid == -1)
	{
		errors(1);
		exit(EXIT_FAILURE);
	}
	/*if the child process do: */
	if (child_pid == 0)
	{
		x = execve(full_path, cmd, environ);
		if (x == -1)
			exit(126);
		exit(EXIT_FAILURE);
	}
	/*if the parent process do :*/
	else
	{
		wait(&sts);
	}
	return (0);
}
