#include "cub3d.h"

void	calc(t_info *info)
{
	t_ray	ray;
	int		x;


	//FLOOR CASTING
	for(int y = 0; y < height; y++)
	{
		// rayDir for leftmost ray (x = 0) and rightmost ray (x = w)
		float rayDirX0 = info->dirX - info->planeX;
		float rayDirY0 = info->dirY - info->planeY;
		float rayDirX1 = info->dirX + info->planeX;
		float rayDirY1 = info->dirY + info->planeY;

		// Current y position compared to the center of the screen (the horizon)
		int p = y - height / 2;

		// Vertical position of the camera.
		float posZ = 0.5 * height;

		// Horizontal distance from the camera to the floor for the current row.
		// 0.5 is the z position exactly in the middle between floor and ceiling.
		float rowDistance = posZ / p;

		// calculate the real world step vector we have to add for each x (parallel to camera plane)
		// adding step by step avoids multiplications with a weight in the inner loop
		float floorStepX = rowDistance * (rayDirX1 - rayDirX0) / width;
		float floorStepY = rowDistance * (rayDirY1 - rayDirY0) / width;

		// real world coordinates of the leftmost column. This will be updated as we step to the right.
		float floorX = info->posX + rowDistance * rayDirX0;
		float floorY = info->posY + rowDistance * rayDirY0;

		for(int x = 0; x < width; ++x)
		{
			// the cell coord is simply got from the integer parts of floorX and floorY
			int cellX = (int)(floorX);
			int cellY = (int)(floorY);

			// get the texture coordinate from the fractional part
			int tx = (int)(texWidth * (floorX - cellX)) & (texWidth - 1);
			int ty = (int)(texHeight * (floorY - cellY)) & (texHeight - 1);

			floorX += floorStepX;
			floorY += floorStepY;

			// choose texture and draw the pixel
			int floorTexture = 3;
			int ceilingTexture = 6;

			int color;

			// floor
			color = info->texture[floorTexture][texWidth * ty + tx];
			color = (color >> 1) & 8355711; // make a bit darker

			info->buf[y][x] = color;

			//ceiling (symmetrical, at screenHeight - y - 1 instead of y)
			color = info->texture[ceilingTexture][texWidth * ty + tx];
			color = (color >> 1) & 8355711; // make a bit darker

			info->buf[height - y - 1][x] = color;
		}
	}
	//
	x = 0;
	while (x < width)
	{
		calc_ray_init(info, &ray, &x);
		calc_step_init(info, &ray);
		calc_dda(info, &ray);
		
		/*	stepX|Y 가 -1 이라면 : (1 - stepX|Y) / 2 = 1
					    1 이라면 :					= 0 이 된다
			이는 rayDirX|Y 가 0 보다 작을때 길이에 1을 더해주기 위함이다. (sideDist 때와 비슷)

			** 수직거리 계산하는 법 :
			mapX - posX + (1 - stepX) / 2
			공식은 삼각형의 비에 의해 도출 //한번다시체크하자
		*/
		if (ray.side == 0)
			ray.perpWallDist = (ray.mapX - info->posX + (1 - ray.stepX) / 2)
								/ ray.rayDirX;
		else
			ray.perpWallDist = (ray.mapY - info->posY + (1 - ray.stepY) / 2)
								/ ray.rayDirY;
		
		calc_draw(&ray, info, x);
		// verLine(info, x, ray.drawStart, ray.drawEnd, ray.color);
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
	/*	deltaDistX|Y 구하기

	*/
	ray->deltaDistX = fabs(1 / ray->rayDirX); 
	ray->deltaDistY = fabs(1 / ray->rayDirY);
	ray->hit = 0;
}

void	calc_step_init(t_info *info, t_ray *ray)
{
	/*	초기값구하기
		stepX|Y : rayDirX|Y 의 값이 양수라면 +1, 음수라면 -1
		sideDistX|Y : rayDirX|Y 가 양수라면 오른쪽,위쪽 방향으로 이동,
								음수라면 왼쪽,아래쪽으로 이동.
					sideDistX : deltaDistX
					= (map + 1) - posX : 1
						통분을통해
					sideDistX = ((map + 1) - posX) * deltaDistX 가 된다.
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
	while (ray->hit == 0) // 벽에 부딪힐때까지 매번 한칸씩 광선을 이동시키는 루프
	{
		if (ray->sideDistX < ray->sideDistY) // 점프할 때마다 각각의 값이 더해진다
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

void	calc_draw(t_ray *ray, t_info *info, int x)
{
	ray->lineHeight = (int)(height / ray->perpWallDist);
		// 거리에 따라 크기를 조절하기 위해서 역수 + 픽셀단위로 맞춰주기 위해 *h
		// 벽을 더 높게 그리기려면 (2 * h)
	ray->drawStart = -ray->lineHeight / 2 + height / 2; // 중심점 밑에서부터
	if(ray->drawStart < 0) // 벽이 화면 범위 아래 놓여있는 경우
		ray->drawStart = 0;
	ray->drawEnd = ray->lineHeight / 2 + height / 2; // 중심점 위로
	if(ray->drawEnd >= height) // 벽이 화면 범위 위에 놓여있는 경우
		ray->drawEnd = height - 1;

	//
	double wallX;
	if (ray->side == 0)
		wallX = info->posY + ray->perpWallDist * ray->rayDirY;
	else
		wallX = info->posX + ray->perpWallDist * ray->rayDirX;
	wallX -= floor(wallX);

	int texX = (int)(wallX * (double)texWidth);
	if (ray->side == 0 && ray->rayDirX > 0)
		texX = texWidth - texX - 1;
	if (ray->side == 1 &&  ray->rayDirY < 0)
		texX = texWidth - texX - 1;
	
	double step;
	step = 1.0 * texHeight / ray->lineHeight;

	double texPos;
	texPos = (ray->drawStart - height / 2 + ray->lineHeight / 2) * step;
	
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
	texNum = worldMap[ray->mapX][ray->mapY] - 1;
	int y = ray->drawStart;
	while (y < ray->drawEnd)
	{
		int texY;
		texY = (int)texPos & (texHeight - 1);
		texPos += step;
		ray->color = info->texture[texNum][texHeight * texY + texX];
		if (ray->side == 1)
			ray->color = (ray->color >> 1) & 8355711;
		info->buf[y][x] = ray->color;
		
		y++;
	}
	
}
