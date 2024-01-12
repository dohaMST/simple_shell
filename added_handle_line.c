#include "shell.h"

/**
 * read_line - it get the command form the prompt
 * Return: it returns the command
 */

char *read_line(void)
{
	char *cmd = NULL;
	size_t len = 0;
	ssize_t i;

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$ ", 2);
	}
	i = getline(&cmd, &len, stdin);
	if (i == -1)
        {
		free(cmd);
		/*return (NULL);*/
		exit(EXIT_SUCCESS);
	}
	return (cmd);
}
