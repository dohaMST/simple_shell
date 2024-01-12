#include "shell.h"

/**
 * main - The program enters a continuous loop that
 * represents the main shell execution.
 * Prompt and User Input: prompt(STDIN_FILENO, buf): Displays the shell prompt
 * if in interactive mode.
 * line = get_line(stdin): Reads a line of input from the user.
 * Check for Empty Input: Checks if the entered line is empty (contains only
 * a newline character).If so, skips to the next iteration.
 * Tokenization: tokens = tokenizer(line): Tokenizes the input line into
 * individual commands and arguments.
 * Execute Built-in Commands: builtin_status = buiilt_in_execu(tokens):
 * Checks and executes built-in commands such as "exit" or "env."
 * If a built-in command was successful or the user requested exit, free
 * allocated memory and continue to the next iteration.
 * Get PATH Environment Variable: path = get_env("PATH"): Retrieves the value
 * of the PATH environment variable.
 * Determine Full Path: fullpath = which_path(tokens[0], fullpath, path):
 *Determines the full path of the command to be executed.
 * Execute Command in Child Process: child_status = child(fullpath, tokens):
 * Executes the command in a child process.
 * Error Handling: Displays an error if the child process fails to execute.
 * Free Allocated Memory: free_all(tokens, path, line, fullpath, flag):
 * Frees the memory allocated for tokens, the PATH variable, the input line,
 * and fullpath if it was dynamically allocated.
 * Return Status: The loop continues until the user requests to exit the shell.
 * The program returns 0 on successful completion.
 * @ac: the count of arguments
 * @argv: the array of arguments
 * Return: 0 on success
 */

int main(int ac, char **argv)
{
	char *line, *fullpath;
	char **tokens;
	int flag = 0, status = 0, idx = 0; /* 0 if fullpath is not malloc'd, 1 otherwise */
	int child_status;
	(void) ac;
	/*struct stat buf;*/
	/* Main shell loop */
	while (1)
	{
		line = read_line();
		/*added*/
		if (line == NULL)/*reached the EOF ctr+D*/
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
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
			handle_builtin(tokens, argv, &status, idx);


		fullpath = handle_path(tokens[0]);
		/* If fullpath is NULL, use the entered command as is */
		if (fullpath == NULL)
			fullpath = tokens[0];
		else
			flag = 1; /* flag to 1 indicat fullpath was allocat */
		/* Execute the command in a child process */
		child_status = child(fullpath, tokens);
		/* Display an error if the child process fails to execute */
		if (child_status == -1)
			errors(2);
		/* Free allocated memory for tokens, the PATH variable, the */
		/* input line, and fullpath if it was dynamically allocated */
		free_all(tokens, line, fullpath, flag);
	}
	/* Return 0 on successful completion */
	return (0);
}
