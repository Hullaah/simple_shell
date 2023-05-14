#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * my_getline - A function similar to the standard library getline function
 * @lineptr: a pointer to the buffer that will hold the input line
 * @: a pointer to the size of the buffer pointed to by lineptr
 * @: a pointer to the input stream to read from
 * Description: the function dynamically allocates memory for a buffer to
 * hold the line of input read from the stream and automatically adjusts the
 * buffer size to fit the input line
 * Return: The function returns a signed integer value
 */

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
	char c;
	ssize_t num_read = 0;
	size_t i = 0;

	if (lineptr == NULL || n == NULL)
	{
		return (-1);
	}

	if (*lineptr == NULL)
	{
		*n = 128;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
		{
			return (-1);
		}
	}
	
	while (1)
	{
		if (i >= *n - 1)
		{
			*n *= 2;
			char *new_lineptr = realloc(*lineptr, *n);
			if (new_lineptr == NULL)
			{
				return (-1);
			}
			*lineptr = new_lineptr;
		}

		num_read = read(STDIN_FILENO, &c, 1);
		if (num_read == -1)
		{
			return (-1);
		}
		else if (num_read == 0)
		{
			break;
		}
		(*lineptr)[i] = c;
		i++;

		if (c == '\n')
		{
			break;
		}
	}
	(*lineptr)[i] = '\0';
	return (i);
}
