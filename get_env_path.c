#include "nice_header.h"

/**
 * _getenv - getenv recreation
 * @name: char, used for path
 * Return: null or string with the value of
 * the requested environment variable
 */
char *_getenv(const char *name)
{
	int i, j;
	int status;

	for (i = 0; environ[i] != NULL; i++)
	{
		status = 1;
		for (j = 0; environ[i][j] != '='; j++)
		{
			if (name[j] != environ[i][j])
			{
				status = 0;
				break;
			}
		}

		if (status)
		{
			return (&environ[i][j + 1]);
		}
	}
	return (NULL);
}

/**
 * _getpathdir - put tokens in list
 * @path: string with the value of
 * the requested environment variable
 * @pathCopy: a
 * Return: a
 */
Node *_getpathdir(char *path, char **pathCopy)
{
	char *token = NULL;
	Node *head;
	Node *pathNode;
	char *delim = ":\0"; /* null char*/


	if (path == NULL)
		return (NULL);

	*pathCopy = _strdup(path); /* free on shellLoop() */

	head = NULL;
	pathNode = malloc(sizeof(Node));
	if (pathNode == NULL)
		return (NULL);

	token = strtok(*pathCopy,  delim);
	pathNode->str = token;
	pathNode->next = head;
	head = pathNode;
	while (token != NULL)
	{
		token = strtok(NULL, delim);
		if (token == NULL) /* don't save token NULL in list */
			break;
		pathNode = malloc(sizeof(Node));
		if (pathNode == NULL)
			return (NULL);
		pathNode->str = token;
		pathNode->next = head;
		head = pathNode;
	}
	return (head);
}


/**
 * listpath - Return a linked list of all directories of path
 * @pathCopy: path
 * Return: linked list
 */
Node *listpath(char **pathCopy)
{
	char *getEnv;
	Node *pathDirs = NULL;

	getEnv = _getenv("PATH");
	if (*getEnv == '\0')
		return (NULL);
	pathDirs = _getpathdir(getEnv, pathCopy);

	return (pathDirs);
}

