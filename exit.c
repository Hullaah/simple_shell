#include "main.h"
/**
 * _is_digit - checks if a character is a digit
 * @c: character to be checked
 * Return: integer
 */
int _is_digit(char c)
	return ((c >= '0' && c <= '9') ? 1 : 0);
/**
 * str_to_integer - converts a string to an integer
 * @s: string to be converted
 * Return: integer
*/
int *str_to_integer(char *s)
{
	int power = 1, ans = 0, i;

	if ((s[0] < '0' || s[0] > '9') && s[0] != '-')
		return (NULL)
	for (i = 1; s[i] != '\0'; i++)
	{
		if(!_is_digit(s[i]))
			return (NULL);
	}
	i -= (s[0] == '-') ? 2 : 1;
	for (; i > 0; i--)
		power *= 10;
	i = (s[0] == '-') ? 1 : 0;
	for (; s[i] != '\0'; i++)
		ans += (power < 0) ? (s[i] - '0') * -power : (s[i] - '0') * power;
	return (&ans);
}
