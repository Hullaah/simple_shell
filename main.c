#include "main.h"

int main(void)
{
	char **vector, **path, **commands, *command, *lineptr, *paths;
        envlist_t *envlist = NULL;
	size_t n = 0;
	ssize_t num;
	int status, i = 0;
	pid_t pid;
	fexec_built_in_t built_in;

        create_envlist(&envlist);
        paths = _getenv("PATH", envlist);
	path = strtow(paths, ':');
	if (isatty(STDIN_FILENO))
	{
		for (;;)
		{
			write(1, "$ ", 2);
			lineptr = NULL;
			num = _getline(&lineptr, &n, STDIN_FILENO);
			if (!num)
			{
				free(lineptr);
				free_vec(path);
				free_list(envlist);
				break;
			}
			vector = strtow(lineptr, ' ');
			free(lineptr);
			built_in  = get_ops_built_in(vector[0]);
			if (built_in)
			{
				built_in(vector, &envlist);
				free_vec(vector);
				continue;
			}
			command = implement_path(vector[0], path);
			if (!command)
			{
				free_vec(vector);
				continue;
			}
			free(vector[0]);
			vector[0] = command;
			pid = fork();
			if (pid == -1)
			{
				perror("fork");
				_exit(-1);
			}
			if (pid > 0)
			{
				free_vec(vector);
				waitpid(pid, &status, 0);
			}
			else
			{
				execve(vector[0], vector, environ);
				perror(vector[0]);
				free_vec(vector);
				_exit(-1);
			}
		}
		if (!num)
			write(1, "\n", 1);
	}
	else
	{
		num = _getline(&lineptr, &n, STDIN_FILENO);
		commands = strtow(lineptr, '\n');
		free(lineptr);
		for (i = 0; commands[i]; i++)
		{
			vector = strtow(commands[i], ' ');
			command = implement_path(vector[0], path);
			if (!command)
			{
				free_vec(vector);
				continue;
			}
			free(vector[0]);
			vector[0] = command;
			pid = fork();
			if (pid == -1)
			{
				perror("fork");
				_exit(-1);
			}
			if (pid > 0)
			{
				free_vec(vector);
				waitpid(pid, &status, 0);
			}
			else
			{
				execve(vector[0], vector, environ);
				perror(vector[0]);
				free_vec(vector);
				_exit(-1);
			}
		}
		free_vec(commands);
	}
	exit(0);
}
