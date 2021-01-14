/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 22:18:50 by dhyeon            #+#    #+#             */
/*   Updated: 2021/01/14 22:25:06 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calc_ray_init(t_cub *cub, t_ray *ray, int *x)
{
	ray->c_x = 2 * (*x) / (double)cub->conf.w - 1;
	ray->r_x = cub->info.dir.x + cub->info.plane.x * ray->c_x;
	ray->r_y = cub->info.dir.y + cub->info.plane.y * ray->c_x;
	ray->m_x = (int)cub->info.pos.x;
	ray->m_y = (int)cub->info.pos.y;
	ray->delta_x = fabs(1 / ray->r_x);
	ray->delta_y = fabs(1 / ray->r_y);
	ray->hit = 0;
}

void	calc_step_init(t_cub *cub, t_ray *ray)
{
	if (ray->r_x < 0)
	{
		ray->step_x = -1;
		ray->side_x = (cub->info.pos.x - ray->m_x) * ray->delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_x = (ray->m_x + 1.0 - cub->info.pos.x) * ray->delta_x;
	}
	if (ray->r_y < 0)
	{
		ray->step_y = -1;
		ray->side_y = (cub->info.pos.y - ray->m_y) * ray->delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_y = (ray->m_y + 1.0 - cub->info.pos.y) * ray->delta_y;
	}
}

void	calc_dda(t_cub *cub, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_x < ray->side_y)
		{
			ray->side_x += ray->delta_x;
			ray->m_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_y += ray->delta_y;
			ray->m_y += ray->step_y;
			ray->side = 1;
		}
		if (cub->conf.map[ray->m_x][ray->m_y] == '1')
			ray->hit = 1;
	}
}

void	calc_basic(t_ray *ray, t_cub *cub)
{
	ray->line_h = (int)(cub->conf.h / ray->perp);
	ray->draw_s = -ray->line_h / 2 + cub->conf.h / 2;
	if (ray->draw_s < 0)
		ray->draw_s = 0;
	ray->draw_e = ray->line_h / 2 + cub->conf.h / 2;
	if (ray->draw_e >= cub->conf.h)
		ray->draw_e = cub->conf.h - 1;
	if (ray->side == 0)
		ray->w_x = cub->info.pos.y + ray->perp * ray->r_y;
	else
		ray->w_x = cub->info.pos.x + ray->perp * ray->r_x;
	ray->w_x -= floor(ray->w_x);
	ray->t_x = (int)(ray->w_x * (double)TEX_W);
	if (ray->side == 0 && ray->r_x > 0)
		ray->t_x = TEX_W - ray->t_x - 1;
	if (ray->side == 1 && ray->r_y < 0)
		ray->t_x = TEX_W - ray->t_x - 1;
	ray->step = 1.0 * TEX_H / ray->line_h;
	ray->t_p = (ray->draw_s - cub->conf.h / 2 + ray->line_h / 2) * ray->step;
}

void	calc(t_cub *cub)
{
	t_ray	ray;
	int		x;

	x = 0;
	draw_fc(cub);
	while (x < cub->conf.w)
	{
		calc_ray_init(cub, &ray, &x);
		calc_step_init(cub, &ray);
		calc_dda(cub, &ray);
		if (ray.side == 0)
			ray.perp = (ray.m_x - cub->info.pos.x + (1 - ray.step_x) / 2)
								/ ray.r_x;
		else
			ray.perp = (ray.m_y - cub->info.pos.y + (1 - ray.step_y) / 2)
								/ ray.r_y;
		cub->info.zbuffer[x] = ray.perp;
		calc_draw(&ray, cub, x);
		x++;
	}
	render_sprite(cub);
}
