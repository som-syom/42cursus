// 인자는 op파일 한개만 => 틀릴경우 Error: argument\n
// open, read 실패시 => Error: Operation file corrupted/n
// error 일시 return 1, error 아닌 경우 return 0
// op파일 형식
	// WIDTH HEIGHT BACKGROUND_CHAR => 0 < (int)WIDTH, HEIGHT <= 300
	// r X Y WIDTH HEIGHT CHAR => (float)WIDTH, HEIGHT = top left corner / 0 < (float)WIDTH, HEIGHT
		// => empty rectangle
	// R X Y WIDTH HEIGHT CHAR => (float)WIDTH, HEIGHT = top left corner / 0 < (float)WIDTH, HEIGHT
// allowed function : fopen, fread, fscanf, fclose, write, malloc, calloc, realloc, free, memset, powf, sqrtf
#include "test_micro.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	print_error(char *str)
{
	write(1, str, ft_strlen(str));
	return (1);
}

int	check_arg(int w, int h, char c)
{
	if (c == 0)
		return (-1)
	if (!(0 < w && w <= 300) || !(0 < h && h <= 300))
		return (-1);
	return (0);
}

int	make_empty_map(t_info *info)
{
	int	i;
	int	j;

	if (!(info->map = (char **)malloc(sizeof(char *) * (h + 1))))
		return (0);
	memset((void *)info->map, 0, sizeof(info->map));
	i = 0;
	while (i < h)
	{
		j = 0;
		if (!(info->map[i] = (char *)malloc(sizeof(char) * (w + 1))))
			return (0);
		while (j < w)
		{
			info->map[i][j] = info->c;
			j++;
		}
		info->map[i][j] = 0;
		i++;
	}
	info->map[i] = 0;
	return (1);
}

int	check_draw(t_info *info)
{
	if (info->rec.w <= 0 || info->rec.h <= 0 || info->rec.c == 0)
		return (0);
	//map 에 그리기
	return (1);
}

void	print_map(t_info *info)
{
	//map 출력하기
}

int main(int argc, char **argv)
{
	t_info	info;
	FILE	*fd;
	int		size;

	if (argc != 2)
		print_error("Error: argument\n");
	if (fd = fopen(argv[1], "r") < 0)
		print_error("Error: Operation file corrupted\n");
	if (fscanf(fd, "%d %d %c", info.w, info.h, info.c) == -1)
		print_error("Error: Operation file corrupted\n");
	if (check_arg(info.w, info.h, info.c) == -1)
		return (1);
	if (!make_empty_map(&info))
		return (1);
	while ((size = fscanf(fd, "%c %f %f %f %f %c", info.rec.type, info.rec.x, info.rec.y, info.rec.w, info.rec.h, info.rec.c)) != EOF)
	{
		if (size != 6 || !check_draw(&info))
			print_error("Error\n");
	}
	print_rec(&info);

	return (0);
}