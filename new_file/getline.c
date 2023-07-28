#include "shell.h"

/**
 * custom_getline - Custom implementation of getline function.
 *
 * Return: A pointer to the line read (including the newline character) or NULL
 *         if there is no more input (EOF) or an error occurs.
 */
char *custom_getline(void)
{
	static char buffer[BUFFER_SIZE];
	static size_t buffer_index = 0;
	static ssize_t buffer_read_size = 0;

	char *line = NULL;
	size_t line_index = 0;

	while (1)
	{
		/* If buffer is empty, read more data from the input */
		if (buffer_index >= (size_t)buffer_read_size)
		{
			buffer_read_size = read(STDIN_FILENO, buffer, BUFFER_SIZE);
			buffer_index = 0;

			/* If read returns 0 (end of file) or an error, return NULL */
			if (buffer_read_size <= 0)
			{
				if (line_index == 0)
				{
					return (NULL); /* No more data to read */
				}
				else
				{
					break; /* Return the line read so far */
				}
			}
		}

		/* Copy characters from buffer to line until newline or end of buffer */
		while (buffer_index < (size_t)buffer_read_size)
		{
			if (buffer[buffer_index] == '\n')
			{
				buffer_index++; /* Skip the newline character */
				break;
			}
			if (line_index == 0)
			{
				/* Allocate memory for the line if it's the first character */
				line = (char *)malloc(BUFFER_SIZE);
				if (!line)
				{
					perror("Memory allocation failed");
					exit(EXIT_FAILURE);
				}
			}
			else if (line_index % BUFFER_SIZE == 0)
			{
				/* Reallocate memory for the line if needed */
				char *temp = (char *)realloc(line, line_index + BUFFER_SIZE);
				if (!temp)
				{
					free(line);
					perror("Memory allocation failed");
					exit(EXIT_FAILURE);
				}
				line = temp;
			}

			line[line_index++] = buffer[buffer_index++];
		}
	}

	/* Null-terminate the line */
	if (line)
	{
		line[line_index] = '\0';
	}

	return (line);
}
