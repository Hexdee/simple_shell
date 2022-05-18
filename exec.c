#include <unistd.h>
#include <sys/types.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

/**
 * execute - executes a command
 * @cmd: The command to execute
 *
 * Return: 0 for success, -1 for failure
 */

int execute(char *cmd)
{
	int child_status;
	pid_t child_pid;
	char *argv[2];

	argv[0] = cmd;
	argv[1] = NULL;

	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(cmd, argv, NULL))
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
