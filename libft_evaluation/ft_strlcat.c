/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungkim <sungkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 19:01:32 by sungkim           #+#    #+#             */
/*   Updated: 2021/05/08 18:38:57 by sungkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dest_num;
	size_t	src_num;

	i = 0;
	dest_num = ft_strlen(dest);
	src_num = ft_strlen(src);
	if (dstsize < dest_num + 1)
		return (src_num + dstsize);
	while (i + 1 + dest_num < dstsize)
	{
		if (*(src + i) == 0)
			break ;
		*(dest + dest_num + i) = *(src + i);
		i++;
	}
	*(dest + dest_num + i) = '\0';
	return (src_num + dest_num);
}
