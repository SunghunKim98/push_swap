/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungkim <sungkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:43:35 by sungkim           #+#    #+#             */
/*   Updated: 2021/06/27 13:53:53 by sungkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft_evaluation/libft.h"

typedef struct	s_info
{
	int			*a;
	int			*b;
	int			size_a;
	int			size_b;
	int			total;
}				t_info;

typedef struct	s_call
{
	int			pa_call_num;
	int			pb_call_num;
	int			ra_call_num;
	int			rb_call_num;
}				t_call;

typedef	struct	s_pivot
{
	int			pivot_big;
	int			pivot_small;
}				t_pivot;

void			init(t_info *p, int *arr, int size);
void			print_all(t_info *p);
void			swap(int *p, int a, int b);
void			rotate(int *p, int length);
void			reverse_rotate(int *p, int length);
void			sa(t_info *p);
void			sb(t_info *p);
void			ss(t_info *p);
void			pa(t_info *p);
void			pb(t_info *p);
void			ra(t_info *p);
void			rb(t_info *p);
void			rr(t_info *p);
void			rra(t_info *p);
void			rrb(t_info *p);
void			rrr(t_info *p);
void			free_all(t_info *p);

void			bring_them_up(t_info *p, t_call *call);
void			sort_under_three(t_info *p, int r, char ch);
void			A_to_B(t_info *p, int r);
void			B_to_A(t_info *p, int r);

void			set_ra(t_info *p, t_call *call);
void			set_rb(t_info *p, t_call *call);
void			set_pa(t_info *p, t_call *call);
void			set_pb(t_info *p, t_call *call);

void			init_pivot(t_pivot *p);
void			sort_return_pivots(t_pivot *p, int *arr, int num);
t_pivot			find_pivot(t_info *p, int r, char ch);
t_call			*init_call();

int				sort_return_mid(int *arr, int num);
int				find_pivot_one(t_info *p, int r, char ch);

void			ft_putstr(char *str);

#endif
