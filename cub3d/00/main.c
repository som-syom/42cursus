/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 02:48:15 by dhyeon            #+#    #+#             */
/*   Updated: 2021/01/13 07:27:06 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    print_err(int err_num)
{
	//나중에 정리하기
	if (err_num == -1)
		ft_putstr("인자 오류\n");
	else if (err_num == -2)
		ft_putstr("맵 확장자 오류\n");
	else if (err_num == -3)
		ft_putstr("맵 오류\n");
	else if (err_num == -4)
		ft_putstr("파일 읽기 오류\n");
	perror("error message");
	exit(1);
}

int     check_arg(int ac, char **av, t_config * conf)
{
	int		len;

	if (ac >= 4)
		return (-1);
	if (ac == 3 && !(ft_strncmp(av[2], "--save", 6)))
		conf->is_save = 1;
	else if (ac == 3)
		return (-1);
	len = ft_strlen(av[1]);
	if (ft_strncmp(av[1] + len - 4, ".cub", 4) != 0)
		return (-2);
	return (0);
}

int		init_all(t_cub *cub)
{
	int i;
	int save;

	save = cub->conf.is_save;
	ft_memset(&cub->conf, 0, sizeof(cub->conf));
	cub->conf.is_save = save;
	if (!(cub->conf.tex_path = ft_calloc(4, sizeof(char *))))
		return (-1);
	if (!(cub->info.texture = (int **)malloc(sizeof(int *) * 5)))
		return (-1);
	i = -1;
	while (++i < 4)
	{
		if (!(cub->info.texture[i] = ft_calloc(64 * 64, sizeof(int))))
			return (-1);
	}
	if (!(cub->conf.map_lst = malloc(sizeof(t_list))))
		return (-1);

	cub->conf.map_lst = 0;
	ft_memset(cub->conf.rgb, -1, sizeof(int) * 2);
	// i = -1;
	// while (++i < 8)
	// 	cub->conf.tex_path[i] = 0;
	cub->info.sp_num = 0;
	cub->info.move_speed = 0.1;
	cub->info.rot_speed = 0.1;
	return (0);
}

void	draw(t_cub *cub)
{
	int x;
	int y;

	y = 0;
	while (y < cub->conf.h)
	{
		x = 0;
		while (x < cub->conf.w)
		{
			cub->info.img->data[y * cub->conf.w + x] = cub->info.buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(cub->info.mlx, cub->info.win, cub->info.img, 0, 0);
}



int		parse_data(t_cub *cub)
{
	int i;
	int x;
	int y;

	i = -1;
	while (++i < 5)
	{
		if (!(cub->info.texture[i] = mlx_xpm_file_to_image(cub->info.mlx,
			cub->conf.tex_path[i], &x, &y)) || x != 64 || y != 64)
			return (-4);
	}
	if(!(cub->info.buf = (int **)malloc(sizeof(int *) * (cub->conf.h + 1))))
		return (-1);
	i = -1;
	while (++i < cub->conf.h)
	{
		if (!(cub->info.buf[i] = ft_calloc(cub->conf.w + 1, sizeof(int))))
			return (-1);
	}
	if (!(cub->info.zbuffer = ft_calloc(cub->conf.w, sizeof(double *))))
		return (-1);
	return (0);
}

int		add_header(const int fd, t_cub *cub)
{
	t_bmp_header		header;
	int					tmp;
	const unsigned char	header_base[] = {
		0x42, 0x4D, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x01, 0x00, 0x18, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	};

	ft_memcpy(&header, header_base, sizeof(header));
	header.width = cub->conf.w;
	header.height = cub->conf.h;
	tmp = 3 * header.width;
	while (tmp % 4 != 0)
		tmp++;
	header.imgsz = tmp * header.height;
	header.filesz = header.start_offset_54 + header.imgsz;
	write(fd, &header, sizeof(header));
	return (tmp - 3 * header.width);
}

void	draw_img(const int fd, t_cub *cub, int padding)
{
	int	i;
	int	j;

	i = cub->conf.h;
	while (--i >= 0)
	{
		j = -1;
		while (++j < cub->conf.w)
			write(fd, &cub->info.img->data[i * cub->conf.w + j], 3);
		j = -1;
		while (++j < padding)
			write(fd, "\x00", 1);
	}
}

void	save_bmp(t_cub *cub)
{
	const int fd = open("screenshot.bmp", O_CREAT | O_RDWR | O_TRUNC, 0644);

	if (fd == -1)
		print_err(-1);
	draw_img(fd, cub, add_header(fd, cub));
	close(fd);
	exit(0);
}

int		main_loop(t_cub *cub)
{
	calc(cub);
	draw(cub);
	return (0);
}

int     main(int argc, char **argv)
{
	// t_config    conf;
	t_cub		cub;
	int			err_num;

	cub.info.mlx = mlx_init();
	if ((err_num = check_arg(argc, argv, &cub.conf)) != 0)
		print_err(err_num);
	if ((err_num = init_all(&cub)) != 0)
		print_err(err_num);
	if ((err_num = set_map(&cub, &cub.conf, argv[1])) != 0)
		print_err(err_num);
	if ((err_num = parse_data(&cub)) != 0)
		print_err(err_num);
	cub.info.win = mlx_new_window(cub.info.mlx, cub.conf.w, cub.conf.h, "CUB3D");
	cub.info.img = mlx_new_image(cub.info.mlx, cub.conf.w, cub.conf.h);
	if (cub.conf.is_save == 1)
	{
		main_loop(&cub);
		save_bmp(&cub);
	}
	// cub.info.img.data = (int *)mlx_get_data_addr(cub.img.img,)
	mlx_hook(cub.info.win, 2, 1, &key_press, &cub);
	mlx_loop_hook(cub.info.mlx, &main_loop, &cub);
	mlx_loop(cub.info.mlx);
	return (0);
}
