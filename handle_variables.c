#include "shell.h"

/**
 * handle_variables - Function to handle variable replacement in the command.
 * @cmd: Array of command and arguments.
 */

void handle_variables(char **cmd, int *status)
{
	/*char *x;*/
	char status_str[20];

    if (strcmp(cmd[1], "$?") == 0)
    {
       /* x = handle_itoa(*status);*/
       /* _puts(x);*/

	    sprintf(status_str, "%d", *status);
    }
}
