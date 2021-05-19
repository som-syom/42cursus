/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 05:41:07 by dhyeon            #+#    #+#             */
/*   Updated: 2021/05/19 14:28:15 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_calloc(size_t n, size_t size, void **ret)
{
	*ret = (char *)malloc(size * n);
	if (!*ret)
		return (0);
	ft_memset(*ret, 0, (n * size));
	return (1);
}
