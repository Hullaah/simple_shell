#include "main.h"
/**
 * delete_nodeint_at_index - deletes a node from a list at index specified
 * by index
 * @head: pointer to address of list
 * @index: index of node to be deleted
 * Return: 1 if deletion is succesful and -1 if not
*/
int delete_nodeint_at_index(env_list_t **head, int index)
{
	env_list_t *ptr = *head, *preptr, *node;
	unsigned int i = 0;

	if (!(*head))
		return (-1);
	if (!index)
	{
		node = ptr->next;
		free(ptr);
		*head = node;
		return (1);
	}
	while (i != index && ptr)
	{
		i++;
		preptr = ptr;
		ptr = ptr->next;
	}
	if (i != index)
		return (-1);
	node = ptr->next;
	free(ptr);
	preptr->next = node;
	return (1);
}
