#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - Entry point
 * Description: A simple shell
 * @argc: cli argument count
 * @argv: vector of arguments
 * Return: Always 0 (Success)
 */

int main(__attribute__((unused))int argc, char **argv)
{
	int lineLen;
	char *line = NULL, **args = NULL;
	size_t len = 0;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		lineLen = getline(&line, &len, stdin);
		if (lineLen == -1)
		{
			write(STDOUT_FILENO, "\n", 1);
			free(line);
			exit(EXIT_SUCCESS);
		}
		line[lineLen - 1] = '\0';
		args = split_string(line, ' ');
		if (execute(args))
			perror(argv[0]);
	}
	return (0);
}
