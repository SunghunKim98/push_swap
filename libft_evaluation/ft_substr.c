/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungkim <sungkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 20:45:17 by sungkim           #+#    #+#             */
/*   Updated: 2021/05/08 17:28:57 by sungkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	if (s == NULL)
		return (NULL);
	p = (char*)malloc(sizeof(char) * (len + 1));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[i] != '\0' && i + start < ft_strlen(s))
	{
		p[i] = s[i + start];
		i++;
	}
	p[i] = '\0';
	return (p);
}
