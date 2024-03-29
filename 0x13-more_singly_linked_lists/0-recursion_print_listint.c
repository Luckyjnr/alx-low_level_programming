#include "lists.h"
#include <stdio.h>

/**
 * recursion_printer - A function that prints all the elements in the list
 * @f: A pointer to listint structure
 * Return: the number of nodes.
 */
size_t recursion_printer(const listint_t *f)
{
	printf("%d\n", h->n);
	return (1 + recursion_printer(h->next));
}
