/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 17:48:47 by dhyeon            #+#    #+#             */
/*   Updated: 2021/06/12 22:19:43 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

# define PHILO_MAX	200
# define FORK_MAX	200

# define TAKE_FORK	0
# define EATING		1
# define SLEEPING	2
# define THINGKING	3
# define DEAD		4

# define FORK_MSG	"has taken a fork"
# define EAT_MSG	"is eating"
# define SLEEP_MSG	"is sleeping"
# define THINK_MSG	"is thinking"
# define DIE_MSG	"died"

typedef struct		s_philo
{
	struct s_info	*info;
	int				num;
	int				time;
	int				is_eating;
	int				eat_count;
	int				left;
	int				right;
}					t_philo;

typedef struct		s_info
{
	pthread_t		*p;
	t_philo			**philo;
	pthread_mutex_t	print;
	int				num_philo;
	int				time_to_die;
	int					time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				end_flag;
	long			start_time;
}					t_info;

pthread_mutex_t		mutex[FORK_MAX];

/*
**	philo
*/

void				print_status(t_philo *philo, int flag, char *msg);
void				eating(t_philo *philo, int first, int second);
void				*philo_routine(void *p);
int					check_time(t_info *info, int i, long time);
int					check_must_eat(t_info *info);
void				*check_status(t_info *info);
void				make_thread(t_info *info);
int					check_arg(t_info *info, int ac, char **av);

/*
**	utils
*/

void				msleep(int ms);
int					ft_atoi(const char *str);
int					ft_isdigit_str(char *str);
void				*ft_calloc(size_t n, size_t size);

#endif