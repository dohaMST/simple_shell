#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

extern char **environ;
extern char **ENVR;
/*handle_cmd.c*/
void _puts(char *str);
char *read_line(void);

/*string_tools.c*/
int strlen_handler(char *str);
char *strdup_handler(char *str);
char *strcpy_handler(char *dest, char *src);
int strcmp_handler(char *str1, char *str2);
void strcat_handler(char *dest, char *src);
/*string_tools2.c*/
void revstr_handler(char *str, int len);
char *handle_itoa(int x);

/*int count_tokens(const char *line);
char **arrOfCmd(char *line);*/
char **arrOfCmd(char *line);

/*fncHelp.c*/
void freeArr(char **arr);
void handle_error(char *name, char *cmd, int i);

/*execute_handler.c*/
int execute_handler(char **cmd, char **argv, int idx);

/*getenv_handler.c*/
char *getenv_handler(char *x);

/*getpath_handler.c*/
char *getpath_handler(char *cmd);

/*exitshelh_handler.c*/
void exitshell_handler(char **cmd, int *sts);

/*handle_printenv.c*/
void handle_printenv(char **cmd, int *status);

/*builtins_handler.c*/
void handle_builtin(char **cmd, char **argv, int *status, int index);
int is_builtin(char *cmd);

/**/
void cd_builtin(char **cmd, int *status);

/**/
void handle_variables(char **cmd, int *status); 


#endif
