/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungkim <sungkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 20:40:30 by sungkim           #+#    #+#             */
/*   Updated: 2021/05/05 21:31:00 by sungkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

	p1 = (unsigned char *)dest;
	p2 = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		p1[i] = p2[i];
		if (p2[i] == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
