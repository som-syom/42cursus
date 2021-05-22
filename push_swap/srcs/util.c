/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 04:15:21 by dhyeon            #+#    #+#             */
/*   Updated: 2021/05/22 17:55:18 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

void	*ft_salloc(size_t n, size_t size)
{
	void	*ret;

	ret = (char *)malloc(size * n);
	if (!ret)
		print_error();
	ft_memset(ret, 0, (n * size));
	return (ret);
}

t_node	*create_new_node(int num, t_node *prev, t_node *next)
{
	t_node	*new;

	new = ft_salloc(1, sizeof(t_node));
	new->num = num;
	new->prev = prev;
	new->next = next;
	return (new);
}

void	push_front_num(t_stack *a, int num)
{
	t_node	*tmp;
	t_node	*prev;

	if (a->top == 0)
		a->top = create_new_node(num, 0, 0);
	else
	{
		tmp = a->top;
		while (tmp)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		tmp = create_new_node(num, prev, 0);
		prev->next = tmp;
	}
}
