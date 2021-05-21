/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 14:09:42 by dhyeon            #+#    #+#             */
/*   Updated: 2021/05/21 21:00:18 by dhyeon           ###   ########.fr       */
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

int		*make_arr_sort(t_stack *s, int size, int type)
{
	int		i;
	int		*arr;
	t_node	*tmp;

	arr = ft_salloc(size, sizeof(int));
	tmp = s->top;
	i = -1;
	while (++i < size)
	{
		if (type == NUM)
			arr[i] = tmp->num;
		else if (type == RANK)
			arr[i] = tmp->rank;
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

	arr = make_arr_sort(info->a, info->size, NUM);
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

	arr = make_arr_sort(s, size, RANK); // 랭크 수정해야함
	sol->pivot1 = arr[(size - 1) / 3];
	sol->pivot2 = arr[(size - 1) / 3 * 2];
	sol->pa_cnt = 0;
	sol->pb_cnt = 0;
	sol->ra_cnt = 0;
	sol->rb_cnt = 0;
	free(arr);
}

void	small_sort(t_info *info, int size, char stack_name)
{
	if (stack_name == 'a')
	{
		if (size == 3)
			mini_sort_3_a(info);
		else if (size == 2)
		{
			if (info->a->size >= 2 && info->a->top->rank > info->a->top->next->rank)
			{
				if (info->b->size >=2 && info->b->top->rank < info->b->top->next->rank)
					command(info, SS, "ss\n");
				else
					command(info, SA, "sa\n");
			}
		}
	}
	else if (stack_name == 'b')
	{
		if (size == 3)
			mini_sort_3_b(info);
		else
		{
			if (size == 2)
			{
				if (info->b->size >= 2 && info->b->top->rank < info->b->top->next->rank)
				{
					if (info->a->size >=2 && info->a->top->rank > info->a->top->next->rank)
						command(info, SS, "ss\n");
					else
						command(info, SB, "sb\n");
				}
				command(info, PA, "pa\n");
			}
			command(info, PA, "pa\n");
		}
	}
}

void	re_rotate2(t_info *info, int ra_size, int rb_size)
{
	if (info->a->size / 2 > ra_size && info->b->size / 2 < rb_size)
	{
		rb_size = info->b->size - rb_size;
		while (ra_size-- > 0)
			command(info, RRA, "rra\n");
		while (rb_size-- > 0)
			command(info, RB, "rb\n");
	}
	else
	{
		ra_size = info->a->size - ra_size;
		while (ra_size-- > 0)
			command(info, RA, "ra\n");
		while (rb_size-- > 0)
			command(info, RRB, "rrb\n");
	}
	// 나중에 최적화 필요
}

void	re_rotate(t_info *info, int ra_size, int rb_size)
{
	int	rrr;

	if (ra_size != 0)
		ra_size =  ra_size % info->a->size;
	if (rb_size != 0)
		rb_size = rb_size % info->b->size;
	if (ra_size < rb_size)
		rrr = ra_size;
	else
		rrr = rb_size;
	ra_size -= rrr;
	rb_size -= rrr;
	if (info->a->size / 2 < ra_size && info->b->size / 2 < rb_size)
	{
		ra_size = info->a->size - ra_size;
		rb_size = info->b->size - rb_size;
		while (rrr--)
			command(info, RR, "rr\n");
		while (ra_size-- > 0)
			command(info, RA, "ra\n");
		while (rb_size-- > 0)
			command(info, RB, "rb\n");
	}
	else// if (info->a->size / 2 > ra_size && info->b->size / 2 > rb_size)
	{
		while (rrr--)
			command(info, RRR, "rrr\n");
		while (ra_size-- > 0)
			command(info, RRA, "rra\n");
		while (rb_size-- > 0)
			command(info, RRB, "rrb\n");
	}
	// else //	반대로 도는 경우
	// 	re_rotate2(info, ra_size, rb_size);
}

void	b_to_a(t_info *info, int size)
{
	t_solve	sol;

	if (size <= 3)
	{
		small_sort(info, size, 'b');
		return ;
	}
	init_solve(&sol, info->b, size);
	// printf("===================[ btoa ] \n");
	// test_pivot(size, sol.pivot1, sol.pivot2);
	while (size--)
	{
		if (info->b->top->rank < sol.pivot1)
			sol.rb_cnt += command(info, RB, "rb\n");
		else
			sol.pa_cnt += command(info, PA, "pa\n");
			if (info->a->top->rank < sol.pivot2)
				sol.ra_cnt += command(info, RA, "ra\n");
	}
	a_to_b(info, sol.pa_cnt - sol.ra_cnt);
		// printf("       rotate : ra = %d | rb = %d | pa - ra = %d\n", sol.ra_cnt, sol.rb_cnt, sol.pa_cnt - sol.ra_cnt);
	re_rotate(info, sol.ra_cnt, sol.rb_cnt);
	a_to_b(info, sol.ra_cnt);
	b_to_a(info, sol.rb_cnt);
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
	// printf("===================[ atob ]\n");
	// test_pivot(size, sol.pivot1, sol.pivot2);
	while (size--)
	{
		if (info->a->top->rank >= sol.pivot2)
			sol.ra_cnt += command(info, RA, "ra\n");
		else
		{
			sol.pb_cnt += command(info, PB, "pb\n");
			if (info->b->top->rank >= sol.pivot1)
				sol.rb_cnt += command(info, RB, "rb\n");
		}
	}
		// printf("       rotate : ra = %d | rb = %d | pb - rb = %d\n", sol.ra_cnt, sol.rb_cnt, sol.pb_cnt - sol.rb_cnt);
	re_rotate(info, sol.ra_cnt, sol.rb_cnt);
	a_to_b(info, sol.ra_cnt);
	b_to_a(info, sol.rb_cnt);
	b_to_a(info, sol.pb_cnt - sol.rb_cnt);
}

int		is_sorted(t_info *info)
{
	t_node	*tmp;
	int		i;

	i = 1;
	tmp = info->a->top;
	while (i <= info->size)
	{
		if (tmp->rank != i)
			return (0);
		i++;
		tmp = tmp->next;
	}
	return (1);
}

void	solve(t_info *info)
{
	save_rank(info);
	// test_rank(info);
	if (!is_sorted(info))
		a_to_b(info, info->a->size);
}
