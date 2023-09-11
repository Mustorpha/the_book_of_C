#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void)
{
	pid_t child_process;
	char *dir[]= {"/bin/ls", "-l", "/tmp", NULL};
	int i;

	for (i = 0; i < 5; i++)
	{
		if (fork() == 0)
		{
			child_process = getpid();
			execve(dir[0], dir, NULL);
		}
		else
		{
			wait(&child_process);
		}
	}
	return (0);
}