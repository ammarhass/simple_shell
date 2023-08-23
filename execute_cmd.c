#include "main.h"
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));

}

/**
 * print - print digit
 * @n: number of digit
 * Return: void
 */

void print(unsigned long n)
{

	if (n / 10)
	{
		print(n / 10);
	}

	_putchar(n % 10 + '0');
}

/**
 * exec_cmd - execute the command
 *
 * @arr: array of strings that takes from the getline
 * @argv: array of C-style strings
 * @count: number of command that have been executed
 *
 * Return: Nothing
 */

void exec_cmd(char **arr, char **argv, int count)
{
	char *Command;
	pid_t pid;
	int state;

	pid = fork();
	if (pid == -1)
	{
		perror("Error\n");
		exit(0);
	}
	if (pid == 0)
	{
		Command = Check_Command(arr[0]);
		if (Command)
			execve(Command, arr, NULL);
		else
		{
			write(1, argv[0], _strlen(argv[0]));
			write(1, ": ", 2);
			print(count);
			write(1, ": ", 2);
			write(1, arr[0], _strlen(arr[0]));
			write(1, ": not found\n", _strlen(": not found\n"));
		}
		if (Command != NULL)
			free(Command);
		exit(0);
	}
	else
	{
		wait(&state);
	}
	free(arr);
	arr = NULL;
}
