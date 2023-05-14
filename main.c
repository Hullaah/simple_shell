#include "main.h"

int main(void)
{
	char **vector, *path, *program;
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t num;
	int status;
	pid_t pid;

	for (;;)
	{
		write(1, "$ ", 2);
		pid = fork();
		if (pid == -1)
			handle_error("fork");
		if (pid != 0)
			waitpid(pid, &status, 0);
		else
		{
			num = _getline(&lineptr, &n, STDIN_FILENO);
			if (num == 0)
			{
				free(lineptr);
				_exit(1);
			}
                        path = _getenv("PATH");
			vector = strtow(lineptr, ' ');
                        program = implement_path(vector[0], path);
                        free(vector[0]);
                        vector[0] = program;
			free(lineptr);
			execve(vector[0], vector, environ);
			perror(vector[0]);
			free_vec(vector);
			_exit(-1);
		}
	}
	exit(0);
}
