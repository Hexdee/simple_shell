#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - Entry point
 * Description: A simple shell
 * Return: Always 0 (Success)
 */

int main(void)
{
	char *line = NULL;
	size_t lineLen = 0;
	int status, commandLen;
	char **command = NULL;

	do {
		printf("$ ");
		commandLen = getline(&line, &lineLen, stdin);
		if (feof(stdin))
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		line[commandLen - 1] = '\0';
		status = executeCommand(line);

		free(line);
		line = NULL;
		lineLen = 0;
	} while (status);

	return (0);
}
