#include "push_swap.h"

void	rotate(int *p, int length)
{
	int	i;
	int	tmp;

	i = length - 1;
	tmp = p[i];
	while (i > 0)
	{
		p[i] = p[i - 1];
		i--;
	}
	p[i] = tmp;
}

void	reverse_rotate(int *p, int length)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = p[0];
	while (i + 1 < length)
	{
		p[i] = p[i + 1];
		i++;
	}
	p[i] = tmp;
}

void	sa(t_info *p)
{
	if (p->size_a > 1)
	{
		swap(p->a, p->size_a - 1, p->size_a - 2);
		ft_putstr("sa");
	}
}

void	sb(t_info *p)
{
	if (p->size_b > 1)
	{
		swap(p->b, p->size_b - 1, p->size_b - 2);
		ft_putstr("sb");
	}
}

void	ss(t_info *p)
{
	if (p->size_a > 1)
		swap(p->a, p->size_a - 1, p->size_a - 2);
	if (p->size_b > 1)
		swap(p->b, p->size_b - 1, p->size_b - 2);
	ft_putstr("ss");
}
