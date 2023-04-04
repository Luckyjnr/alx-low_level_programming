#include "lists.h"


/**
 * print_listint - prints all the elements in the list
 * @f: head of a list
 * Return: number of nodes.
 */
size_t print_listint(const listint_t *f)
{
	size_t nodes = 0;

	while (f)
	{
		printf("%d\n", pnt->n);
		pnt = pnt->next;
		nodes++;
	}
	return (nodes);
}
