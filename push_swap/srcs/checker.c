/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 15:14:54 by dhyeon            #+#    #+#             */
/*   Updated: 2021/05/22 17:54:33 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (s1 == 0)
		return (-1);
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (s1[i] == '\0' && s2[i] == '\0')
		return (0);
	return (s1[i] - s2[i]);
}

void	handle_cmd(t_info *info, char *cmd)
{
	if (!ft_strcmp(cmd, "pa"))
		command(info, PA, 0);
	else if (!ft_strcmp(cmd, "pb"))
		command(info, PB, 0);
	else if (!ft_strcmp(cmd, "sa"))
		command(info, SA, 0);
	else if (!ft_strcmp(cmd, "sb"))
		command(info, SB, 0);
	else if (!ft_strcmp(cmd, "ss"))
		command(info, SS, 0);
	else if (!ft_strcmp(cmd, "ra"))
		command(info, RA, 0);
	else if (!ft_strcmp(cmd, "rb"))
		command(info, RB, 0);
	else if (!ft_strcmp(cmd, "rr"))
		command(info, RR, 0);
	else if (!ft_strcmp(cmd, "rra"))
		command(info, RRA, 0);
	else if (!ft_strcmp(cmd, "rrb"))
		command(info, RRB, 0);
	else if (!ft_strcmp(cmd, "rrr"))
		command(info, RRR, 0);
	else
		print_error();
}

int		is_sorted_ab(t_info *info)
{
	t_node	*tmp;
	int		i;

	if (info->b->size != 0)
		return (0);
	tmp = info->a->top;
	i = 1;
	while (tmp)
	{
		if (tmp->rank != i)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_info	info;
	char	*line;
	int		rd;

	if (!check_arg(argc, argv))
		print_error();
	init_stack(argc, argv, &info);
	save_rank(&info);
	while ((rd = get_next_line(0, &line)) > 0)
	{
		handle_cmd(&info, line);
		free(line);
	}
	if (rd == 0)
	{
		if (!is_sorted_ab(&info))
			write(1, "KO\n", 3);
		else
			write(1, "OK\n", 3);
	}
	return (0);
}