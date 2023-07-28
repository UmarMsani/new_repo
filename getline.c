#include "shell.h"
#include "struct.h"

/**
 * read_input - A function that will read the line provided in the prompt.
 *
 * @data: A pointer to the programs data.
 *
 * Return: The count of Bytes provided in our prompt.
 */

int read_input(Cdata *data)
{
	ssize_t bytes, index = 0;

	static char *arrayCommands[10] = {NULL};
	static char operatorsArray[10] = {'\0'};

	char buff[BUFFER_SIZE] = {'\n'};

	char op = operatorsArray[0];

	if (!arrayCommands[0] || (op == '&' errno != 0) || (op == '|' && errno == 0))
	{
		for (index = 0; arrayCommand[index]; index++)
		{
			free(arrayCommands[index]);
			arrayCommands[index] = NULL;
		}
		bytes = read(data->fd, &buff, BUFFER_SIZE - 1);

		if (bytes == 0)
			return (-1);

		index = 0;

		do {
			arrayCommands[index] = str_dup(custom_strtok(index ? NULL : buff, "\n;"));
			index = operator_check(arrayCommands, index, operatorsArray);
		} while (arrayCommands[index++]);
	}
		data->Input = arrayCommands[0];

		for (index = 0; arrayCommands[index]; i++)
		{
			arrayCommands[index] = arrayCommands[index + 1];

			operatorsArray[index] = operatorsArray[index + 1];
		}
		return (string_len(data->Input));
}


/**
 * operator_check - A fucntion that checks and splits for && and || operators.
 *
 * @arrayCommands: The array of commands.
 * @index: The Index in the array of commands to be checked.
 * @operatorsArray: The array of logical operators for each command prior.
 *
 * Return: The index of the previous command in the array.
 */

int operator_check(char *arrayCommands[], int index, char operatorsArray[])
{
	char *temp = NULL;
	int a;

	for (a = 0; arrayCommands[index] != NULL && arrayCommands[index][a]; a++)
	{
		if (arrayCommands[index][a] == '&' && arrayCommands[index][a + 1] == '&')
		{
			temp = arrayCommands[index];
			arrayCommands[index][a] = '\0';
			arrayCommands[index] = str_dup(arrayCommands[index]);
			arrayCommands[index + 1] = str_dup(temp + a + 2);
			index++;
			operatorsArray[index] = '&';
			free(temp);
			a = 0;
		}

		if (arrayCommands[index][a] == '|' && arrayCommands[index][a + 1] == '|')
		{
			temp = arrayCommands[index];
			arrayCommands[index][a] = '\0';
			arrayCommands[index] = str_dup(arrayCommands[index]);
			arrayCommands[index + 1] = str_dup(temp + a + 2);
			index++;
			operatorsArray[index] = '|';
			free(temp);
			a = 0;
		}
	}
	return (index);
}




