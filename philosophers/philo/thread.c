/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 22:25:20 by dhyeon            #+#    #+#             */
/*   Updated: 2021/06/15 19:06:25 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	now;
	long			ret;

	gettimeofday(&now, 0);
	ret = (now.tv_sec * 1000) + (now.tv_usec / 1000);
	return (ret);
}

void	eating(t_philo *philo, int first, int second)
{
	philo->take_fork = 1;
	pthread_mutex_lock(&g_mutex[first]);
	if (philo->info->end_flag)
		print_status(philo, TAKE_FORK, FORK_MSG);
	if (philo->info->num_philo == 1)
		return ;
	pthread_mutex_lock(&g_mutex[second]);
	philo->take_fork = 0;
	if (philo->info->end_flag)
		print_status(philo, TAKE_FORK, FORK_MSG);
	print_status(philo, EATING, EAT_MSG);
	philo->eat_count++;
	philo->is_eating = 1;
	if (philo->info->end_flag == 0)
		return ;
	msleep(philo->info->time_to_eat);
	pthread_mutex_unlock(&g_mutex[second]);
	pthread_mutex_unlock(&g_mutex[first]);
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
		while (philo->info->num_philo == 1)
			if (philo->info->end_flag)
				return (0);
		if (philo->info->must_eat && philo->eat_count == philo->info->must_eat)
			return (0);
		if (philo->info->end_flag)
			print_status(philo, SLEEPING, SLEEP_MSG);
		if (philo->info->end_flag)
			msleep(philo->info->time_to_sleep);
		if (philo->info->end_flag)
			print_status(philo, THINGKING, THINK_MSG);
	}
	return (0);
}

void	make_thread(t_info *info)
{
	pthread_t	monitor;
	int			i;

	pthread_create(&monitor, 0, (void*)(void*)check_status, (void *)info);
	if (!(info->p = ft_calloc(info->num_philo, sizeof(pthread_t))))
		return ;
	i = 0;
	while (i < info->num_philo)
	{
		pthread_create(&info->p[i], 0, philo_routine, (void *)info->philo[i]);
		i++;
		usleep(1);
	}
	pthread_join(monitor, 0);
	i = 0;
	while (i < info->num_philo)
	{
		pthread_detach(info->p[i]);
		i++;
	}
}
