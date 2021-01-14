/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 23:05:14 by dhyeon            #+#    #+#             */
/*   Updated: 2020/07/03 04:35:54 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_list	*ft_lstnew(char *content)
{
	t_list *res;

	if (!(res = (t_list *)malloc(sizeof(t_list))))
		return (0);
	res->content = content;
	res->next = 0;
	return (res);
}
