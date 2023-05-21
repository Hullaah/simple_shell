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
		if (a[i] == b[i])
			i++;
		else
			return (a[i] - b[i]);
	}
        if (a[i] == '=' && b[i] == '\0')
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
 * _getenv - gets an environment variable
 * @name: environment variable name to be gotten
 * Return: Value of environment variable or NULL if not found
*/
char *_getenv(char *name, envlist_t *envlist)
{
        envlist_t *traverse;
	if (!name)
		return (NULL);
	for (traverse = environ; traverse; traverse = traverse->next)
	{
		if (!strcmpr_until_sign(name, traverse->var, '='))
			return (slice_env(traverse->var));
	}
	return (NULL);
}

