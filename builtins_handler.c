#include "shell.h"
/**
 * is_builtin - Function to check if a command is a built-in command.
 * @cmd: The command to check.
 *
 * Return: 1 if the command is a built-in, 0 otherwise.
 */
int is_builtin(char *cmd)
{
	char *builtins[] = {
		"exit", "env", "setenv", "cd", NULL
	};
	int i;

	/* Loop through the array of built-in commands */
	for (i = 0; builtins[i]; i++)
	{
		/* Compare the given command with each built-in command*/
		if (strcmp_handler(cmd, builtins[i]) == 0)
		return (1); /*it doesnt exist*/
	}

	return (0); /* it exists */
}


/**
 * handle_builtin - Function to handle execution of built-in commands.
 * @cmd: Array of command and arguments.
 * @argv: Array of arguments to the shell program.
 * @status: Pointer to the exit status of the shell.
 * @index: Index of the command in the input sequence (not used here).
 */
void handle_builtin(char **cmd, char **argv, int *status, int index)
{
	(void)argv;
	(void)index;

	/* Handle variable replacement*/
	if (strcmp(cmd[0], "echo") == 0)
		handle_variables(cmd, status);

	/* Check if the command is "exit" */
	if (strcmp_handler(cmd[0], "exit") == 0)
		exitshell_handler(cmd, status);
	/* Check if the command is "env"*/
	else if (strcmp_handler(cmd[0], "env") == 0)
		handle_printenv(cmd, status);
	/* checks if the command is "cd" */
	else if (strcmp_handler(cmd[0], "cd") == 0)
		cd_builtin(cmd, status);
}

