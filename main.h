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

typedef int (*fexec_built_in_t)(char **vector, envlist_t **envlist);

/**
 * struct envlist_t - a linked list of environment variables for the shell
 * @var: environment variable
 * @length: string length
 * @next: pointer to next node
*/
typedef struct envlist_t
{
	char *var;
	int length;
	struct envlist_t *next;
}
envlist_t;
/**
 * struct built_ins_struct_t - a structure for the built-in commands
 * @command: command
 * @f: function to execute command
*/
typedef struct built_ins_struct_t
{
	char *command;
	fexec_built_in_t f;
}
built_ins_struct_t;

extern char **environ;

char **strtow(char *str, char delim);

ssize_t _getline(char **lineptr, size_t *n, int fd);

void *_memcpy(void *dest, const void *src, size_t n);

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

char *_getenv(char *name, envlist_t *envlist);

char *concat(char *s1, char *s2, char *s3);

int _strlen(char *s);

void free_vec(char **vector);

void handle_error(char *error);

char *implement_path(char *on, char **path);

char *_strdup(char *str);

int _strcmp(char *s1, char *s2);

int strcmpr_until_sign(char *a, char *b, char sign);

int *str_to_integer(char *s);

int delete_envlist_at_index(envlist_t **head, int index);

envlist_t *insert_envlist_at_index(envlist_t **head, int idx, char *s);

envlist_t *add_envlist(envlist_t **head, char *str);

envlist_t *create_envlist(envlist_t **envlist);

int _setenv(char *name, char *value, envlist_t **envlist);

int _unsetenv(char *name, envlist_t **envlist);

void printenv(envlist_t *envlist);

char *slice_env(char *name);

#endif
