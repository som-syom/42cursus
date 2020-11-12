/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 20:47:20 by dhyeon            #+#    #+#             */
/*   Updated: 2020/11/11 19:19:14 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int     get_next_line(char **line)
{
    char buf[1] = {0};
	char *ret;
	int rd = 0;
	int i = 0;

	if (!(ret = (char*)malloc(sizeof(char) * 1000)))
		return (-1);
	ret[0] = 0;
	if (line == 0)
		return (-1);
	while ((rd = read(0, buf, 1)) > 0)
	{
		if (buf[0] == '\n')
		{
			break;
		}
		ret[i] = buf[0];
		ret[i + 1] = 0;
		i++;
	}
	*line = ret;
	return (rd);
}