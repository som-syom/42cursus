/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 02:36:05 by dhyeon            #+#    #+#             */
/*   Updated: 2021/05/21 19:56:05 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_new_node(int num, t_node *prev, t_node *next)
{
	t_node	*new;

	new = ft_salloc(1, sizeof(t_node));
	new->num = num;
	new->prev = prev;
	new->next = next;
	return (new);
}

void	push_front_num(t_stack *a, int num)
{
	t_node	*tmp;
	t_node	*prev;

	if (a->top == 0)
		a->top = create_new_node(num, 0, 0);
	else
	{
		tmp = a->top;
		while (tmp)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		tmp = create_new_node(num, prev, 0);
		prev->next = tmp;
	}
}

int		main(int argc, char **argv)
{
	t_info	info;

	if (!check_arg(argc, argv))
		print_error();
	init_stack(argc, argv, &info);
	// test(&info);
	solve(&info);
	test(&info);

	return (0);
}
