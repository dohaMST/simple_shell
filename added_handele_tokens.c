#include "shell.h"

/**
 * arrOfCmd - Function to tokenize a string based on whitespace characters.
 * @line: The string we wanna be tokenized.
 * Return: An array of tokens (strings).
 */

char **arrOfCmd(char *line)
{
	char *token = NULL, *tmp = NULL;
	char **cmd =NULL;
	int cpt = 0, i = 0;

	if (!line)
		return (NULL);
	tmp = strdup(line);
	token = strtok(tmp, " \t\n");
	if (token == NULL)
	{
		free(tmp), tmp = NULL;
		free(line), line = NULL;
		return (NULL);
	}

	while (token)
	{
		cpt++;
		token = strtok(NULL, " \t\n");
	}
	free(tmp), tmp = NULL;
	cmd = malloc(sizeof(char *) * (cpt + 1));

	if(!cmd)
	{
		free(line), line = NULL;
		return (NULL);
	}

	token = strtok(line, " \t\n");
	while (token)
	{
		cmd[i] = strdup(token);
		token = strtok(NULL, " \t\n");
		i++;
	}
	free(line), line = NULL;
	cmd[i] = NULL;
	return (cmd);
}
