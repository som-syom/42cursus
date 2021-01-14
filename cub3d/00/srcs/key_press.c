/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 22:13:24 by dhyeon            #+#    #+#             */
/*   Updated: 2021/01/14 22:18:03 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_press_left(t_cub *cub)
{
	const double old_dir_x = cub->info.dir.x;
	const double old_plane_x = cub->info.plane.x;

	cub->info.dir.x = cub->info.dir.x * cos(cub->info.rot_speed)
					- cub->info.dir.y * sin(cub->info.rot_speed);
	cub->info.dir.y = old_dir_x * sin(cub->info.rot_speed) + cub->info.dir.y
				* cos(cub->info.rot_speed);
	cub->info.plane.x = cub->info.plane.x * cos(cub->info.rot_speed)
					- cub->info.plane.y * sin(cub->info.rot_speed);
	cub->info.plane.y = old_plane_x * sin(cub->info.rot_speed)
					+ cub->info.plane.y * cos(cub->info.rot_speed);
}

void	key_press_right(t_cub *cub)
{
	const double old_dir_x = cub->info.dir.x;
	const double old_plane_x = cub->info.plane.x;

	cub->info.dir.x = cub->info.dir.x * cos(-cub->info.rot_speed)
					- cub->info.dir.y * sin(-cub->info.rot_speed);
	cub->info.dir.y = old_dir_x * sin(-cub->info.rot_speed) + cub->info.dir.y
				* cos(-cub->info.rot_speed);
	cub->info.plane.x = cub->info.plane.x * cos(-cub->info.rot_speed)
					- cub->info.plane.y * sin(-cub->info.rot_speed);
	cub->info.plane.y = old_plane_x * sin(-cub->info.rot_speed)
					+ cub->info.plane.y * cos(-cub->info.rot_speed);
}

int		key_press(int key, t_cub *cub)
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
