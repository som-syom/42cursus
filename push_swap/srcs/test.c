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
			printf("| %-10d", bb->num);
			bb = bb->next;
		}
		printf("\n");
	}
	printf("-------------------------\n");
	printf("cnt = %d\n", info->count);
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

void	test_pivot(int size, int p1, int p2)
{
	printf("size : %d==================================\n", size);
	printf("pivot1 : %d\n", p1);
	printf("pivot2 : %d\n", p2);
}