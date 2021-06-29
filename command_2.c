#include "push_swap.h"

void	pa(t_info *p)
{
	int	tmp;

	if (p->size_b > 0)
	{
		tmp = (p->b)[p->size_b - 1];
		p->size_b--;
		p->a[p->size_a++] = tmp;
		ft_putstr("pa");
	}
}

void	pb(t_info *p)
{
	int	tmp;

	if (p->size_a > 0)
	{
		tmp = p->a[p->size_a - 1];
		p->size_a--;
		p->b[p->size_b++] = tmp;
		ft_putstr("pb");
	}
}

void	ra(t_info *p)
{
	if (p->size_a > 1)
	{
		rotate(p->a, p->size_a);
		ft_putstr("ra");
	}
}

void	rb(t_info *p)
{
	if (p->size_b > 1)
	{
		rotate(p->b, p->size_b);
		ft_putstr("rb");
	}
}

void	rr(t_info *p)
{
	if (p->size_a > 1)
		rotate(p->a, p->size_a);
	if (p->size_b > 1)
		rotate(p->b, p->size_b);
	ft_putstr("rr");
}
