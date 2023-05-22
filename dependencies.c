#include "main.h"
/**
 * strcmpr_until_sign - compares two string up to a sign
 * @a: first string
 * @b: second string
 * @sign: sign to compare up to
 * Return: 0 if the same up to sign. diffence between the two characters if not
*/
int strcmpr_until_sign(char *a, char *b, char sign)
{
	int i = 0;

	while (b[i] != sign)
	{
		if (a[i] != b[i])
			return (a[i] - b[i]);
		i++;
	}
	if (b[i] == '=' && a[i] == '\0')
		return (0);
	return (a[i] - b[i]);
}
/**
 * slice_env - slices the value of an environment variable value from the
 * environment variable
 * @name: Environment variable name
 * Return: environment variable value or NULL if not gotten
*/
char *slice_env(char *name)
{
	int i = 0;

	while (name[i] != '=' && name[i] != '\0')
		i++;
	return (((name + i + 1)[0] != '\0') ? name + i + 1 : NULL);
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
