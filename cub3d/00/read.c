/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 02:49:56 by dhyeon            #+#    #+#             */
/*   Updated: 2020/12/05 18:04:48 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_digit(char **strs)
{
	int i;
	int j;

	i = 0;
	while (strs[i] != 0)
	{
		j = 0;
		while (strs[i][j] != 0)
		{
			if (ft_isdigit(strs[i][j]) == 0)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_free(char **strs)
{
	int i;

	i = 0;
	while (strs[i] != 0)
	{
		free(strs[i]);
		strs[i] = 0;
		i++;
	}
	free(strs);
	strs = 0;
}

int		check_win_size(t_config *conf, char *str)
{
	char **r;

	if (conf->w != 0 || conf->h != 0)
		return (-3);
	r = ft_split(str, ' ');
	if (r[2] != 0)
		return (-3);
	if (check_digit(r) != 0)
		return (-3);
	conf->w = ft_atoi(r[0]);
	conf->h = ft_atoi(r[1]);
	ft_free(r);
	if (conf->w < 500 || conf->w > 1400)
		conf->w = 640;
	if (conf->h < 500 || conf->h > 1000)
		conf->h = 640;
	return (0);
}

int		check_texture(t_config *conf, char *str, int info)
{
	int len;

	if (conf->tex_path[info] != 0)
		return (-3);
	len = ft_strlen(str);
	if ((ft_strncmp(str + len - 4, ".xpm", 4) != 0) ||
		(ft_strncmp(str, ".", 1) != 0))
		return (-3);
	conf->tex_path[info] = ft_strdup(str); //앞뒤로 공백있는지도 체크해야하는지?
	// printf("%d : %s\n", info, conf->tex_path[info]);
	return (0);
}

int		check_rgb(t_config *conf, int *c, int info)
{
	if (!(0 <= c[0] && c[0] <= 255) || !(0 <= c[1] && c[1] <= 255)
									|| !(0 <= c[2] && c[2] <= 255))
		return (-3);
	conf->rgb[info] = (c[0] << 16) | (c[1] << 8) | c[2];
	// printf("rgb[%d] = %d\n", info, conf->rgb[info]);
	return (0);
}

int		check_color(t_config *conf, char *str, int info)
{
	char	**color;
	int		i_color[3];

	if (conf->rgb[info] != -1)
		return (-3);
	color = ft_split(str, ',');
	if (check_digit(color) != 0 || color[3] != 0)
		return (-3);
	i_color[0] = ft_atoi(color[0]);
	i_color[1] = ft_atoi(color[1]);
	i_color[2] = ft_atoi(color[2]);
	ft_free(color);
	if (check_rgb(conf, i_color, info) != 0)
		return (-3);
	return (0);
}

int		parse_line(t_config *conf, char *str)
{
	if (ft_strncmp(str, "R ", 2) == 0)
		return (check_win_size(conf, str + 2));
	if (ft_strncmp(str, "NO ", 3) == 0)
		return (check_texture(conf, str + 3, 0));
	if (ft_strncmp(str, "SO ", 3) == 0)
		return (check_texture(conf, str + 3, 1));
	if (ft_strncmp(str, "WE ", 3) == 0)
		return (check_texture(conf, str + 3, 2));
	if (ft_strncmp(str, "EA ", 3) == 0)
		return (check_texture(conf, str + 3, 3));
	if (ft_strncmp(str, "S ", 2) == 0)
		return (check_texture(conf, str + 2, 4));
	if (ft_strncmp(str, "F ", 2) == 0)
		return (check_color(conf, str + 2, 0));
	if (ft_strncmp(str, "C ", 2) == 0)
		return (check_color(conf, str + 2, 1));
	return (-3);
}

int		is_blank(char *s)
{
	int i;

	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == '\n' || (9 <= s[i] && s[i] <= 13) || s[i] == ' ')
			i++;
		else
			return (-3);
	}
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
	// printf("cnt = %d\n", conf->map_cnt);
	// else
	// 	parse_map(conf, str);
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
			return (-3);
		free(line);
		if (gnl_err == 0)
			break ;
	}
	cub->test = 0;
	printf("map_cnt = %d\n", conf->map_cnt);
	return (gnl_err);
}

int		set_map(t_cub *cub, t_config *conf, char *path)
{
	if ((conf->fd = open(path, O_RDONLY)) < 0)
		return (-3);
	if (read_map_file(cub, conf) != 0)
		return (-3);
	return (0);
}