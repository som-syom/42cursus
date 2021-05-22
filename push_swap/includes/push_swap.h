/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 02:27:49 by dhyeon            #+#    #+#             */
/*   Updated: 2021/05/22 17:55:50 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>

# define PA 1
# define PB 2
# define SA 3
# define SB 4
# define SS 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11

# define NUM 1
# define RANK 2

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# define GNL_SUCCESS 1
# define GNL_EOF 0
# define GNL_ERROR -1

typedef struct	s_solve
{
	int			pivot1;
	int			pivot2;
	int			ra_cnt;
	int			rb_cnt;
	int			pa_cnt;
	int			pb_cnt;
}				t_solve;

typedef struct	s_node
{
	int				num;
	int				rank;
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

/*
**	init & utils
*/

void		*ft_salloc(size_t n, size_t size);
void		print_error(void);
int			check_arg(int ac, char **argv);
void		create_stack(t_stack *a, char **av);
void		init_stack(int ac, char **av, t_info *info);
void		push_front_num(t_stack *a, int num);
t_node		*create_new_node(int num, t_node *prev, t_node *next);
int			check_duplicated(t_stack *a, int num);
int			*make_arr_sort(t_stack *s, int size, int type);
t_node		*create_new_node(int num, t_node *prev, t_node *next);
void		push_front_num(t_stack *a, int num);
void		save_rank(t_info *info);

/*
**	solve
*/

int			command(t_info *info, int cmd, char *str);
void		commands(t_info *info, int cmd, char *str, int size);
void		solve(t_info *info);
void		mini_sort_3_a(t_info *info);
void		a_to_b(t_info *info, int size);
void		b_to_a(t_info *info, int size);
void		mini_sort_3_b(t_info *info);

/*
**	instuctions
*/

int			pa(t_info *info);
int			pb(t_info *info);
int			sa(t_info *info);
int			sb(t_info *info);
int			ss(t_info *info);
int			ra(t_info *info);
int			rb(t_info *info);
int			rr(t_info *info);
int			rra(t_info *info);
int			rrb(t_info *info);
int			rrr(t_info *info);

/*
**	checker
*/

int			get_next_line(int fd, char **line);

/*
**	test
*/

void		test_arr(int arr[], int size);
void		test(t_info *info);
void		test_rank(t_info *info);
void		test_pivot(int size, int p1, int p2);

#endif
