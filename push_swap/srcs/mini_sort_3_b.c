/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort_3_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 19:56:29 by dhyeon            #+#    #+#             */
/*   Updated: 2021/05/21 15:21:07 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mini_sort_123_b(t_info *info)
{
	if (info->b->size == 3)
	{
		command(info, SB, "sb\n");
		command(info, RRB, "rrb\n");
		commands(info, PA, "pa\n", 3);
	}
	else
	{
		command(info, RB, "rb\n");
		command(info, SB, "sb\n");
		commands(info, PA, "pa\n", 2);
		command(info, RRB, "rrb\n");
		command(info, PA, "pa\n");
	}
}

void	mini_sort_213_b(t_info *info)
{
	if (info->b->size == 3)
	{
		command(info, RRB, "rrb\n");
		commands(info, PA, "pa\n", 3);
	}
	else
	{
		command(info, PA, "pa\n");
		command(info, SB, "sb\n");
		command(info, PA, "pa\n");
		command(info, SA, "sa\n");
		command(info, PA, "pa\n");
	}
}

void	mini_sort_132_b(t_info *info)
{
	command(info, RB, "rb\n");
	commands(info, PA, "pa\n", 3);
}

void	mini_sort_3_b(t_info *info)
{
	int	rank[3];

	rank[0] = info->a->top->rank;
	rank[1] = info->a->top->next->rank;
	rank[2] = info->a->top->next->next->rank;
	if (rank[0] < rank[1] && rank[0] < rank[2] && rank[1] < rank[2]) // 123
		mini_sort_123_b(info);
	else if (rank[0] < rank[1] && rank[0] < rank[2] && rank[1] > rank[2]) // 132
		mini_sort_132_b(info);
	else if (rank[0] > rank[1] && rank[0] < rank[2] && rank[1] < rank[2]) // 213
		mini_sort_213_b(info);
	else if (rank[0] < rank[1] && rank[0] > rank[2] && rank[1] > rank[2]) // 231
	{
		command(info, SB, "sb\n");
		commands(info, PA, "pa\n", 3);
	}
	else if (rank[0] > rank[1] && rank[0] > rank[2] && rank[1] < rank[2]) // 312
	{
		commands(info, PA, "pa\n", 3);
		command(info, SA, "sa\n");
	}
	else // 321
		commands(info, PA, "pa\n", 3);
}
