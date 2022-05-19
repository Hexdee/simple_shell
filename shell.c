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
	int cmdLen;
	char *cmd = NULL;
	size_t len = 0;

	while (1)
	{ 
		write(STDIN_FILENO, "$ ", 3);
		cmdLen = getline(&cmd, &len, stdin);
		if (cmdLen == -1)
		{
			free(cmd);
			exit(EXIT_SUCCESS);
		}
		cmd[cmdLen - 1] = '\0';
		if (execute(cmd))
			perror(argv[0]);

		if (isatty(STDIN_FILENO))
			break;
	}
	return (0);
}
