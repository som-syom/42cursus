#include "cub3d.h"

void	calc(t_info *info)
{
	t_ray	ray;
	int		x;

	x = 0;
	while (x < width)
	{
		calc_ray_init(info, &ray, &x);
		calc_step_init(info, &ray);
		calc_dda(info, &ray);
		
		if (ray.side == 0)
			ray.perpWallDist = (ray.mapX - info->posX + (1 - ray.stepX) / 2)
								/ ray.rayDirX;
		else
			ray.perpWallDist = (ray.mapY - info->posY + (1 - ray.stepY) / 2)
								/ ray.rayDirY;
		calc_draw(&ray);
		verLine(info, x, ray.drawStart, ray.drawEnd, ray.color);
		x++;
	}
}

void	calc_ray_init(t_info *info, t_ray *ray, int *x)
{
	ray->cameraX = 2 * (*x) / (double)width - 1; // 카메라 평면 구하기
	ray->rayDirX = info->dirX + info->planeX * ray->cameraX; // (방향벡터 + 카메라평면 * 배수)
	ray->rayDirY = info->dirY + info->planeY * ray->cameraX;
	ray->mapX = (int)info->posX;
	ray->mapY = (int)info->posY;
	ray->deltaDistX = fabs(1 / ray->rayDirX); //
	ray->deltaDistY = fabs(1 / ray->rayDirY);
	ray->hit = 0;
}

void	calc_step_init(t_info *info, t_ray *ray)
{
	/*	초기값구하기
		
	*/
	if (ray->rayDirX < 0)
	{
		ray->stepX = -1;
		ray->sideDistX = (info->posX - ray->mapX) * ray->deltaDistX;
	}
	else
	{
		ray->stepX = 1;
		ray->sideDistX = (ray->mapX + 1.0 - info->posX) * ray->deltaDistX;
	}
	if (ray->rayDirY < 0)
	{
		ray->stepY = -1;
		ray->sideDistY = (info->posY - ray->mapY) * ray->deltaDistY;
	}
	else
	{
		ray->stepY = 1;
		ray->sideDistY = (ray->mapY + 1.0 - info->posY) * ray->deltaDistY;
	}
}

void	calc_dda(t_info *info, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->sideDistX < ray->sideDistY)
		{
			ray->sideDistX += ray->deltaDistX;
			ray->mapX += ray->stepX;
			ray->side = 0;
		}
		else
		{
			ray->sideDistY += ray->deltaDistY;
			ray->mapY += ray->stepY;
			ray->side = 1;
		}
		if (worldMap[ray->mapX][ray->mapY] > 0)
			ray->hit = 1;
	}
}

void	calc_draw(t_ray *ray)
{
	ray->lineHeight = (int)(height / ray->perpWallDist);
	ray->drawStart = -ray->lineHeight / 2 + height / 2;
	if(ray->drawStart < 0)
		ray->drawStart = 0;
	ray->drawEnd = ray->lineHeight / 2 + height / 2;
	if(ray->drawEnd >= height)
		ray->drawEnd = height - 1;

	if (worldMap[ray->mapY][ray->mapX] == 1)
		ray->color = 0xFF0000;
	else if (worldMap[ray->mapY][ray->mapX] == 2)
		ray->color = 0x00FF00;
	else if (worldMap[ray->mapY][ray->mapX] == 3)
		ray->color = 0x0000FF;
	else if (worldMap[ray->mapY][ray->mapX] == 4)
		ray->color = 0xFFFFFF;
	else
		ray->color = 0xFFFF00;
	
	if (ray->side == 1)
		ray->color = ray->color / 2;
}
