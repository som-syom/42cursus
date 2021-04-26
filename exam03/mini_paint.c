#include "mini_paint.h"

char map[301][301];
int w, h;
char c;
float cx, cy, cr;
char cc, ct;

int error_ret(FILE *fd, int flag)
{
	if (flag == 1 && fd)
		fclose(fd);
	write(1, "Error: Operation file corrupted\n", 32);
	return (1);
}

int	get_map(FILE *fd)
{
	int size;
	size = fscanf(fd, "%d %d %c\n", &w, &h, &c);
	if (size != 3 || !(0 < w && w <= 300) || !(0 < h && h <= 300) || c == 0)
	{
		return (-1);
	}
	int i = 0;
	int j = 0;
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			map[i][j] = c;
			j++;
		}
		map[i][j] = '\0';
		i++;
	}
	return (0);
}

void	draw_circle(void)
{
	int i, j;

	i = 0;
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			if (sqrtf(((cx - j) * (cx - j)) + ((cy - i) * (cy - i))) > cr)
			{
				j++;
				continue ;
			}
			if (cr - sqrtf(((cx - j) * (cx - j)) + ((cy - i) * (cy - i))) < 1.00000000)
				map[i][j] = cc;
			else if (ct == 'C')
				map[i][j] = cc;
			j++;
		}
		i++;
	}
}

void	ft_putstr(char *str)
{
	int i = 0;

	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	print_map(void)
{
	int i = 0;

	while (i < h)
	{
		ft_putstr(map[i]);
		write(1, "\n", 1);
		i++;
	}
}

int main(int argc, char **argv)
{
	FILE *fd;
	int size;

	if (argc != 2)
	{
		write(1, "Error: argument\n", 17);
		return (1);
	}
	if (!(fd = fopen(argv[1], "r")))
		return (error_ret(fd, 0));
	if (get_map(fd) == -1)
		return (error_ret(fd, 1));
	while ((size = fscanf(fd, "%c %f %f %f %c\n", &ct, &cx, &cy, &cr, &cc)) == 5)
	{
		if ((ct != 'c' && ct != 'C') || cr <= 0)
			return (error_ret(fd, 1));
		if (cx + cr < 0.0000 || cy + cr < 0.0000)
			continue ;
		draw_circle();
	}
	if (size != -1)
		return (error_ret(fd, 1));
	print_map();
	fclose(fd);
	return (0);
}
