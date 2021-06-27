/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungkim <sungkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 20:45:00 by sungkim           #+#    #+#             */
/*   Updated: 2021/05/05 20:53:26 by sungkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char*)s1;
	p2 = (unsigned char*)s2;
	i = 0;
	while (i < n)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		if (*p1 == '\0' && *p2 == '\0')
			return (0);
		else if (*p1 == '\0' || *p2 == '\0')
			return (*p1 - *p2);
		i++;
		p1++;
		p2++;
	}
	return (0);
}
