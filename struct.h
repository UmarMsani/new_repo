#ifndef STRUCT_H
#define STRUCT_H

/********** Custom Data ***********/

typedef struct 
{
	char *my_program;
	char *Input;
	char *Command;
	int execute_counter;
	int fd;
	char **env;
	char **token;
	char **alias;
} Cdata;

typdef struct 
{
	char *builtin_command;
	int (*function)(Cdata *data);
} BulitinData;

#endif /* STRUCT_H */
