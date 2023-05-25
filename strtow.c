#include "main.h"
/**
 * word_count - count the number of words in a string
 * @str: string
 * @delim: delimeter
 * Return: number of words in a string
*/
int word_count(char *str, char delim)
{
	int i = 1;
	int words = 0;

	if (str[0] != delim)
		words++;
	for (; str[i] != '\0'; i++)
	{
		if (str[i] != delim && str[i - 1] == delim)
			words++;
	}
	return (words);
}
/**
 *  word_length - calculates the length of each word in a string
 * @str: string
 * @word: The word in the string whose length is to be calculated.
 * @delim: delimeter
 * e.g: first word, second word, third word and so on
 * Return: length of word in a string
*/
int word_length(char *str, int word, char delim)
{
	int i = 1, j = 0, words = 0;

	if (str[0] != delim)
	{
		words++;
		if (word == words)
		{
			while (str[j] != delim && str[j] != '\0')
				j++;
			return (j);
		}
	}
	for (; str[i] != '\0'; i++)
	{
		if (str[i] != delim && str[i - 1] == delim)
		{
			words++;
			if (word == words)
			{
				while (str[i] != delim && str[i] != '\0')
				{
					i++;
					j++;
				}
				break;
			}
		}
	}
	return (j);

}
/**
 * get_word - gets the word in a string
 * @str: string
 * @word: word to be gotten. e.g whether first word, second word or third word
 * and so on is to be gotten
 * @delim: delimeter
 * Return: gotten word
*/
char *get_word(char *str, int word, char delim)
{
	int i = 1;
	int words = 0;

	if (str[0] != delim)
	{
		words++;
		if (word == words)
		{
			return (&str[0]);
		}
	}
	for (; str[i] != '\0'; i++)
	{
		if (str[i] != delim && str[i - 1] == delim)
		{
			words++;
			if (word == words)
			{
				return (&str[i]);
			}
		}
	}
	return (0);
}
/**
 * strtow - converts  a string to array of words
 * @str: string
 * @delim: delimeter
 * Return: array of words
*/
char **strtow(char *str, char delim)
{
	int total_word = word_count(str, delim);
	int i, j, k, string_length;
	char **string_arr;
	char *tmp;

	if (str == NULL || total_word == 0)
	{
		return (NULL);
	}
	string_arr = malloc((total_word + 1) * sizeof(char *));
	if (string_arr == NULL)
		return (NULL);
	for (i = 0; i < total_word; i++)
	{
		string_arr[i] = malloc(word_length(str, i + 1, delim) + 1);
		if (string_arr[i] == NULL)
		{
			free(string_arr);
			return (NULL);
		}
	}
	for (k = 0; k < total_word; k++)
	{
		string_length = word_length(str, k + 1, delim);
		for (j = 0; j < string_length; j++)
		{
			tmp = get_word(str, k + 1, delim);
			if (*(tmp + j) != delim)
			{
				string_arr[k][j] = *(tmp + j);
			}
		}
		string_arr[k][j] = '\0';
	}
	string_arr[i] = NULL;
	return (string_arr);
}
