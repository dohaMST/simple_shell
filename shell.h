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

char *read_line(void);
char **tokenizer(char *line);
void freeArr2D(char **arr);
int _execute(char **cmd, char **argv, int idx);
char *_getenv(char *var);
char *_getpath(char *cmd);
void print_error(char *name, char *cmd, int idx);
void reverse_string(char *str, int len);
char *_itoa(int n);

void exit_shell(char **cmd, int *status);
void print_env(char **cmd, int *status);
void handle_builtin(char **cmd, char **argv, int *status, int index);
int is_builtin (char *command);
void _puts(char *str);
int count_tokens(const char *line);
int extract_tokens(const char *line, char **cmd);


#endif
