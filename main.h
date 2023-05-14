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

extern char **environ;

char **strtow(char *str, char delim);

ssize_t _getline(char **lineptr, size_t *n, int fd);

void *_memcpy(void *dest, const void *src, size_t n);

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

char *_getenv(const char *name);

char *string_nconcat(char *s1, char *s2, unsigned int n);

int _strlen(char *s);

void free_vec(char **vector);

void handle_error(char *error);

char *implement_path(char *on, char *path_value);

char *_strdup(char *str);

#endif
