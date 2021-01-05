/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 15:22:55 by dhyeon            #+#    #+#             */
/*   Updated: 2021/01/06 00:06:48 by dhyeon           ###   ########.fr       */
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

int		is_blank(char *s)
{
	int i;

	i = 0;
	if (ft_strlen(s) == 0)
		return (0);
	while (s[i] != 0)
	{
		if (s[i] == '\n' || (9 <= s[i] && s[i] <= 13) || s[i] == ' ')
			i++;
		else
			return (-3);
	}
	return (0);
}
