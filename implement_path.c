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

char *implement_path(char *command, char **path)
{
	char **traverse, *string;
	struct stat st;

	if (is_implemented_path(command, path))
	{
		if (!stat(command, &st))
			return (_strdup(command));
		perror(command);
		return (NULL);
	}
	for (traverse = path; *traverse; traverse++)
	{
		string = concat(*traverse, "/", command);
		if (!stat(string, &st))
			return (string);
		free(string);
	}
	perror(command);
	return (NULL);
}

