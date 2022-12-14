#include "nice_header.h"

/**
 * free_list - free nodes
 * @head: pointer to the linked list
 *
 * Return: nothing
 */
void free_list(Node *head)
{
	Node *temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
	free(head);
}

/**
 * print_list - Print all the elements of the list
 * @h: Linked list data
 *
 * Return: Number of elements in the list
 */
size_t print_list(const Node *h)
{
	size_t i = 0;

	while (h)
	{
		if (h->str)
		{
			_puts(STDOUT_FILENO, h->str);
		}
		else
		{
			_puts(STDOUT_FILENO, "(nil)");
		}
		h = h->next;
		i++;
	}

	return (i);
}

