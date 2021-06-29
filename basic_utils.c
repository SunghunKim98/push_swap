#include "push_swap.h"

void	init(t_info *p, int *arr, int size)
{
	int	i;

	p->a = (int*)malloc(sizeof(int) * (size));
	p->b = (int*)malloc(sizeof(int) * (size));
	i = -1;
	while (++i < size)
		(p->a)[i] = arr[size - 1 - i];
	p->size_a = size;
	p->size_b = 0;
	p->total = size;
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
