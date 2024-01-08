#include "shell.h"

/**
 * main - a main function for simple shell project
 * @ac: the count of arguments
 * @argv: the array of arguments
 * Return: 0 for success
 */

int main(int ac, char **argv)
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
                cmd = arrOfCmd(line);
                if (!cmd)
                        continue;

                 if (is_builtin(cmd[0]))
                        handle_builtin(cmd, argv, &status, idx);

                else
                        status = execute_handler(cmd, argv, idx);
        }


        return (0);
}
