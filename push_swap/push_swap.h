/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:51:13 by cbustama          #+#    #+#             */
/*   Updated: 2022/02/08 17:30:20 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	top;
	int	maxsize;
	int	*items;
}t_stack;

t_stack	*newstack(int capacity);
void	ft_sa_order(t_stack *a, int n);
int		ft_char(int n, char **str);
int		ft_rep(int n, int *stack);
int		ft_error_atoi(const char *str);
void	ft_sb_order(t_stack *a, int n);
void	ft_ra_order(t_stack *a, int n);
void	ft_rra_order(t_stack *a, int n);
void	ft_pa_order(t_stack *a, t_stack *b);
void	ft_pb_order(t_stack *a, t_stack *b);
int		order_now(t_stack *a);
int		min_max(t_stack *a, int n);
void	order_small(t_stack *a, t_stack *b);
int		ft_above(t_stack *a, int n);
void	ft_sort(t_stack *a);
void	rotate_a(t_stack *a, int n);
void	sort_magic(t_stack *a, t_stack *b);
void	ft_rb_order(t_stack *b, int n);
void	ft_rrb_order(t_stack *b, int n);
void	rotate_b(t_stack *b, int n);
int		ft_index(t_stack *a, int n);
void	move_top(t_stack *a, int min, int max);
void	top_position(t_stack *a, t_stack *b);
void	put_in_position(t_stack *a, t_stack *b);
void	move_min_max_top(t_stack *b);
void	start_n(char *c, t_stack *a, t_stack *b, int n);
void	start_b(char *c, t_stack *a, t_stack *b, int n);
void	index_s(t_stack **a);
t_stack	*go_st(int size, char **args);
void	_write(void);
void	rever_items(int *items, size_t size);
void	put_position_b(t_stack *a, t_stack *b);
int		min(t_stack *stack);
int		max(t_stack *stack);
void	position(t_stack *a, t_stack *b);
#endif
