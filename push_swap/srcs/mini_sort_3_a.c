/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort_3_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 20:46:05 by dhyeon            #+#    #+#             */
/*   Updated: 2021/05/19 21:00:09 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mini_sort_132_a(t_info *info)
{
	if (info->a->size == 3)
	{
		command(info, SA, "sa\n");
		command(info, RA, "ra\n");
	}
	else
	{
		command(info, PB, "pb\n");
		command(info, SA, "sa\n");
		command(info, PA, "pa\n");
	}
}

void	mini_sort_231_a(t_info *info)
{
	if (info->a->size == 3)
	{
		command(info, SA, "sa\n");
		command(info, RRA, "rra\n");
	}
	else
	{
		command(info, PB, "pb\n");
		command(info, SA, "sa\n");
		command(info, PA, "pa\n");
		command(info, SA, "sa\n");
	}
}

void	mini_sort_312_a(t_info *info)
{
	if (info->a->size == 3)
		command(info, RRA, "rra\n");
	else
	{
		command(info, SA, "sa\n");
		command(info, PB, "pb\n");
		command(info, SA, "sa\n");
		command(info, PA, "pa\n");
	}
}

void	mini_sort_321_a(t_info *info)
{
	if (info->a->size == 3)
	{
		command(info, RA, "ra\n");
		command(info, SA, "sa\n");
	}
	else
	{
		command(info, SA, "sa\n");
		command(info, PB, "pb\n");
		command(info, SA, "sa\n");
		command(info, PA, "pa\n");
		command(info, SA, "sa\n");
	}
}

void	mini_sort_3_a(t_info *info)
{
	int	rank[3];

	rank[0] = info->a->top->rank;
	rank[1] = info->a->top->next->rank;
	rank[2] = info->a->top->next->next->rank;
	if (rank[0] < rank[1] && rank[0] < rank[2] && rank[1] < rank[2])
		return ;
	else if (rank[0] > rank[1] && rank[0] < rank[2] && rank[1] < rank[2])
		command(info, SA, "sa\n");
	else if (rank[0] < rank[1] && rank[0] < rank[2] && rank[1] > rank[2])
		mini_sort_132_a(info);
	else if (rank[0] < rank[1] && rank[0] > rank[2] && rank[1] > rank[2])
		mini_sort_231_a(info);
	else if (rank[0] > rank[1] && rank[0] > rank[2] && rank[1] < rank[2])
		mini_sort_312_a(info);
	else
		mini_sort_321_a(info);
}
