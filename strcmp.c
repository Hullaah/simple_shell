#include "main.h"
/**
 * _strcmp - compares to string to check if they are equal
 * @s1: first string
 * @s2: second string
 * Return: 0 if the strings are equal. Else the difference betwen the string if
 * they are not equal
*/
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] - s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}
	return (0);
}
