#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
        dlistint_t *ptr, *p, *p2;
	unsigned int i = 0;

	if (*head == NULL)
		return (-1);

	ptr = *head;
	while (ptr)
	{
		ptr = ptr->next;
		i++;
	}
	ptr = *head;
	if (index == 0)
	{
		*head = ptr->next;
		if (*head)
			(*head)->prev = NULL;
		free(ptr);
	}
	else if (i > index)
	{
		i = 0;
		while (i < (index - 1))
		{
			ptr = ptr->next;
			i++;
		}
		p2 = ptr->next;
		p = ptr->next->next;
		ptr->next = p;
		if (p)
			p->prev = ptr;
		free(p2);
	}
	else
		return (-1);
	return (1);
}
