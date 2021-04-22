// 인자는 op파일 한개만 => 틀릴경우 Error: argument\n
// open, read 실패시 => Error: Operation file corrupted/n
// error 일시 return 1, error 아닌 경우 return 0
// op파일 형식
	// WIDTH HEIGHT BACKGROUND_CHAR => 0 < (int)WIDTH, HEIGHT <= 300
	// r X Y WIDTH HEIGHT CHAR => (float)WIDTH, HEIGHT = top left corner / 0 < (float)WIDTH, HEIGHT
		// => empty rectangle
	// R X Y WIDTH HEIGHT CHAR => (float)WIDTH, HEIGHT = top left corner / 0 < (float)WIDTH, HEIGHT
// allowed function : fopen, fread, fscanf, fclose, write, malloc, calloc, realloc, free, memset, powf, sqrtf
#include "micro_paint.h"

char	map[301][301];
int 	w, h;
char	c;

int	close_file(FILE *fd)
{
	if (fd)
		fclose(fd);
	return (1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	print_error(char *str)
{
	write(1, str, ft_strlen(str));
	return (1);
}

int	check_arg(int w, int h, char c, int size)
{
	if (size != 3)
		return (-1);
	if (c == 0)
		return (-1);
	if (!(0 < w && w <= 300) || !(0 < h && h <= 300))
		return (-1);
	return (0);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	print_map(void)
{
	int	i;

	i = 0;
	while (i < h)
	{
		ft_putstr(map[i]);
		write(1, "\n", 1);
		i++;
	}
}

int	make_empty_map(void)
{
	int	i;

	i = 0;
	while (i < h)
	{
		memset(map[i], c, w);
		map[i][w] = 0;
		i++;
	}
	return (1);
}

int	check_draw(t_info *info)
{
	if (info->w <= 0 || info->h <= 0 || info->c == 0)
		return (0);
	if (!(info->type == 'r' || info->type == 'R'))
		return (0);
	//map 에 그리기
	int i = 0;
	int j = 0;
	while (h > i)
	{
		j = 0;
		while (w > j)
		{
			if (!(info->x <= j && j <= info->x + info->w) || !(info->y <= i && i <= info->y + info->h))
			{
				j++;
				continue ;
			}
			if (j - info-> x < 1.0 || i - info->y < 1.0 || info->x + info->w - j < 1.0 || info->y + info->h - i < 1.0)
				map[i][j] = info->c;
			else if (info->type == 'R')
				map[i][j] = info->c;
			j++;
		}
		i++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	t_info	info;
	FILE	*fd;
	int		size;

	if (argc != 2)
		return (print_error("Error: argument\n"));
	if (!(fd = fopen(argv[1], "r")))
		return (print_error("Error: Operation file corrupted\n"));
	if ((size = fscanf(fd, "%d %d %c\n", &w, &h, &c)) == -1)
		return (close_file(fd) && print_error("Error: Operation file corrupted\n"));
	if (check_arg(w, h, c, size) == -1)
		return (close_file(fd) && print_error("Error: Operation file corrupted\n"));
	make_empty_map();
	// printf("check =====\n");
	// printf("w : %d h : %d c : %c\n", w, h, c);
	while ((size = fscanf(fd, "%c %f %f %f %f %c\n", &info.type, &info.x, &info.y, &info.w, &info.h, &info.c)) != EOF)
	{
		// printf("size = %d\n", size);
		// printf("t : %c x: %f y: %f w : %f h : %f c : %c\n", info.type, info.x, info.y, info.w, info.h, info.c);
		if (size != 6)
			return (close_file(fd) && print_error("Error: Operation file corrupted\n"));
		// if (info.x + info.w < 0 || info.y + info.h < 0)
		// 	continue ;
		if (!check_draw(&info))
			return (close_file(fd) && print_error("Error: Operation file corrupted\n"));
	}
	print_map();
	fclose(fd);
	return (0);
}
