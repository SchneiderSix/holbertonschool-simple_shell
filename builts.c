#include "nice_header.h"


/**
 * _strcmp - Compares two strings
 * @s1: pointer to string
 * @s2: pointer to string
 * Return: value
 */
int _strcmp(char *s1, char *s2)
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

	return (0);
}

/**
 * isBasicExit - Check if get an exit
 * @tokens: explicit name
 * @count_token: explicit name
 * @size: explicit name
 * Return: nothing
 */
void isBasicExit(char ***tokens, int count_token, ssize_t *size)
{
	char *p = NULL;

	if (count_token != 2 || *tokens == NULL)
	{
		return;
	}
	p = (*tokens)[0];

	if (_strcmp(p, "exit") == 0)
	{
		*size = -1;
		free(*tokens);
		*tokens = NULL;
	}
}

/**
 * isEnv - Check if get an env
 * @tokens: n
 * @count_token: n
 * return: nothing
 */
void isEnv(char ***tokens, int count_token)
{
	char *p = NULL;
	int i;

	if (count_token != 2 || *tokens == NULL)
		return;

	p = (*tokens)[0];

	if (_strcmp(p, "env") == 0)
	{
		i = 0;
		while (environ[i])
		{
			_puts(STDOUT_FILENO, environ[i++]);
			_puts(STDOUT_FILENO, "\n");
		}
		free(*tokens);
		*tokens = NULL;
	}
}

