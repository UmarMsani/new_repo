#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_LENGTH 1024
#define MAX_ARGS 50
#define BUFFER_SIZE 1024

/* Declaration of the 'environ' variable as extern */
extern char **environ;

/* Function Prototypes */
void execute_command(const char *n);
void print_prompt(int is_interactive);
void parse_arguments(const char *command, char *args[]);
void print_environment(void);

/* gtline.c */
char *custom_getline(void);

#endif
