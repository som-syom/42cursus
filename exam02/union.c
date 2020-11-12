#include <unistd.h>

int main(int argc, char **argv)
{
	char save[200];
	int i = 1, j;
	int a = 0, count = 0;

	if (argc == 3)
	{
		while (i < 3)
		{
			j = 0;
			while (argv[i][j] != 0)
			{
				a = count;
				while (a >= 0)
				{
					if (save[a] == argv[i][j])
						break ;
					a--;
				}
				if (a == -1)
				{
					save[count] = argv[i][j];
					count++;
				}
				j++;
			}
			i++;
		}
		write(1, save, count);
	}
	write(1, "\n", 1);
}