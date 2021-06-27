/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungkim <sungkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 20:43:48 by sungkim           #+#    #+#             */
/*   Updated: 2021/05/05 21:02:03 by sungkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*p1;
	unsigned char	*p2;
	int				i;

	p1 = (unsigned char *)dest;
	p2 = (unsigned char *)src;
	if (len == 0 || dest == src)
		return (dest);
	if (p1 < p2)
	{
		i = -1;
		while ((size_t)(++i) < len)
			p1[i] = p2[i];
	}
	else
	{
		p1 = p1 + len - 1;
		p2 = p2 + len - 1;
		i = -1;
		while ((size_t)(++i) < len)
			*(p1 - i) = *(p2 - i);
	}
	return (dest);
}
