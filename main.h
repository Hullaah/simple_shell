#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#define BUFFER 1024

char **strtow(char *str);

ssize_t _getline(char **lineptr, size_t *n, int fd);

#endif
