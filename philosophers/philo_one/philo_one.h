/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 17:48:47 by dhyeon            #+#    #+#             */
/*   Updated: 2021/06/09 20:14:46 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

# define PHILO_MAX 200
# define FORK_MAX 200

# define TAKE_FORK 0
# define EATING 1
# define SLEEPING 2
# define THINGKING 3
# define DEAD 4

typedef struct		s_philo
{
	struct s_info	*info;
	int				num;
	int				time;
	int				is_eating;
	int				left;
	int				right;
}					t_philo;

typedef struct	s_info
{
	t_philo		**philo;
	int			num_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			must_eat;
	int			eat_count;
	int			dead_flag;
	long		start_time;
}				t_info;

pthread_mutex_t	mutex[FORK_MAX];

/*
**	utils
*/

int				ft_atoi(const char *str);
int				ft_isdigit_str(char *str);
void			*ft_calloc(size_t n, size_t size);

#endif