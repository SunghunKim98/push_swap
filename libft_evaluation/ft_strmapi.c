/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmapi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungkim <sungkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 20:44:57 by sungkim           #+#    #+#             */
/*   Updated: 2021/05/05 20:52:59 by sungkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*p;
	size_t	size;
	size_t	i;

	size = ft_strlen(s);
	p = (char *)malloc(sizeof(char) * (size + 1));
	if (p == 0)
		return (NULL);
	i = 0;
	while (i < size)
	{
		p[i] = f(i, s[i]);
		i++;
	}
	p[i] = '\0';
	return (p);
}
