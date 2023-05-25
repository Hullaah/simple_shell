#include "main.h"
/**
 * handle_comments - removes comments from the vector of strings
 * @vector: an array of strings
 * Description: the function iterates through the array of strings and removes
 * any string starting with a '#' character
 * Return:modified vector with comments removed, Null if a comment
 * is found at the beginning.
 */ 
char **handle_comments(char **vector)
{
	int i, j;

	for (i = 0; vector[i]; i++)
	{
		if (vector[i][0] == '#')
		{
			if (i == 0)
				return (NULL);
			j = i;
			while (vector[j])
			{
				free(vector[j]);
				j++;
			}
			vector[i] = NULL;
			return (vector);
		}
	}
	return (vector);
}
int format_spaces(char **vector, char **path, envlist_t **envlist,
char *program, int co, char **mode)
{
	int i, j, k;
	char **vec;
	char **comments;

	for (i = 0; vector[i]; i++)
	{
		vec = strtow(vector[i], ' ');
                if (!vec)
			continue;
		comments = handle_comments(vec);
		if (!comments)
		{
			free_vec(vec);
			continue;
		}
		k = execute_built_in(envlist, vec);
		if (!_strcmp(vec[0], "exit"))
		{
                        if (k == -1)
                        {
                                printerr("%s: %d: %s: Illegal number: %s\n", program, co, vec[0], vec[1]);
                                free_vec(vec);
                                if (!vector[i + 1])
                                        return (2);
                                continue;
                        }
			free_vec(vector);
			free_list(*envlist);
			free_vec(path);
			if (mode)
				free(mode);
                        if (i && !vec[1])
                        {
			        free_vec(vec);
                                exit(j);
                        }
			free_vec(vec);
			exit(k);
		}
		if (!k)
		{
			free_vec(vec);
			continue;
		}
		if (!_strcmp(vec[0], "cd"))
                {
			printerr("%s: %d: %s: can't cd to %s\n", program, co, vec[0], vec[1]);
                        free_vec(vec);
                        continue;
                }
		j = fork_cmd(vec, path);
		if (!j)
		{
			printerr("%s: %d: %s: not found\n", program, co, vec[0]);
			free_vec(vec);
		}
                if (j == 2 && !vector[i + 1])
                        return (2);
	}
	return (1);
}
/**
 * execute - executes a string containing commands
 * @string: string containing commands
 * @num:number of commands in the strings
 * @path: array of strings rep the search path
 * @envlist: pointet to env list
 * @program: name of program
 * @co:current command line number
 * @mode: array of strings rep the execution mode
 * Return: 2 on success.
 */ 
int execute(char *string, int num, char **path, envlist_t **envlist,
char *program, int co, char **mode)
{
	char **vector;
	int i;

	if (num == 1)
       	{
		free(string);
		return (num);
	}
	if (!num)
	{	
		free(string);
		free_vec(path);
		free_list(*envlist);
		return (-1);
	}
	vector = strtow(string, ';');
	free(string);
        if (!vector || !vector[0])
                return (0);
	i = format_spaces(vector, path, envlist, program, co, mode);
	free_vec(vector);
        if (i == 2)
                return (2);
	return (3);
}
