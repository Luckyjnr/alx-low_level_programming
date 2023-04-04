#include "lists.h"


/**
 * add_nodeint - adds a new nod at the begining of a linked list
 * @head: head of a list
 * @g: integer data to put into the new node
 * Return: the address of the new element, NULL if failed
 */
listint_t *add_nodeint(listint_t **head, const int g)
{
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->g = g;
	new->next = *head;

	*head = new;

	return (new);
}
