#include "nice_header.h"

/**
 * addPath - get and check if the command is available
 * @tokens: explicit name
 * @path: explicit name
 * Return: pointer to the filename
 */
char *addPath(char ***tokens, Node *path)
{
	Node *pathDirs;
	struct stat st;
	char *firstOne, *copyPath = NULL;
	int lenOne, lenTwo;

	if (*tokens == NULL)
		return (NULL);

	pathDirs = path;
	if (pathDirs == NULL)
		return (NULL);

	firstOne = *(tokens)[0];
	lenOne = _strlen(firstOne);

	while (pathDirs != NULL)
	{
		lenTwo = _strlen(pathDirs->str);
		copyPath = malloc((lenTwo + lenOne + 2) * sizeof(char));
		if (copyPath == NULL)
			return (NULL);
		*copyPath = '\0'; /* Initialized value with null char */
		_strcat(copyPath, pathDirs->str);
		_strcat(copyPath, "/");
		_strcat(copyPath, firstOne);
		if (stat(copyPath, &st) == 0)
			break;

		free(copyPath);
		copyPath = NULL;
		pathDirs = pathDirs->next;
	}
	return (copyPath);

}
/**
 * processTokens - get all of the strings separated by a delimiter in
 * an array of strings
 * @tokens: explicit name
 * @buffer: explicit name
 * @countToken: explicit name
 *
 * Return: nothing
 */
void processTokens(char ***tokens, char **buffer, int countToken)
{
	char *token = NULL;
	char *delim = " \n\t";
	int i;

	*tokens = malloc(sizeof(char *) * countToken);
	token = strtok(*buffer, delim);
	for (i = 0; token != NULL; i++)
	{
		(*tokens)[i] = token;
		token = strtok(NULL, delim);
	}
	(*tokens)[i] = token; /*Save the NULL token*/
}

/**
 * lenTokens - get the number of words separated by a delimiter
 * @lenReaded: size
 * @buffer: explicit name
 * Return: int words in buffer
 */
int lenTokens(ssize_t lenReaded, char **buffer)
{
	char *tempToken = NULL, *copyBuffer = NULL;
	char *delim = " \n\t";
	int i;

	copyBuffer = malloc(sizeof(char) * lenReaded);
	_strcpy(copyBuffer, *buffer);
	tempToken = strtok(copyBuffer, delim);
	for (i = 0; tempToken != NULL; i++)
		tempToken = strtok(NULL, delim);
	i++; /* One more to save NULL */
	free(copyBuffer);
	return (i);
}

/**
 * replaceNewLine - replace the new line in the buffer
 * by a null character
 * @buffer: explicit name
 * Return: nothing
 */
void replaceNewLine(char **buffer)
{
	int i;

	for (i = 0; (*buffer)[i] != '\0'; i++)
		continue;
	(*buffer)[i - 1] = '\0';  /* Replace '\n' by '\0' */

}


/**
 * readLine - Get and process the data in the stdin
 * @buffer: explicit name
 * @tokens: explicit name
 * Return: number of chars readed in stdin
 */
ssize_t readLine(char **buffer, char ***tokens)
{
	size_t bufferSize = 0;
	ssize_t gl;
	int countToken, i;

	*tokens = NULL;
	gl = _getline(buffer, &bufferSize, stdin);

	if (gl > 0)
	{
		i = 0;
		while ((*buffer)[i] == ' ' || (*buffer)[i] == '\t')
		{
			if ((*buffer)[i + 1] == '\n')
				return (gl);
			i++;
		}
	}

	if (gl > 0 && **buffer != '\n')
	{
		replaceNewLine(buffer);
		countToken = lenTokens(gl, buffer);
		processTokens(tokens, buffer, countToken);
		isBasicExit(tokens, countToken, &gl);
		isEnv(tokens, countToken);
	}

	return (gl);
}

