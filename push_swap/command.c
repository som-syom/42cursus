/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 18:11:40 by dhyeon            #+#    #+#             */
/*   Updated: 2021/05/17 19:43:31 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	command(t_info *info, int cmd)
{
	if (cmd == PA)
		pa(info);
	else if (cmd == PB)
		pb(info);
	else if (cmd == SA)
		sa(info);
	else if (cmd == SB)
		sb(info);
	else if (cmd == SS)
		ss(info);
	else if (cmd == RA)
		ra(info);
	else if (cmd == RB)
		rb(info);
	else if (cmd == RR)
		rr(info);
	else if (cmd == RRA)
		rra(info);
	else if (cmd == RRB)
		rrb(info);
	else if (cmd == RRR)
		rrr(info);
}