#include "push_swap.h"

void		init_pivot(t_pivot *p)
{
	p->pivot_big = 0;
	p->pivot_small = 0;
}

void		sort_return_pivots(t_pivot *p, int *arr, int num)
{
	int	i;
	int	j;

	i = 0;
	while (++i < num)
	{
		j = -1;
		while (++j < num - i)
		{
			if (arr[j] > arr[j + 1])
				swap(arr, j, j + 1);
		}
	}
	p->pivot_big = arr[num / 3 * 2];
	p->pivot_small = arr[num / 3];
}

t_pivot		find_pivot(t_info *p, int r, char ch)
{
	t_pivot		pivot;
	int			*num;
	int			i;

	init_pivot(&pivot);
	if(!(num = (int*)malloc(sizeof(int) * r)))
		return (pivot);
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
	sort_return_pivots(&pivot, num, r);
	return (pivot);
}

t_call      *init_call()
{
	t_call	*p;

	p = (t_call*)malloc(sizeof(t_call));
	p->pa_call_num = 0;
	p->pb_call_num = 0;
	p->ra_call_num = 0;
	p->rb_call_num = 0;
	return (p);
}