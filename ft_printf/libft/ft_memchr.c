/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 01:56:38 by dhyeon            #+#    #+#             */
/*   Updated: 2020/07/02 02:05:45 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *ptr, int val, size_t n)
{
	unsigned char *ptr_tmp;
	unsigned char val_tmp;

	ptr_tmp = ptr;
	val_tmp = val;
	while (n--)
	{
		if (*ptr_tmp++ == val_tmp)
			return ((void *)(ptr_tmp - 1));
	}
	return (0);
}
