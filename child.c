#include "shell.h"

/**
 * child - This function is designed to be called when executing a
 * @fullpath: Full path of the executable.
 * @tokens: Tokenized user input.
 * Return: 0 on success, -1 on failure.
 */
int child(char *fullpath, char **tokens)
{
	pid_t child_pid;
	int status;
	int execve_status;
	char **envp = environ;
	/* Create a child process using fork */
	child_pid = fork();
	if (child_pid == -1)
	{
		/* If fork fail print an error and exit with failure status */
		errors(1);
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		/* Code inside the child process */
		execve_status = execve(fullpath, tokens, envp);
		if (execve_status == -1)
			exit(126);
		exit(EXIT_FAILURE);
	}
	else
	{
		/* Code inside the parent process */
		/* Wait for the child process to finish */
		wait(&status);
	}
	return (0); /* Return 0 on success */
}
