/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 00:29:17 by dhyeon            #+#    #+#             */
/*   Updated: 2021/06/13 00:41:55 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	eating(t_philo *philo)
{
	struct timeval	time;

	if (sem_wait(philo->info->forks) == -1)
		printf("wait error\n");
	print_status(philo, TAKE_FORK, FORK_MSG);
	if (philo->info->end_flag == 0)
		return ;
	if (sem_wait(philo->info->forks) == -1)
		printf("wait error\n");
	print_status(philo, TAKE_FORK, FORK_MSG);
	philo->is_eating = 1;
	gettimeofday(&time, 0);
	philo->time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	print_status(philo, EATING, EAT_MSG);
	philo->eat_count++;
	if (philo->info->must_eat && philo->eat_count == philo->info->must_eat)
		sem_post(philo->info->eat_flag);
	msleep(philo->info->time_to_eat);
	philo->is_eating = 0;
	sem_post(philo->info->forks);
	sem_post(philo->info->forks);
}

void	philo_routine(t_philo *philo)
{
	while (philo->info->end_flag)
	{
		eating(philo);
		print_status(philo, SLEEPING, SLEEP_MSG);
		msleep(philo->info->time_to_sleep);
		print_status(philo, THINGKING, THINK_MSG);
	}
}

void	make_process(t_info *info)
{
	int			i;
	pthread_t	all_monitor;
	pthread_t	ate;

	pthread_create(&all_monitor, 0, all_check, (void *)info);
	pthread_create(&ate, 0, check_eat, (void *)info);
	i = -1;
	while (++i < info->num_philo)
	{
		info->philo[i]->pid = fork();
		if (info->philo[i]->pid < 0)
			printf("fork error\n");
		else if (info->philo[i]->pid == 0)
			pid_child(info->philo[i]);
	}
	pthread_join(all_monitor, 0);
	pthread_join(ate, 0);
	i = -1;
	while (++i < info->num_philo)
		waitpid(info->philo[i]->pid, 0, 0);
	sem_unlink("fork");
	sem_close(info->forks);
}
