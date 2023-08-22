#include "main.h"

/**
 * divide_string - function to divide a string
 * into small strings depend on a delimiter
 *
 * @buf: string to divide
 * @delimiter: delimiter
 * Return: pointer to pointer to char
 */

char **divide_string(char *buf, char *delimiter)
{
	char *tok;
	char **toks;
	int k = 0;

	toks = malloc(sizeof(char *) * 40);
	if (toks == NULL)
		return (NULL);

	tok = strtok(buf, delimiter);

	while (tok)
	{
		toks[k] = tok;
		tok = strtok(NULL, delimiter);
		k++;
	}
	toks[k] = NULL;

	return (toks);
}
