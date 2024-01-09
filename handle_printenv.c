#include "shell.h"

/**
 * handle_printenv - a function that print environment variables
 * @cmd: Array of command's tokens
 * @status: Pointer to the exit status
 */

void handle_printenv(char **cmd, int *status)
{
	char **env_ptr = environ;
	(void)status;

	/* Loop through the environment variables and print them */
	while (*env_ptr)
	{
		/* write(STDOUT_FILENO, *env_ptr, strlen(*env_ptr)); */
		_puts(*env_ptr);
		/* write(STDOUT_FILENO, "\n", 1); */
		_puts("\n");
		env_ptr++;
	}

	freeArr(cmd);
	/* Set the exit status to 0 (success) */
	(*status) = 0;
}
