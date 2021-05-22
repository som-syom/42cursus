/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 18:11:40 by dhyeon            #+#    #+#             */
/*   Updated: 2021/05/22 18:15:39 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_cmd(char *str, int flag)
{
	if (str != 0 && flag == 1)
		write(1, str, ft_strlen(str));
}

int		command2(t_info *info, int cmd)
{
	if (cmd == RRA && info->a->size > 1)
		return (rra(info));
	else if (cmd == RRB && info->b->size > 1)
		return (rrb(info));
	else if (cmd == RRR && info->a->size > 1 && info->b->size > 1)
		return (rrr(info));
	else
		return (0);
}

int		command(t_info *info, int cmd, char *str)
{
	int	flag;

	flag = 0;
	if (cmd == PA && info->b->size > 0)
		flag = pa(info);
	else if (cmd == PB && info->a->size > 0)
		flag = pb(info);
	else if (cmd == SA && info->a->size > 1)
		flag = sa(info);
	else if (cmd == SB && info->b->size > 1)
		flag = sb(info);
	else if (cmd == SS && info->a->size > 1 && info->b->size > 1)
		flag = ss(info);
	else if (cmd == RA && info->a->size > 1)
		flag = ra(info);
	else if (cmd == RB && info->b->size > 1)
		flag = rb(info);
	else if (cmd == RR && info->a->size > 1 && info->b->size > 1)
		flag = rr(info);
	else
		flag = command2(info, cmd);
	print_cmd(str, flag);
	// test(info);
	// test_rank(info);
	return (1);
}

void	commands(t_info *info, int cmd, char *str, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		command(info, cmd, str);
		i++;
	}
}