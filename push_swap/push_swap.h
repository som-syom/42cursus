/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 02:27:49 by dhyeon            #+#    #+#             */
/*   Updated: 2021/05/16 06:07:42 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct	s_node
{
	int				num;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct	s_stack
{
	t_node		*top;
	t_node		*bottom;
	int			size;
}				t_stack;

typedef struct	s_info
{
	t_stack		*a;
	t_stack		*b;
	int			size;
	int			count;
}				t_info;

void		*ft_calloc(size_t n, size_t size);
long long	ft_atoi(const char *str);
void		*ft_memset(void *ptr, int val, size_t n);
int			ft_isdigit(int c);

void		print_error(void);
int			check_arg(int ac, char **argv);
void		create_stack(t_stack *a, char **av);
void		init_stack(int ac, char **av, t_info *info);
void		push_front_num(t_stack *a, int num);
t_node		*create_new_node(int num, t_node *prev, t_node *next);

void		pa(t_info *info);
void		pb(t_info *info);
void		sa(t_info *info);
void		sb(t_info *info);
void		ss(t_info *info);
void		ra(t_info *info);
void		rb(t_info *info);
void		rr(t_info *info);
void		rra(t_info *info);
void		rrb(t_info *info);
void		rrr(t_info *info);

#endif
