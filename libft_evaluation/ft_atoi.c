/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungkim <sungkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 20:39:24 by sungkim           #+#    #+#             */
/*   Updated: 2021/05/06 16:09:37 by sungkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check(char ch)
{
	if (ch == ' '
		|| ch == '\t'
		|| ch == '\n'
		|| ch == '\v'
		|| ch == '\f'
		|| ch == '\r')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int		flag;
	long	sum;

	flag = 0;
	sum = 0;
	while (check(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			flag++;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		sum = 10 * sum + *str - '0';
		str++;
	}
	if (flag % 2 == 1)
		sum = -sum;
	return ((int)sum);
}
