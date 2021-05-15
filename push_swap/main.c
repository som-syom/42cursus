/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 02:36:05 by dhyeon            #+#    #+#             */
/*   Updated: 2021/05/16 06:17:25 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_new_node(int num, t_node *prev, t_node *next)
{
	t_node	*new;

	new = ft_calloc(1, sizeof(t_node));
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

void	test(t_info *info)
{
	t_node	*aa;
	t_node	*bb;

	aa = info->a->top;
	bb = info->b->top;
	printf("========[ a | b ]========\n");
	while (aa || bb)
	{
		if (aa)
		{
			printf("%10d | ", aa->num);
			aa = aa->next;
		}
		if (bb)
		{
			printf("%10d", bb->num);
			bb = bb->next;
		}
		printf("\n");
	}
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (!check_arg(argc, argv))
		print_error();
	init_stack(argc, argv, &info);
	test(&info);
	return (0);
}
