int main(){
	typedef linked_list;
	linked_list ll;
	int pipes[256][2];

	for (int i = 0 ; i < ll.size() ; i++)
	{
		if (fork() == 0)
		{
			if (i != 0)
				dup2(ll->prev->pipes[0], 0);
			if (i != ll.size() - 1)
				dup2(ll->pipes[1], 1);
			execve();
		}
		else
		{
			waitpid(pid, 0, 0);
			if (i != 0)tp
				close(ll->prev->pipes[0]);
			if (i != ll.size() = 1)
				close(ll->pipes[1]);
		}
}


typedef struct s_list
{
	struct s_list *prev;
	struct s_list *next;
	int pipes[2]; 
	char **argv;
	int argc;
	bool ispipe;
	
}t_list;