#include "main.h"

/**
* signal_handling - handle the signal
* @check: value of the signal
*
* Return: Nothing
*/

void signal_handling(int check)
{
	if (check == SIGINT)
	{
		write(1, "\n$ ", 3);
	}
}

/**
* main - main function (entry point)
*
* @arc: number of arguments on the command line
* @argv: array of C-style strings
* Return: 0
*/

int main(__attribute__((unused))int arc, char **argv)
{
	char *buf = NULL, **arr;
	size_t buf_size = 0;
	int i = 0, count = 1;

	signal(SIGINT, signal_handling);
	while (1)
	{
		if (isatty(STDIN_FILENO))
		write(1, "$ ", 2);
		i = getline(&buf, &buf_size, stdin);
		if (i == EOF)
		{
			free(buf);
			write(STDIN_FILENO, "\n", 1);
			exit(0);
		}
		else if (_strcmp(buf, "exit") == 0)
		{
			exit(0);
		}
		else if (_strcmp(buf, "env") == 0)
		{
			print_env();
			continue;
		}
		else
		{
			if (i > 1)
			{
				arr = divide_string(buf, " \t\n\r");
				exec_cmd(arr, argv, count);
			}
			count++;
		}
	}
	return (0);
}
