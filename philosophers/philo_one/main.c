/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 17:52:31 by dhyeon            #+#    #+#             */
/*   Updated: 2021/06/07 21:39:33 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	test_arg(t_info *info)
{
	printf("phlio_num : %d\n", info->num_philo);
	printf("time_to_die : %d\n", info->time_to_die);
	printf("time_to_eat : %d\n", info->time_to_eat);
	printf("time_to_sleep : %d\n", info->time_to_sleep);
	printf("must_eat : %d\n", info->must_eat);
}

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
	test_arg(info);
	return (1);
}

void	msleep(int ms)
{
	struct timeval tv1;
	struct timeval tv2;

	gettimeofday(&tv1, NULL);
	long val1 = tv1.tv_sec * 1000 + tv1.tv_usec/1000;
	// printf("%ld %ld\n", tv1.tv_sec, tv1.tv_usec/1000);
	while (1)
	{
		gettimeofday(&tv2, NULL);
		long val2 = tv2.tv_sec * 1000 + tv2.tv_usec/1000;
		if (val2 - val1 >= ms)
			return;
	}
}

int	init_info(t_info *info)
{
	int	i;

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

void	print_status(t_philo *philo, int flag)
{
	static struct timeval	start;
	struct timeval			now;
	int						timestamp;

	if (start.tv_sec == 0)
		gettimeofday(&start, 0);
	gettimeofday(&now, 0);
	timestamp = ((now.tv_sec * 1000) + (now.tv_usec / 1000))
				- ((start.tv_sec * 1000) + (start.tv_usec / 1000));
	if (flag == TAKE_FORK)
		printf("%dms %d has taken a fork\n", timestamp, philo->num);
	else if (flag == EATING)
	{
		philo->eat = timestamp;
		printf("%dms %d is eating\n", timestamp, philo->num);
	}
	else if (flag == SLEEPING)
		printf("%dms %d is sleeping\n", timestamp, philo->num);
	else
		printf("%dms %d is thinking\n", timestamp, philo->num);
}

void	eating(t_philo *philo)
{
	struct timeval	time;

	pthread_mutex_lock(&mutex[philo->left]);
	print_status(philo, TAKE_FORK);
	pthread_mutex_lock(&mutex[philo->right]);
	print_status(philo, TAKE_FORK);
	print_status(philo, EATING);
	msleep(philo->info->time_to_eat);
	philo->info->eat_count++;
	pthread_mutex_unlock(&mutex[philo->left]);
	pthread_mutex_unlock(&mutex[philo->right]);
}

void	*philo_routine(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	while (1)
	{
		//eat
		eating(philo);
		
		//sleep
		print_status(philo->num, SLEEPING);
		msleep(philo->info->time_to_sleep);
		//think
		print_status(philo->num, THINGKING);
	}
}

void	test_philo(t_philo *philo)
{
	printf("philo num : %d\n", philo->num);
	printf("philo left : %d right : %d\n", philo->left, philo->right);
}

void	make_thread(t_info *info)
{
	pthread_t	*p;
	int			i;

	if (!(p = ft_calloc(info->num_philo, sizeof(pthread_t))))
		return ;
	i = 0;
	while (i < info->num_philo)
	{
		// test_philo(info->philo[i]);
		pthread_create(&p[i], 0, philo_routine, (void *)info->philo[i]);
		i++;
	}
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
