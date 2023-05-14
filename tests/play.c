#include "../main.h"
/**
 * compile with:
 * 		gcc -g -Wall -Werror -Wextra -pedantic -std=gnu89 tests/play.c *.c
 * Execute:
 * 	./a.out
 * check for memory leaks:
 * 			valgrind ./a.out
 * debug:
 * 	gdb ./a.out
*/
int main(void)
{	
	char *lineptr = NULL;
	size_t num = 0;
	ssize_t read;
	/*char **tab, **arr;*/
	/*Test _getline implementatiion*/
	write(STDOUT_FILENO, "$ ", 2);
	read = _getline(&lineptr, &num, STDIN_FILENO);
	/*read = getline(&lineptr, &num, stdin);*/
        printf("\n%lu\n", num);
	write(STDOUT_FILENO, lineptr, read);
	free(lineptr);
	/*Test strtow implementation*/
	/*tab = strtow("      ALX School         #cisfun      ");
	if (tab == NULL)
	{
        	printf("Failed\n");
        	return (1);
	}
	for (arr = tab; *arr; arr++)
	{
        	printf("%s\n", *arr);
	}
	for (arr = tab; *arr; arr++)
    	{
        	free(*arr);
    	}
	free(tab);*/
	return (0);
}
