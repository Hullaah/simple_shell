#include "main.h"

int is_implemented_path(char *command, char **path)
{
	char **traverse;
	int i = 0;

	for (traverse = path; *traverse; traverse++)
	{
		while ((*traverse)[i] != '\0')
		{
			if (command[i] != '\0')
			{
				if ((*traverse)[i] != command[i])
					break;
			}
                        if (command[i] == '\0')
				return (1);
			i++;
		}
			if ((*traverse)[i] == '\0')
                                return (1);
	}
	return (0);
}

char *implement_path(char *on, char *path_value)
{
	char **tmp_path, **paths, *concat, *tmp_concat;
	struct stat st;
        int status;

	paths = strtow(path_value, ':');
	if (is_implemented_path(on, paths))
	{
                concat = _strdup(on);
		free_vec(paths);
		return (concat);
	}
	for (tmp_path = paths; *tmp_path; tmp_path++)
	{
		tmp_concat = string_nconcat(*tmp_path, "/",1024);
		concat = string_nconcat(tmp_concat, on, 1024);
                status = stat(concat, &st);
		if (!status)
			break;
		free(tmp_concat);
		free(concat);
	}
	free_vec(paths);
	return (!status ? concat : _strdup(on));
}

