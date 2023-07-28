#include "shell.h"

/**
 * check_command - A function that checks if the command provided in
 * command line exists in the PATH.
 *
 * @command: A string containing a list of the command we wish to
 * check.
 *
 * Return: Always 0 (Success)
 */

int check_command(const char *command)
{
	char *path_environment = getenv("PATH");
	char *path = strdup(path_environment);
	char *i = strtok(path, ":");
	char commandpath[1024];

	if (path_environment == NULL)
		return (0);

	while (i != NULL)
	{
	snprintf(commandpath, sizeof(commandpath), "%s/%s", i, command);

	if (access(commandpath, X_OK) == 0)
	{
		free(path);
		return (1);
	}
	i = strtok(NULL, ":");
	}

	free(path);
	return (0);
}


/**
 * execute_command_with_args - A function that executes command with
 * arguements.
 *
 * @command: A string that holds a list of the commands.
 * @arguments: An array that holds the arguments provided by the user.
 *
 * Return: Void
 */

void execute_command_with_args(const char *command, char *const
arguments[])
{
	int i;

	if (check_command(command))
	{
		pid_t pid = fork();


	if (pid == -1)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execvp(command, arguments);
		perror("Error: Execution of command failed");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &i, 0);

		if (WIFEXITED(i) && WEXITSTATUS(i) != 0)
			fprintf(stderr, "Command %s failed\n", command);
	}
	}
	else
	{
		fprintf(stderr, "Command %s not found in PATH\n", command);
	}
}

