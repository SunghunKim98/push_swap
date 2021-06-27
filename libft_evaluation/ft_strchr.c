/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungkim <sungkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 20:44:34 by sungkim           #+#    #+#             */
/*   Updated: 2021/05/06 12:23:00 by sungkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*p;
	int		size;
	int		i;

	p = (char*)s;
	i = 0;
	size = ft_strlen(p);
	while (i <= size)
	{
		if (p[i] == (char)c)
			return (p + i);
		i++;
	}
	return (NULL);
}
