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
