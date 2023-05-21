#include "main.h"

int cd(char *s, envlist_t **envlist)
{
	int i, j, k;
	char *old_pwd, pwd[1024];

	if (!getcwd(pwd, sizeof(pwd)))
	{
		perror("cd");
		return (-1);
	}
	old_pwd = _getenv("PWD", *envlist);
	_setenv("OLDPWD", old_pwd, envlist);
	_setenv("PWD", pwd, envlist);
	/*if (!_strcmp(pwd, old_pwd))
	{
		_unsetenv("OLDPWD", envlist);
	}*/
	old_pwd = pwd;
	j = _strcmp(s, "-");
	k = _strcmp(s, "cd");
	if (!j || !k)
	{
		i = !j ? chdir(old_pwd) : chdir(_getenv("HOME", *envlist));
		if (i == -1)
		{
			perror("cd");
			return (-1);
		}
	}
	i = chdir(s);
	if (i == -1)
	{
		perror("cd");
		return (-1);
	}
	return (0);
}
