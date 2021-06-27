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

void	sort_under_three(t_info *p, int r, char ch)
{
	if (ch == 'a')
	{
		if (r == 2)
		{
			if (p->a[p->size_a - 1] > p->a[p->size_a - 2])
				sa(p);
		}
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

void	deal_with_three(t_info *p, char ch)
{
	if (ch == 'a')
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
	else
	{
		if ((p->b[p->size_b - 1] > p->b[p->size_b - 2]) &&
		(p->b[p->size_b - 1] < p->b[p->size_b - 3]))
			rrb(p);
		else if ((p->b[p->size_b - 1] < p->b[p->size_b - 2]) &&
		(p->b[p->size_b - 2] < p->b[p->size_b - 3]))
		{
			sb(p);
			rrb(p);
		}
		else if ((p->b[p->size_b - 2] < p->b[p->size_b - 3]) &&
		(p->b[p->size_b - 1] > p->b[p->size_b - 3]))
		{
			rrb(p);
			sb(p);
		}
		else if ((p->b[p->size_b - 2] > p->b[p->size_b - 3]) &&
		(p->b[p->size_b - 3] > p->b[p->size_b - 1]))
			rb(p);
		else if ((p->b[p->size_b - 1] < p->b[p->size_b - 2]) &&
		(p->b[p->size_b - 1] > p->b[p->size_b - 3]))
			sb(p);
		pa(p);
		pa(p);
		pa(p);
	}
}

void	deal_with_func_4(t_info *p, char ch)
{
	if (ch == 'a')
	{
		if (p->a[p->size_a - 1] > p->a[p->size_a - 4])
			ra(p);
		else if ((p->a[p->size_a - 1] > p->a[p->size_a - 2]) &&
		(p->a[p->size_a - 1] < p->a[p->size_a - 3]))
			sa(p);
		else if ((p->a[p->size_a - 1] > p->a[p->size_a - 3]) &&
		(p->a[p->size_a - 1] < p->a[p->size_a - 4]))
		{
			rra(p);
			sa(p);
			ra(p);
			ra(p);
		}
	}
	// else
	// {
	// 	if (p->b[p->size_b - 1] < p->b[p->size_b - 4])
	// 		rb(p);
	// 	else if ((p->b[p->size_b - 1] < p->b[p->size_b - 2]) &&
	// 	(p->b[p->size_b - 1] > p->b[p->size_b - 3]))
	// 		sb(p);
	// 	else if ((p->b[p->size_b - 1] < p->b[p->size_b - 3]) &&
	// 	(p->b[p->size_b - 1] > p->b[p->size_b - 4]))
	// 	{
	// 		rrb(p);
	// 		sb(p);
	// 		rb(p);
	// 		rb(p);
	// 	}
	// }
}

void	deal_with_func_5(t_info *p, char ch)
{
	if (ch == 'a')
	{
		if (p->a[p->size_a - 1] > p->a[p->size_a - 5])
			ra(p);
		else if ((p->a[p->size_a - 1] > p->a[p->size_a - 2]) &&
		(p->a[p->size_a - 1] < p->a[p->size_a - 3]))
			sa(p);
		else if ((p->a[p->size_a - 1] > p->a[p->size_a - 3]) &&
		(p->a[p->size_a - 1] < p->a[p->size_a - 4]))
			deal_with_three(p, ch);
		else if ((p->a[p->size_a - 1] > p->a[p->size_a - 4]) &&
		(p->a[p->size_a - 1] < p->a[p->size_a - 5]))
		{
			rra(p);
			sa(p);
			ra(p);
			ra(p);
		}
	}
	// else
	// {
	// 	if (p->b[p->size_b - 1] < p->b[p->size_b - 4])
	// 		rb(p);
	// 	else if ((p->b[p->size_b - 1] < p->b[p->size_b - 2]) &&
	// 	(p->b[p->size_b - 1] > p->b[p->size_b - 3]))
	// 		sb(p);
	// 	else if ((p->b[p->size_b - 1] < p->b[p->size_b - 3]) &&
	// 	(p->b[p->size_b - 1] > p->b[p->size_b - 4]))

	// 	else if ((p->b[p->size_b - 1] < p->b[p->size_b - 4]) &&
	// 	(p->b[p->size_b - 1] > p->b[p->size_b - 5]))
	// 	{
	// 		rrb(p);
	// 		sb(p);
	// 		rb(p);
	// 		rb(p);
	// 	}
	// }
}

void	deal_with_five(t_info *p, char ch)
{
	if (ch == 'a')
	{
		pb(p);
		pb(p);
		deal_with_three(p, 'a');
		pa(p);
		if (!check_if_sorted(p, 4, 'a'))
			deal_with_func_4(p, 'a');
		pa(p);
		if (!check_if_sorted(p, 5, 'a'))
			deal_with_func_5(p, 'a');
	}
	else
	{
		pa(p);
		pa(p);
		deal_with_three(p, 'b');
		pb(p);
		if (!check_if_sorted(p, 4, 'b'))
			deal_with_func_4(p, 'b');
		pb(p);
		if (!check_if_sorted(p, 5, 'b'))
			deal_with_func_5(p, 'b');
	}
}

void	deal_with_3_or_5(t_info *p, int r, char ch)
{
	if (r == 3)
		return (deal_with_three(p, ch));
	if (r == 5)
		return (deal_with_five(p, ch));
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

void	A_to_B(t_info *p, int r)
{
	t_pivot		pivot;
	int			i;
	t_call		*call;

	if (r < 3)
	{
		sort_under_three(p, r, 'a');
		return ;
	}
	if (!check_if_sorted(p, r, 'a'))
	{
		// if (r == 3 || r == 5)
		// {
		// 	deal_with_3_or_5(p, r, 'a');
		// 	return ;
		// }
		pivot = find_pivot(p, r, 'a');
		i = -1;
		call = init_call();
		while (++i < r)
		{
			if (!check_if_needs_ra(p, i, r, pivot.pivot_big))
				break;
			if (p->a[p->size_a - 1] >= pivot.pivot_big)
				set_ra(p, call);
			else
			{
				set_pb(p, call);
				if (p->b[p->size_b - 1] >= pivot.pivot_small)
					set_rb(p, call);
			}
		}
		bring_them_up(p, call);
		A_to_B(p, call->ra_call_num);
		B_to_A(p, call->rb_call_num);
		B_to_A(p, call->pb_call_num - call->rb_call_num);
		free(call);
	}
}

void	B_to_A(t_info *p, int r)
{
	t_pivot		pivot;
	int			i;
	t_call		*call;

	if (r < 3)
		return (sort_under_three(p, r, 'b'));
	// if (r == 3)
	// 	return (deal_with_3_or_5(p, r, 'b'));

	if (!check_if_sorted(p, r, 'b'))
	{
		pivot = find_pivot(p, r, 'b');
		i = -1;
		call = init_call();
		while (++i < r)
		{
			if (!check_if_needs_rb(p, i, r, pivot.pivot_small))
				break;
			if (p->b[p->size_b - 1] < pivot.pivot_small)
				set_rb(p, call);
			else
			{
				set_pa(p, call);
				if (p->a[p->size_a - 1] < pivot.pivot_big)
					set_ra(p, call);
			}
		}
		A_to_B(p, call->pa_call_num - call->ra_call_num);
		bring_them_up(p, call);
		A_to_B(p, call->rb_call_num);
		B_to_A(p, call->ra_call_num);
	}
}
