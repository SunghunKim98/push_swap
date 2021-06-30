/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungkim <sungkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:28:50 by sungkim           #+#    #+#             */
/*   Updated: 2021/06/30 21:46:53 by sungkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		return_error(int *p1, char *p2)
{
	free(p1);
	free(p2);
	write(1, "Error\n", 7);
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

int		error()
{
	write(1, "Error\n", 7);
	return (0);
}

int		execute_one(t_info *p, char *str)
{
	if (!ft_strncmp(str, "sa", (int)ft_strlen(str)))
		return (sa(p));
	else if (!ft_strncmp(str, "sb", (int)ft_strlen(str)))
		return (sb(p));
	else if (!ft_strncmp(str, "ss", (int)ft_strlen(str)))
		return (ss(p));
	else if (!ft_strncmp(str, "pa", (int)ft_strlen(str)))
		return (pa(p));
	else if (!ft_strncmp(str, "pb", (int)ft_strlen(str)))
		return (pb(p));
	else if (!ft_strncmp(str, "ra", (int)ft_strlen(str)))
		return (ra(p));
	else if (!ft_strncmp(str, "rb", (int)ft_strlen(str)))
		return (rb(p));
	else if (!ft_strncmp(str, "rr", (int)ft_strlen(str)))
		return (rr(p));
	else if (!ft_strncmp(str, "rra", (int)ft_strlen(str)))
		return (rra(p));
	else if (!ft_strncmp(str, "rrb", (int)ft_strlen(str)))
		return (rrb(p));
	else if (!ft_strncmp(str, "rrr", (int)ft_strlen(str)))
		return (rrr(p));
	else
		return (error());
}

int		execute_input(t_info *p)
{
	char	*str;

	while (get_next_line(0, &str))
	{
		if (!execute_one(p, str))
			return (0);
		free(str);
	}
	free(str);
	return (1);
}

void	check_if_sorted_free(t_info *p, int *args)
{
	int		i;
	int		flag;

	flag = 0;
	i = -1;
	while (++i < p->size_a - 1 && flag == 0)
	{
		if (p->a[p->size_a - 1 - i] > p->a[p->size_a - 2 - i])
			flag = 1;
	}
	if (flag == 0)
		write(1, "OK\n", 4);
	else
		write(1, "KO\n", 4);
	free(p);
	free(args);
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
	if (!execute_input(p))
		return (0);
	check_if_sorted_free(p, args);
	return (0);
}

int main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	else
		return (if_argc_over_two(argc, argv));
}
