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

int		return_len(char *str)
{
	int		count;
	char	*p;

	p = str;
	count = 0;
	while (*p)
	{
		if (*p == ' ')
			p++;
		else
			break;
	}
	while (*p)
	{
		if (*p != ' ' && *(p + 1) == ' ')
			count++;
		if (*p != ' ' && *(p + 1) == 0)
			count++;
		p++;
	}
	return (count);
}

int		add_to_args(int *args, char *str, int *len)
{
	int		i;
	int		num;
	char	*check;
	char	**args_char;

	num = return_len(str);
	i = -1;
	args_char = ft_split(str, ' ');
	while (++i < num)
	{
		args[*len + i] = ft_atoi(args_char[i]);
		check = ft_itoa(args[*len + i]);
		if (ft_strncmp(args_char[i], check, ft_strlen(args_char[i])))
			return (return_error(args, check));
		free(check);
	}
	*len = *len + i;
	return (1);
}

int		if_argc_over_two(int argc, char **argv)
{
	int		*args;
	int		i;
	int		len;
	t_info	*p;

	i = 0;
	len = 0;
	while (++i < argc - 1)
		if (return_len(argv[i]))
			len += return_len(argv[i]);
	args = (int*)malloc(sizeof(int) * (len + 1));
	i = 0;
	len = 0;
	while (++i < argc)
		if (!add_to_args(args, argv[i], &len))
			return (0);
	if (check_if_duplicates(args, len))
		return (0);
	p = (t_info*)malloc(sizeof(t_info));
	init(p, args, len);
	execute_hierarchy(p, len + 1);
	free(p);
	free(args);
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	else
		return (if_argc_over_two(argc, argv));
}
