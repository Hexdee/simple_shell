#include <unistd.h>
#include <sys/types.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include "main.h"

/**
 * execute - executes a command
 * @cmd: The command to execute
 *
 * Return: 0 for success, -1 for failure
 */

int execute(char **const args)
{
	int child_status;
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(args[0], args, NULL))
			return (-1);
	}
	else
	{
		wait(&child_status);
		if (WEXITSTATUS(child_status) == -1)
			return (-1);
	}
	return (0);
}
