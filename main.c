#include "push_swap.h"

int main(int argc, char **argv)
{
	int		*nums;
	int		i;
	t_info	*p;

	nums = (int*)malloc(sizeof(int) * (argc - 1));
	i = -1;
	while (++i < argc - 1)
		nums[i] = ft_atoi(argv[i + 1]);
	p = (t_info*)malloc(sizeof(t_info));
	init(p, nums, argc - 1);

	print_all(p);

	printf("---------------\n");

	A_to_B(p, argc - 1);

	print_all(p);

	return 0;
}
