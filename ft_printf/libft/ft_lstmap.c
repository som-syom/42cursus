/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 01:34:16 by dhyeon            #+#    #+#             */
/*   Updated: 2020/07/06 22:27:46 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *res;
	t_list *tmp;
	t_list *new;

	if (lst == 0 || f == 0 || del == 0)
		return (0);
	if (!(res = ft_lstnew(f(lst->content))))
		return (0);
	tmp = res;
	lst = lst->next;
	while (lst)
	{
		if (!(new = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&res, del);
			return (0);
		}
		tmp->next = new;
		tmp = tmp->next;
		lst = lst->next;
	}
	return (res);
}
