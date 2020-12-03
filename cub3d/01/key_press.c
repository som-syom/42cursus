#include "cub3d.h"

int	key_press(int key, t_info *info)
{
	if (key == K_W)
		key_press_w(info);
	if (key == K_S)
		key_press_s(info);
	if (key == K_D)
		key_press_d(info);
	if (key == K_A)
		key_press_a(info);
	if (key == K_AR_L)
		key_press_left(info);
	if (key == K_AR_R)
		key_press_right(info);
	if (key == K_ESC)
		exit(0);
	return (0);
}

void	key_press_w(t_info *info)
{
	if (!worldMap[(int)(info->posX + info->dirX * info->moveSpeed)][
			(int)(info->posY)])
		info->posX += info->dirX * info->moveSpeed;
	if (!worldMap[(int)(info->posX)][(int)(info->posY + info->dirY
			* info->moveSpeed)])
		info->posY += info->dirY * info->moveSpeed;
}

void	key_press_s(t_info *info)
{
	if (!worldMap[(int)(info->posX - info->dirX * info->moveSpeed)][
			(int)(info->posY)])
		info->posX -= info->dirX * info->moveSpeed;
	if (!worldMap[(int)(info->posX)][(int)(info->posY - info->dirY
			* info->moveSpeed)])
		info->posY -= info->dirY * info->moveSpeed;
}

void	key_press_d(t_info *info)
{
	if (!worldMap[(int)(info->posX + info->dirY * info->moveSpeed)][
			(int)(info->posY)])
		info->posX += info->dirY * info->moveSpeed;
	if (!worldMap[(int)(info->posX)][(int)(info->posY - info->dirX
			* info->moveSpeed)])
		info->posY -= info->dirX * info->moveSpeed;
}

void	key_press_a(t_info *info)
{
	if (!worldMap[(int)(info->posX - info->dirY * info->moveSpeed)][
			(int)(info->posY)])
		info->posX -= info->dirY * info->moveSpeed;
	if (!worldMap[(int)(info->posX)][(int)(info->posY + info->dirX
			* info->moveSpeed)])
		info->posY += info->dirX * info->moveSpeed;
}

void	key_press_left(t_info *info)
{
	info->oldDirX = info->dirX;
	info->dirX = info->dirX * cos(info->rotSpeed) - info->dirY
				* sin(info->rotSpeed);
	info->dirY = info->oldDirX * sin(info->rotSpeed) + info->dirY
				* cos(info->rotSpeed);
	info->oldPlaneX = info->planeX;
	info->planeX = info->planeX * cos(info->rotSpeed) - info->planeY
				* sin(info->rotSpeed);
	info->planeY = info->oldPlaneX * sin(info->rotSpeed) + info->planeY
				* cos(info->rotSpeed);
}

void	key_press_right(t_info *info)
{
	info->oldDirX = info->dirX;
	info->dirX = info->dirX * cos(-info->rotSpeed) - info->dirY
				* sin(-info->rotSpeed);
	info->dirY = info->oldDirX * sin(-info->rotSpeed) + info->dirY
				* cos(-info->rotSpeed);
	info->oldPlaneX = info->planeX;
	info->planeX = info->planeX * cos(-info->rotSpeed) - info->planeY
				* sin(-info->rotSpeed);
	info->planeY = info->oldPlaneX * sin(-info->rotSpeed) + info->planeY
				* cos(-info->rotSpeed);
}
