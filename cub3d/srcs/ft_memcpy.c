/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 19:47:05 by dhyeon            #+#    #+#             */
/*   Updated: 2021/01/13 07:04:55 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_tmp;
	unsigned char	*src_tmp;
	size_t			i;

	if (dest == 0 && src == 0)
		return (0);
	dest_tmp = dest;
	src_tmp = (unsigned char *)src;
	i = 0;
	while (i++ < n)
		*dest_tmp++ = *src_tmp++;
	return (dest);
}
