/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 12:12:25 by yohan             #+#    #+#             */
/*   Updated: 2020/11/25 06:58:19 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	worldMap[24][24] = {
							{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
							{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
							{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
						};

// void	verLine(t_info *info, int x, int y1, int y2, int color)
// {
// 	int	y;

// 	y = y1;
// 	while (y <= y2)
// 	{
// 		mlx_pixel_put(info->mlx, info->win, x, y, color);
// 		y++;
// 	}
// }

void	draw(t_info *info)
{
	int x;
	int y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			info->img.data[y * width + x] = info->buf[y][x];
			x++;
		}
		y++;
	}

	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

int	main_loop(t_info *info)
{
	calc(info);
	// mlx_put_image_to_window(info->mlx, info->win, &info->img, 0, 0);
	draw(info);
	return (0);
}

void	load_image(t_info *info, int *texture, char *path, t_img *img)
{
	int x;
	int y;

	x = 0;
	y = 0;
	img->img = mlx_xpm_file_to_image(info->mlx, path,
					&img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp,
					&img->size_l, &img->endian);
	printf("width %d, height %d\n", img->img_width, img->img_height);
	y = 0;
	while (y < img->img_height)
	{
		x = 0;
		while (x < img->img_width)
		{
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
			x++;
		}
		y++;
	}

	// int j = 0;
	// while (j < texHeight * texWidth)
	// {
	// 	texture[j] = img->data[j];
	// 	j++;
	// }
	
	mlx_destroy_image(info->mlx, img->img);
}

void	load_texture(t_info *info)
{
	t_img	img;

	load_image(info, info->texture[0], "textures/concrete.xpm", &img);
	load_image(info, info->texture[1], "textures/concrete.xpm", &img);
	load_image(info, info->texture[2], "textures/concrete.xpm", &img);
	load_image(info, info->texture[3], "textures/concrete.xpm", &img);
	load_image(info, info->texture[4], "textures/concrete.xpm", &img);
	load_image(info, info->texture[5], "textures/concrete.xpm", &img);
	load_image(info, info->texture[6], "textures/concrete.xpm", &img);
	load_image(info, info->texture[7], "textures/concrete.xpm", &img);
}

int	main(void)
{
	t_info	info;

	info_new(&info);

	
	info.win = mlx_new_window(info.mlx, width, height, "mlx");

	//test
	int i;
	int j;
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			info.buf[i][j] = 0;
			j++;
		}
		i++;
	}
	
	if ((info.texture = (int **)malloc(sizeof(int *) * 8)) == 0)
		return (-1);
	i = 0;
	while (i < 8)
	{
		if (!(info.texture[i] = (int *)malloc(sizeof(int) * (texHeight * texWidth))))
			return (-1);
		i++;
	}

	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < texHeight * texWidth)
		{
			info.texture[i][j] = 0xFF0000;
			j++;
		}
		i++;
	}
	load_texture(&info);
	
	info.img.img = mlx_new_image(info.mlx, width, height);
	info.img.data = (int *)mlx_get_data_addr(info.img.img, &info.img.bpp,
									&info.img.size_l, &info.img.endian);

	//
	mlx_loop_hook(info.mlx, &main_loop, &info);
	mlx_hook(info.win, X_EVENT_KEY_PRESS, 0, &key_press, &info);

	mlx_loop(info.mlx);
}
