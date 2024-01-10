#include "shell.h"
/**
 * _puts -  function to print the shell prompt
 * @str: String to print.
 */

void _puts2(char *str)
{
	unsigned int len;

	len = strlen_handler(str);
	write(STDOUT_FILENO, str, len);
}

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
		/* write(STDOUT_FILENO, "$ ", 2);*/
		_puts2("$ ");
	}
	i = getline(&cmd, &len, stdin);

	if (i == -1)
	{
		free(cmd);
		return (NULL);
		/*recently added*/
		/*exit(EXIT_SUCCESS);*/
	}
	return (cmd);
}
