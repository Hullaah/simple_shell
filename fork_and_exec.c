#include "main.h"
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

/*int exec_cmd(char **vector)
{
	execve(vector[0], vector, environ);
	perror(vector[0]);
	_exit(2);
}*/

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
		/*j = exec_cmd(vector);*/
        }
	return (1);
}