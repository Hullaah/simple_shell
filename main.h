#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>

typedef struct env_list_t
{
	char *var;
	int length;
	struct env_list_t *next;
}
env_list_t;

extern char **environ;

char **strtow(char *str, char delim);

ssize_t _getline(char **lineptr, size_t *n, int fd);

void *_memcpy(void *dest, const void *src, size_t n);

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

char *_getenv(const char *name);

char *concat(char *s1, char *s2, char *s3);

int _strlen(char *s);

void free_vec(char **vector);

void handle_error(char *error);

char *implement_path(char *on, char **path);

char *_strdup(char *str);

int _strcmp(char *s1, char *s2);

env_list_t *add_env_list(env_list_t **, const char *);

#endif /* MAIN.H*/

