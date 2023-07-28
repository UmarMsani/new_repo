#include "shell.h"
#include "struct.h"

extern const char *help_cd_msg;
extern const char *help_exit_msg;
extern const char *help_env_msg;
extern const char *help_setenv_msg;
extern const char *help_unsetenv_msg;
extern const char *help_msg;

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
        const char *help_messages[] = {
		help_msg,
		help_exit_msg,
		help_env_msg,
		help_setenv_msg,
		help_unsetenv_msg,
		help_cd_msg,
		NULL
	};

	if (data->token[1] == NULL)
	{
		printing_to_fd(help_messages[0] + 6);
		return (1);
	}

	for (index = 1; help_messages[index]; index++)
	{
		if (str_compare(data->token[1], help_messages[index], str_len(data->token[1])))
		{
			printing_to_fd(help_messages[index] + str_len(data->token[1]) + 1);
			return (1);
		}
	}

	errno = EINVAL;
	perror(data->Command);
	return (0);
}


-- INSERT -
