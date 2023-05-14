#include "main.h"
/**
 * strcmpr_until_sign - compares two string up to a sign
 * @a: first string
 * @b: second string
 * @sign: sign to compare up to
 * Return: 0 if the same up to sign. diffence between the two characters if not
*/
int strcmpr_until_sign(const char *a, char *b, char sign)
{
	int i = 0;

	while (b[i] != '\0' && b[i] != sign && a[i] != '\0')
	{
		if (a[i] == b[i])
			i++;
		else
			return (a[i] - b[i]);
	}
	return (0);
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
char *_getenv(const char *name)
{
	char **env;

	if (!name)
		return (NULL);
	for (env = environ; *env; env++)
	{
		if (!strcmpr_until_sign(name, *env, '='))
			return (slice_env(*env));
	}
	return (NULL);
}

