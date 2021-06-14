/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 22:23:13 by dhyeon            #+#    #+#             */
/*   Updated: 2021/06/14 22:56:29 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

int		ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int	i;
	int len;
	char *ret;

	len = ft_strlen(str);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		print_error(FATAL, 0);
	i = 0;
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

void	*ft_memset(void *ptr, int val, size_t n)
{
	unsigned char	*tmp_ptr;
	unsigned char	tmp_val;
	size_t			i;

	tmp_ptr = ptr;
	tmp_val = val;
	i = 0;
	while (i < n)
	{
		tmp_ptr[i] = tmp_val;
		i++;
	}
	return (ptr);
}
