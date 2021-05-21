/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 04:23:45 by dhyeon            #+#    #+#             */
/*   Updated: 2021/05/21 15:29:20 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back_node(t_stack *s, int num, int rank)
{
	t_node	*tmp;

	tmp = ft_salloc(1, sizeof(t_node));
	ft_memset((void *)tmp, 0, sizeof(t_node));
	if (s->size == 0)
		s->bottom = tmp;
	else
	{
		s->top->prev = tmp;
		tmp->next = s->top;
	}
	tmp->num = num;
	tmp->rank = rank;
	s->top = tmp;
	s->size++;
}

void	remove_top_node(t_stack *s)
{
	t_node	*tmp;

	tmp = s->top->next;
	free(s->top);
	s->top = tmp;
	s->size--;
	if (s->size > 0)
		s->top->prev = 0;
}

int		pa(t_info *info)
{
	if (info->b->size > 0)
	{
		push_back_node(info->a, info->b->top->num, info->b->top->rank);
		remove_top_node(info->b);
		info->count++;
		return (1);
	}
	return (0);
}

int		pb(t_info *info)
{
	if (info->a->size > 0)
	{
		push_back_node(info->b, info->a->top->num, info->a->top->rank);
		remove_top_node(info->a);
		info->count++;
		return (1);
	}
	return (0);
}
