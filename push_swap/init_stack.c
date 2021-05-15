/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 04:04:02 by dhyeon            #+#    #+#             */
/*   Updated: 2021/05/16 06:13:11 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	check_arg(int ac, char **argv)
{
	int	i;
	int	j;

	if (ac < 2)
		return (0);
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

void	create_stack(t_stack *a, char **av)
{
	int			i;
	long long	num;
	t_node		*tmp;

	i = 1;
	while (av[i])
	{
		num = ft_atoi(av[i]);
		printf("num : %lld\n", num);
		if (!(INT_MIN < num && num < INT_MAX))
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
	info->a = ft_calloc(1, sizeof(t_stack));
	info->b = ft_calloc(1, sizeof(t_stack));
	ft_memset((void *)info->a, 0, sizeof(t_stack));
	ft_memset((void *)info->b, 0, sizeof(t_stack));
	info->size = ac - 1;
	info->a->size = ac - 1;
	info->b->size = 0;
	create_stack(info->a, av);
}
