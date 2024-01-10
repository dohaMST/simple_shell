#include "shell.h"

/**
 * execute_handler - Function to execute a command in a separate process.
 * @cmd: Array of command and arguments.
 * @argv: Array of command-line arguments.
 * @idx: Index of the command in the input.
 *
 * Return: The exit status of the executed command.
 */

int execute_handler(char **cmd, char **argv, int idx)
{
	pid_t child;          /* Process ID variable */
	char *full_cmd;       /* Full path of the command */
	int status;           /* Status of the child process */

	/* Get the full path of the command */
	full_cmd = getpath_handler(cmd[0]);

	/* Check if the command exists */
	if (!full_cmd)
	{
		/* Print an error message, free the memory, and return an error code*/
		handle_error(argv[0], cmd[0], idx);
		freeArr(cmd);
		return (127);         /* Standard exit status for command not found*/
	}

	/* Create a child process */
	child = fork();
	/*added*/
	if (child == -1)
	{
		write(STDERR_FILENO, ERR_FORK, strlen(ERR_FORK));
		perror("Error");
		exit(EXIT_FAILURE);
	}
	if (child == 0)
	{
		/* Child process: execute the command */
		if (execve(full_cmd, cmd, environ) == -1)
		{
			free(full_cmd);
			freeArr(cmd);
			/*exit(EXIT_FAILURE);*/
			return (-1);
		}
	}
	else
	{
		/*waitpid(child, &status, 0);*/
		/*added*/
		wait(&status);
		freeArr(cmd);
	}

	/* Return the exit status of the child process*/
	/*return (WEXITSTATUS(status));*/
	return (0);
}

