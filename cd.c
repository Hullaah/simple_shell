#include "main.h"

/**
 * cd_prev_dir - changes the current working dir to the previous dir
 * @envlist: pointer to the environment variable list
 * Return: 0 on success, -1 on failure
 */
int cd_prev_dir(envlist_t **envlist)
{
	char *old_pwd, *pwd = NULL, *tmp, pwd2[1024];

	old_pwd = _getenv("OLDPWD", *envlist);
	if (!old_pwd)
	{
		getcwd(pwd2, 1024);
		write(STDOUT_FILENO, pwd2, _strlen(pwd2));
		write(STDOUT_FILENO, "\n", 1);
		return (0);
	}
	if (chdir(old_pwd) == -1)
		return (-1);
	tmp = _strdup(old_pwd);
	old_pwd = _getenv("PWD", *envlist);
	pwd = tmp;

	write(STDOUT_FILENO, pwd, _strlen(pwd));
	write(STDOUT_FILENO, "\n", 1);

	_setenv("OLDPWD", old_pwd, envlist);
	_setenv("PWD", pwd, envlist);
	free(tmp);

	return (0);
}

/**
 * cd_home_dir - changes the current working dir to the home dir
 * @envlist: pointer to the en variable list
 * Return: 0 on success, -1 on failure
 */
int cd_home_dir(envlist_t **envlist)
{
	char *old_pwd, *pwd;

	old_pwd = _getenv("PWD", *envlist);
	pwd = _getenv("HOME", *envlist);
	if (!pwd)
		return (0);
	if (chdir(pwd) == -1)
		return (-1);

	_setenv("OLDPWD", old_pwd, envlist);
	_setenv("PWD", pwd, envlist);

	return (0);
}

/**
 * cd - changes the working directory
 * @s: directory path or special character(- or c)
 * @envlist: pointer to the environment variable list
 * Return: 0 on success, -1 on failure
 */
int cd(char *s, envlist_t **envlist)
{
	char *old_pwd, pwd2[1024];

	if (_strcmp(s, "-") == 0)
	{
		return (cd_prev_dir(envlist));
	}
	else if (_strcmp(s, "cd") == 0)
	{
		return (cd_home_dir(envlist));
	}
	else
	{
		old_pwd = _getenv("PWD", *envlist);
		if (chdir(s) == -1)
			return (-1);
		if (!getcwd(pwd2, 1024))
			return (-1);
		_setenv("OLDPWD", old_pwd, envlist);
		_setenv("PWD", pwd2, envlist);
		return (0);
	}
}
