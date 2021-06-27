#include "push_swap.h"

void	ft_putstr(char *str)
{
	int		i;

	i = -1;
	while (++i < (int)ft_strlen(str))
		write(1, &str[i], 1);
}
