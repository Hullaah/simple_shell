#include "main.h"
/**
 * execute_setenv - function that executes the setenv command
 * @vector: array of command and its argument
 * @envlist: pointer to the environment variables linked list
 * Return: integer
*/
int execute_setenv(char **vector, envlist_t **envlist)
{
	int i, j, set;
	char *s = "Invalid number of arguments\n";

	j = _strlen(s);
	for (i = 0; vector[i]; i++)
		;
	if (i != 3)
	{
		write(STDERR_FILENO, s, j);
		return (0);
	}
	set = _setenv(vector[1], vector[2], envlist);
	if (set == -1)
	{
		s = "setenv encountered an error\n";
		j = _strlen(s);
		write(STDERR_FILENO, s, j);
		return (0);
	}
	return (1);
}
/**
 * execute_env - function that executes the env command
 * @vector: array of command and its argument
 * @envlist: pointer to the environment variables linked list
 * Return: integer
*/
int execute_env(char **vector, envlist_t **envlist)
{
	int i, j;
	char *s = "Invalid number of arguments";

	j = _strlen(s);
	for (i = 0; vector[i]; i++)
		;
	if (i != 1)
	{
		write(STDERR_FILENO, s, j);
		return (0);
	}
	printenv(*envlist);
	return (1);
}
/**
 * execute_unsetenv - function that executes the unsetenv command
 * @vector: array of command and its argument
 * @envlist: pointer to the environment variables linked list
 * Return: integer
*/
int execute_unsetenv(char **vector, envlist_t **envlist)
{
	int i, j, unset;
	char *s = "Invalid number of arguments\n";

	j = _strlen(s);
	for (i = 0; vector[i]; i++)
		;
	if (i != 2)
	{
		write(STDERR_FILENO, s, j);
		return (0);
	}
	unset = _unsetenv(vector[1], envlist);
	if (unset == -1)
	{
		s = "unsetenv encountered an error\n";
		j = _strlen(s);
		write(STDERR_FILENO, s, j);
		return (0);
	}
	return (1);
}
/**
 * execute_exit - function that executes the exit command
 * @vector: array of command and its argument
 * @envlist: pointer to the environment variables linked list
 * Return: integer
*/
int execute_exit(char **vector, __attribute__((unused))envlist_t **envlist)
{
	int i, j, k = 0, *exit_status = &k;
	char *s = "Invalid number of arguments\n";

	j = _strlen(s);
	for (i = 0; vector[i]; i++)
		;
	if (i != 1 && i != 2)
	{
		write(STDERR_FILENO, s, j);
		return (0);
	}
	exit_status = (i == 2) ? str_to_integer(vector[1], exit_status) : &k;
	if (!exit_status)
                return (-1);
	return (*exit_status);
}
/**
 * execute_cd - function that executes the cd command
 * @vector: array of command and its argument
 * @envlist: pointer to the environment variables linked list
 * Return: integer
*/
int execute_cd(char **vector, envlist_t **envlist)
{
	int i, k;

	for (i = 0; vector[i]; i++)
		;
	k = (i > 1) ? cd(vector[1], envlist) : cd(vector[0], envlist);
	if (k == -1)
		return (1);
	return (0);
}
