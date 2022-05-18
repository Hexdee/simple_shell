#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - Entry point
 * Description: prints $, wait for the user to enter a command and print it
 * Return: always 0
 */

int main(__attribute__((unused))int argc, char **argv)
{
	int i, cmdLen;
	char *cmd = NULL;
	size_t len = 0;
	
	while (1)
	{
		printf("$ ");
		cmdLen = getline(&cmd, &len, stdin);
		if (feof(stdin))
		{
			printf("\n");
			free(cmd);
			exit(EXIT_SUCCESS);
		}
		cmd[cmdLen - 1] = '\0';
		if(execute(cmd))
			perror(argv[0]);
	}
	return (0);
}
