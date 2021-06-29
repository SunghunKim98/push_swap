#include "push_swap.h"

void	A_to_B(t_info *p, int r)
{
	t_pivot		pivot;
	int			i;
	t_call		*call;
	int			flag;

	if (!check_if_sorted(p, r, 'a'))
	{
		if (r <= 3)
		return (sort_under_three(p, r, 'a'));
		pivot = find_pivot(p, r, 'a');
		i = -1;
		flag = 0;
		call = init_call();
		while (++i < r)
		{
			if (!check_if_needs_ra(p, i, r, pivot.pivot_big))
			{
				flag = r - i;
				break;
			}
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
		if (flag)
			A_to_B(p, flag + call->ra_call_num);
		else
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
	int			flag;

	if (r < 3)
		return (sort_under_three(p, r, 'b'));
	if (!check_if_sorted(p, r, 'b'))
	{
		pivot = find_pivot(p, r, 'b');
		i = -1;
		flag = 0;
		call = init_call();
		while (++i < r)
		{
			if (!check_if_needs_rb(p, i, r, pivot.pivot_small))
			{
				flag = r - i;
				break;
			}
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
		A_to_B(p, call->ra_call_num);
		if (flag)
			B_to_A(p, call->rb_call_num + flag);
		else
			B_to_A(p, call->rb_call_num);
	}
}
