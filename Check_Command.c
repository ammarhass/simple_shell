#include "main.h"

/**
 * bring_env - function that returns the value of the environment variable
 *
 * @check_env: the environment variable
 * Return: value of the envirnment varivable or NULL
 */

char *bring_env(const char *check_env)
{
	char *str;
	size_t k = 0;

	while (environ[k])
	{
		str = strtok(environ[k], "=");
		if (_strcmp(check_env, str) == 0)
			return (strtok(NULL, "\n"));

		k++;
	}
	return (NULL);
}

/**
 * print_env - function to print the environment variable
 *
 * Return: Nothing
 */

void print_env(void)
{
	size_t k = 0;

	while (environ[k])
	{
		printf("%s\n", environ[k++]);
	}
}

/**
 * Check_Command - function to check if the command exist or not
 *
 * @command: command to check
 * Return: full command or NULL
 */

char *Check_Command(char *command)
{
	struct stat st;
	char *full_command;
	char *tok;
	char *full_path = bring_env("PATH");

	tok = strtok(full_path, ":");

	if (stat(command, &st) == 0)
		return (command);

	while (tok)
	{
		full_command = (char *)malloc(strlen(command) + 2 + strlen(tok));
		if (full_command == NULL)
			return (NULL);

		_strcpy(full_command, tok);
		_strcat(full_command, "/");
		_strcat(full_command, command);

		if (stat(full_command, &st) == 0)
		{
			return (full_command);
		}

		free(full_command);
		tok = strtok(NULL, ":");
	}
	return (NULL);
}

