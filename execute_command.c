#include "shell.h"

/**
 * execute_command - Function that takes an argument from the user
 * and executes it in our shell script.
 *
 * @command: The command argument given by the user.
 *
 * Return: Always 0 (Succes)
 */

void execute_command(const char *command)
{
	int process;
	pid_t pid = fork();

	if (pid == 1)
	{
		perror("Fork Failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execlp(command, command, NULL);

		perror("Command failef");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &process, 0);

		if (WIFEXITED(process) && WEXITSTATUS(process) == EXIT_FAILURE)
		{
			fprintf(stderr, "Command %s not found\n", command);
		}
	}
}
