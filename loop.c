#include "nice_header.h"

/**
 * shellLoop - Run the shell
 * @argv: n
 * Return: nothing
 */
int shellLoop(char **argv)
{
	ssize_t getLine = 1;
	char **tokens = NULL, *buffer = NULL, *fullPath = NULL, *pathCopy = NULL;
	Node *path = NULL;
	int errorShowed = 0, counter = 1;

	path = listpath(&pathCopy);
	while (1)
	{
		fflush(stdout);
		/*if (isatty(STDIN_FILENO))
			write(1, "$", 1);*/ /*test non interactive*/
		getLine = readLine(&buffer, &tokens);
		if (getLine == EOF) /* check for EOF */
			break;
		errorShowed = 0;
		fullPath = addPath(&tokens, path);
		isPath(&tokens, &fullPath, argv, &counter, &errorShowed);
		isDir(&tokens, &fullPath, argv, &counter, &errorShowed);
		executeLine(&buffer, &tokens, fullPath, &errorShowed);
		counter++;
	}
	free_list(path); /* linked list with all the paths */
	free(pathCopy); /* free linked list of all directories of path */
	free(buffer); /* main buffer */
	return (errorShowed);
}

