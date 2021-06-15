/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 17:52:31 by dhyeon            #+#    #+#             */
/*   Updated: 2021/06/15 18:59:39 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_philo(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_philo)
	{
		pthread_mutex_init(&g_mutex[i], 0);
		info->philo[i]->num = i;
		info->philo[i]->left = i;
		info->philo[i]->right = i + 1;
		info->philo[i]->info = info;
		i++;
	}
	info->philo[info->num_philo - 1]->right = 0;
}

int		init_info(t_info *info)
{
	int				i;

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
	set_philo(info);
	pthread_mutex_init(&info->print, 0);
	info->start_time = get_time();
	return (1);
}

void	print_status(t_philo *philo, int flag, char *msg)
{
	long	timestamp;
	long	now;

	if (!philo || !philo->info || philo->info->end_flag == 0)
		return ;
	philo->printing = 1;
	pthread_mutex_lock(&philo->info->print);
	now = get_time();
	timestamp = now - philo->info->start_time;
	if (flag == EATING)
		philo->time = get_time();
	if (philo->info->end_flag && philo->info->start_time)
		printf("%ldms %d %s\n", timestamp, philo->num + 1, msg);
	if (flag != DEAD)
		pthread_mutex_unlock(&philo->info->print);
	philo->printing = 0;
}

void	free_all(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->num_philo)
		free(info->philo[i]);
	free(info->philo);
}

int		main(int argc, char **argv)
{
	t_info	info;

	if (!check_arg(&info, argc, argv))
		return (0);
	if (!init_info(&info))
		return (0);
	make_thread(&info);
	free_all(&info);
	return (0);
}
