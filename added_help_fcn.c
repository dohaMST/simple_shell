#include "shell.h"

/**
 * freeArr - a function to free a double pointer
 * @arr: the array we wanna free
 */
void freeArr(char **arr)
{
	int i;

	if (!arr)
		return;
	for (i = 0; arr[i]; i++)
	{
		free(arr[i]);
		arr[i] = NULL;
	}
	free(arr), arr = NULL;
}

/**
 * handle_error - Function to handle errors related to command execution.
 * @name: The name of the program.
 * @cmd: The command that caused the error.
 * @i: The index of the command in the input sequence.
 */
void handle_error(char *name, char *cmd, int i)
{
	char *index, msg[] = ": not found\n";

	/* Convert the index to a string */
	index = handle_itoa(i);

	/* Write the error message to stderr */
	write(STDERR_FILENO, name, strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, strlen(cmd));
	write(STDERR_FILENO, msg, strlen(msg));

    /* Free the dynamically allocated index string */
	free(index);
}
