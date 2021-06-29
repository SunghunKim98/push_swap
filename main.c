#include "push_swap.h"

int		check_if_duplicates(int *nums, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (nums[i] == nums[j])
			{
				free(nums);
				write(1, "Error\n", 7);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

char	**split_str_to_int(char *str)
{
	char	**args;

	args = ft_split(str, ' ');
	return (args);
}

int		return_len(char *str)
{
	int		count;
	char	*p;

	p = str;
	count = 0;
	while (*p)
	{
		if (*(p++) == ' ')
			count++;
	}
	return (count + 1);
}

int		handle_variable(char **args, int len)
{
	int		*nums;
	char	*check;
	int		i;
	t_info	*p;

	nums = (int*)malloc(sizeof(int) * len);
	i = -1;
	while (++i < len)
	{
		nums[i] = ft_atoi(args[i]);
		check = ft_itoa(nums[i]);
		if (ft_strncmp(args[i], check, ft_strlen(args[i])))
			return (return_error(nums, check));
		free(check);
	}
	if (check_if_duplicates(nums, len))
		return (0);
	p = (t_info*)malloc(sizeof(t_info));
	init(p, nums, len);
	execute_hierarchy(p, len + 1);
	free(p);
	free(nums);
	free(args);
	return (0);
}

int		handle_just_input(char **args, int len)
{
	int		*nums;
	char	*check;
	int		i;
	t_info	*p;

	nums = (int*)malloc(sizeof(int) * len);
	i = -1;
	while (++i < len)
	{
		nums[i] = ft_atoi(args[i + 1]);
		check = ft_itoa(nums[i]);
		if (ft_strncmp(args[i + 1], check, ft_strlen(args[i + 1])))
			return (return_error(nums, check));
		free(check);
	}
	if (check_if_duplicates(nums, len))
		return (0);
	p = (t_info*)malloc(sizeof(t_info));
	init(p, nums, len);
	execute_hierarchy(p, len + 1);
	free(p);
	free(nums);
	return (0);
}

int main(int argc, char **argv)
{
	char	**args;
	int		len;

	if (argc < 2)
		return (0);
	else if (argc == 2)
	{
		args = split_str_to_int(argv[1]);
		len = return_len(argv[1]);
		return (handle_variable(args, len));
	}
	else
		return (handle_just_input(argv, argc - 1));
}
