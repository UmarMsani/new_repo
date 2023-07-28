#include "shell.h"
/**
 * print_prompt - A function that prints out the name of our prompt
 * upon entering the shell script.
 * @is_interactive: to check interactive mode
 *
 * Return: Void
 */
void print_prompt(int is_interactive)
{
	if (is_interactive)
	{
		const char prompt[] = "$ ";

		write(1, prompt, sizeof(prompt) - 1);
	}
}
