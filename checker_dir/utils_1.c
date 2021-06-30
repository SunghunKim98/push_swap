# include "checker.h"

void	swap(int *p, int a, int b)
{
	int tmp;

	tmp = p[a];
	p[a] = p[b];
	p[b] = tmp;
}

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

int		sa(t_info *p)
{
	if (p->size_a > 1)
		swap(p->a, p->size_a - 1, p->size_a - 2);
	return (1);
}

int		sb(t_info *p)
{
	if (p->size_b > 1)
		swap(p->b, p->size_b - 1, p->size_b - 2);
	return (1);
}
