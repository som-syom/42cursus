#include "cub3d.h"

#define texHeight 64
#define texWidth 64

void	calc_ray_init(t_cub *cub, t_ray *ray, int *x)
{
	ray->cameraX = 2 * (*x) / (double)cub->conf.w - 1;
	ray->rayDirX = cub->info.dir.x + cub->info.plane.x * ray->cameraX;
	ray->rayDirY = cub->info.dir.y + cub->info.plane.y * ray->cameraX;
	ray->mapX = (int)cub->info.pos.x;
	ray->mapY = (int)cub->info.pos.y;
	ray->deltaDistX = fabs(1 / ray->rayDirX);
	ray->deltaDistY = fabs(1 / ray->rayDirY);
	ray->hit = 0;
}

void	calc_step_init(t_cub *cub, t_ray *ray)
{
	if (ray->rayDirX < 0)
	{
		ray->stepX = -1;
		ray->sideDistX = (cub->info.pos.x - ray->mapX) * ray->deltaDistX;
	}
	else
	{
		ray->stepX = 1;
		ray->sideDistX = (ray->mapX + 1.0 - cub->info.pos.x) * ray->deltaDistX;
	}
	if (ray->rayDirY < 0)
	{
		ray->stepY = -1;
		ray->sideDistY = (cub->info.pos.y - ray->mapY) * ray->deltaDistY;
	}
	else
	{
		ray->stepY = 1;
		ray->sideDistY = (ray->mapY + 1.0 - cub->info.pos.y) * ray->deltaDistY;
	}
}

void	calc_dda(t_cub *cub, t_ray *ray)
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
		// ft_strchr("12", conf->map[ray->map.x][ray->map.y])
		if (cub->conf.map[ray->mapX][ray->mapY]  > '0')
			ray->hit = 1;
	}
}

