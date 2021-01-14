/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 22:21:14 by dhyeon            #+#    #+#             */
/*   Updated: 2021/01/14 22:22:43 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	calc_dist(t_xy_d sp, t_xy_d pl)
{
	return (sqrt(pow(sp.x - pl.x, 2) + pow(sp.y - pl.y, 2)));
}

void	sort_sprites(t_cub *cub)
{
	int		i;
	int		j;
	t_xy_d	temp;

	i = 0;
	while (i < cub->info.sp_num)
	{
		j = i + 1;
		while (j < cub->info.sp_num)
		{
			if (calc_dist(cub->info.sprites[i], cub->info.pos) <
				calc_dist(cub->info.sprites[j], cub->info.pos))
			{
				temp = cub->info.sprites[i];
				cub->info.sprites[i] = cub->info.sprites[j];
				cub->info.sprites[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	draw_sprites(t_cub *cub, t_sprite *sp)
{
	int i;
	int y;
	int d;
	int c;

	i = sp->draw_s.x - 1;
	while (++i < sp->draw_e.x)
	{
		sp->tex.x = (int)((256 * (i - (-sp->sp_h / 2 + sp->screen_x)) * 64
					/ sp->sp_h) / 256);
		if (sp->transform.y > 0 && i > 0 && i < cub->conf.w
			&& sp->transform.y < cub->info.zbuffer[i])
		{
			y = sp->draw_s.y - 1;
			while (++y < sp->draw_e.y)
			{
				d = (y - sp->mv_screen) * 256 - cub->conf.h * 128
												+ sp->sp_h * 128;
				sp->tex.y = ((d * 64) / sp->sp_h) / 256;
				c = cub->info.texture[4][64 * sp->tex.y + sp->tex.x];
				if ((c & 0x00FFFFFF) != 0)
					cub->info.buf[y][i] = c;
			}
		}
	}
}

void	calc_sprites(t_cub *cub, t_sprite *sp)
{
	int i;

	i = -1;
	while (++i < cub->info.sp_num)
	{
		sp->sp_dir.x = cub->info.sprites[i].x - cub->info.pos.x;
		sp->sp_dir.y = cub->info.sprites[i].y - cub->info.pos.y;
		sp->inv_det = 1.0 / (cub->info.plane.x * cub->info.dir.y
					- cub->info.dir.x * cub->info.plane.y);
		sp->transform.x = sp->inv_det * (cub->info.dir.y * sp->sp_dir.x
					- cub->info.dir.x * sp->sp_dir.y);
		sp->transform.y = sp->inv_det * (-cub->info.plane.y * sp->sp_dir.x
					+ cub->info.plane.x * sp->sp_dir.y);
		sp->screen_x = (int)(cub->conf.w / 2)
					* (1 + sp->transform.x / sp->transform.y);
		sp->mv_screen = (int)(300 / sp->transform.y);
		sp->sp_h = (int)fabs((cub->conf.h / sp->transform.y) / 1);
		sp->draw_s.y = ft_max(-sp->sp_h / 2 + cub->conf.h / 2 + sp->mv_screen
						, 0);
		sp->draw_e.y = ft_min(sp->sp_h / 2 + cub->conf.h / 2 + sp->mv_screen,
								cub->conf.h - 1);
		sp->draw_s.x = ft_max(-sp->sp_h / 2 + sp->screen_x, 0);
		sp->draw_e.x = ft_min(sp->sp_h / 2 + sp->screen_x, cub->conf.w - 1);
		draw_sprites(cub, sp);
	}
}

void	render_sprite(t_cub *cub)
{
	t_sprite	sp;

	sort_sprites(cub);
	calc_sprites(cub, &sp);
}
