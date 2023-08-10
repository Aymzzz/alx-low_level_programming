#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - Concatenates two strings.
 * @s1: First string.
 * @s2: Second string.
 * @n: Number of characters from s2 to concatenate.
 *
 * Return: Pointer to newly allocated space with concatenated string.
 *         If memory allocation fails, returns NULL.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
    unsigned int len1 = 0, len2 = 0;
    unsigned int i, j;
    char *result;

    if (s1 == NULL)
        s1 = "";
    if (s2 == NULL)
        s2 = "";

    while (s1[len1] != '\0')
        len1++;

    while (s2[len2] != '\0')
        len2++;

    if (n >= len2)
        n = len2;

    result = malloc(sizeof(char) * (len1 + n + 1));

    if (result == NULL)
        return (NULL);

    for (i = 0; i < len1; i++)
        result[i] = s1[i];

    for (j = 0; j < n; j++, i++)
        result[i] = s2[j];

    result[i] = '\0';
    return (result);
}

