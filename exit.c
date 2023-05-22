#include "main.h"
/**
 * _is_digit - checks if a character is a digit
 * @c: character to be checked
 * Return: integer
 */
int _is_digit(char c)
{
	return ((c >= '0' && c <= '9') ? 1 : 0);
}
/**
 * str_to_integer - converts a string to an integer
 * @s: string to be converted
 * @ans: address where converted integer is to be stored
 * Return: pointer to integer
*/
int *str_to_integer(char *s, int *ans)
{
	int power = 1, i;

	*ans = 0;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (!_is_digit(s[i]))
			return (NULL);
	}
	for (; i > 0; i--)
		power *= 10;
	i = 0;
	power /= 10;
	for (; s[i] != '\0'; i++, power /= 10)
		*ans += (s[i] - '0') * power;
	return (ans);
}
