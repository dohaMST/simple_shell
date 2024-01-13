#include "shell.h"

/**
 * arrOfCmd_handler - Function to tokenize a string based on whitespace characters.
 * @line: The string we wanna be tokenized.
 * Return: An array of tokens (strings).
 */
char **arrOfCmd_handler(char *line)
{
	char **cmd;
	char *token;
	unsigned int a;

	cmd = malloc(sizeof(char) * BUFFER);
	if (cmd == NULL)
	{
		write(STDERR_FILENO, ERR_MALLOC, str_len(ERR_MALLOC));
		exit(EXIT_FAILURE);
	}
	/* extract tokens by strtok*/
	token = strtok(line, "\n\t\r ");
	a = 0;
	while (token != NULL)
	{
		cmd[a] = token;  /* impliment the array */
		token = strtok(NULL, "\n\t\r ");
		a++;
	}
	cmd[a] = NULL; /* the last element should be NULL*/
	return (cmd);
}
