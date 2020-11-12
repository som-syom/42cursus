#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	char save[200];
	int j, k;
	int a = 0, count = 0;

	if (argc == 3)
	{
		j = 0;
		while (argv[1][j] != 0)
		{
			k = 0;
			while (argv[2][k] != 0)
			{
				if (argv[1][j] == argv[2][k])
				{
					a = count;
					while (a >= 0)
					{
						if (save[a] == argv[1][j])
							break ;
						a--;
					}
					if (a == -1)
					{
						save[count] = argv[1][j];
						count++;
						break ;
					}
				}
				k++;
			}
			j++;
		}
	}
	// printf("%s", save);
	write(1, save, count);
	write(1, "\n", 1);
	return (0);
}