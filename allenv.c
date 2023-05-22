#include "main.h"
/**
 * _unsetenv - removes an environment variable from the envlist
 * @name: variable name
 * @envlist: environment list
 * Return: integer
*/
int _unsetenv(char *name, envlist_t **envlist)
{
	envlist_t *ptr;
	int cmpr, i = 0;

	for (ptr = *envlist; ptr; ptr = ptr->next)
	{
		cmpr = strcmpr_until_sign(name, ptr->var, '=');
		if (!cmpr)
		{
			delete_envlist_at_index(envlist, i);
			return (0);
		}
		i++;
	}
	return (-1);
}
/**
 * printenv - prints all the environment variables
 * @envlist: pointer to the environment list
 * Return: void
*/
void printenv(envlist_t *envlist)
{
	envlist_t *traverse;

	for (traverse = envlist; traverse; traverse = traverse->next)
	{
		write(STDOUT_FILENO, traverse->var, traverse->length);
		write(STDOUT_FILENO, "\n", 1);
	}
}
/**
 * _setenv - sets an environment variable to a particular value
 * @name: variable name
 * @value: variable value to be given to name
 * @envlist: environment variables list to work with
 * Return: integer
*/
int _setenv(char *name, char *value, envlist_t **envlist)
{
	char *string;
	envlist_t *ptr;
	int cmpr, i = 0;

	string = concat(name, "=", value);
	for (ptr = *envlist; ptr; ptr = ptr->next)
	{
		cmpr = strcmpr_until_sign(string, ptr->var, '=');
		if (!cmpr)
		{
			delete_envlist_at_index(envlist, i);
			insert_envlist_at_index(envlist, i, string);
			free(string);
			return (0);
		}
		i++;
	}
	add_envlist(envlist, string);
	free(string);
	return (0);
}
/**
 * _getenv - gets an environment variable
 * @name: environment variable name to be gotten
 * @envlist: environment list
 * Return: Value of environment variable or NULL if not found
*/
char *_getenv(char *name, envlist_t *envlist)
{
	envlist_t *traverse = envlist;

	if (!name)
		return (NULL);
	while (traverse)
	{
		if (!strcmpr_until_sign(name, traverse->var, '='))
			return (slice_env(traverse->var));
		traverse = traverse->next;
	}
	return (NULL);
}
