/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 03:09:20 by dhyeon            #+#    #+#             */
/*   Updated: 2020/12/09 15:31:50 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned char	tmp;
	size_t			i;

	tmp = c;
	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == tmp)
			return ((char *)(str + i));
		i++;
	}
	if (str[i] == tmp)
		return ((char *)(str + i));
	return (0);
}
