#include <stdlib.h>
#include "main.h"

/**
 * strtow - splits a string into words
 * @str: the input string to split
 *
 * Return: pointer to an array of strings (words)
 */
char **strtow(char *str)
{
	char **words;
	int i, j, k, len, count;

	if (str == NULL || *str == '\0')
		return (NULL);

	len = 0;
	count = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			count++;
	}

	if (count == 0)
		return (NULL);

	words = (char **)malloc(sizeof(char *) * (count + 1));
	if (words == NULL)
		return (NULL);

	for (i = 0, k = 0; i < count; i++)
	{
		while (str[k] == ' ')
			k++;

		len = 0;
		while (str[k + len] != ' ' && str[k + len] != '\0')
			len++;

		words[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (words[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(words[j]);
			free(words);
			return (NULL);
		}

		for (j = 0; j < len; j++)
			words[i][j] = str[k++];
		words[i][j] = '\0';
	}

	words[i] = NULL;
	return (words);
}
