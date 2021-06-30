#include "checker.h"

int		rr(t_info *p)
{
	if (p->size_a > 1)
		rotate(p->a, p->size_a);
	if (p->size_b > 1)
		rotate(p->b, p->size_b);
	return (1);
}

int		rra(t_info *p)
{
	if (p->size_a > 1)
		reverse_rotate(p->a, p->size_a);
	return (1);
}

int		rrb(t_info *p)
{
	if (p->size_b > 1)
		reverse_rotate(p->b, p->size_b);
	return (1);
}

int		rrr(t_info *p)
{
	if (p->size_a > 1)
		reverse_rotate(p->a, p->size_a);
	if (p->size_b > 1)
		reverse_rotate(p->b, p->size_b);
	return (1);
}
