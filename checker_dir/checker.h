/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungkim <sungkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:26:22 by sungkim           #+#    #+#             */
/*   Updated: 2021/06/30 21:35:48 by sungkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

#include <unistd.h>
#include <stdlib.h>

#include "../libft_evaluation/libft.h"
#include "get_next_line.h"

typedef struct	s_info
{
	int			*a;
	int			*b;
	int			size_a;
	int			size_b;
	int			total;
}				t_info;

void	swap(int *p, int a, int b);
void	rotate(int *p, int length);
void	reverse_rotate(int *p, int length);
int		sa(t_info *p);
int		sb(t_info *p);

int		ss(t_info *p);
int		pa(t_info *p);
int		pb(t_info *p);
int		ra(t_info *p);
int		rb(t_info *p);

int		rr(t_info *p);
int		rra(t_info *p);
int		rrb(t_info *p);
int		rrr(t_info *p);

#endif
