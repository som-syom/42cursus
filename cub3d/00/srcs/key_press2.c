/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 22:17:29 by dhyeon            #+#    #+#             */
/*   Updated: 2021/01/14 22:17:48 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_press_w(t_cub *cub)
{
	if (cub->conf.map[(int)(cub->info.pos.x + cub->info.dir.x
			* cub->info.move_speed)][(int)(cub->info.pos.y)] != '1')
		cub->info.pos.x += cub->info.dir.x * cub->info.move_speed;
	if (cub->conf.map[(int)(cub->info.pos.x)][(int)(cub->info.pos.y
			+ cub->info.dir.y * cub->info.move_speed)] != '1')
		cub->info.pos.y += cub->info.dir.y * cub->info.move_speed;
}

void	key_press_s(t_cub *cub)
{
	if (cub->conf.map[(int)(cub->info.pos.x - cub->info.dir.x
			* cub->info.move_speed)][(int)(cub->info.pos.y)] != '1')
		cub->info.pos.x -= cub->info.dir.x * cub->info.move_speed;
	if (cub->conf.map[(int)(cub->info.pos.x)][(int)(cub->info.pos.y
			- cub->info.dir.y * cub->info.move_speed)] != '1')
		cub->info.pos.y -= cub->info.dir.y * cub->info.move_speed;
}

void	key_press_d(t_cub *cub)
{
	if (cub->conf.map[(int)(cub->info.pos.x + cub->info.dir.y
			* cub->info.move_speed)][(int)(cub->info.pos.y)] != '1')
		cub->info.pos.x += cub->info.dir.y * cub->info.move_speed;
	if (cub->conf.map[(int)(cub->info.pos.x)][(int)(cub->info.pos.y
			- cub->info.dir.x * cub->info.move_speed)] != '1')
		cub->info.pos.y -= cub->info.dir.x * cub->info.move_speed;
}

void	key_press_a(t_cub *cub)
{
	if (cub->conf.map[(int)(cub->info.pos.x - cub->info.dir.y
			* cub->info.move_speed)][(int)(cub->info.pos.y)] != '1')
		cub->info.pos.x -= cub->info.dir.y * cub->info.move_speed;
	if (cub->conf.map[(int)(cub->info.pos.x)][(int)(cub->info.pos.y
			+ cub->info.dir.x * cub->info.move_speed)] != '1')
		cub->info.pos.y += cub->info.dir.x * cub->info.move_speed;
}
