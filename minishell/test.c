#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char **argv, char *envp[])
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		printf("Hello\n");
		exit(123);
	}
	else
	{
		int status;
		waitpid(pid, &status, 0);
		printf("World %d\n", WEXITSTATUS(status));
	}

}
