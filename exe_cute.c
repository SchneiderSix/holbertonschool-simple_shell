#include "nice_header.h"

/**
 * executeLine - exeutes the command entered in the child process
 * @buffer: explicit name
 * @tokens: explicit name
 * @fullPath: n
 * @st: status of error
 * Return: 1 suc -1 fail
 */
int executeLine(char **buffer, char ***tokens, char *fullPath, int *st)
{
	int parent, exe, status;

	if (*tokens == NULL)
	{
		return (1);
	}
	if (**buffer == '\n' || fullPath == NULL)
	{
		free(*tokens);
		return (1);
	}
	parent =  fork();
	if (parent == -1)
	{
		perror("Failed to fork");
		return (-1);
	}
	if (parent == 0)
	{	/*exeute line func (*tokens)[0]*/
		exe = execve(fullPath, *tokens, environ);
		if (exe == -1)
		{

			free(*tokens);
			free(*buffer);
			exit(99);
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			*st = WEXITSTATUS(status); /*status code of the child*/
	}
	free(*tokens);
	free(fullPath); /* fullPath from addPath() or isPath() */
	return (1);
}

/**
 * isPath - check the path
 * @tokens: explicit name
 * @path: explicit name
 * @argv: explicit name
 * @count: explicit name
 * @error_code: explicit name
 * Return: nothing
 */
void isPath(char ***tokens, char **path,
		char **argv, int *count, int *error_code)
{
	char *firstOne = NULL;
	char buffer[33];
	char *msg = NULL;

	if (*path != NULL || *tokens == NULL)
		return;

	firstOne = *(tokens)[0];

	if (access(firstOne, F_OK | X_OK) == 0)
	{
		*path = _strdup(firstOne);  /*This will be free in exe*/
	}
	else
	{
		if (access(firstOne, F_OK) != 0)
		{
			msg = "not found\n";
			pfError(argv[0], itoa(*count, buffer, 10), firstOne, msg);
			*error_code = 127;
		}
		else if (access(firstOne, X_OK) != 0)
		{
			msg = "Permission denied\n";
			pfError(argv[0], itoa(*count, buffer, 10), firstOne, msg);
			*error_code = 126;
		}
	}
}

/**
 * isDir - check dr access
 * @tokens: explicit name
 * @path: explicit name
 * @argv: explicit name
 * @count: explicit name
 * @error_code: explicit name
 * Return: nothing
 */
void isDir(char ***tokens, char **path,
		char **argv, int *count, int *error_code)
{
	struct stat st;
	char buffer[33];
	char *firstOne = NULL;
	char *msg = NULL;

	if (*tokens == NULL)
		return;

	firstOne = *(tokens)[0];

	if (stat(firstOne, &st) == 0)
	{
		if ((st.st_mode & S_IFMT) == S_IFDIR)
		{
			msg = "Permission denied\n";
			pfError(argv[0], itoa(*count, buffer, 10), firstOne, msg);
			*error_code = 126;

			if (*path != NULL)
			{
				free(*path);
				*path = NULL;
			}
		}
	}
}

