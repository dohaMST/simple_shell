#include "shell.h"

/**
 * main _ the main program for shell prj
 * @ac: the count of arguments
 * @argv: the array of arguments
 * Return: 0 on success
 */

int main(int ac, char **argv)
{
	char *line, *fullpath;
	char **tokens;
	int status = 0, idx = 0, x = 0;
	int child_status;
	(void) ac;
	/*struct stat buf;*/
	/* Main shell loop */
	while (1)
	{
		line = read_line();
		/* Check if the line is \n */
		if (str_cmp(line, "\n", 1) == 0)
		{
			free(line);
			continue;
		}
		idx++;
		/* handle tokens */
		tokens = arrOfCmd_handler(line);
		if (tokens[0] == NULL)
		{
			free(tokens);
			continue;
		}
		/* handle builtins commands */
		if (is_builtin(tokens[0]))
		{
			handle_builtin(tokens, argv, &status, idx);
			continue;
		}

		/*handle full path*/
		fullpath = handle_path(tokens[0]);
		if (fullpath == NULL)
			fullpath = tokens[0];
		else
			x = 1; /*to ckeck if full path was allocated or not */

		/* Execute the command in a child process */
		child_status = child(fullpath, tokens);
		/* Display an error if the child process fails to execute */
		/*added / changed -1 to 0 */
		if (child_status == -1)
			errors(2);
		/* Free allocated memory for tokens, the PATH variable, the */
		/* input line, and fullpath if it was dynamically allocated */
		free_all(tokens, line, fullpath, x);
	}
	/* Return 0 on successful completion */
	return (0);
}
