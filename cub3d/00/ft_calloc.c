/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 05:41:07 by dhyeon            #+#    #+#             */
/*   Updated: 2020/12/09 10:05:58 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*ft_calloc(size_t n, size_t size)
{
	void *m;

	if (!(m = malloc(n * size)))
		return (0);
	ft_memset(m, 0, (n * size));
	return (m);
}
