/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 22:37:15 by dhyeon            #+#    #+#             */
/*   Updated: 2021/06/10 22:20:22 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>

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
	pid_t			pid;
	pthread_t		monitor;
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
	sem_t		*forks;
	sem_t		*eat_count;
	int			num_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			must_eat;
	int			end_flag;
	long		start_time;
// jachoi
	sem_t		*die;
}				t_info;

void	msleep(int ms);
void	*ft_calloc(size_t n, size_t size);
int		ft_isdigit_str(char *str);
int		ft_atoi(const char *str);

 #endif