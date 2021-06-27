/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungkim <sungkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 20:45:10 by sungkim           #+#    #+#             */
/*   Updated: 2021/05/06 12:23:27 by sungkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	int		size;

	p = (char*)s;
	size = 0;
	while (p[size])
		size++;
	while (size >= 0)
	{
		if (p[size] == (char)c)
			return (p + size);
		size--;
	}
	return (NULL);
}
