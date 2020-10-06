/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 04:34:29 by dhyeon            #+#    #+#             */
/*   Updated: 2020/08/12 05:43:22 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_index(char *back)
{
	int i;

	i = 0;
	if (back == 0)
		return (-1);
	while (back[i])
	{
		if (back[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		gnl_return(char **back, char **line, char *buf)
{
	char	*back_tmp;
	int		idx;

	if (buf != 0)
		free(buf);
	idx = get_index(*back);
	if (idx != -1)
	{
		back_tmp = ft_strdup(*back);
		free(*back);
		back_tmp[idx] = '\0';
		*line = ft_strdup(back_tmp);
		*back = ft_strdup(back_tmp + idx + 1);
		if (back_tmp != 0)
			free(back_tmp);
		return (GNL_SUCCESS);
	}
	if (*back != 0)
	{
		*line = *back;
		*back = 0;
	}
	else
		*line = ft_strdup("");
	return (GNL_EOF);
}

int		get_next_line(int fd, char **line)
{
	static char	*back[OPEN_MAX];
	char		*buf;
	char		*tmp;
	int			gnl_read;

	if (fd < 0 || line == 0 || BUFFER_SIZE <= 0)
		return (GNL_ERROR);
	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (GNL_ERROR);
	while ((get_index(back[fd]) == -1)
		&& ((gnl_read = read(fd, buf, BUFFER_SIZE)) > 0))
	{
		buf[gnl_read] = '\0';
		tmp = back[fd];
		back[fd] = ft_strjoin(back[fd], buf);
		if (tmp != 0)
			free(tmp);
	}
	if (gnl_read < 0)
	{
		free(buf);
		return (GNL_ERROR);
	}
	return (gnl_return(&back[fd], line, buf));
}