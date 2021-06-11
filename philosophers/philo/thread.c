/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 22:25:20 by dhyeon            #+#    #+#             */
/*   Updated: 2021/06/11 18:12:53 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philo, int first, int second)
{
	pthread_mutex_lock(&mutex[first]);
	if (philo->info->end_flag)
		print_status(philo, TAKE_FORK, FORK_MSG);
	pthread_mutex_lock(&mutex[second]);
	if (philo->info->end_flag)
		print_status(philo, TAKE_FORK, FORK_MSG);
	print_status(philo, EATING, EAT_MSG);
	philo->eat_count++;
	philo->is_eating = 1;
	if (philo->info->end_flag == 0)
		return ;
	msleep(philo->info->time_to_eat);
	pthread_mutex_unlock(&mutex[second]);
	pthread_mutex_unlock(&mutex[first]);
	philo->is_eating = 0;
}

void	*philo_routine(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	while (philo->info->end_flag)
	{
		if (philo->info->end_flag && (philo->num == 0 || philo->num % 2 == 0))
			eating(philo, philo->left, philo->right);
		else if (philo->info->end_flag)
			eating(philo, philo->right, philo->left);
		if (philo->info->end_flag)
			print_status(philo, SLEEPING, SLEEP_MSG);
		if (philo->info->end_flag)
			msleep(philo->info->time_to_sleep);
		if (philo->info->end_flag)
			print_status(philo, THINGKING, THINK_MSG);
	}
	return (0);
}

int		check_time(t_info *info, int i, int time)
{
	if ((info->philo[i]->time != 0 &&
			time - info->philo[i]->time > info->time_to_die)
	 	|| (info->philo[i]->time == 0 && 
		 	time - info->start_time > info->time_to_die))
		return (1);
	return (0);
}

int		check_must_eat(t_info *info)
{
	int	i;

	if (info->must_eat == 0)
		return (0);
	else
	{
		i = -1;
		while (++i < info->num_philo)
		{
			if (info->must_eat > info->philo[i]->eat_count)
				return (0);
		}
		info->end_flag = 0;
		return (1);
	}
}

void	*check_status(t_info *info)
{
	struct timeval	now;
	int				time;
	int				i;

	while (info->end_flag)
	{
		gettimeofday(&now, 0);
		time = ((now.tv_sec * 1000) + (now.tv_usec / 1000));
		i = -1;
		while (++i < info->num_philo)
		{
			if (check_must_eat(info))
				break ;
			if (info->philo[i]->is_eating == 0 && check_time(info, i, time))
			{
				print_status(info->philo[i], DEAD, DIE_MSG);
				info->end_flag = 0;
				break ;
			}
		}
	}
	return (0);
}
