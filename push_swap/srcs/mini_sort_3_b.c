/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort_3_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 19:56:29 by dhyeon            #+#    #+#             */
/*   Updated: 2021/05/20 21:32:36 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mini_sort_3_b(t_info *info)
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
