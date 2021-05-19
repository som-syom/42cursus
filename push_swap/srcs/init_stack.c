/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 04:04:02 by dhyeon            #+#    #+#             */
/*   Updated: 2021/05/19 17:55:15 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int		check_arg(int ac, char **argv)
{
	int	i;
	int	j;

	if (ac == 1)
		exit(1);
	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && !(j == 0 && argv[i][j] == '-'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		check_duplicated(t_stack *a, int num)
{
	t_node	*tmp;

	tmp = a->top;
	while (tmp)
	{
		if (tmp->num == num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	create_stack(t_stack *a, char **av)
{
	int			i;
	long long	num;
	t_node		*tmp;
	int			flag;

	i = 1;
	while (av[i])
	{
		flag = 0;
		num = ft_atoi(av[i], &flag);
		// printf("num : %lld\n", num);
		if (!(INT_MIN < num && num < INT_MAX) || flag == 1)
			print_error();
		if (!check_duplicated(a, (int)num))
			print_error();
		push_front_num(a, (int)num);
		i++;
	}
	tmp = a->top;
	while (tmp->next)
		tmp = tmp->next;
	a->bottom = tmp;
}

void	init_stack(int ac, char **av, t_info *info)
{
	ft_memset((void *)info, 0, sizeof(info));
	info->a = ft_salloc(1, sizeof(t_stack));
	info->b = ft_salloc(1, sizeof(t_stack));
	ft_memset((void *)info->a, 0, sizeof(t_stack));
	ft_memset((void *)info->b, 0, sizeof(t_stack));
	info->size = ac - 1;
	info->a->size = ac - 1;
	info->b->size = 0;
	create_stack(info->a, av);
}
