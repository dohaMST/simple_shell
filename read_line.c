#include "shell.h"
/**
 * _puts -  function to print the shell prompt
 * @str: String to print.
 * Return: void
 */

void _puts(char *str)
{
	unsigned int length;

	length = strlen(str);
	write(STDOUT_FILENO, str, length);
}

/**
 * read_line - a function to read lines
 * Return: line
 */

char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t n;

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$ ", 2);
		/*_puts("$ ");*/
	}
	n = getline(&line, &len, stdin);

	if (n == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
