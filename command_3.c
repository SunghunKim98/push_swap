#include "push_swap.h"

void	rra(t_info *p)
{
	if (p->size_a > 1)
	{
		reverse_rotate(p->a, p->size_a);
		ft_putstr("rra");
	}
}

void	rrb(t_info *p)
{
	if (p->size_b > 1)
	{
		reverse_rotate(p->b, p->size_b);
		ft_putstr("rrb");
	}
}

void	rrr(t_info *p)
{
	if (p->size_a > 1)
		reverse_rotate(p->a, p->size_a);
	if (p->size_b > 1)
		reverse_rotate(p->b, p->size_b);
	ft_putstr("rrr");
}
