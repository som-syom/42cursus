/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revers_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 05:49:37 by dhyeon            #+#    #+#             */
/*   Updated: 2021/05/21 15:30:22 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		rra(t_info *info)
{
	t_node	*new_bottom;

	new_bottom = info->a->bottom->prev;
	info->a->top->prev = info->a->bottom;
	info->a->bottom->next = info->a->top;
	info->a->top = info->a->bottom;
	info->a->top->prev = 0;
	info->a->bottom = new_bottom;
	info->a->bottom->next = 0;
	info->count++;
	return (1);
}

int		rrb(t_info *info)
{
	t_node	*new_bottom;

	new_bottom = info->b->bottom->prev;
	info->b->top->prev = info->b->bottom;
	info->b->bottom->next = info->b->top;
	info->b->top = info->b->bottom;
	info->b->top->prev = 0;
	info->b->bottom = new_bottom;
	info->b->bottom->next = 0;
	info->count++;
	return (1);
}

int		rrr(t_info *info)
{
	rra(info);
	rrb(info);
	info->count--;
	return (1);
}
