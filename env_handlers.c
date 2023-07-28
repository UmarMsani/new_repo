#include "shell.h"

/**
 * get_key - A function that gets the value of our environment variable.
 *
 * @mykey: The variable of interest.
 * @data: The pointer to our programs data.
 *
 * Return: A pointer to the value of our enviroment variable, otherwise
 * NULL if it error.
 */

char get_key(char *mykey, Cdata *data)
{
	int a, key_len = 0;

	if (mykey == NULL || data->env == NULL)
		return (NULL);

	key_len = string_len(mykey);

	for (a = 0; data->env[a]; a++)
	{
		if (str_compare(mykey, data->env[a], key_len) &&
		data->env[a][key_len] == '=')
		{
				return (data->env[a] + key_len + 1);
		}
	}
		return (NULL);
}


/**
 * print_env_data - A function that prints the environment we are currently in.
 *
 * @data: A pointer to our porgrams struct data.
 *
 * Return: Nothing.
 */

void print_env_data(Cdata *data)
{
	int index;

	for (index = 0; data->env[index]; index++)
	{
		printing_to_fd(data->env[index]);
		printing_to_fd("\n");
	}
}


/**
 * delete_key_env - A function that removes a key from our environment.
 *
 * @key: The key to be removed.
 *
 * @data: A pointer to out programs struct data.
 *
 * Return: 1 if the key was removed Succesfully, otherwise 0 if error.
 */

int delete_key_env(char *key, Cdata *data)
{
	int index, key_len = 0;

	if (key == NULL || data->env == NULL)
	{
		return (0);
	}

	key_len = string_len(key);

	for (index = 0; data->env[index]; index++)
	{
		if (str_compare(key, data->env[index], key_len) &&
				data->env[index][key_len] == '=')
		{
			free(data->env[index]);
			index++;

			for (; data->env[index]; index++)
			{
				data->env[index - 1] = data->env[index];
			}

			data->env[index - 1] = NULL;
			return (1);
		}
	}
	return (0);
}


/**
 * set_key - This function will overwrite the value of our environment
 * variable,
 * otherwise it will create it if it does not exist.
 *
 * @key: The name of the environment variable to set.
 * @v: The new value assigned to the environment variable.
 * @data: A pointer to the programs data struct.
 *
 * Return: Returns 1 if a parameter = NULL, 2 if error, otherwise 0 if Success.
 */

int set_key(char *key, char *v, Cdata *data)
{
	int a, key_len = 0, new_key = 1;

	if (key == NULL || v == NULL || data->env == NULL)
		return (1);

	key_len = string_len(key);

	for (a = 0; data->env[a]; a++)
	{
		if (str_compare(key, data->env[a], key_len) &&
				data->env[a][key_len] == '=')
		{
			new_key = 0;
			free(data->env[a]);
			break;
		}
	}

	data->[a] = str_concat(str_dup(key), "=");
	data->env[a] = str_concat(data->env[a], v);

	if (new_key)
	{
		data->env[a + 1] = NULL;
	}
	return (0);
}
