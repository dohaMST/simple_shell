#include "shell.h"

/**
 * arrOfCmd - Function to tokenize a string based on whitespace characters.
 * @line: The string we wanna be tokenized.
 * Return: An array of tokens (strings).
 */
char **arrOfCmd(char *line)
{
	char **cmd = NULL;
	char *token = strtok(strdup_handler(line), " \t\n");
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
		cmd[i++] = strdup_handler(token);
		token = strtok(NULL, " \t\n");
	}
	free(line);
	cmd[i] = NULL;
	return (cmd);
}
