#include "shell.h"

/**
 * cd_builtin - a function to handle the "cd" cmd
 * @cmd: Array of command's tokens
 * @status: Pointer to the exit status
 */
void cd_builtin(char **cmd, int *status)
{
	/* Check if the "cd" command has the correct number of arguments */
	if (cmd[1] == NULL)
	{
		_puts("cd: missing argument\n");
		/*fprintf(stderr, "cd: missing argument\n");*/
		*status = 2; /* Set a custom exit status for the error */
		return;
	}
	/* Change the current working directory using chdir */
	if (chdir(cmd[1]) != 0)
	{
		perror("cd"); /* Print an error message if chdir fails */
		*status = 1;  /* Set a custom exit status for the error */
	}
	else
	{
		*status = 0; /* Set exit status to 0 for successful execution */
	}
}
