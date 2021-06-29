#include "push_swap.h"

int		check_if_sorted(t_info *p, int r, char ch)
{
	int		i;

	i = -1;
	if (ch == 'a')
	{
		while (++i < r - 1)
		{
			if (p->a[p->size_a - 1 - i] > p->a[p->size_a - 2 - i])
				return (0);
		}
		return (1);
	}
	else
	{
		while (++i < r - 1)
		{
			if (p->a[p->size_a - 1 - i] < p->a[p->size_a - 2 - i])
				return (0);
		}
		i = -1;
		while (++i < r)
			pa(p);
		return (1);
	}
}

void	deal_with_three(t_info *p)
{
	if ((p->a[p->size_a - 1] > p->a[p->size_a - 2]) &&
	(p->a[p->size_a - 1] < p->a[p->size_a - 3]))
		sa(p);
	else if ((p->a[p->size_a - 1] > p->a[p->size_a - 2]) &&
	(p->a[p->size_a - 2] > p->a[p->size_a - 3]))
	{
		sa(p);
		rra(p);
	}
	else if ((p->a[p->size_a - 2] < p->a[p->size_a - 3]) &&
	(p->a[p->size_a - 1] > p->a[p->size_a - 3]))
		ra(p);
	else if ((p->a[p->size_a - 2] > p->a[p->size_a - 3]) &&
	(p->a[p->size_a - 3] > p->a[p->size_a - 1]))
	{
		sa(p);
		ra(p);
	}
	else if ((p->a[p->size_a - 1] < p->a[p->size_a - 2]) &&
	(p->a[p->size_a - 1] > p->a[p->size_a - 3]))
		rra(p);
}

int		*find_sorted_arr(t_info *p)
{
	int		*nums;
	int		i;
	int		j;

	i = -1;
	nums = (int*)malloc(sizeof(int) * 5);
	while (++i < 5)
		nums[i] = p->a[p->size_a - 1 - i];
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4 - i)
		{
			if (nums[j] > nums[j + 1])
				swap(nums, j, j + 1);
		}
	}
	return (nums);
}

void	filter_with_bigone(t_info *p, int b)
{
	int		i;

	i = -1;
	while (++i < 5)
	{
		if (p->a[p->size_a - 1] > b)
			ra(p);
		else
			pb(p);
	}
	deal_with_three(p);
	if (p->b[p->size_b - 1] < p->b[p->size_b - 2])
		sb(p);
	pa(p);
	pa(p);
}

void	deal_with_five(t_info *p)
{
	int		*num;
	int		second_small;

	if (!check_if_sorted(p, 5, 'a'))
	{
		num = find_sorted_arr(p);
		second_small = num[1];
		filter_with_bigone(p, second_small);
		free(num);
	}
}