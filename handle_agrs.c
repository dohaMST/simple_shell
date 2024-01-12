#include "shell.h"

/**
 * handle_args - Function to generate argument vector
 * @cmd: Thearray of command
 * Return: Array of strings
 */

char **handle_args(char **cmd)
{
	char **args;
	unsigned int i = 0;
	unsigned int num_args = 0;

	/* Count the number of arguments in cmd*/
	while (cmd[num_args] != NULL)
	{
		num_args++;
	}
	args = malloc(sizeof(char *) * (num_args + 1));
	if (!args)
		perror("malloc");

	while (cmd[i])
	{
		if (cmd[i][0] == '#')
			break;
		args[i] = cmd[i];
		i++;
	}
	args[i] = NULL;
	return (args);
}
