/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 00:42:56 by dhyeon            #+#    #+#             */
/*   Updated: 2020/07/03 02:16:04 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *tmp;
	t_list *current;

	tmp = *lst;
	while (tmp != 0)
	{
		current = tmp->next;
		if (tmp == 0)
			break ;
		ft_lstdelone(tmp, del);
		tmp = 0;
		tmp = current;
	}
	*lst = 0;
}
