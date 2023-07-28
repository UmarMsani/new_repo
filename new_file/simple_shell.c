#include "shell.h"
#define MAX_LENGTH 1024

/**
 * execute_command - Function that takes an argument from the user
 * and executes it in our shell.
 *
 * @command: The command argument given by the user in the prompt.
 *
 * Return: Always 0 (Success)
 */

void execute_command(const char *command)
{
	pid_t pid;
	char *args[MAX_ARGS];
	int process;

	parse_arguments(command, args);

	/* Check if the command exists before forking*/

	pid = fork();
	if (pid == -1)
	{
		perror("Fork failed");
		printf("\n");
		exit(EXIT_FAILURE);
	} else if (pid == 0)
	{
		execvp(args[0], args);
		perror("command failed");
		exit(EXIT_FAILURE);
	} else
	{
		waitpid(pid, &process, 0);
		if (WIFEXITED(process) && WEXITSTATUS(process) == EXIT_FAILURE)
		{
			fprintf(stderr, "Command '%s' not found\n", command);
		}
	}
}

/**
 * main - Entry point of our program.
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	char command[MAX_LENGTH];
	int operating = 1;

	int is_interactive = isatty(fileno(stdin));

	while (operating)
	{
		print_prompt(is_interactive);
		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			operating = 0;
			continue;
		}
		command[strcspn(command, "\n")] = '\0';

		if (strcmp(command, "exit") == 0)
		{
			operating = 0;
		}
		else
		{
			execute_command(command);
		}
	}
	return (0);
}
