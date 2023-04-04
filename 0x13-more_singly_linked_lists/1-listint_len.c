#include "lists.h"
#include <stdio.h>

/**
 * listint_len - returns the number of elements in the list
 * @f: A pointer to listint_t structure
 * Return: number of elements.
 */
size_t listint_len(const listint_t *f)
{
	size_t nodes = 0;

	while (f)
	{
		f = f->next;
		nodes++;
	}
	return (nodes);
}
