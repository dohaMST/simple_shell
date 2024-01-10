#include "shell.h"

/**
 * which_path - Searches directories in the PATH variable for a command.
 * Takes a command, a pointer to store the full path of the command (fullpath),
 * and the PATH variable (path).
 * Copies the PATH variable to a temporary variable path_copy.
 * Iterates through directories in the PATH variable using strtok.
 * Constructs the full path of the command by concatenating the directory
 * path and the command.
 * Checks if the full path is executable using the access function.
 * Returns the full path if executable, otherwise, returns NULL.
 * @command: Command to search for.
 * Return: Pointer to the full_path of the command.
 */
char *which_path(char *command)
{
	/* Length variables */
	unsigned int com_length, pa_length, orig_pa_length;
	char *path_copy, *token, *fullpath, *path;  /* String pointers */

	com_length = strlen(command);
	path = get_env("PATH");
	orig_pa_length = strlen(path);
	/* Allocate memory for a copy of the PATH variable */
	path_copy = malloc(sizeof(char) * orig_pa_length + 1);
	if (path_copy == NULL)
	{
		write(STDERR_FILENO, ERR_MALLOC, str_len(ERR_MALLOC));
		return (NULL);
	}
	/* Copy the PATH variable to path_copy */
	strcpy(path_copy, path);
	/* Initialize token using strtok */
	token = strtok(path_copy, ":");
	if (token == NULL)
		token = strtok(NULL, ":");
	/* Iterate through directories in the PATH variable */
	while (token != NULL)
	{
		pa_length = strlen(token);
		/* Allocate memory for the full path of the command within */
		fullpath = malloc(sizeof(char) * (pa_length + com_length) + 2);
		if (fullpath == NULL)
		{
			write(STDERR_FILENO, ERR_MALLOC, strlen(ERR_MALLOC));
			return (NULL);
		}
		/* Construct the full path by concatenating the directory */
		strcpy(fullpath, token);
		fullpath[pa_length] = '/';
		strcpy(fullpath + pa_length + 1, command);
		fullpath[pa_length + com_length + 1] = '\0';
		/* Check if full path executable (has execute permissions) */
		if (access(fullpath, X_OK) != 0)
		{
			free(fullpath);/* Free memory if path not executable */
			fullpath = NULL;
			token = strtok(NULL, ":");  /* Move to the next dir */
		}
		else
			break; /* Exit the loop if executable path is found */
	}
	free(path_copy);  /* Free memory allocated for the PATH variable copy */
	return (fullpath);  /* Return the pointer to the full path of the command */
}
