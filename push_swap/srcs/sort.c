/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 14:09:42 by dhyeon            #+#    #+#             */
/*   Updated: 2021/05/19 22:28:38 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_unit(int arr[], int l, int r)
{
	int	tmp;

	tmp = arr[l];
	arr[l] = arr[r];
	arr[r] = tmp;
}

void	quick_sort(int arr[], int left, int right)
{
	int	l;
	int	r;
	int	pivot;

	l = left;
	r = right;
	pivot = arr[(left + right) / 2];
	while (l <= r)
	{
		while (arr[l] < pivot)
			l++;
		while (arr[r] > pivot)
			r--;
		if (l <= r)
		{
			if (l != r)
				swap_unit(arr, l, r);
			l++;
			r--;
		}
	}
	if (left < r)
		quick_sort(arr, left, r);
	if (l < right)
		quick_sort(arr, l, right);
}

void	test_arr(int arr[], int size)
{
	int	i;

	i = 0;
	while (i <= size)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
}

void	test_rank(t_info *info)
{
	t_node	*tmp;

	tmp = info->a->top;
	while (tmp)
	{
		printf("num : %5d | rank : %d\n", tmp->num, tmp->rank);
		tmp = tmp->next;
	}
}

int		*make_arr_sort(t_stack *s, int size)
{
	int		i;
	int		*arr;
	t_node	*tmp;

	arr = ft_salloc(size, sizeof(int));
	tmp = s->top;
	i = -1;
	while (tmp)
	{
		arr[++i] = tmp->num;
		tmp = tmp->next;
	}
	quick_sort(arr, 0, size - 1);
	return (arr);
}

void	save_rank(t_info *info)
{
	int		*arr;
	int		j;
	int		i;
	t_node	*tmp;

	arr = make_arr_sort(info->a, info->size);
	i = -1;
	tmp = info->a->top;
	while (++i < info->size)
	{
		j = -1;
		while (++j < info->size)
		{
			if (arr[j] == tmp->num)
			{
				tmp->rank = j + 1;
				break ;
			}
		}
		tmp = tmp->next;
	}
	free(arr);
}

void	init_solve(t_solve *sol, t_stack *s, int size)
{
	int		*arr;

	arr = make_arr_sort(s, size);
	sol->pivot1 = arr[(size - 1) / 3];
	sol->pivot2 = arr[(size - 1) / 3 * 2];
	free(arr);
}

void	small_sort(t_info *info, int size, char stack_name)
{
	if (stack_name == 'a')
	{
		if (size == 3)
			mini_sort_3_a(info);
	}
}

void	re_rotate(t_info *info, int ra_size, int rb_size)
{

}

void	b_to_a(t_info *info, int size)
{
	
}

void	a_to_b(t_info *info, int size)
{
	t_solve	sol;

	if (size <= 3)
	{
		small_sort(info, size, 'a');
		return ;
	}
	init_solve(&sol, info->a, size);
	while (size--)
	{
		if (info->a->top->rank > sol.pivot2)
		{
			command(info, RA, "ra\n");
			sol.ra_cnt++;
		}
		else
		{
			command(info, PB, "pb\n");
			sol.pb_cnt++;
			if (info->a->top->rank > sol.pivot1)
			{
				command(info, RB, "rb\n");
				sol.rb_cnt++;
			}
		}
	}
	re_rotate(info, sol.ra_cnt, sol.rb_cnt);
	a_to_b(info, sol.ra_cnt);
	b_to_a(info, sol.rb_cnt);
	b_to_a(info, sol.pb_cnt - sol.rb_cnt);
}

void	solve(t_info *info)
{
	save_rank(info);
	test_rank(info);
	a_to_b(info, info->a->size);
}
