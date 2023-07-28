#include "shell.h"

/**
 * main - Entry Point.
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	char line_input[1024];
	char *arguments[64];
	int index = 0;

	while (1)
	{
		printf("$ ");
		fflush(stdout);


		if (fgets(line_input, sizeof(line_input), stdin) == NULL)
			break;


	line_input[strcspn(line_input, "\n")] = '\0';

	if (strlen(line_input) > 0)
	{
		char *command = strtok(line_input, " ");

		while (command != NULL)
		{
			arguments[index++] = command;
			command = strtok(NULL, " ");
		}

		arguments[index] = NULL;

		execute_command_with_args(arguments[0], arguments);
	}
	if (strcmp(command, "exit") == 0)
	{
		exit_bulitin();
	}
	}
	return (0);
}


