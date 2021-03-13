#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int ac, char** av, char**envp)
{
   char* argv[] = {"/bin/cat", 0};
	 pid_t pid = fork();

	 if (pid == 0)
	 {
		write(1, "Hello\n", 6);
 		execve(argv[0], argv, envp);
		write(1, "World\n", 6);
		exit(345);
    }
	  waitpid(pid, 0, 0);
	  printf("aaaaa\n");
	char buf[999];
	chdir("/home/dhyeon/som/42cursus/");
	  printf("%s\n", getcwd(buf, 999));
  	return 123;
}
