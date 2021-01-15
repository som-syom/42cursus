/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 22:10:39 by dhyeon            #+#    #+#             */
/*   Updated: 2021/01/15 01:04:27 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			parse_data(t_cub *cub)
{
	int		i;
	int		x;
	int		y;

	i = -1;
	while (++i < 5)
	{
		if (!(cub->dummy[i] = mlx_xpm_file_to_image(cub->info.mlx,
			cub->conf.tex_path[i], &x, &y)) || x != 64 || y != 64)
			return (-2);
		cub->info.texture[i] = cub->dummy[i]->data;
	}
	if (!(cub->info.buf = (int **)malloc(sizeof(int *) * (cub->conf.h + 1))))
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

int			init_all(t_cub *cub)
{
	int save;

	save = cub->conf.is_save;
	ft_memset(&cub->conf, 0, sizeof(cub->conf));
	cub->conf.is_save = save;
	if (!(cub->conf.tex_path = ft_calloc(5, sizeof(char *))))
		return (-1);
	if (!(cub->info.texture = (int **)malloc(sizeof(int *) * 5)))
		return (-1);
	cub->conf.map_lst = 0;
	ft_memset(cub->conf.rgb, -1, sizeof(int) * 2);
	cub->info.sp_num = 0;
	cub->info.move_speed = 0.1;
	cub->info.rot_speed = 0.1;
	return (0);
}

int			check_arg(int ac, char **av, t_config *conf)
{
	int	len;

	if (ac >= 4 || ac == 1)
		return (-4);
	if (ac == 3 && !(ft_strncmp(av[2], "--save", 6)))
		conf->is_save = 1;
	else if (ac == 3)
		return (-4);
	len = ft_strlen(av[1]);
	if (ft_strncmp(av[1] + len - 4, ".cub", 4) != 0)
		return (-3);
	return (0);
}
