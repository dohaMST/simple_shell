#include "shell.h"

/**
 * main2 - a main function for simple shell project
 * @ac: the count of arguments
 * @argv: the array of arguments
 * Return: 0 for success
 */

int main2(int ac, char **argv)
{
	char *line = NULL;
	char **cmd = NULL;
	int status = 0, idx = 0;
	(void) ac;

	while (1)
	{
		line = read_line();
		if (line == NULL)/*reached the EOF ctr+D*/
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		idx++;
		/*added*/
		if (strcmp(line, "\n") == 0)
		{
			free(line);
			continue;
		}
		/*idx++;*/
		/*cmd = arrOfCmd(line);*/
		cmd = tokenizer(line);
		/*added*/
		if (cmd[0] == NULL)
		{
			free(cmd);
			continue;
		}
		if (!cmd)
			continue;

		if (is_builtin(cmd[0]))
			handle_builtin(cmd, argv, &status, idx);
		else
		{
			status = execute_handler(cmd, argv, idx);
			if (status == -1)
			{
				perror("Error");
			}
		}
	}


	return (0);
}
