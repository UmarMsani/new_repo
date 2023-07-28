#include "shell.h"

/**
 * parse_arguments - Function that parses the command line and extracts
 * the command and its arguments.
 *
 * @command: The command argument given by the user in the prompt.
 * @args: Array to store the command and its arguments.
 */

void parse_arguments(const char *command, char *args[])
{
	char *token;
	int i = 0;

	/* Parse the command and its arguments*/
	token = strtok((char *)command, " ");
	while (token != NULL && i < MAX_ARGS - 1)
	{
		args[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	args[i] = NULL;
}
