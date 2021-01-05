/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 02:49:56 by dhyeon            #+#    #+#             */
/*   Updated: 2021/01/05 23:55:02 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		save_map(t_config *conf, char *str)
{
	int		len;
	t_list	*new;
	char	*tmp;

	len = ft_strlen(str);
	if (conf->map_size.x < len)
		conf->map_size.x = len;
	tmp = str;
	while (*tmp)
	{
		if (ft_strchr("012 NEWS", *tmp) == 0)
			return (-3);
		if (ft_strchr("NEWS", *tmp))
		{
			if (conf->player_dir != 0)
				return (-3);
			conf->player_dir = *tmp;
		}
		tmp++;
	}
	new = ft_lstnew(ft_strdup(str));
	ft_lstadd_back(&conf->map_lst, new);
	return (0);
}

int		check_conf(t_config *conf, char *str)
{
	if (conf->map_cnt < 8)
	{
		if (is_blank(str) == 0)
			return (0);
		else if (parse_line(conf, str) != 0)
			return (-3);
		else
			conf->map_cnt++;
	}
	else if (conf->map_cnt == 8 && is_blank(str) == 0
								&& conf->map_size.x == 0)
		return (0);
	else
	{
		if (save_map(conf, str) != 0)
			return (-3);
	}
	return (0);
}

int		read_map_file(t_cub *cub, t_config *conf)
{
	int		gnl_err;
	char	*line;

	line = 0;
	while (1)
	{
		if ((gnl_err = get_next_line(conf->fd, &line)) < 0)
			break ;
		if (check_conf(conf, line) != 0)
		{
			gnl_err = -3;
			break ;
		}
		free(line);
		if (gnl_err == 0)
			break ;
	}
	cub->test = 0;
	return (gnl_err);
}

void	set_player_dir(t_cub *cub, char dir)
{
	cub->info.dir.x = 0;
	cub->info.dir.y = 0;
	cub->info.plane.x = 0;
	cub->info.plane.y = 0;
	if (dir == 'N')
	{
		cub->info.dir.x = -1;
		cub->info.plane.y = 0.66;
	}
	if (dir == 'E')
	{
		cub->info.dir.y = -1;
		cub->info.plane.x = -0.66;
	}
	if (dir == 'W')
	{
		cub->info.dir.y = 1;
		cub->info.plane.x = 0.66;
	}
	if (dir == 'S')
	{
		cub->info.dir.x = 1;
		cub->info.plane.y = -0.66;
	}
}

int		set_player_pos(t_cub *cub, int i, int j)
{
	cub->info.pos.x = i + 0.5;
	cub->info.pos.y = j + 0.5;
	return (0);
}

void	save_sprite(t_cub *cub)
{
	int cnt;
	int i;
	int j;

	cub->info.sprites = ft_calloc(cub->info.sp_num, sizeof(t_xy_d));
	cnt = 0;
	i = -1;
	while (++i < cub->conf.map_size.y + 2)
	{
		j = -1;
		while (cub->conf.map[i][++j] != '\0')
		{
			if (cub->conf.map[i][j] == '2')
			{
				cub->info.sprites[cnt].x = j;
				cub->info.sprites[cnt].y = i;
				cnt++;
			}
		}
	}
}

int		check_player_sp(t_config *conf, t_cub *cub, int i, int j)
{
	if (conf->player_dir == 0)
		return (-3);
	else
		set_player_dir(cub, conf->player_dir);
	i = -1;
	while (++i < conf->map_size.y + 2)
	{
		j = -1;
		while (conf->map[i][++j] != '\0')
		{
			if (ft_strchr("NEWS", conf->map[i][j]) != 0)
			{
				if(set_player_pos(cub, i, j) != 0)
					return (-3);
				printf("i j = %d %d\n", i, j);
			}
			if (conf->map[i][j] == '2')
				cub->info.sp_num++;
		}
	}
	save_sprite(cub);
	return (0);
}



int		set_map(t_cub *cub, t_config *conf, char *path)
{
	int		err_num;

	if ((conf->fd = open(path, O_RDONLY)) < 0)
		return (-4);
	if ((err_num = read_map_file(cub, conf)) != 0)
		return (err_num);
	if ((err_num = create_map(conf)) != 0)
		return (err_num);
	if ((err_num = check_valid_map(conf)) != 0)
		return (err_num);
	if ((err_num = check_player_sp(conf, cub, 0, 0)) != 0)
		return (err_num);
	return (0);
}
