#include "cub3d.h"

void	key_press_w(t_cub *cub)
{
	if (cub->conf.map[(int)(cub->info.pos.x + cub->info.dir.x * cub->info.move_speed)][
			(int)(cub->info.pos.y)] != '1')
		cub->info.pos.x += cub->info.dir.x * cub->info.move_speed;
	if (cub->conf.map[(int)(cub->info.pos.x)][(int)(cub->info.pos.y + cub->info.dir.y
			* cub->info.move_speed)] != '1')
		cub->info.pos.y += cub->info.dir.y * cub->info.move_speed;
}

void	key_press_s(t_cub *cub)
{
	if (cub->conf.map[(int)(cub->info.pos.x - cub->info.dir.x * cub->info.move_speed)][
			(int)(cub->info.pos.y)] != '1')
		cub->info.pos.x -= cub->info.dir.x * cub->info.move_speed;
	if (cub->conf.map[(int)(cub->info.pos.x)][(int)(cub->info.pos.y - cub->info.dir.y
			* cub->info.move_speed)] != '1')
		cub->info.pos.y -= cub->info.dir.y * cub->info.move_speed;
}

void	key_press_d(t_cub *cub)
{
	if (cub->conf.map[(int)(cub->info.pos.x + cub->info.dir.y * cub->info.move_speed)][
			(int)(cub->info.pos.y)] != '1')
		cub->info.pos.x += cub->info.dir.y * cub->info.move_speed;
	if (cub->conf.map[(int)(cub->info.pos.x)][(int)(cub->info.pos.y - cub->info.dir.x
			* cub->info.move_speed)] != '1')
		cub->info.pos.y -= cub->info.dir.x * cub->info.move_speed;
}

void	key_press_a(t_cub *cub)
{
	if (cub->conf.map[(int)(cub->info.pos.x - cub->info.dir.y * cub->info.move_speed)][
			(int)(cub->info.pos.y)] != '1')
		cub->info.pos.x -= cub->info.dir.y * cub->info.move_speed;
	if (cub->conf.map[(int)(cub->info.pos.x)][(int)(cub->info.pos.y + cub->info.dir.x
			* cub->info.move_speed)] != '1')
		cub->info.pos.y += cub->info.dir.x * cub->info.move_speed;
}

void	key_press_left(t_cub *cub)
{
	const double oldDirX = cub->info.dir.x;
	const double oldPlaneX = cub->info.plane.x;

	cub->info.dir.x = cub->info.dir.x * cos(cub->info.rot_speed) - cub->info.dir.y
				* sin(cub->info.rot_speed);
	cub->info.dir.y = oldDirX * sin(cub->info.rot_speed) + cub->info.dir.y
				* cos(cub->info.rot_speed);
	cub->info.plane.x = cub->info.plane.x * cos(cub->info.rot_speed) - cub->info.plane.y
				* sin(cub->info.rot_speed);
	cub->info.plane.y = oldPlaneX * sin(cub->info.rot_speed) + cub->info.plane.y
				* cos(cub->info.rot_speed);
}

void	key_press_right(t_cub *cub)
{
	const double oldDirX = cub->info.dir.x;
	const double oldPlaneX = cub->info.plane.x;

	cub->info.dir.x = cub->info.dir.x * cos(-cub->info.rot_speed) - cub->info.dir.y
				* sin(-cub->info.rot_speed);
	cub->info.dir.y = oldDirX * sin(-cub->info.rot_speed) + cub->info.dir.y
				* cos(-cub->info.rot_speed);
	cub->info.plane.x = cub->info.plane.x * cos(-cub->info.rot_speed) - cub->info.plane.y
				* sin(-cub->info.rot_speed);
	cub->info.plane.y = oldPlaneX * sin(-cub->info.rot_speed) + cub->info.plane.y
				* cos(-cub->info.rot_speed);
}

int	key_press(int key, t_cub *cub)
{
	if (key == K_W)
		key_press_w(cub);
	if (key == K_S)
		key_press_s(cub);
	if (key == K_D)
		key_press_d(cub);
	if (key == K_A)
		key_press_a(cub);
	if (key == K_AR_L)
		key_press_left(cub);
	if (key == K_AR_R)
		key_press_right(cub);
	if (key == K_ESC)
		exit(0);
	return (0);
}
