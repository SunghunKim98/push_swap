#include "checker.h"

int		ss(t_info *p)
{
	if (p->size_a > 1)
		swap(p->a, p->size_a - 1, p->size_a - 2);
	if (p->size_b > 1)
		swap(p->b, p->size_b - 1, p->size_b - 2);
	return (1);
}

int		pa(t_info *p)
{
	int	tmp;

	if (p->size_b > 0)
	{
		tmp = (p->b)[p->size_b - 1];
		p->size_b--;
		p->a[p->size_a++] = tmp;
	}
	return (1);
}

int		pb(t_info *p)
{
	int	tmp;

	if (p->size_a > 0)
	{
		tmp = p->a[p->size_a - 1];
		p->size_a--;
		p->b[p->size_b++] = tmp;
	}
	return (1);
}

int		ra(t_info *p)
{
	if (p->size_a > 1)
		rotate(p->a, p->size_a);
	return (1);
}

int		rb(t_info *p)
{
	if (p->size_b > 1)
		rotate(p->b, p->size_b);
	return (1);
}
