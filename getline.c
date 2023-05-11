#include "main.h"
/**
 * _getline - just like the standard library getline function but uses file de-
 * scriptors just instead of FILE pointer type
 * @lineptr: pointer to buffer to store read string
 * @n: pointer to buffer size
 * @fd: file descriptor
 * Return: Amount of bytes read
*/
ssize_t _getline(char **lineptr, size_t *n, int fd)
{
	ssize_t red;
	char *tmp;
	int malloced = *n + BUFFER;

	if (*lineptr)
		red = read(fd, *lineptr, *n);
	else
	{
		*lineptr = malloc(malloced);
		if (!*lineptr)
			return (-1);
		red = read(fd, *lineptr, malloced);
	}
	if (!red)
		return (0);
	*n = red;
	while (*(*lineptr + (red - 1)) != '\n' && red)
	{
		malloced += BUFFER;
		tmp = realloc(*lineptr, malloced);
		if (!tmp)
			return (-1);
		*lineptr = tmp;
		red = read(fd, *lineptr, *n);
		if (red)
			*n = red;
	}
	return (*n);
}
