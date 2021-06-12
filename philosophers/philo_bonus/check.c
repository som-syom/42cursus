/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 00:27:45 by dhyeon            #+#    #+#             */
/*   Updated: 2021/06/13 00:51:41 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int		check_arg(t_info *info, int ac, char **av)
{
	int	i;

	if (ac != 5 && ac != 6)
		return (print_error("invalid arg num"));
	i = 0;
	while (++i < ac)
	{
		if (!ft_isdigit_str(av[i]))
			return (print_error("put only numberic arg"));
	}
	memset(info, 0, sizeof(t_info));
	info->num_philo = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		info->must_eat = ft_atoi(av[5]);
	if (info->num_philo < 1 || info->time_to_die < 0 || info->time_to_eat < 0
		|| info->time_to_sleep < 0 || info->must_eat < 0)
		return (print_error("put positive number"));
	return (1);
}

void	*check_status(void *p)
{
	struct timeval	now;
	t_philo			*philo;
	int				time;

	philo = (t_philo *)p;
	while (philo->info->end_flag)
	{
		gettimeofday(&now, 0);
		time = (now.tv_sec * 1000) + (now.tv_usec / 1000);
		if (!philo->is_eating &&
			((philo->time && time - philo->time > philo->info->time_to_die) ||
			(philo->time == 0 &&
				time - philo->info->start_time > philo->info->time_to_die)))
		{
			sem_wait(philo->info->print_die);
			print_status(philo, DEAD, DIE_MSG);
			sem_post(philo->info->die);
			philo->info->end_flag = 0;
			break ;
		}
	}
	return (0);
}

void	*all_check(void *in)
{
	t_info	*info;
	int		i;

	info = (t_info *)in;
	sem_wait(info->die);
	i = -1;
	while (++i < info->num_philo)
		kill(info->philo[i]->pid, 9);
	exit(0);
	return (0);
}

void	*check_eat(void *in)
{
	t_info	*info;
	int		i;

	info = (t_info *)in;
	if (info->must_eat)
	{
		sem_unlink("all_eat");
		info->eat_flag = sem_open("all_eat", O_CREAT, 0644, info->num_philo);
		i = -1;
		while (++i < info->num_philo * 2 - 1)
			sem_wait(info->eat_flag);
		sem_wait(info->print);
		i = -1;
		while (++i < info->num_philo)
			kill(info->philo[i]->pid, 9);
		exit(0);
	}
	return (0);
}

void	pid_child(t_philo *philo)
{
	pthread_create(&philo->monitor, 0, check_status, (void *)philo);
	philo_routine(philo);
	pthread_join(philo->monitor, 0);
	exit(0);
}
