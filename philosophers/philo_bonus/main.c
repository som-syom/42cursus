/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 22:37:48 by dhyeon            #+#    #+#             */
/*   Updated: 2021/06/11 19:21:14 by dhyeon           ###   ########.fr       */
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
	struct timeval	start;

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
	sem_unlink("print");
	info->print = sem_open("print", O_CREAT, 0644, 1);
	sem_unlink("print_die");
	info->print_die = sem_open("print_die", O_CREAT, 0644, 1);
	sem_unlink("fork");
	info->forks = sem_open("fork", O_CREAT, 0644, info->num_philo);
	sem_unlink("die");
	info->die = sem_open("die", O_CREAT, 0644, 1);
	sem_wait(info->die);
	sem_unlink("all_eat");
	if (info->must_eat)
	{
		info->eat_flag = sem_open("all_eat", O_CREAT, 0644, info->num_philo);
		i = -1;
		while (++i < info->num_philo)
			sem_wait(info->eat_flag);
	}
	i = 0;
	while (i < info->num_philo)
	{
		info->philo[i]->num = i;
		info->philo[i]->info = info;
		i++;
	}
	gettimeofday(&start, 0);
	info->start_time = (start.tv_sec * 1000) + (start.tv_usec / 1000);
	return (1);
}

void	print_status(t_philo *philo, int flag, char *msg)
{
	struct timeval			now;
	int						timestamp;

	if (philo->info->end_flag == 0)
		return ;
	gettimeofday(&now, 0);
	timestamp = ((now.tv_sec * 1000) + (now.tv_usec / 1000))
				- philo->info->start_time;
	if (flag == EATING)
		philo->time = (now.tv_sec * 1000) + (now.tv_usec / 1000);
	sem_wait(philo->info->print);
	printf("%dms %d %s\n", timestamp, philo->num + 1, msg);
	if (flag != DEAD)
		sem_post(philo->info->print);
}

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
			// sem_post(philo->info->print_die);
			sem_post(philo->info->die);
			philo->info->end_flag = 0;
			// kill(0, 9);
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
	i = -1;
	while (++i < info->num_philo)
		sem_wait(info->eat_flag);
	i = -1;
	while (++i < info->num_philo)
		kill(info->philo[i]->pid, 9);
	exit(0);
	return (0);
}

void	make_process(t_info *info)
{
	int			i;
	pthread_t	all_monitor;
	pthread_t	ate;

	pthread_create(&all_monitor, 0, all_check, (void *)info);
	pthread_create(&ate, 0, check_eat, (void *)info);
	i = 0;
	while (i < info->num_philo)
	{
		info->philo[i]->pid = fork();
		if (info->philo[i]->pid < 0)
			printf("fork error\n");
		else if (info->philo[i]->pid == 0)
		{
			pthread_create(&info->philo[i]->monitor, 0, check_status, (void *)info->philo[i]);
			philo_routine(info->philo[i]);
			pthread_join(info->philo[i]->monitor, 0);
			exit(0);
		}
		i++;
	}
	pthread_join(all_monitor, 0);
	pthread_join(ate, 0);
	i = -1;
	while (++i < info->num_philo)
		waitpid(info->philo[i]->pid, 0, 0);
	sem_unlink("fork");
	sem_close(info->forks);
	// i = -1;
	// while (++i < info->num_philo)
	// 	kill(info->philo[i]->pid, SIGKILL);

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
