#include "main.h"
/**
 * implement_command - implement the command by searching for its executable
 * @vector: an array of strings representing the commands and its args
 * @path:an array of strings representing the paths to search for the command
 * Return: 0 on success, indicating the command has been implemented
 */
int implement_command(char **vector, char **path)
{
	char *command;

	command = implement_path(vector[0], path);
	if (!command)
		return (0);
	free(vector[0]);
	vector[0] = command;
	return (1);
}

/**
 * fork_cmd - executes a command by forking a new process.
 * @vector: an array of strings representing the command and its args
 * @path: an array of strings representing the paath to search for the command
 * Return: 1 on success.
 */
int fork_cmd(char **vector, char **path)
{
	pid_t pid;
	int status, j;

	j = implement_command(vector, path);
	if (!j)
		return (0);
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(-1);
	}
	if (pid > 0)
	{
		free_vec(vector);
		waitpid(pid, &status, 0);
                if (WEXITSTATUS(status))
                        return (2);
	}
	else
        {
                execve(vector[0], vector, environ);
	        perror(vector[0]);
	        _exit(2);
        }
	return (1);
}
