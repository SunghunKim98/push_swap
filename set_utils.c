#include "push_swap.h"

void	set_ra(t_info *p, t_call *call)
{
	ra(p);
	call->ra_call_num++;
}

void	set_rb(t_info *p, t_call *call)
{
	rb(p);
	call->rb_call_num++;
}

void	set_pa(t_info *p, t_call *call)
{
	pa(p);
	call->pa_call_num++;
}

void	set_pb(t_info *p, t_call *call)
{
	pb(p);
	call->pb_call_num++;
}
