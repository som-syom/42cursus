/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 02:48:15 by dhyeon            #+#    #+#             */
/*   Updated: 2021/01/15 00:39:48 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		print_err(int num)
{
	if (num == -1)
		printf("Error : Malloc Fail\n");
	else if (num == -2)
		printf("Error : Path Not Found\n");
	else if (num == -3)
		printf("Error : Invalid Map File\n");
	else if (num == -4)
		printf("Error : Invalid num arg\n");
	exit(-1);
}

void		draw(t_cub *cub)
{
	int x;
	int y;

	y = -1;
	while (++y < cub->conf.h)
	{
		x = 0;
		while (x < cub->conf.w)
		{
			cub->info.img->data[y * cub->conf.w + x] = cub->info.buf[y][x];
			x++;
		}
	}
	mlx_put_image_to_window(cub->info.mlx, cub->info.win, cub->info.img, 0, 0);
}

int			main_loop(t_cub *cub)
{
	calc(cub);
	draw(cub);
	return (0);
}

void		game_start(t_cub *cub)
{
	cub->info.win = mlx_new_window(cub->info.mlx, cub->conf.w, cub->conf.h,
									"CUB3D");
	cub->info.img = mlx_new_image(cub->info.mlx, cub->conf.w, cub->conf.h);
	if (cub->conf.is_save == 1)
	{
		main_loop(cub);
		save_bmp(cub);
	}
	mlx_hook(cub->info.win, 2, 1, key_press, cub);
	mlx_hook(cub->info.win, 17, 1 << 5, ft_exit, 0);
	mlx_loop_hook(cub->info.mlx, main_loop, cub);
	mlx_loop(cub->info.mlx);
}

int			main(int argc, char **argv)
{
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
	game_start(&cub);
	return (0);
}
