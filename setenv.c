#include "main.h"
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
			delete_envlist_at_index(i, envlist);
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
