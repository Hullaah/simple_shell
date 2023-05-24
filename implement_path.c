#include "main.h"
/**
 * is_implemented_path - checks if a command's path is implemented
 * @command: command to check
 * @path: array of paths to check
 * Return: integer denoting whether path is implemented or not
*/				
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
        if (command[i] == '.') 
                return (1);
	return (0);
}
/**
 * implement_path - implements a command path
 * @command: command whose path is to be implemented
 * @path: an array of paths to use to implement path
 * Return: implemented path
*/
char *implement_path(char *command, char **path)
{
	char **traverse, *string;
	struct stat st;

	if (is_implemented_path(command, path))
	{
		if (!stat(command, &st))
			return (_strdup(command));
		return (NULL);
	}
	for (traverse = path; *traverse; traverse++)
	{
		string = concat(*traverse, "/", command);
		if (!stat(string, &st))
			return (string);
		free(string);
	}
	return (NULL);
}

