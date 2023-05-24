#include "main.h"
char **handle_comments(char **vector)
{
	int i, j;
        char **vec;

	for (i = 0; vector[i]; i++)
	{
		if (vector[i][0] == '#')
		{
                        vec = vector + i;
                        j = i;
			while (vec[j])
                        {
                                free(vec[j]);
                                j++;
                        }
			vector[i] = NULL;
			return (vector);
		}
	}
        return (vector);
}
int format_spaces(char **vector, char **path, envlist_t **envlist,
char *program, int co)
{
	int i, j;
        char **vec;

	for (i = 0; vector[i]; i++)
	{
	        vec = strtow(vector[i], ' ');
                handle_comments(vec);
                j = execute_built_in(envlist, vec);
                if (!_strcmp(vec[0], "exit"))
                {
                        free_vec(vec);
                        free_vec(vector);
                        free_list(*envlist);
                        free_vec(path);
                        exit(j);
                }
                if (!j)
                {
                        if (!_strcmp(vec[0], "cd"))
                                printerr("%s: %d: %s: can't cd into %s\n", program, co, vec[0], vec[1]);
                        free_vec(vec);
                        continue;
                }
                j = fork_cmd(vec, path);
                if (!j)
                {
                        printerr("%s: %d: %s: not found\n", program, co, vec[0]);
                        free_vec(vec);
                        continue;
                }
	}
        return (1);
}
int execute(char *string, int num, char **path, envlist_t **envlist,
char *program, int co)
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
	i = format_spaces(vector, path, envlist, program, co);
        free_vec(vector);
        if (!i)
                return (0);
        return (2);
}
