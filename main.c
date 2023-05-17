#include "main.h"

int main(void)
{
	char **vector, **path, *command, *lineptr;
	size_t n = 0;
	ssize_t num;
	int status;
	pid_t pid;

	path = strtow(_getenv("PATH"), ':');
	for (;;)
	{
		write(1, "$ ", 2);
		lineptr = NULL;
		num = _getline(&lineptr, &n, STDIN_FILENO);
		if (!num || !_strcmp(lineptr, "exit"))
		{
			free(lineptr);
			free_vec(path);
			break;
		}
		vector = strtow(lineptr, ' ');
		free(lineptr);
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
			handle_error("fork");
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
		write(1,"\n", 1);
	exit(0);
}
