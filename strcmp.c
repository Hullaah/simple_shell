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
	if (s1[0] != '\0' && s2[0] != '\0')
	{
		if (s1[0] == s2[0])
			return (_strcmp(s1 + 1, s2 + 1));
		else
			return (s1[0] - s2[0]);
	}
	else
		return (s1[0] - s2[0]);
}
