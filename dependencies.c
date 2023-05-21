#include "main.h"

/**
 * handle_error - handles the error
 * @error: value tobl pass to perror
 * Return: void (does not have a return value
*/
void handle_error(char *error)
{
	perror(error);
	_exit(1);
}
/**
 * free_vec - frees a dynamically allocated array of strings
 * @vector: vector to be freed
 * Return: void (does not have a return value)
*/
void free_vec(char **vector)
{
	char **arr;

	for (arr = vector; *arr; arr++)
	{
		free(*arr);
	}
	free(vector);
}

/**
 * _strdup - creates a copy of a string in the heap
 * @str: string to be duplicated
 * Return: pointer to char in the heap
*/
char *_strdup(char *str)
{
	char *string;
	int i;
	int str_length;

	if (str == NULL)
		return (NULL);
	str_length = _strlen(str);
	string = malloc(str_length + 1);
	if (string == NULL)
		return (NULL);
	for (i = 0; i < str_length; i++)
		string[i] = str[i];
	string[i] = '\0';
	return (string);
}
/**
 * free_list - frees an allocated ptr to a singly linked list
 * @head: linked list
 * Return: void (does not have a return value)
*/
void free_list(envlist_t *head)
{
	envlist_t *node;
	char *string;

	if (head)
	{
		while (head)
		{
			node = head->next;
			string = head->var;
			free(string);
			free(head);
			head = node;
		}
	}
}
