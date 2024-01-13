#include "shell.h"

/**
 * errors - a function to handle errors
 * @error: the number of error
 * Return: void
 */

void errors(int error)
{
	switch (error)
	{
		case 1: /* fork error to stderr */
			write(STDERR_FILENO, ERR_FORK, str_len(ERR_FORK));
			perror("Error");
			break;
		case 2: /* handle execve error to stderr */
			perror("Error");
			break;
		case 3: /* handle malloc error to stderr */
			write(STDERR_FILENO, ERR_MALLOC, str_len(ERR_MALLOC));
			break;
		case 4: /* handle empty path error to stderr */
			write(STDERR_FILENO, ERR_PATH, str_len(ERR_PATH));
			break;
		default:
			return;
	}
}
