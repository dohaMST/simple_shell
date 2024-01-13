#include "shell.h"

/**
 * handle_free - This function is designed to free dynamically allocated memory
 * @cmd: the array of command
 * @line: the input buffer.
 * @full_path: full path.
 * @x: it helps for checking if full_path was allocated
 * Return: void
 */
void handle_free(char **cmd, char *line, char *full_path, int x)
{
	/* free the tokens array */
	free(cmd);
	/* free the prompt input */
	free(line);
	/* Checking if full_path was allocated before freeing it */
	if (x == 1)
		free(full_path);
}

/**
 * free_dp - This function is responsible for freeing a double pointer (array)
 * @array: Double pointer to free.
 * @length: Length of the double pointer.
 * Return: void
 */
void free_dp(char **array, unsigned int length)
{
	unsigned int a;

	for (a = 0; a < length; a++)
	{
		/* Free the memory alocated */
		free(array[a]);
	}
	free(array);
}
