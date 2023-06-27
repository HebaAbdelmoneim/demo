#ifndef SHELL_H
#define SHELL_H

/* header files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <dirent.h>
#include <ctype.h>

/* definitions */
#define BUFFER_SIZE 1024
#define COMMAND_NO 0

/* write functions (_put.c) */

int _putchar(char c);
void _putstr(char *str);

/* str functions (string1.c) */

int _strlen(char *str);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, unsigned int n);
char *_strcpy(char *dest, char *src);

/* str functions (string2.c) */

unsigned int _strcspn(char *str, char *rejc);

/* itoa functions (itoa.c) */

void rev_string(char *s);
char *_itoa(int n, char *str, int base);

/* environment functions (env.c) */

char *_getenv(char *envp[], char *var);
void print_env(char *envp[]);


/* input functions (handle_input.c) */

char *_getline(void);
char **get_tokens(char *command);


/* handle functions (handle_functions.c) */

void  get_process(char *envp[], char *cmd, char *args[]);
int is_builtin_command(char *cmd);
void handle_error(char *arg, int entry, char * cmd, char *err);
void handle_cd(char *arg, char *envp[]);

/* helping functions (helping.c) */

void display_prompt(void);
unsigned int command_start_message(char *str, unsigned int n);

#endif /*SHELL_H*/
