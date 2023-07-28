#include "shell.h"

/**
 * compare_strings - Helper function to compare strings for qsort.
 * @a: Pointer to the first string.
 * @b: Pointer to the second string.
 * Return: Integer less than, equal to, or greater than zero if the first
 *         string is found, respectively, to be less than, to match, or be
 *         greater than the second.
 */
int compare_strings(const void *a, const void *b)
{
	return (strcmp(*(const char **)a, *(const char **)b));
}

/**
 * get_environment - Function to get the current environment variables.
 * Return: A sorted array of strings containing the environment variables,
 *         or NULL if the environment is empty.
 */
char **get_environment(void)
{
	/* The environment variables are accessible through 'environ' var*/
	size_t num_vars = 0;
	char **env = environ;
	size_t i;
	char **env_sorted;

	/* Count the number of environment variables */
	while (*env != NULL)
	{
		num_vars++;
		env++;
	}

	if (num_vars == 0)
	{
		return (NULL); /* Environment is empty */
	}

	/* Create an array to store the environment variables */
	env_sorted = malloc((num_vars + 1) * sizeof(char *));
	if (env_sorted == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}

	/* Copy the environment variables to the array */
	env = environ; /* Reset the pointer to the beginning of the environment*/
	for (i = 0; i < num_vars; i++)
	{
		env_sorted[i] = environ[i];
	}

	/* Sort the environment variables in alphabetical order */
	qsort(env_sorted, num_vars, sizeof(char *), compare_strings);
	env_sorted[num_vars] = NULL; /* Add NULL terminator to the array */

	return (env_sorted);
}

/**
 * free_environment - Function to free memory allocated for enviro array.
 * @env: The sorted array of environment variables.
 */
void free_environment(char **env)
{
	free(env);
}
