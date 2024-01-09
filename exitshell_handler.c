#include "shell.h"

/**
 * exitshell_handler - Function to exit the shell program.
 * @cmd: Array of command and arguments.
 * @sts: Pointer to the exit status of the shell.
 * Return: void
 */

void exitshell_handler(char **cmd, int *sts)
{
	/* Free the memory allocated for the array of command and arguments */
	freeArr(cmd);
	/* Exit the shell program with the provided status */
	exit(*sts);
}
