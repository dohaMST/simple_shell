#include "shell.h"

/**
 * arrOfCmd - Function to tokenize a string based on whitespace characters.
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
		errors(3);
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
