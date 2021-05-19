/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 04:23:45 by dhyeon            #+#    #+#             */
/*   Updated: 2021/05/19 14:27:00 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back_node(t_stack *s, int num)
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
	s->top = tmp;
	s->size++;
}

void	remove_top_node(t_stack *s)
{
	t_node	*tmp;

	tmp = s->top->next;
	free(s->top);
	s->top = tmp;
	s->top->prev = 0;
	s->size--;
}

void	pa(t_info *info)
{
	if (info->b->size > 0)
	{
		push_back_node(info->a, info->b->top->num);
		remove_top_node(info->b);
		info->count++;
	}
}

void	pb(t_info *info)
{
	if (info->a->size > 0)
	{
		push_back_node(info->b, info->a->top->num);
		remove_top_node(info->a);
		info->count++;
	}
}
