/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 04:54:27 by dhyeon            #+#    #+#             */
/*   Updated: 2021/05/16 05:48:08 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_info *info)
{
	t_node	*new_top;

	new_top = info->a->top->next;
	info->a->bottom->next = info->a->top;
	info->a->top->prev = info->a->bottom;
	info->a->bottom = info->a->top;
	info->a->bottom->next = 0;
	info->a->top = new_top;
	info->a->top->prev = 0;
	info->count++;
}

void	rb(t_info *info)
{
	t_node	*new_top;

	new_top = info->b->top->next;
	info->b->bottom->next = info->b->top;
	info->b->top->prev = info->b->bottom;
	info->b->bottom = info->b->top;
	info->b->bottom->next = 0;
	info->b->top = new_top;
	info->b->top->prev = 0;
	info->count++;
}

void	rr(t_info *info)
{
	ra(info);
	rb(info);
	info->count--;
}
