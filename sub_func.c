#include "push_swap.h"

void	bring_them_up(t_info *p, t_call *call)
{
	int		i;

	i = -1;
	if (call->ra_call_num > call->rb_call_num)
	{
		while (++i < call->rb_call_num)
			rrr(p);
		while (i++ < call->ra_call_num)
			rra(p);
	}
	else
	{
		while (++i < call->ra_call_num)
			rrr(p);
		while (i++ < call->rb_call_num)
			rrb(p);
	}
}

void	sort_three(t_info *p)
{
	if ((p->a[p->size_a - 1] > p->a[p->size_a - 2]) &&
	(p->a[p->size_a - 1] < p->a[p->size_a - 3]))
		sa(p);
	if ((p->a[p->size_a - 2] < p->a[p->size_a - 3]) &&
	(p->a[p->size_a - 1] > p->a[p->size_a - 3]))
	{
		sa(p);
		pb(p);
		sa(p);
		pa(p);
	}
	if ((p->a[p->size_a - 1] < p->a[p->size_a - 3]) &&
	(p->a[p->size_a - 2] > p->a[p->size_a - 3]))
	{
		pb(p);
		sa(p);
		pa(p);
	}
	if ((p->a[p->size_a - 1] < p->a[p->size_a - 2]) &&
	(p->a[p->size_a - 1] > p->a[p->size_a - 3]))
	{
		pb(p);
		sa(p);
		pa(p);
		sa(p);
	}
	if ((p->a[p->size_a - 1] > p->a[p->size_a - 2]) &&
	(p->a[p->size_a - 2] > p->a[p->size_a - 3]))
	{
		sa(p);
		pb(p);
		sa(p);
		pa(p);
		sa(p);
	}
}

void	sort_under_three(t_info *p, int r, char ch)
{
	if (ch == 'a')
	{
		if (r == 2)
		{
			if (p->a[p->size_a - 1] > p->a[p->size_a - 2])
				sa(p);
		}
		if (r == 3)
			sort_three(p);
	}
	else
	{
		if (r == 1)
			pa(p);
		else
		{
			if (p->b[p->size_b - 1] < p->b[p->size_b - 2])
				sb(p);
			pa(p);
			pa(p);
		}
	}
}

int		check_if_needs_ra(t_info *p, int i, int r, int pivot)
{
	int		j;

	j = -1;
	while (++j < r - i)
	{
		if (p->a[p->size_a - 1 - j] < pivot)
			return (1);
	}
	return (0);
}

int		check_if_needs_rb(t_info *p, int i, int r, int pivot)
{
	int		j;

	j = -1;
	while (++j < r - i)
	{
		if (p->b[p->size_b - 1 - j] > pivot)
			return (1);
	}
	return (0);
}
