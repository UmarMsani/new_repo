#ifndef SHELL_H
#define SHELL_H

/* Required header files */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stddef.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "struct.h"


/************ Files in Simple Shell *****************/


/* Print_Handlers.c */

int printing_to_fd(int fd, const char *string);
int print_error_msg(int err_code, long execute_counter, const char
                *commandname, const char *arg);


/* Print_Prompt.c */

void print_prompt(void);


/* String_hanlders.c */

char *str_concat(const char *str_1, const char *str_2);
void str_rev(char *string);
char *str_dup(const char *string);
int str_compare(const char *str_1, const char *str_2);
int string_len(char *str);


/* Path_handler.c */

void execute_command_with_args(const char *command, char *const
arguments[]);
int check_command(const char *command);


/* Numbers_Handlers.c */

int _atoi(const char *string);
int count_occurances(const char *str, char target);
void intlong_to_str(long num, char *str, int base);


/* Execute_command.c */

void execute_command(const char *command);


/* Getline.c */

int read_input(Cdata *data);
int operator_check(char *arrayCommands[], int index, char operatorsArray[]);


/* Function prototypes */

void running_shell(void);
int parse_argument(char *input, char *arguments[]);
int resolve_commandpath(char *command, char *resolved_path);
void execute_command(char *command, char *arguments[]);

void exit_shell();
void print_environment();
