#include "lists.h"


/**
 * print_listint - prints all the elements in the list
 * @f: head of a list
 * Return: number of nodes.
 */
size_t print_listint(const listint_t *f)
{
	size_t nodes = 0;

	while (f != null)
	{
		printf("%d\n", f->n);
		f = f->next;
		nodes++;
	}
	return (nodes);
}
