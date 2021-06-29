#include "push_swap.h"

void	ft_putstr(char *str)
{
	int		i;

	i = -1;
	while (++i < (int)ft_strlen(str))
		write(1, &str[i], 1);
	write(1, "\n", 1);
}

int		return_error(int *p1, char *p2)
{
	free(p1);
	free(p2);
	write(1, "Error\n", 7);
	return (0);
}

void	execute_hierarchy(t_info *p, int argc)
{
	if (argc - 1 == 3)
		deal_with_three(p);
	else if (argc - 1 == 5)
		deal_with_five(p);
	else
		A_to_B(p, argc - 1);
}
