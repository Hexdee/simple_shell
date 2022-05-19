#include <stdlib.h>
#define BUFSIZE 16
char **split_string(char *str, char sep)
{
	int i, j, count = 0, started = 0;
	char **tokens = malloc(sizeof(char *) * BUFSIZE);

	for(i = 0; str[i]; i++)
	{
		if (str[i] != ' ' && !started)
		{
			tokens[count] = &str[i];
			started = 1;
			count++;
		}
		else if (str[i] == ' ' && started)
		{
			str[i] = '\0';
			started = 0;
		}
	}

	tokens[count] = NULL;
	return (tokens);
}
