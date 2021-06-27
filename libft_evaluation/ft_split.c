/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungkim <sungkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 20:44:30 by sungkim           #+#    #+#             */
/*   Updated: 2021/05/08 20:56:08 by sungkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		find_num(char const *s, char c)
{
	char const	*p;
	int			num;

	num = 0;
	p = s;
	while (*p)
	{
		if (*(p++) == c)
			num++;
	}
	return (num);
}

char	*ft_strncpy(char const *str, int start, int end)
{
	char	*p;
	int		i;

	p = (char*)malloc(sizeof(char) * (end - start + 1));
	i = 0;
	while (i < end - start)
	{
		p[i] = str[start + i];
		i++;
	}
	p[end - start] = '\0';
	return (p);
}

void	reset(int *i, int *index, int *start)
{
	*i = -1;
	*index = 0;
	*start = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	int		start;
	int		end;
	int		i;
	int		index;

	p = (char**)malloc(sizeof(char*) * (find_num(s, c) + 2));
	if (p == 0)
		return (NULL);
	reset(&i, &index, &start);
	while (s[++i])
	{
		if (s[i] == c)
		{
			end = i;
			if (start != end)
				p[index++] = ft_strncpy(s, start, end);
			start = end + 1;
		}
	}
	if (start != i)
		p[index++] = ft_strncpy(s, start, i);
	p[index] = NULL;
	return (p);
}
