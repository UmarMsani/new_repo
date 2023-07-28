#include "shell.h"

/**
 * string_len - A function that returns the length of a string.
 *
 * @str: Pointer to String.
 *
 * Return: Length of the String.
 */

int string_len(char *str)
{
	int len = 0;

	while (str[len] != '\0')
	{
		len++;
	}

	return (len);
}

/**
 * str_compare - A function that takes 2 strings and compares them.
 *
 * @str_1: First String.
 * @str_2: Second String.
 *
 * Return: 0 if strings are eqaul, negative if string 1 < string 2 and
 * positive if String 1 > String 2.
 */

int str_compare(const char *str_1, const char *str_2)
{
	while (*str_1 && *str_2)
	{
		if (*str_1 != *str_2)
		{
			return (*str_1 - *str_2);
		}
		str_1++;
		str_2++;
	}
	return (*str_1 - *str_2);
}

/**
 * str_dup - A function that duplicates a string.
 *
 * @string: A pointer to the string to be copied.
 *
 * Return: A pointer to the original copy.
 */

char *str_dup(const char *string)
{
	size_t len = strlen(string);

	char *duplicate = malloc(len + 1);

	if (duplicate == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	strcpy(duplicate, string);
	return (duplicate);
}

/**
 * str_concat - A function that concatenates 2 strings.
 *
 * @str_1: First string.
 * @str_2: Second string.
 *
 * Return: A pointer to the concatenated string.
 */

char *str_concat(const char *str_1, const char *str_2)
{
	size_t len1 = strlen(str_1);
	size_t len2 = strlen(str_2);

	char *concat = malloc(len1 + len2 + 1);

	if (concat == NULL)
	{
		fprintf(stderr, "Memory allocation Failed.\n");
		exit(EXIT_FAILURE);
	}

	strcpy(concat, str_1);
	strcpy(concat, str_2);

	return (concat);
}

/**
 * str_rev - A function that Revereses a string.
 *
 * @string: A pointer to the string that will be reveresed.
 *
 * Return: A pointer to the string that is reveresed.
 */

void str_rev(char *string)
{
	int begin = 0;
	int finish = strlen(string) - 1;

	while (begin < finish)
	{
		char temp = string[begin];

		string[begin] = string[finish];
		string[finish] = temp;
		begin++;
		finish--;
	}
}
