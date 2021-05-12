#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int ac, char** av, char**envp)
{
	char* argv[] = {"/bin/cat", 0};
	char* echo[] = {"/bin/echo", "hello", 0};
	
	int pipes[2];
	pipe(pipes);
	pid_t pid0 = fork();
	if (pid0 == 0)
	{
		dup2(pipes[STDOUT_FILENO],STDOUT_FILENO);
		execve(echo[0], echo , envp);
		write(1, "ayayayayaya", 10);
		exit(1);
	}
	else
	{
		waitpid(pid0, 0, 0);
		close(pipes[STDOUT_FILENO]);
	}

	 pid_t pid = fork();

	 if (pid == 0)
	 {
		dup2(pipes[STDIN_FILENO], STDIN_FILENO);
 		execve(argv[0], argv, envp);
		write(1, "auayayayaya", 10);
		exit(1);
    }
	else{
		waitpid(pid, 0, 0);
		close(pipes[STDIN_FILENO]);
		// printf("aaaaa\n");
		// char buf[999];
		// chdir("/home/dhyeon/som/42cursus/");
	  	// printf("%s\n", getcwd(buf, 999));
	}
  	return 123;
}
