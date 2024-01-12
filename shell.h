#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER 1024
#define TRUE 1
#define PROMPT "$ "
/* error strings */
#define ERR_MALLOC "Unable to malloc space\n"
#define ERR_FORK "Unable to fork and create child process\n"
#define ERR_PATH "No such file or directory\n"
extern char **environ;

/**
 * struct list_s - linked list of variables
 * @value: value
 * @next: pointer to next node
 *
 * Description: generic linked list struct for variables.
**/
typedef struct list_s
{
	char *value;
	struct list_s *next;
} list_s;

/**
 * struct built_s - linked list of builtins
 * @name: name of builtin
 * @p: pointer to function
 *
 * Description: struct for builtin functions.
**/
typedef struct built_s
{
	char *name;
	int (*p)(void);
} built_s;

char **arrOfCmd_handler(char *str);
int child(char *fullpath, char **tokens);
void errors(int error);
char *handle_path(char *cmd);

void _puts(char *str);
int str_len(char *s);
int str_cmp(char *name, char *variable, unsigned int length);
int str_ncmp(char *name, char *variable, unsigned int length);
char *str_cpy(char *dest, char *src);


char *get_env(const char *name);
char **copy_env(char **environ_copy, unsigned int environ_length);
list_s *pathlist(char *variable, list_s *head);

void free_dp(char **array, unsigned int length);
void free_all(char **cmd, char *line, char *full_path, int x);


char *read_line(void);
char **arrOfCmd(char *line);
void handle_printenv(char **cmd, int *status);
void cd_builtin(char **cmd, int *status);
void exitshell_handler(char **cmd, int *sts);
void handle_builtin(char **cmd, char **argv, int *status, int index);
int is_builtin(char *cmd);
void freeArr(char **arr);
void handle_error(char *name, char *cmd, int i);
char *handle_itoa(int x);
void revstr_handler(char *str, int len);
void _puts(char *str);

#endif /* SHELL_H */
