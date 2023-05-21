#include "main.h"

void printenv(envlist_t *envlist)
{
        envlist_t *traverse;

        for (traverse = envlist; traverse; traverse = traverse->next)
                write(STDOUT_FILENO, traverse->var, traverse->length);
}
