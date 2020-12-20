/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 15:24:43 by dhyeon            #+#    #+#             */
/*   Updated: 2020/12/09 15:24:52 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_win_size(t_config *conf, char *str)
{
	char **r;

	if (conf->w != 0 || conf->h != 0)
		return (-3);
	skip_space(&str);
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
	skip_space(&str);
	len = ft_strlen(str);
	if ((ft_strncmp(str + len - 4, ".xpm", 4) != 0) ||
		(ft_strncmp(str, ".", 1) != 0))
		return (-3);
	conf->tex_path[info] = ft_strdup(str);
	// printf("%d : %s\n", info, conf->tex_path[info]);
	return (0);
}

int		check_rgb(t_config *conf, int *c, int info)
{
	if (!(0 <= c[0] && c[0] <= 255) || !(0 <= c[1] && c[1] <= 255)
									|| !(0 <= c[2] && c[2] <= 255))
		return (-3);
	conf->rgb[info] = (c[0] << 16) | (c[1] << 8) | c[2];
	// 나중에 합치기
	return (0);
}

int		check_color(t_config *conf, char *str, int info)
{
	char	**color;
	int		i_color[3];

	if (conf->rgb[info] != -1)
		return (-3);
	skip_space(&str);
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
