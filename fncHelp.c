#include "shell.h"

/**
 * freeArr - Function to free memory associated with an array of strings.
 * @arr: Array of strings to be freed
 */

void freeArr(char **arr)
{
	int i;

	/*Check if the array is NULL*/
	if (!arr)
		return;
	/*Loop through the array and free each string*/
	for (i = 0; arr[i]; i++)
	{
		free(arr[i]);
		arr[i] = NULL;
	}
	/*Free the array itself and set the pointer to NULL*/
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
	write(STDERR_FILENO, name, strlen_handler(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, strlen_handler(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, strlen_handler(cmd));
	write(STDERR_FILENO, msg, strlen_handler(msg));

	/* Free the dynamically allocated index string */
	free(index);
}
