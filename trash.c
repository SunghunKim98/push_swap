#include "push_swap.h"

int		sort_return_mid(int *arr, int num)
{
	int	i;
	int	j;

	i = -1;
	while (++i < num)
	{
		j = -1;
		while (++j < num - i)
		{
			if (arr[j] > arr[j + 1])
				swap(arr, j, j + 1);
		}
	}
	return (arr[num / 2]);
}

int		find_pivot_one(t_info *p, int r, char ch)
{
	int	*num;
	int	i;

	num = (int*)malloc(sizeof(int) * r);
	i = -1;
	if (ch == 'a')
	{
		while (++i < r)
			num[i] = p->a[p->size_a - 1 - i];
	}
	else
	{
		while (++i < r)
			num[i] = p->b[p->size_b - 1 - i];
	}
	i = sort_return_mid(num, r);
	free(num);
	return (i);
}
