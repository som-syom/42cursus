#include "cub3d.h"

#define texHeight 64
#define texWidth 64

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
		// ft_strchr("12", conf->map[ray->map.x][ray->map.y])
		if (cub->conf.map[ray->m_x][ray->m_y]  == '1')
			ray->hit = 1;
	}
}

void	calc_basic(t_ray *ray, t_cub *cub)
{
	ray->line_h = (int)(cub->conf.h / ray->perp);
	ray->draw_s = -ray->line_h / 2 + cub->conf.h / 2;
	if(ray->draw_s < 0)
		ray->draw_s = 0;
	ray->draw_e = ray->line_h / 2 + cub->conf.h / 2;
	if(ray->draw_e >= cub->conf.h)
		ray->draw_e = cub->conf.h - 1;
	if (ray->side == 0)
		ray->w_x = cub->info.pos.y + ray->perp * ray->r_y;
	else
		ray->w_x = cub->info.pos.x + ray->perp * ray->r_x;
	ray->w_x -= floor(ray->w_x);
	ray->t_x = (int)(ray->w_x * (double)texWidth);
	if (ray->side == 0 && ray->r_x > 0)
		ray->t_x = texWidth - ray->t_x - 1;
	if (ray->side == 1 &&  ray->r_y < 0)
		ray->t_x = texWidth - ray->t_x - 1;
	ray->step = 1.0 * texHeight / ray->line_h;
	ray->t_p = (ray->draw_s - cub->conf.h / 2 + ray->line_h / 2) * ray->step;
}

int		get_tex_num(t_ray *ray)
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
	while(i < cub->info.sp_num)
	{
		j = i + 1;
		while (j < cub->info.sp_num)
		{
			if (calc_dist(cub->info.sprites[i], cub->info.pos) < calc_dist(cub->info.sprites[j], cub->info.pos))
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

// int			ft_max(int a, int b)
// {
// 	return (a > b) ? a : b;
// }

// int			ft_min(int a, int b)
// {
// 	return (a < b) ? a : b;
// }

// double		ft_minf(double a, double b)
// {
// 	return (a < b) ? a : b;
// }

// t_sprite	init_sprites(t_xy_d transform, int w, int h)
// {
// 	t_xy_d		center;
// 	t_sprite	ret;

// 	center.x = w * 0.5;
// 	center.y = h * 0.5;
// 	ret.screen_x = center.x * (1 + transform.x / transform.y);
// 	ret.offset = 300 / transform.y;
// 	ret.size = fabs(h / transform.y);
// 	ret.draw_x.x = ft_max(0, ret.screen_x - ret.size / 2);
// 	ret.draw_x.y = ft_min(w - 1, ret.size / 2 + ret.screen_x);
// 	ret.draw_y.x = ft_max(0, center.y - ret.size / 2 + ret.offset);
// 	ret.draw_y.y = ft_min(h - 1, center.y + ret.size / 2 + ret.offset);
// 	return (ret);
// }

// void	draw_sprites(t_cub *cub, t_sprite sp, t_xy_d transform)
// {
// 	sp.x = sp.draw_x.x - 1;
// 	while (++sp.x < sp.draw_x.y)
// 	{
// 		sp.xoffset = (sp.draw_x.x <= 0) ?
// 				(sp.x - sp.draw_x.y + sp.size) / sp.size :
// 				(sp.x - sp.draw_x.x) / sp.size;
// 		sp.tx = ft_minf(64 * sp.xoffset + 0.5, 63);
// 		if (transform.y > 0 && sp.tx > 0 && sp.tx < cub->conf.w &&
// 							transform.y < cub->info.zbuffer[sp.x])
// 		{
// 			sp.y = sp.draw_y.x - 1;
// 			while (++sp.y < sp.draw_y.y)
// 			{
// 				sp.yoffset = (sp.y - sp.draw_y.x) / sp.size;
// 				sp.ty = ft_minf(64 * sp.yoffset + 0.5, 63);
// 				if (cub->info.texture[4][64 * sp.ty + sp.tx] & 0x00ffffff)
// 					cub->info.buf[sp.y][sp.x] = cub->info.texture[4][64 * sp.ty + sp.tx];
// 			}
// 		}
// 	}
// }

// void	render_sprite(t_cub *cub)
// {
// 	int			i;
// 	t_xy_d		sp_d;
// 	double		inv_det;
// 	t_xy_d		transform;
// 	t_sprite	sp;

// 	sort_sprites(cub);
// 	i = -1;
// 	while (++i < cub->info.sp_num)
// 	{
// 		sp_d.x = cub->info.sprites[i].x - cub->info.pos.x;
// 		sp_d.y = cub->info.sprites[i].y - cub->info.pos.y;
// 		inv_det = 1.0 / (cub->info.plane.x * cub->info.dir.y
// 					- cub->info.dir.x * cub->info.plane.y);
// 		transform.x = inv_det * (cub->info.dir.y * sp_d.x - cub->info.dir.x * sp_d.y);
// 		transform.y = inv_det * (cub->info.plane.y * sp_d.x + cub->info.plane.x * sp_d.y);
// 		sp = init_sprites(transform, cub->conf.w, cub->conf.h);
// 		draw_sprites(cub, sp, transform);
// 	}
// }

void	calc_draw(t_ray *ray, t_cub *cub, int x)
{
	calc_basic(ray, cub);
	ray->tex_num = get_tex_num(ray);
	int y = ray->draw_s;
	while (y < ray->draw_e)
	{
		ray->t_y = (int)ray->t_p & (texHeight - 1);
		ray->t_p += ray->step;
		ray->color = cub->info.texture[ray->tex_num][texHeight * ray->t_y + ray->t_x];
		if (ray->side == 1)
			ray->color = (ray->color >> 1) & 8355711;
		cub->info.buf[y][x] = ray->color;
		y++;
	}
}

void	draw_fc(t_cub *cub)
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
	// render_sprite(cub);
}
