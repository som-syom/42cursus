/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 17:52:31 by dhyeon            #+#    #+#             */
/*   Updated: 2021/06/12 22:58:31 by dhyeon           ###   ########.fr       */
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
	struct timeval	start;
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
	pthread_mutex_lock(&philo->info->print);
	if (philo->info->end_flag)
		printf("%dms %d %s\n", timestamp, philo->num + 1, msg);
	pthread_mutex_unlock(&philo->info->print);
}

void	free_all(t_info *info)
{
	int	i;

	i = -1;
	while (i < info->num_philo)
		free(info->philo[i]);
	free(info->philo);
	free(info->p);
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
