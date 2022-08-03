#include "nice_header.h"

/**
 * main - Dear shell
 * @argc: argument count
 * @argv: argument vector, array of character pointers
 * listing all the arguments
 * Return: nothing
 */
int main(int argc, char **argv)
{
	int status = 0;

	(void) argc;
	status = shellLoop(argv);

	return (status);
}

