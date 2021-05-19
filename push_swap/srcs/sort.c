/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 14:09:42 by dhyeon            #+#    #+#             */
/*   Updated: 2021/05/18 16:29:34 by dhyeon           ###   ########.fr       */
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

void	solve(t_info *info)
{
	int		arr[info->a->size];
	t_node	*tmp;
	int		i;

	tmp = info->a->top;
	i = -1;
	while (tmp)
	{
		arr[++i] = tmp->num;
		tmp = tmp->next;
	}
	test_arr(arr, i);
	quick_sort(arr, 0, i);
	test_arr(arr, i);
}