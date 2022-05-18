#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * executeCommand - Execute a command
 * @command: The command to execute
 *
 * Return: 1 on success
 */

int executeCommand(char *command)
{
	int wstatus;
	pid_t child_pid;

	char *argv[] = { NULL, NULL };
	char *environ[] = { NULL };

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0)
	{
		if (execve(command, argv, environ) < 0)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(child_pid, &wstatus, 0);
	}
	return (1);
}
