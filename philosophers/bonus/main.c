/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 22:37:48 by dhyeon            #+#    #+#             */
/*   Updated: 2021/06/10 02:13:24 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void test_arg(t_info *info)
{
	printf("info num : %d\n", info->num_philo);
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
	info->forks = sem_open("fork", O_CREAT, 0644, info->num_philo);
	i = 0;
	while (i < info->num_philo)
	{
		info->philo[i]->num = i;
		info->philo[i]->info = info;
		i++;
	}
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
	printf("%dms %d %s\n", timestamp, philo->num + 1, msg);
}

void	philo_routine(t_philo *philo)
{
	while (philo->info->end_flag)
	{
		printf("philo num : %d\n", philo->num);
		sem_wait(philo->info->forks);
			printf("fail\n");
		print_status(philo, TAKE_FORK, FORK_MSG);
		sem_wait(philo->info->forks);
		print_status(philo, TAKE_FORK, FORK_MSG);
		philo->is_eating = 1;
		print_status(philo, EATING, EAT_MSG);
		philo->info->eat_count++;
		msleep(philo->info->time_to_eat);
		philo->is_eating = 0;
		sem_post(philo->info->forks);
		sem_post(philo->info->forks);
		print_status(philo, SLEEPING, SLEEP_MSG);
		msleep(philo->info->time_to_sleep);
		print_status(philo, THINGKING, THINK_MSG);
	}
}

void	make_process(t_info *info)
{
	int		i;
	pid_t	pid[200];

	i = 0;
	while (i < info->num_philo)
	{
		pid[i] = fork();
		if (pid[i] < 0)
			printf("fork error\n");
		if (pid[i] == 0)
		{
			printf("status : %d flag : %d\n", i, info->end_flag);
			philo_routine(info->philo[i]);
			exit(0);
		}
		i++;
	}
	printf("qqq\n");

}

int	main(int argc, char **argv)
{
	t_info	info;

	if (!check_arg(&info, argc, argv))
		return (0);
	if (!init_info(&info))
		return (0);
	make_process(&info);
	return (0);
}
