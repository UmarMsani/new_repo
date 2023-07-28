#include "shell.h"

/**
 * printing_to_fd - A function that writes an array of characters to a
 * specified file descriptor.
 *
 * @fd: The file descriptor to write to (STDOUT_FILENO or STDERR_FILENO)
 * @string: A pointer to the array of Characters.
 *
 * Return: The number of bytes written, otherwie -1 on error.
 */

int printing_to_fd(int fd, const char *string)
{
	return (write(fd, string, string_len(*string)));
}


/**
 * print_error_msg - A function that write an error message to the standard
 * error.
 *
 * @err_code: The error code to be printed.
 * @execute_counter: The execution as a long int.
 * @commandname: The name of the command which caused the error.
 * @arg: The additional argument for specififc errors that may occur.
 *
 * Return: The number of bytes, otherwise -1 if error occurs.
 */

int print_error_msg(int err_code, long execute_counter, const char
		*commandname, const char *arg)
{
	char execute_counterStr[10] = {'\0'};

	intlong_to_str(execute_counter, execute_counterStr, 10);

	if (err_code == 2 || err_code == 3)
	{
		printing_to_fd(STDERR_FILENO, data->program_name);
		printing_to_fd(STDERR_FILENO, ": ");
		printing_to_fd(STDERR_FILENO, execute_counterStr);
		printing_to_fd(SDERR_FILENO, ": ");
		printing_to_fd(STDERR_FILENO, data->tokens[0]);

		if (err_code == 2)
		{
			printing_to_fd(STDERR_FILENO, ": Illegal Number: ");
		}
		else
		{
			printing_to_fd(STDERR_FILENO, ": Unablle to cd to ");
		}
		printing_to_fd(STDERR_FILENO, args);
		printing_to_fd(STDERR_FILENO, "\n");
	}
	else if (err_code == 127 || err_code == 126)
	{
		printing_to_fd(STDERR_FILENO, data->program_name);
		printing_to_fd(STDERR_FILENO, ": ");
		printing_to_fd(STDERR_FILENO, execute_counterStr);
		printing_to_fd(STDERR_FILENO, ": ");
		printing_to_fd(STDERR_FILENO, commandname);

		if (err_code == 127)
		{
			printing_to_fd(STDERR_FILENO, ": Cannot be found\n");
		}
		else
		{
			printing_to_fd(STDERR_FILENO, ": Access denied\n");
		}
	}
	return (0);
}
