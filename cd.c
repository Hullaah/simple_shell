#include "main.h"

int cd(char *s, envlist_t **envlist)
{
	int i, j, k;
	char *old_pwd, *pwd = NULL, *tmp, pwd2[1024];


	j = _strcmp(s, "-");
	if (!j)
	{
		old_pwd = _getenv("OLDPWD", *envlist);
		if (!old_pwd)
		{
                        getcwd(pwd2, 1024);
                        write(STDOUT_FILENO, pwd2, _strlen(pwd2));
                        write(STDOUT_FILENO, "\n", 1);
                        return (0);
		}
		i = chdir(old_pwd);
		if (i == -1)
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
	k = _strcmp(s, "cd");
	if (!k)
	{
		old_pwd = _getenv("PWD", *envlist);
		pwd = _getenv("HOME", *envlist);
                if (!pwd)
                        return (0);
		i = chdir(pwd);
		if (i == -1)
			return (-1);
		_setenv("OLDPWD", old_pwd, envlist);
		_setenv("PWD", pwd, envlist);
		return (0);
	}
	old_pwd = _getenv("PWD", *envlist);
	i = chdir(s);
	if (i == -1)
		return (-1);
	if (!getcwd(pwd2, 1024))
		return (-1);
	_setenv("OLDPWD", old_pwd, envlist);
	_setenv("PWD", pwd2, envlist);
	return (0);
}
