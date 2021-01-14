/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 22:23:33 by dhyeon            #+#    #+#             */
/*   Updated: 2021/01/14 22:49:37 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_max(int a, int b)
{
	return (a > b) ? a : b;
}

int			ft_min(int a, int b)
{
	return (a < b) ? a : b;
}

int			get_tex_num(t_ray *ray)
{
	if (ray->side)
	{
		if (ray->r_y * -1 < 0)
			return (3);
		return (2);
	}
	if (ray->r_x * -1 < 0)
		return (1);
	return (0);
}

void		calc_draw(t_ray *ray, t_cub *cub, int x)
{
	int y;

	calc_basic(ray, cub);
	ray->tex_num = get_tex_num(ray);
	y = ray->draw_s;
	while (y < ray->draw_e)
	{
		ray->t_y = (int)ray->t_p & (TEX_H - 1);
		ray->t_p += ray->step;
		ray->color = cub->info.texture[ray->tex_num][
						TEX_H * ray->t_y + ray->t_x];
		if (ray->side == 1)
			ray->color = (ray->color >> 1) & 8355711;
		cub->info.buf[y][x] = ray->color;
		y++;
	}
}

void		draw_fc(t_cub *cub)
{
	int i;
	int j;

	i = -1;
	while (++i < cub->conf.h)
	{
		j = -1;
		while (++j < cub->conf.w)
		{
			if (i < cub->conf.h / 2)
				cub->info.buf[i][j] = cub->conf.rgb[1];
			else
				cub->info.buf[i][j] = cub->conf.rgb[0];
		}
	}
}
