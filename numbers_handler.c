#include "shell.h"

/**
 * intlong_to_str - A function that converts a number to a string.
 *
 * @num: The number converted to a string.
 * @str: Where the string is saved.
 * @base: Base to convert to a number.
 *
 * Return: Void.
 */

void intlong_to_str(long num, char *str, int base)
{
	int i = 0;
	int neg = 0;
	char letters[] = "0123456789abcdef";

	if (num == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return;
	}

	if (num < 0)
	{
		neg = 1;
		num = -num;
	}

	while (num)
	{
		str[i++] = letters[num % base];
		num /= base;
	}

	if (neg)
	{
		str[i++] = '-';
	}
	str[i] = '\0';
	str_rev(str);
}

/**
 * count_occurances - A function that takes a string and a target character
 * as input.
 *
 * @str: A pointer to the string origin.
 * @target: The string with characters to be counted.
 *
 * Return: Number of occurances.
 */

int count_occurances(const char *str, char target)
{
	int num = 0;

	while (*str)
	{
		if (*str == target)
		{
			num++;
		}
		str++;
	}
		return (num);
}

/**
 * _atoi - A function that converts a string to an integer.
 *
 * @string: A pointer to the string origin.
 *
 * Return: The integer of a string, otherwise 0.
 */

int _atoi(const char *string)
{
	int s = 1;
	unsigned int num = 0;

	while (*string == '-' || *string == '+')
	{
		if (*string == '-')
		{
			s *= -1;
		}
			string++;
	}

	while (*string >= '0' && *string <= '9')
	{
		num = (num * 10) + (*string - '0');
		string++;
	}

	return ((int)(num * s));
}




