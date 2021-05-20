/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 04:16:12 by dhyeon            #+#    #+#             */
/*   Updated: 2021/05/20 18:16:30 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_info *info)
{
	int	tmp;

	if (info->a->size > 1)
	{
		tmp = info->a->top->num;
		info->a->top->num = info->a->top->next->num;
		info->a->top->next->num = tmp;
		tmp = info->a->top->rank;
		info->a->top->rank = info->a->top->next->rank;
		info->a->top->next->rank = tmp;
		info->count++;
	}
}

void	sb(t_info *info)
{
	int	tmp;

	if (info->b->size > 1)
	{
		tmp = info->b->top->num;
		info->b->top->num = info->b->top->next->num;
		info->b->top->next->num = tmp;
		tmp = info->b->top->rank;
		info->b->top->rank = info->b->top->next->rank;
		info->b->top->next->rank = tmp;
		info->count++;
	}
}

void	ss(t_info *info)
{
	sa(info);
	sb(info);
	info->count--;
}
