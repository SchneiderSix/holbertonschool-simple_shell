#ifndef NICE_HEADER_H
#define NICE_HEADER_H

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>


extern char **environ;

/**
 * struct Node - singly linked list
 * @str: string - (malloc'ed string)
 * @next: points to the next node
 */
typedef struct Node
{
	char *str;
	struct Node *next;
} Node;

/* loop */
int shellLoop(char **argv);

/* builts */
void isBasicExit(char ***tokens, int countToken, ssize_t *gl);
void isEnv(char ***tokens, int countToken);
int _strcmp(char *s1, char *s2);

/* parser */
char *addPath(char ***tokens, Node *path);
void processTokens(char ***tokens, char **buffer, int countToken);
int lenTokens(ssize_t lenReaded, char **buffer);
void replaceNewLine(char **buffer);
ssize_t readLine(char **buffer, char ***tokens);

/* exe_cute */
int executeLine(char **buffer, char ***tokens, char *fullPath, int *errShowed);
void isPath(char ***tokns, char **path, char **av, int *count, int *errShowed);
void isDir(char ***tokens, char **path, char **av, int *count, int *errShowed);

/* str_func */
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);

/* more_str_func */
int _abs(int n);
void rev_string(char *s);
char *itoa(int value, char *buffer, int base);

/* list_func */
void free_list(Node *head);
size_t print_list(const Node *h);

/* memo */
int _getchar(void);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

/* get_env_path */
char *_getenv(const char *name);
Node *_getpathdir(char *path, char **pathCopy);
Node *listpath(char **pathCopy);

/* output */
void pfError(char *av, char *count, char *firstOne, char *message);
void print_error(char *str);
void _puts(int fd, char *str);

#endif

