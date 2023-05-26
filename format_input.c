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
/**
 * format_spaces - formats and executes commands
 * @vector: array of strings representing the commands.
 * @path: array of strings representing the search path
 * @envlist: pointer to the environment list
 * @program: name of program
 * @co: current command line number
 * @mode: array of strings representing the execution mode
 * Return: 1 on success
 */
int format_spaces(char **vector, char **path, envlist_t **envlist,
char *program, int co, char **mode)
{
	int i, j;
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
		j = handle_built_in(vec, comments, vector, path, envlist, program, co, mode);
		if (j != 0)
			return (j);
	}
	return (1);
}
/**
 * handle_built_in - handles the execution of built-in commands
 * @vec: array of command arguments
 * @comments: array of comments in the command
 * @vector: original command vector
 * @path: array of paths for command execution
 * @envlist: pointer to the environment list
 * @program: name of program
 * @co: current command index
 * @mode: execution mode
 * Return: the status code of the command execution
 */
int handle_built_in(char **vec, char **comments, char **vector, char **path, envlist **envlist, char *program, int co, char **mode)
{
	int k, j;

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
		return (0);
	}
	if (!_strcmp(vec[0], "cd"))
	{
		printerr("%s: %d: %s: cant't cd to %s\n", program, co, vec[0], vec[1]);
		free_vec(vec);
		return (0);
	}
	return (execute_external_cmd(vec, path, envlist, program, co));
}
/**
 * execute_external_cmd - executes external command
 * @vec:array of command args
 * @path: array of paths for cmd execution
 * @envlist: pointer to the environment list
 * @program: name of the program
 * @co: current command index
 * Return: the status code of the command execution
 */
int execute_external_cmd(char **vec, char **path, envlist_t **envlist, char *program, int co)
{
	int j;

	j = fork_cmd(vec, path);
	if (!j)
	{
		printerr("%s: %d: %s: not found\n", program, co, vec[0]);
		free_vec(vec);
	}
	return ((j == 2 && !vector[i + 1]) ? 2 : 0);
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
