#include "main.h"

void signalHandler(int sig)
{
	(void) sig;
	write(STDOUT_FILENO, "\n$ ", 3);
}
int main(int argc, char *argv[])
{
	char **path, **commands, *lineptr, *paths;
	envlist_t *envlist = NULL;
	size_t n = 0;
	ssize_t num;
        int executed, i, fd, j = 0;

	signal(SIGINT, signalHandler);
	create_envlist(&envlist);
	paths = _getenv("PATH", envlist);
	path = strtow(paths, ':');
	if (argc > 1 || !isatty(STDIN_FILENO))
	{
		lineptr = NULL;
                if (argc > 1)
                {
                        fd = open(argv[1], O_RDONLY);
                        if (fd == -1)
                        {
                                perror("cannot open file");
		                free_vec(path);
		                free_list(envlist);
                                exit(-1);
                        }
                }
                else
                        fd = STDIN_FILENO;
		num = _getline(&lineptr, &n, fd);
		commands = strtow(lineptr, '\n');
		free(lineptr);
		for (i = 0; commands[i]; i++)
		{
                        executed = execute(commands[i], num, path, &envlist, argv[0], i + 1);
                        if (executed == -1)
                                break;
                        if (executed == 1 || !executed)
                                continue;
		}
                free(commands);
		free_vec(path);
		free_list(envlist);
	}
	else
	{
		for (;;)
		{
                        j++;
			write(1, "$ ", 2);
			lineptr = NULL;
			num = _getline(&lineptr, &n, STDIN_FILENO);
                        executed = execute(lineptr, num, path, &envlist, argv[0], j);
                        if (executed == -1)
                                break;
                        if (executed == 1 || !executed)
                                continue;
		}
		if (executed == -1)
			write(1, "\n", 1);
	}
	exit(0);
}
