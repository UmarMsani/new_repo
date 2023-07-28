#include "shell.h"
#include "struct.h"

/**
 * freeData - This function frees all fields of our Data.
 *
 * @data: A pointer to our programs data.
 *
 * Return: void.
 */

void freeData(Cdata *data)
{
	if (data->fd != 0)
	{
		if (close(data->fd))
			perror(data->my_program);
	}

	freeRepeatedData(data);
	freeArrayPointers(data->env);
	freeArrayPointers(data->alias);
}


/**
 * free_repeated_data - A function that frees the fields needed in loops.
 *
 * @data: A pointer to our programs struct data.
 *
 * Return: void.
 */

void free_repeated_data(Cdata *data)
{
	if (data->tokens)
		free_pointers_array(data->tokens);

	if (data->Input)
		free(data->Input);

	if (data->Command)
		free(data->Command);

	data->Input = NULL;
	data->Command = NULL;
	data->tokens = NULL;
}

/**
 * free_pointers_array - A function that frees each array of pointers.
 *
 * @ptr_array: The array of pointers.
 *
 * Return: Void.
 */

void free_pointers_array(char **ptr_array)
{
	int index;

	if (ptr_array == NULL)
	{
		return;
	}

	for (index = 0; ptr_array[index] != NULL; index++)
	{
		free(ptr_array[index];
		ptr_array[index] = NULL;
	}

	free(ptr_array);
}


