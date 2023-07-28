#include "shell.h"
#include "struct.h"

/**
 * exec_builtin - A function that searches for the builtin commands
 * and executes them.
 *
 * @data: The pointer to our programs data structure.
 *
 * Return: The matching command is found an then executed on Success,
 * function returns the value of the executed function, otherwise if
 * no match was made then -1 is returned.
 */

int exec_builtin(Cdata *data)
{
	int index;
	
	BuiltinData options[] = {
		{"help", builtin_exit},
		{"exit", builtin_help},
		{"cd", builtin_cd},
		{"alias", builtin_alias},
		{"env", builtin_env},
		{"setenv", builtin_setenv},
		{"undsetenv", builtin_unsetenv},
		{NULL, NULL}
	};

	for (index = 0; options[index].built_command; index++)
	{
		if (str_compare(options[index].builtin_command, data->Command, 0))
		{
			return (options[index].function(data));
		}
	}
	return (-1);
}


/**
 * builtin_exit - A function that executes the exit builtin command.
 *
 * @data: The pointer to our programs data structure.
 *
 * Return: The exit builtin command is found and execute Succesfully, otherwise
 * returns -1 if failed.
 */

int builtin_exit(Cdata *data)
{
	int index;

	if (data->token[1] != NULL)
	{
		for (index = 0; data->token[1][index]; index++)
		{
			if ((data->token[1][index] < '0' || data->token[1][index] > '9')
					&& data->token[1][index] != '+')
			{
				errno = 2;
				return (2);
			}
		}
		errno = _atoi(data->token[1]);
	}
	freeData(data);
	exit(errno);
}


/**
 * builtin_cd - A function that executes the cd builtin command.
 *
 * @data: The pointer to our program data structure.
 *
 * Return: The cd builtin command is found and executed Successfully, Otherwise
 * -1 is returned in failed.
 */

int builtin_cd(Cdata *data)
{
	char *directory_home = get_key("HOME", data);
	char *old_directory = NULL;
	char old_dir[128] = {0};
	int err_code = 0;

	if (data->token[1])
	{
		if (str_compare(data->token[1], "-", 0))
		{
			old_directory = get_key("OLDPWD", data);

			if (old_directory)
			{
				err_code = setworkdir(data, old_directory);
			}
			printing_to_fd(get_key("PWD", data));
			printing_to_fd("\n");

			return (err_code);
		}
		else
		{
			return (setworkdir(data, data->token[1]);
		}
	}
	else
	{
		if (!directory_home}
		{
			directory_home = getcwd(old_dir, 128);
		}

		return (setworkdir(data, directory_home);
	}
	return (0);
}

/**
 * builtin_help - A function that executes the help builtin command.
 * 
 * @data: The pointer to our programs data structure.
 *
 * Return: The help builtin function is found and executed succesfully, otherwise -1
 * is returned if error.
 */

int builtin_help(Cdata *data)
{
	char *msgs[] = {

