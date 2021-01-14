/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 22:51:01 by dhyeon            #+#    #+#             */
/*   Updated: 2021/01/15 00:24:59 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_player_dir(t_cub *cub, char dir)
{
	cub->info.dir.x = 0;
	cub->info.dir.y = 0;
	cub->info.plane.x = 0;
	cub->info.plane.y = 0;
	if (dir == 'N')
	{
		cub->info.dir.x = -1;
		cub->info.plane.y = 0.66;
	}
	if (dir == 'E')
	{
		cub->info.dir.y = -1;
		cub->info.plane.x = -0.66;
	}
	if (dir == 'W')
	{
		cub->info.dir.y = 1;
		cub->info.plane.x = 0.66;
	}
	if (dir == 'S')
	{
		cub->info.dir.x = 1;
		cub->info.plane.y = -0.66;
	}
}

int		set_player_pos(t_cub *cub, int i, int j)
{
	cub->info.pos.x = i + 0.5;
	cub->info.pos.y = j + 0.5;
	return (0);
}

void	save_sprite(t_cub *cub)
{
	int cnt;
	int i;
	int j;

	cub->info.sprites = ft_calloc(cub->info.sp_num, sizeof(t_xy_d));
	cnt = 0;
	i = -1;
	while (++i < cub->conf.map_size.y + 2)
	{
		j = -1;
		while (cub->conf.map[i][++j] != '\0')
		{
			if (cub->conf.map[i][j] == '2')
			{
				cub->info.sprites[cnt].x = i;
				cub->info.sprites[cnt].y = j;
				cnt++;
			}
		}
	}
}

int		check_player_sp(t_config *conf, t_cub *cub, int i, int j)
{
	if (conf->player_dir == 0)
		return (-3);
	else
		set_player_dir(cub, conf->player_dir);
	i = -1;
	while (++i < conf->map_size.y + 2)
	{
		j = -1;
		while (conf->map[i][++j] != '\0')
		{
			if (ft_strchr("NEWS", conf->map[i][j]) != 0)
			{
				if (set_player_pos(cub, i, j) != 0)
					return (-3);
			}
			if (conf->map[i][j] == '2')
				cub->info.sp_num++;
		}
	}
	save_sprite(cub);
	return (0);
}
