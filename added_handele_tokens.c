#include "shell.h"

/**
 * arrOfCmd - Function to tokenize a string based on whitespace characters.
 * @line: The string we wanna be tokenized.
 * Return: An array of tokens (strings).
 */

char **arrOfCmd(char *line)
{
	char *token;
	char **cmd;
	unsigned int i = 0;

	token = strtok(line, "\n\t\r ");
	cmd = malloc(sizeof(char) * BUFFER);

	if(!cmd)
	{
		write(STDERR_FILENO, ERR_MALLOC, str_len(ERR_MALLOC));
		exit(EXIT_FAILURE);
	}

	token = strtok(line, "\n\t\r ");
	while (token)
	{
		cmd[i] = strdup(token);
		token = strtok(NULL, "\n\t\r ");
		i++;
	}
	cmd[i] = NULL;
	return (cmd);
}
