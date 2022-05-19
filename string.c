#include <stdlib.h>
#define BUFSIZE 16

/**
 * split_string - splits a string into an array of words
 * @str: the string to split
 * @sep: the separator
 *
 * Return: pointer to the array of splited strings
 */

char **split_string(char *str, char sep)
{
	int i, count = 0, started = 0;
	char **tokens = malloc(sizeof(char *) * BUFSIZE);

	for (i = 0; str[i]; i++)
	{
		if (str[i] != sep && !started)
		{
			tokens[count] = &str[i];
			started = 1;
			count++;
		}
		else if (str[i] == sep && started)
		{
			str[i] = '\0';
			started = 0;
		}
	}

	tokens[count] = NULL;
	return (tokens);
}
