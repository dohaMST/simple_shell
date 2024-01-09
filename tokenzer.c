#include "shell.h"

/**
 * tokenizer - Function to tokenize a string based on whitespace characters.
 * @line: The input string to be tokenized.
 *
 * Return: An array of tokens (strings).
 */
char **tokenizer(char *line)
{
	char **cmd = NULL;
	char *token = strtok(strdup(line), " \t\n");
	int cpt = 0, i = 0;

	if (!line)
		return (NULL);
	while (token)
	{
		cpt++;
		token = strtok(NULL, " \t\n");
	}
	cmd = malloc(sizeof(char *) * (cpt + 1));
	if (!cmd)
	{
		free(line);
		return (NULL);
	}
	i = 0;
	token = strtok(line, " \t\n");
	while (token)
	{
		cmd[i++] = strdup(token);
		token = strtok(NULL, " \t\n");
	}
	free(line);
	cmd[i] = NULL;
	return (cmd);
}

