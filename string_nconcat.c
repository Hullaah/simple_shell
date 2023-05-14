#include "main.h"
#include <stdlib.h>

/**
 * _strlen - calculates the length of a string
 * @s: s
 * Return: the length of a string
*/
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
/**
 * string_nconcat - concatenates two string up to n bytes
 * @s1: first_string
 * @s2: second_string
 * @n: number of bytes to copy up to
 * Return: new pointer to concatenated string
*/
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	size_t s1_length, s2_length, total_length, i;
	char *s;

	if (s2 == NULL)
		s2 = "";
	if (s1 == NULL)
		s1 = "";
	s1_length = _strlen(s1);
	s2_length = _strlen(s2);
	if (n >= s2_length)
		n = s2_length;
	total_length = s1_length + n;
	s = malloc(total_length + 1);
	if (s == NULL)
		return (NULL);
	for (i = 0; i < total_length; i++)
	{
		if (i < s1_length)
			s[i] = s1[i];
		else
			s[i] = s2[i - s1_length];
	}
	s[i] = '\0';
	return (s);
}
