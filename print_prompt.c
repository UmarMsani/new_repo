#include "shell.h"

/**
 * print_prompt - A function that prints out the name of our prompt
 * upon entering the shell script.
 *
 * Return: Void
 */

void print_prompt(void)
{
	const char prompt[] = "$ ";

	write(1, prompt, sizeof(prompt) - 1);
}
