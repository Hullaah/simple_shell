#include "main.h"
/**
 * insert_envlist_at_index - inserts a node at point specified by index
 * @head: pointer to address of list
 * @idx: point which node is to be inserted
 * @s: node's data
 * Return: pointer to modified node
*/
envlist_t *insert_envlist_at_index(envlist_t **head, int idx, char *s)
{
	int  i = 0;
	envlist_t *node, *ptr = *head, *preptr = *head;

	node = malloc(sizeof(envlist_t));
	if (!node)
		return (NULL);
	node->var = _strdup(s);
	node->length = _strlen(s);
	node->next = NULL;

	if (!ptr && !idx)
	{
		*head = node;
		return (*head);
	}
	if (ptr && !idx)
	{
		node->next = *head;
		*head = node;
		return (*head);
	}
	if (!ptr && idx)
		return (NULL);
	while (i != idx && ptr)
	{
		i++;
		preptr = ptr;
		ptr = ptr->next;
	}
	if (i != idx)
		return (ptr);
	preptr->next = node;
	node->next = ptr;
	return (*head);
}
/**
 * add_envlist - adds a node to the end of a singly linked list
 * @head: pointer to node start
 * @str: node string
 * Return: pointer to new node
*/
envlist_t *add_envlist(envlist_t **head, char *str)
{
	envlist_t *node;
	envlist_t *ptr = *head;
	char *string;
	int string_length;

	string_length = _strlen(str);
	node = malloc(sizeof(envlist_t));
	if (node == NULL)
		return (NULL);
	string = _strdup(str);
	if (string == NULL)
	{
		free(node);
		return (NULL);
	}
	node->var = string;
	node->length = string_length;
	node->next = NULL;
	if (!ptr)
	{
		*head = node;
		return (*head);
	}
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = node;
	return (*head);
}
/**
 * delete_envlist_at_index - deletes a node from a list at index specified
 * by index
 * @head: pointer to address of list
 * @index: index of node to be deleted
 * Return: 1 if deletion is succesful and -1 if not
*/
int delete_envlist_at_index(envlist_t **head, int index)
{
	envlist_t *ptr = *head, *preptr, *node;
	int i = 0;

	if (!(*head))
		return (-1);
	if (!index)
	{
		node = ptr->next;
		free(ptr->var);
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
	free(ptr->var);
	free(ptr);
	preptr->next = node;
	return (1);
}
/**
 * create_envlist - initialises the environment variables list
 * @envlist: environment list to be populated
 * Return: the populated environment variables list
*/
envlist_t *create_envlist(envlist_t **envlist)
{
	char **traverse;

	for (traverse = environ; *traverse; traverse++)
	{
		add_envlist(envlist, *traverse);
	}
	return (*envlist);
}
