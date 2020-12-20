/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 15:27:08 by dhyeon            #+#    #+#             */
/*   Updated: 2020/12/09 15:27:42 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		map_init(t_config *conf)
{
	int i;
	int j;

	if (!(conf->map = (char **)malloc(sizeof(char *) * (conf->map_size.y +3))))
		return (-1);
	i = -1;
	while (++i < conf->map_size.y + 2)
	{
		if (!(conf->map[i] = (char *)malloc(sizeof(char) * conf->map_size.x + 3)))
		{
			ft_free(conf->map);
			return (-1);
		}
	}
	i = -1;
	while (++i < (conf->map_size.y + 2))
	{
		j = -1;
		while (++j < (conf->map_size.x + 3))
			conf->map[i][j] = ' ';
	}
	conf->map[conf->map_size.y + 2] = 0;
	return (0);
}

int		list_to_array(t_config *conf)
{
	int		i;
	int		j;
	t_list	*tmp;

	tmp = conf->map_lst;
	i = 0;
	while (++i < conf->map_size.y + 1)
	{
		j = -1;
		while (tmp->content[++j] != 0)
			conf->map[i][j + 1] = tmp->content[j];
		tmp = tmp->next;
	}
	tmp = conf->map_lst;
	while (tmp)
	{
		free(tmp->content);
		tmp = tmp->next;
	}
	free(tmp);
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
	i = -1;
	while (++i < conf->map_size.y + 1)
	{
		conf->map[i][conf->map_size.x + 2] = '\0';
	}
	int j = 0;
	while (j < 16)
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
	while (++i < conf->map_size.y + 2)
	{
		j = -1;
		while (conf->map[i][++j] != '\0')
		{
			if (conf->map[i][j] == ' ')
			{
				if (i < conf->map_size.y + 1 &&
					(conf->map[i][j + 1] == '0' || conf->map[i + 1][j] == '0'))
				{
					printf("x : %d | y : %d\n", i, j);
					return (-3);
				}
				if (i != 0 && conf->map[i - 1][j] == '0')
				{
					printf("x : %d | y : %d\n", i, j);
					return (-3);
				}
				if (j != 0 && conf->map[i][j - 1] == '0')
				{
					printf("x : %d | y : %d\n", i, j);
					return (-3);
				}
			}
		}
	}
	return (0);
}
