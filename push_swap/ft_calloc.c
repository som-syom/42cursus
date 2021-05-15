/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 05:41:07 by dhyeon            #+#    #+#             */
/*   Updated: 2021/05/16 03:39:18 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	*ft_calloc(size_t n, size_t size)
{
	void	*ret;

	ret = (char *)malloc(size * n);
	if (!ret)
		print_error();
	ft_memset(ret, 0, (n * size));
	return (ret);
}
