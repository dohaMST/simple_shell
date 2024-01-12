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
		"exit", "env", 
	};
	char *copy_line;
	int i;

	line_copy = strdup(cmd);
	/* Loop through the array of built-in commands */
	for (i = 0; i < 2; i++)
	{
		/* Compare the given command with each built-in command*/
		if (strcmp(cmd, builtins[i]) == 0)
		{
			free(line_copy);
			return (1); /*it exists*/
		}
	}

	return (0); /* it doesnt exist */
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

	/* Check if the command is "exit" */
	if (strcmp(cmd[0], "exit") == 0)
		exitshell_handler(cmd, status);
	/*Check if the command is "env"*/
	else if (strcmp(cmd[0], "env") == 0)
	{
		/*handle_printenv(cmd, status);*/
		print_environment();
	}
	/* checks if the command is "cd" */
	else if (strcmp(cmd[0], "cd") == 0)
		cd_builtin(cmd, status);
}

/**
 * exitshell_handler - Function to exit the shell program.
 * @cmd: Array of command and arguments.
 * @sts: Pointer to the exit status of the shell.
 * Return: void
 */

void exitshell_handler(char **cmd, int *sts)
{
	/* Free the memory allocated for the array of command and arguments */
	freeArr(cmd);
	/* Exit the shell program with the provided status */
	exit(*sts);
}


/**
 * cd_builtin - a function to handle the "cd" cmd
 * @cmd: Array of command's tokens
 * @status: Pointer to the exit status
 */
void cd_builtin(char **cmd, int *status)
{
	/* Check if the "cd" command has the correct number of arguments */
	if (cmd[1] == NULL)
	{
		_puts("cd: missing argument\n");
		*status = 2; /* Set a custom exit status for the error */
		return;
	}
	/* Change the current working directory using chdir */
	if (chdir(cmd[1]) != 0)
	{
		perror("cd"); /* Print an error message if chdir fails */
		*status = 1;  /* Set a custom exit status for the error */
	}
	else
	{
		*status = 0; /* Set exit status to 0 for successful execution */
	}
}


/**
 * handle_printenv - Function to print environment variables to standard output.
 * @cmd: Array of command and arguments.
 * @status: Pointer to the exit status (unused in this function).
 */

void handle_printenv(char **cmd, int *status)
{
	char **env_ptr = environ;
	(void)status;

	/* Loop through the environment variables and print them */
	while (*env_ptr)
	{
		/* write(STDOUT_FILENO, *env_ptr, strlen(*env_ptr)); */
		_puts(*env_ptr);
		/* write(STDOUT_FILENO, "\n", 1); */
		_puts("\n");
		env_ptr++;
	}
	freeArr(cmd);
	/* Set the exit status to 0 (success) */
	(*status) = 0;
}

