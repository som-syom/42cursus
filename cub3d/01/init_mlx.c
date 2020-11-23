#include "cub3d.h"

void    info_new(t_info *info)
{
    info->mlx = mlx_init();

	info->posX = 12;
	info->posY = 5;
	info->dirX = -1;
	info->dirY = 0;
	info->planeX = 0;
	info->planeY = 0.66;
	info->moveSpeed = 0.15;
	info->rotSpeed = 0.15;
}