void	calc_draw(t_ray *ray, t_cub *cub, int x)
{
	ray->lineHeight = (int)(cub->conf.h / ray->perpWallDist);
	ray->drawStart = -ray->lineHeight / 2 + cub->conf.h / 2; // 중심점 밑에서부터
	if(ray->drawStart < 0) // 벽이 화면 범위 아래 놓여있는 경우
		ray->drawStart = 0;
	ray->drawEnd = ray->lineHeight / 2 + cub->conf.h / 2; // 중심점 위로
	if(ray->drawEnd >= cub->conf.h) // 벽이 화면 범위 위에 놓여있는 경우
		ray->drawEnd = cub->conf.h - 1;

	double wallX;
	if (ray->side == 0)
		wallX = cub->info.pos.y + ray->perpWallDist * ray->rayDirY;
	else
		wallX = cub->info.pos.x + ray->perpWallDist * ray->rayDirX;
	wallX -= floor(wallX);

	int texX = (int)(wallX * (double)texWidth);
	if (ray->side == 0 && ray->rayDirX > 0)
		texX = texWidth - texX - 1;
	if (ray->side == 1 &&  ray->rayDirY < 0)
		texX = texWidth - texX - 1;

	double step;
	step = 1.0 * texHeight / ray->lineHeight;

	double texPos;
	texPos = (ray->drawStart - cub->conf.h / 2 + ray->lineHeight / 2) * step;

	//
	// int flag = 0;
	// if (worldMap[ray->mapY][ray->mapX] == 1)
	// 	ray->color = 0xFF0000;
	// else if (worldMap[ray->mapY][ray->mapX] == 2)
	// 	ray->color = 0x00FF00;
	// else if (worldMap[ray->mapY][ray->mapX] == 3)
	// 	ray->color = 0x0000FF;
	// else if (worldMap[ray->mapY][ray->mapX] == 4)
	// 	ray->color = 0xFFFFFF;
	// else
	// 	{
	// 		while (y < ray->drawEnd)
	// 		{
	// 			int texY;
	// 			texY = (int)texPos & (texHeight - 1);
	// 			texPos += step;
	// 			ray->color = info->texture[0][texHeight * texY + texX];
	// 			if (ray->side == 1)
	// 				ray->color = (ray->color >> 1) & 8355711;
	// 			info->buf[y][x] = ray->color;
	// 			y++;
	// 			flag = 1;
	// 		}
	// 	}
	int texNum;
	// texNum = cub->conf.map[ray->mapX][ray->mapY] - 1;
	texNum = 0;
	int y = ray->drawStart;
	while (y < ray->drawEnd)
	{
		int texY;
		texY = (int)texPos & (texHeight - 1);
		texPos += step;
		ray->color = cub->info.texture[texNum][texHeight * texY + texX];
		if (ray->side == 1)
			ray->color = (ray->color >> 1) & 8355711;
		cub->info.buf[y][x] = ray->color;

		y++;
	}

	//==================================================================

	// int i = 0;

	// while(i < numSprites)
	// {
	// 	spriteOrder[i] = i;
	// 	spriteDistance[i] = ((info->pos.x - sprite[i].x) * (info->pos.x - sprite[i].x) + (info->pos.y - sprite[i].y) * (info->pos.y - sprite[i].y)); //sqrt not taken, unneeded
	// 	i++;
	// }
	// sortSprites(spriteOrder, spriteDistance, numSprites);

	// i = 0;
	// while(i < numSprites)
	// {
	// 	double spriteX = sprite[spriteOrder[i]].x - info->pos.x;
	// 	double spriteY = sprite[spriteOrder[i]].y - info->pos.y;

	// 	double invDet = 1.0 / (info->plane.x * info->dir.y - info->dir.x * info->plane.y); //required for correct matrix multiplication

	// 	double transformX = invDet * (info->dir.y * spriteX - info->dir.x * spriteY);
	// 	double transformY = invDet * (-info->plane.y * spriteX + info->plane.x * spriteY); //this is actually the depth inside the screen, that what Z is in 3D, the distance of sprite to player, matching sqrt(spriteDistance[i])

	// 	int spriteScreenX = (int)((conf->w / 2) * (1 + transformX / transformY));

	// 	int vMoveScreen = (int)(vMove / transformY);

	// 	//calculate height of the sprite on screen
	// 	int spriteHeight = (int)fabs((conf->h / transformY) / vDiv); //using "transformY" instead of the real distance prevents fisheye
	// 	//calculate lowest and highest pixel to fill in current stripe
	// 	int drawStartY = -spriteHeight / 2 + conf->h / 2 + vMoveScreen;
	// 	if(drawStartY < 0) drawStartY = 0;
	// 	int drawEndY = spriteHeight / 2 + conf->h / 2 + vMoveScreen;
	// 	if(drawEndY >= conf->h) drawEndY = conf->h - 1;

	// 	//calculate width of the sprite
	// 	int spriteWidth = (int)fabs((conf->h / transformY) / uDiv);
	// 	int drawStartX = -spriteWidth / 2 + spriteScreenX;
	// 	if(drawStartX < 0) drawStartX = 0;
	// 	int drawEndX = spriteWidth / 2 + spriteScreenX;
	// 	if(drawEndX >= conf->w) drawEndX = conf->w - 1;

	// 	//loop through every vertical stripe of the sprite on screen
	// 	for(int stripe = drawStartX; stripe < drawEndX; stripe++)
	// 	{
	// 		int texX = (int)((256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * texWidth / spriteWidth) / 256);
	// 		//the conditions in the if are:
	// 		//1) it's in front of camera plane so you don't see things behind you
	// 		//2) it's on the screen (left)
	// 		//3) it's on the screen (right)
	// 		//4) ZBuffer, with perpendicular distance
	// 		if(transformY > 0 && stripe > 0 && stripe < conf->w && transformY < info->zBuffer[stripe])
	// 		for(int y = drawStartY; y < drawEndY; y++) //for every pixel of the current stripe
	// 		{
	// 			int d = (y-vMoveScreen) * 256 - conf->h * 128 + spriteHeight * 128; //256 and 128 factors to avoid floats
	// 			int texY = ((d * texHeight) / spriteHeight) / 256;
	// 			if (texconf->w * texY + texX > texHeight * texWidth) {
	// 				printf("%d\n", texWidth * texY + texX);
	// 			}
	// 			int color = info->texture[sprite[spriteOrder[i]].texture][texWidth * texY + texX]; //get current color from the texture
	// 			if((color & 0x00FFFFFF) != 0) info->buf[y][stripe] = color; //paint pixel if it isn't black, black is the invisible color
	// 		}
	// 	}
	// 	i++;
	// }
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
			ray.perpWallDist = (ray.mapX - cub->info.pos.x + (1 - ray.stepX) / 2)
								/ ray.rayDirX;
		else
			ray.perpWallDist = (ray.mapY - cub->info.pos.y + (1 - ray.stepY) / 2)
								/ ray.rayDirY;

		calc_draw(&ray, cub, x);
		// cub->info.zbuffer[x] = ray.perpWallDist;
		x++;
	}
}
