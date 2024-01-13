#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

/*defining xxxx*/

#define BUFFER 1024
#define TRUE 1
#define PROMPT "$ "
/* strings for handling errors */

#define ERR_MALLOC "Unable to malloc space\n"
#define ERR_FORK "Unable to fork and create child process\n"
#define ERR_PATH "No such file or directory\n"
extern char **environ;

/**
 * struct list_s - a linked list
 * @value: the val
 * @next: points to the next node
 * Description: a struct for a linked list
**/
typedef struct list_s
{
	char *value;
	struct list_s *next;
} list_s;


char **arrOfCmd_handler(char *str);
int execute_handler(char *full_path, char **cmd);
void errors(int error);
char *handle_path(char *cmd);

void _puts(char *str);
int str_len(char *str);
int str_cmp(char *name, char *variable, unsigned int length);
int str_ncmp(char *str1, char *str2, unsigned int len);
char *str_cpy(char *dest, char *src);


char *get_env(const char *name);
char **copy_env(char **environ_copy, unsigned int environ_length);
list_s *pathlist(char *variable, list_s *head);

void free_dp(char **array, unsigned int length);
void handle_free(char **cmd, char *line, char *full_path, int x);


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

#endif
