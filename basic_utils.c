#include "push_swap.h"

void	init(t_info *p, int *arr, int size)
{
	int	i;

	p->a = (int*)malloc(sizeof(int) * (size));
	p->b = (int*)malloc(sizeof(int) * (size));
	i = -1;
	while (++i < size)
		(p->a)[i] = arr[i];
	p->size_a = size;
	p->size_b = 0;
	p->total = size;
}

void	print_all(t_info *p)
{
	int	i;
	int	bigger;

	if (p->size_a > p->size_b)
		bigger = p->size_a;
	else
		bigger = p->size_b;
	i = bigger - 1;
	while (i >= 0)
	{
		if (i > p->size_a - 1)
			printf("");
		else
			printf("%d", p->a[i]);
		printf("  |  ");
		if (i > p->size_b - 1)
			printf("");
		else
			printf("%d", p->b[i]);
		i--;
		printf("\n");
	}
	printf("\na  |  b\n");
}

void	free_all(t_info *p)
{
	free(p->a);
	free(p->b);
}

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

void	sa(t_info *p)
{
	if (p->size_a > 1)
	{
		swap(p->a, p->size_a - 1, p->size_a - 2);
		ft_putstr("sa\n");
	}
}

void	sb(t_info *p)
{
	if (p->size_b > 1)
	{
		swap(p->b, p->size_b - 1, p->size_b - 2);
		ft_putstr("sb\n");
	}
}

void	ss(t_info *p)
{
	if (p->size_a > 1)
		swap(p->a, p->size_a - 1, p->size_a - 2);
	if (p->size_b > 1)
		swap(p->b, p->size_b - 1, p->size_b - 2);
	ft_putstr("ss\n");
}

void	pa(t_info *p)
{
	int	tmp;

	if (p->size_b > 0)
	{
		tmp = (p->b)[p->size_b - 1];
		p->size_b--;
		p->a[p->size_a++] = tmp;
		ft_putstr("pa\n");
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
		ft_putstr("pb\n");
	}
}

void	ra(t_info *p)
{
	if (p->size_a > 1)
	{
		rotate(p->a, p->size_a);
		ft_putstr("ra\n");
	}
}

void	rb(t_info *p)
{
	if (p->size_b > 1)
	{
		rotate(p->b, p->size_b);
		ft_putstr("rb\n");
	}
}

void	rr(t_info *p)
{
	if (p->size_a > 1)
		rotate(p->a, p->size_a);
	if (p->size_b > 1)
		rotate(p->b, p->size_b);
	ft_putstr("rr\n");
}

void	rra(t_info *p)
{
	if (p->size_a > 1)
	{
		reverse_rotate(p->a, p->size_a);
		ft_putstr("rra\n");
	}
}

void	rrb(t_info *p)
{
	if (p->size_b > 1)
	{
		reverse_rotate(p->b, p->size_b);
		ft_putstr("rrb\n");
	}
}

void	rrr(t_info *p)
{
	if (p->size_a > 1)
		reverse_rotate(p->a, p->size_a);
	if (p->size_b > 1)
		reverse_rotate(p->b, p->size_b);
	ft_putstr("rrr\n");
}
