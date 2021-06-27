/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungkim <sungkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 20:45:14 by sungkim           #+#    #+#             */
/*   Updated: 2021/05/06 17:46:01 by sungkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*p;
	size_t	i;

	if (s1 == 0 || set == 0)
		return (NULL);
	start = 0;
	while (ft_strchr(set, s1[start]) && s1[start])
		start++;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[end - 1]) && start < end)
		end--;
	p = (char*)malloc(sizeof(char) * (end - start + 1));
	if (p == 0)
		return (NULL);
	i = 0;
	while (i < end - start)
	{
		p[i] = s1[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
