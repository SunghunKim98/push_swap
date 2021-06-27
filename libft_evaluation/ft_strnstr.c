/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungkim <sungkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 20:45:03 by sungkim           #+#    #+#             */
/*   Updated: 2021/05/08 20:51:39 by sungkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	size;
	size_t	i;

	size = ft_strlen((char*)needle);
	if (*needle == 0)
		return ((char*)haystack);
	i = 0;
	while (haystack[i] && i + size <= len)
	{
		if (ft_strncmp(haystack + i, needle, size) == 0)
			return ((char*)(haystack + i));
		i++;
	}
	return (0);
}
