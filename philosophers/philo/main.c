/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 17:52:31 by dhyeon            #+#    #+#             */
/*   Updated: 2021/06/10 22:32:03 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_arg(t_info *info, int ac, char **av)
{
	int	i;

	if (ac != 5 && ac != 6)
		return (0);
	i = 1;
	while (i < ac)
	{
		if (!ft_isdigit_str(av[i]))
			return (0);
		i++;
	}
	memset(info, 0, sizeof(t_info));
	info->num_philo = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		info->must_eat = ft_atoi(av[5]);
	if (info->num_philo < 2 || info->time_to_die < 0 || info->time_to_eat < 0
		|| info->time_to_sleep < 0 || info->must_eat < 0)
		return (0);
	return (1);
}

int	init_info(t_info *info)
{
	int	i;

	info->end_flag = 1;
	if (!(info->philo = ft_calloc(info->num_philo, sizeof(t_philo *))))
		return (0);
	i = 0;
	while (i < info->num_philo)
	{
		if (!(info->philo[i] = ft_calloc(1, sizeof(t_philo))))
			return (0);
		i++;
	}
	i = 0;
	while (i < info->num_philo)
	{
		pthread_mutex_init(&mutex[i], 0);
		info->philo[i]->num = i;
		info->philo[i]->left = i;
		info->philo[i]->right = i + 1;
		info->philo[i]->info = info;
		i++;
	}
	info->philo[info->num_philo - 1]->right = 0;
	return (1);
}

void	print_status(t_philo *philo, int flag, char *msg)
{
	static struct timeval	start;
	struct timeval			now;
	int						timestamp;

	if (philo->info->end_flag == 0)
		return ;
	if (start.tv_sec == 0)
	{
		gettimeofday(&start, 0);
		philo->info->start_time = (start.tv_sec * 1000) + (start.tv_usec / 1000);
	}
	gettimeofday(&now, 0);
	timestamp = ((now.tv_sec * 1000) + (now.tv_usec / 1000))
				- ((start.tv_sec * 1000) + (start.tv_usec / 1000));
	if (flag == EATING)
		philo->time = (now.tv_sec * 1000) + (now.tv_usec / 1000);
	if (philo->info->end_flag)
		printf("%dms %d %s\n", timestamp, philo->num + 1, msg);
}

void	make_thread(t_info *info)
{
	pthread_t	*p;
	pthread_t	monitor;
	int			i;

	if (!(p = ft_calloc(info->num_philo, sizeof(pthread_t))))
		return ;
	i = 0;
	while (i < info->num_philo)
	{
		pthread_create(&p[i], 0, philo_routine, (void *)info->philo[i]);
		i++;
	}
	pthread_create(&monitor, 0, (void*)(void*)check_status, (void *)info);
	pthread_join(monitor, 0);
	i = 0;
	while (i < info->num_philo)
	{
		pthread_join(p[i], 0);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (!check_arg(&info, argc, argv))
		return (0);
	if (!init_info(&info))
		return (0);
	make_thread(&info);
	return (0);
}
