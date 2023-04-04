#include "lists.h"
#include <string.h>


/**
 * add_nodeint - adds a new nod at the begining of a linked list
 * @head: head of a list
 * @n: integer data to put into the new node
 * Return: the address of the new element, NULL if failed
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = *head;

	*head = new;

	return (new);
}
