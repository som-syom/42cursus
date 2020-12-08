/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 02:49:56 by dhyeon            #+#    #+#             */
/*   Updated: 2020/12/08 22:51:30 by dhyeon           ###   ########.fr       */
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

void	skip_space(char **str)
{
	char	*tmp;
	int		back;
	int		len;

	tmp = *str;
	while (*tmp == ' ')
		tmp++;
	len = ft_strlen(tmp);
	while (tmp[len - 1] == ' ')
		len--;
	tmp[len] = '\0';
	*str = tmp;
}

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
		if (ft_isdigit(*tmp) == 0 && *tmp != ' ' && *tmp != 'N' &&
						*tmp != 'S' && *tmp != 'W' && *tmp != 'E')
			return (-3);
		if (*tmp == 'N' || *tmp == 'S' || *tmp == 'W' || *tmp == 'E')
		{
			if (conf->player_dir != 0)
				return (-3);
			else
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
			printf("test0\n");
			gnl_err = -3;
			break ;
		}
		free(line);
		if (gnl_err == 0)
			break ;
	}
	cub->test = 0;
	printf("gnl_err: %d\n", gnl_err);
	return (gnl_err);
}

int		map_init(t_config *conf)
{
	int i;
	int j;

	if (!(conf->map = (char **)malloc(sizeof(char *) * (conf->map_size.y) + 3)))
		return (-1);
	i = -1;
	while (++i < conf->map_size.y + 2)
	{
		if (!(conf->map[i] = (char *)malloc(sizeof(char) * conf->map_size.x + 2)))
		{
			ft_free(conf->map);
			return (-1);
		}
	}
	i = -1;
	while (++i < conf->map_size.y + 2)
	{
		j = -1;
		while (++j < conf->map_size.x + 2)
		{
			conf->map[i][j] = ' ';
		}
	}
	conf->map[conf->map_size.y + 2] = 0;
	return (0);
}

int		list_to_array(t_config *conf)
{
	int		i;
	t_list	*tmp;

	tmp = conf->map_lst;
	i = 1;
	printf("start\n");
	while (tmp)
	{
		conf->map[i]= ft_strjoin(" ", tmp->content);
		// printf("tmp : |%s|\n", ft_strjoin(" ", tmp->content));
		if (conf->map[i] == 0)
			return (-3);
		tmp = tmp->next;
		i++;
	} //따로 프리해주기
	return (0);
}

int		create_map(t_config *conf)
{
	int i;
	int len;

	conf->map_size.y = ft_lstsize(conf->map_lst);
	if (map_init(conf) != 0)
		return (-3);
	if (list_to_array(conf) != 0)
		return (-3);
	i = 0;
	while (++i < conf->map_size.y + 1)
	{
		if ((len = ft_strlen(conf->map[i])) < conf->map_size.x + 1)
			conf->map[i][len] = ' ';
		conf->map[i][conf->map_size.x + 1] = '\0';
	}
	int j = 0;
	while (conf->map[j])
	{
		printf("arr[%3d] : |%s|\n", j , conf->map[j]);
		j++;
	}
	return (0);
}

int		check_valid_map(t_config *conf)
{
	int i;
	int j;

	i = -1;
	while (++i < conf->map_size.y + 1)
	{
		j = -1;
		while (conf->map[i][++j] != '\0')
		{
			if (conf->map[i][j] == ' ')
			{
				if (conf->map[i][j + 1] == '0' || conf->map[i][j + 1] == '0')
				{
					printf("x : %d | y : %d\n", i, j);
					return (-3);
				}
				if (i != 0 && conf->map[i - 1][j] == 0)
				{
					printf("x : %d | y : %d\n", i, j);
					return (-3);
				}
				if (j != 0 && conf->map[i][j - 1] == 0)
				{
					printf("x : %d | y : %d\n", i, j);
					return (-3);
				}
			}
		}
	}
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
	return (0);
}
