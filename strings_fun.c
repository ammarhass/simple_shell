#include"main.h"

/**
 * _strcat - function that concatenates two strings
 * @dest: pointer to the first string
 * @src: pointer to the second string
 * Return: pointer to the concatenates string
 */

char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;
	int l1 = 0, l2 = 0, t_len = 0;

	for (l1 = 0; dest[l1] != '\0'; l1++)
	{}
	for (l2 = 0; src[l2] != '\0'; l2++)
	{}

	t_len = l1 + l2;

	for (i = l1; i < t_len; i++)
	{
		dest[i] = src[j++];
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strlen - get the length of a string using pointer
 * @s: pointer to char
 * Return: length of a string
 */

int _strlen(char *s)
{
	int k;

	for (k = 0; s[k] != '\0'; k++)
	{}

	return (k);
}

/**
 * _cmp - function that compares two strings
 * @s1: pointer to the first string
 * @s2: pointer to the second string
 * Return: int
 */

int _cmp(const char *s1, const char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	if (s1[i] != s2[i])
		return  (1);

	return (0);
}

/**
 * _strcpy - function that copies the string pointed to by src,
 * including the terminating null byte (\0),
 * to the buffer pointed to by dest
 * @dest: pointer to char
 * @src: pointer to char
 * Return: pointer to char
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0, j = 0;

	while (src[i] != '\0')
	{
		dest[j++] = src[i++];
	}
	dest[j] = src[i];
	return (dest);
}

/**
 * _strlen_recursion - function that returns the length of a string
 *
 * @s: pointer to char
 * Return: length of the string
 */

int _strlen_recursion(char *s)
{

	if (*s)
	{
		return (1 + _strlen_recursion(++s));
	}

	else
		return (0);

}
