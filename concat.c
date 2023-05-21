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
		i++;
	return (i);
}
/**
 * concat - concatenates three string together
 * @s1: first_string
 * @s2: second_string
 * @s3: third string
 * Return: new pointer to concatenated string
*/
char *concat(char *s1, char *s2, char *s3)
{
	size_t s1_length, s2_length, s3_length, total_length, i;
	char *s;

	if (s2 == NULL)
		s2 = "";
	if (s1 == NULL)
		s1 = "";
	if (s3 == NULL)
		s3 = "";
	s1_length = _strlen(s1);
	s2_length = _strlen(s2);
	s3_length = _strlen(s3);
	total_length = s1_length + s2_length + s3_length;
	s = malloc(total_length + 1);
	if (s == NULL)
		return (NULL);
	for (i = 0; i < total_length; i++)
	{
		if (i < s1_length)
			s[i] = s1[i];
		else if (i < (s1_length + s2_length))
			s[i] = s2[i - s1_length];
		else
			s[i] = s3[i - s2_length - s1_length];
	}
	s[i] = '\0';
	return (s);
}
