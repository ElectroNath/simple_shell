#ifndef _MAIN_H_
#define _MAIN_H_
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <dirent.h>
#include <limits.h>
#include <string.h>

extern char **environ;

char *show_input(void);
void shell_prompt(void);
char *_strcat(char *src);
int _strlen(char *str);
void place(char *str);
char *findfile(char *command);
char *discover_command(char *command);
int compare(char *s1, char *s2);
int _strcmprdir(char *s1, char *s2);
int char_put(char c);
void puter(char *str);
char *str_concat(char *s1, char *s2);
int findslash(char *cmd);
int findslashExit(char *s1, char *s2);
int findslashEnv(char *s1, char *s2);
void execute(char **cmd);
char **keysInit(char *parameter);
void ctrlC(int sig);
#endif
