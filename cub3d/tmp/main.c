/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 20:05:19 by dhyeon            #+#    #+#             */
/*   Updated: 2020/11/16 21:02:42 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

typedef struct	s_param
{
	int		x;
	int		y;
	char	str[3];
}				t_param;

typedef struct	s_img
{
	void	*ptr;
	int		*data;
	int		width;
	int		height;

	int		size_l;
	int		bpp;
	int		endian;
}				t_img;

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win;
}				t_mlx;

void	param_init(t_param *param)
{
	param->x = 3;
	param->y = 4;
	param->str[0] = 'a';
	param->str[1] = 'b';
	param->str[2] = '\0';
}

int		key_press(int keycode, t_param *param)
{
	static int	a = 0;

	if (keycode == KEY_W)
		param->x++;
	else if (keycode == KEY_S)
		param->x--;
	else if (keycode == KEY_D)
		param->y++;
	else if (keycode == KEY_A)
		param->y--;
	else if (keycode == KEY_ESC)
		exit(0);
	printf("x : %d | y : %d \n", param->x, param->y);
	return(0);
}

int		main(void)
{
	t_mlx	*mlx;
	t_img	img;
	t_param	param;
	int		count_w;
	int		count_h;

	param_init(&param);
	mlx->mlx_ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "dhyen_example");
	//img.img_ptr = mlx_new_image(mlx->mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
	img.ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, "./texture/wall_s.xpm", &img.width, &img.height);
	img.data = (int *)mlx_get_data_addr(img.ptr, &img.bpp, &img.size_l, &img.endian);

	count_h = -1;
	while (++count_h < img.height)
	{
		count_w = -1;
		while (++count_w < img.width / 2)
		{
			if (count_w % 2)
				img.data[count_h * img.width + count_w] = 0xFFFFFF;
			else
				img.data[count_h * img.width + count_w] = 0xFF0000;
		}
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, img.ptr, 50, 50);


	printf("--------------------\n");
	printf("Current \nx : %d | y : %d\n", param.x, param.y);
	mlx_hook(mlx->win, X_EVENT_KEY_PRESS, 0, &key_press, &param);
	mlx_loop(mlx->mlx_ptr);
}
