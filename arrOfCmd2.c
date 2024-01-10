#include "shell.h"

/**
 * arrOfCmd - Function to tokenize a string based on whitespace characters.
 * @line: The string we wanna be tokenized.
 * Return: An array of tokens (strings).
 */
char **arrOfCmd(char *line)
{
	char **cmd = NULL;
	/*added*/
	char *token = strtok(strdup(line), "\n\t\r ");
	/*char *token = strtok(strdup_handler(line), " \t\n");*/
	int cpt = 0, i = 0;

	if (!line)
		return (NULL);

	while (token)
	{
		cpt++;
		/*token = strtok(NULL, " \t\n");*/
		/*added*/
		token = strtok(NULL, " \t\n\r");
	}
	cmd = malloc(sizeof(char *) * (cpt + 1));
	if (!cmd)
	{
		free(line);
		/*return (NULL);*/
		/*added*/
		write(STDERR_FILENO, ERR_MALLOC, strlen(ERR_MALLOC));
		exit(EXIT_FAILURE);
	}
	i = 0;
	/*token = strtok(line, " \t\n");*/
	token = strtok(line, "\n\t\r ");
	while (token)
	{
		cmd[i++] = strdup_handler(token);
		/*token = strtok(NULL, " \t\n");*/
		token = strtok(NULL, "\n\t\r ");
	}
	free(line);
	cmd[i] = NULL;
	return (cmd);
}
