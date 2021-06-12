/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 22:37:48 by dhyeon            #+#    #+#             */
/*   Updated: 2021/06/13 00:32:30 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	set_semaphore(t_info *info)
{
	sem_unlink("print");
	info->print = sem_open("print", O_CREAT, 0644, 1);
	sem_unlink("print_die");
	info->print_die = sem_open("print_die", O_CREAT, 0644, 1);
	sem_unlink("fork");
	info->forks = sem_open("fork", O_CREAT, 0644, info->num_philo);
	sem_unlink("die");
	info->die = sem_open("die", O_CREAT, 0644, 1);
	sem_wait(info->die);
}

int		init_info(t_info *info)
{
	int	i;
	struct timeval	start;

	info->end_flag = 1;
	if (!(info->philo = ft_calloc(info->num_philo, sizeof(t_philo *))))
		return (0);
	i = -1;
	while (++i < info->num_philo)
	{
		if (!(info->philo[i] = ft_calloc(1, sizeof(t_philo))))
			return (0);
	}
	set_semaphore(info);
	i = -1;
	while (++i < info->num_philo)
	{
		info->philo[i]->num = i;
		info->philo[i]->info = info;
	}
	gettimeofday(&start, 0);
	info->start_time = (start.tv_sec * 1000) + (start.tv_usec / 1000);
	return (1);
}


void	all_free(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->num_philo)
		free(info->philo[i]);
	free(info->philo);
	sem_close(info->print);
	sem_unlink("print");
	sem_close(info->print_die);
	sem_unlink("print_die");
	sem_close(info->die);
	sem_unlink("die");
	sem_close(info->eat_flag);
	sem_unlink("all_eat");
}

int		main(int argc, char **argv)
{
	t_info	info;

	if (!check_arg(&info, argc, argv))
		return (0);
	if (!init_info(&info))
		return (0);
	make_process(&info);
	all_free(&info);
	return (0);
}
