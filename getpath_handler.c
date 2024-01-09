#include "shell.h"

/**
 * getpath_handler - a function to retrieve the full path of a command.
 * @cmd: The command we wanna find the full path.
 * Return: The full path of the command if found, otherwise, NULL.
 */
char *getpath_handler(char *cmd)
{
	char *p_env, *full_cmd, *dir;
	int i;
	struct stat st;

	/* Check if the command is already a path */
	for (i = 0; cmd[i]; i++)
	{
		if (cmd[i] == '/')
		{
			if (stat(cmd, &st) == 0)
				return (strdup_handler(cmd)); /* The path is correct (exists) */
			return (NULL); /* The path is incorrect or doesn't exist */
		}
	}
	p_env = getenv_handler("PATH");
	if (!p_env)
		return (NULL);
	/* Handling PATH - searching through directories */
	dir = strtok(p_env, ":");
	while (dir)
	{
		full_cmd = malloc(strlen(dir) + strlen_handler(cmd) + 2);
		if (full_cmd)
		{
			/* Construct the full path by combining directory and command */
			strcpy_handler(full_cmd, dir);
			strcat_handler(full_cmd, "/");
			strcat_handler(full_cmd, cmd);
			if (stat(full_cmd, &st) == 0)
			{
				free(p_env);
				return (full_cmd); /* Return the full path if found */
			}
			free(full_cmd), full_cmd = NULL; /* Free memory if not found */
			dir = strtok(NULL, ":"); /* Move to the next directory in PATH */
		}
	}
	free(p_env);
	return (NULL); /* Return NULL if the command is not found in any directory */
}

