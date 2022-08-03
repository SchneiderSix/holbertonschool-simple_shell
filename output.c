#include "nice_header.h"

/**
 * pfError - print error
 * @av: a
 * @count: a
 * @firstOne: a
 * @message: a
 * Return: nothing
 */
void pfError(char *av, char *count, char *firstOne, char *message)
{
	char *dd = ": ";

	print_error(av);
	print_error(dd);
	print_error(count);
	print_error(dd);
	print_error(firstOne);
	print_error(dd);
	print_error(message);
}

/**
 * print_error - print error aux
 * @str: string
 * Return: nothing
 */
void print_error(char *str)
{
	_puts(STDERR_FILENO, str);
}

/**
 * _puts - prints a string in stdout followed by a new line
 * @fd: dile descriptor
 * @str: string
 * Return: nothing
 */
void _puts(int fd, char *str)
{
	char *t;
	int len = 0;

	for (t = str; *t != '\0'; t++)
		len++;
	write(fd, str, len);
}

