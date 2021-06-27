/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungkim <sungkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 20:44:19 by sungkim           #+#    #+#             */
/*   Updated: 2021/05/07 15:12:09 by sungkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	putnbr_recur(int n, int fd)
{
	char ch;

	if (n > 0)
	{
		putnbr_recur(n / 10, fd);
		ch = n % 10 + '0';
		write(fd, &ch, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		putnbr_recur(-n, fd);
	}
	else
		putnbr_recur(n, fd);
}
