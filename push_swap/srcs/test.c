#include "push_swap.h"

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
			printf("%-10d", bb->num);
			bb = bb->next;
		}
		printf("\n");
	}
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
