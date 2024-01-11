#include "shell.h"

/**
 * handle_path - Function to retrieve the full path of a command.
 * @cmd: The command for which to find the full path.
 *
 * Return: The full path of the command if found, otherwise, NULL.
 */
char *handle_path(char *cmd)
{
	unsigned int cmdSize, pathSize, orig_pa_length;
	char *path_copy, *token, *fullpath, *path;

	cmdSize = strlen(cmd);
	path = get_env("PATH");
	orig_pa_length = strlen(path);
	/* Allocating memory for the copy */
	path_copy = malloc(sizeof(char) * orig_pa_length + 1);
	/*check if it is NULL */
	if (path_copy == NULL)
	{
		write(STDERR_FILENO, ERR_MALLOC, strlen(ERR_MALLOC));
		return (NULL);
	}
	/* Copy the PATH to the copy */
	strcpy(path_copy, path);
	token = strtok(path_copy, ":");
	/*check if the token is NULL*/
	if (token == NULL)
		token = strtok(NULL, ":");
	while (token != NULL)
	{
		pathSize = strlen(token);
		fullpath = malloc(sizeof(char) * (pathSize + cmdSize) + 2);
		if (fullpath == NULL)
		{

			write(STDERR_FILENO, ERR_MALLOC, strlen(ERR_MALLOC));
			return (NULL);
		}
		strcpy(fullpath, token);
		fullpath[pathSize] = '/';
		str_cpy(fullpath + pathSize + 1, cmd);
		fullpath[pathSize + cmdSize + 1] = '\0';
		if (access(fullpath, X_OK) != 0)
		{
			free(fullpath);
			fullpath = NULL;
			token = strtok(NULL, ":");
		}
		else
			break;
	}
	free(path);
	free(path_copy);
	/*return the full path */
	return (fullpath);
}
