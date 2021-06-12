/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 22:00:23 by dhyeon            #+#    #+#             */
/*   Updated: 2021/06/12 22:29:02 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int print_error(char *str)
{
	printf("Error : %s\n", str);
	return (0);
}

int	check_arg(t_info *info, int ac, char **av)
{
	int	i;

	if (ac != 5 && ac != 6)
		return (print_error("invalid arg num"));
	i = 1;
	while (i < ac)
	{
		if (!ft_isdigit_str(av[i]))
			return (print_error("put only numberic arg"));
		i++;
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

int		check_time(t_info *info, int i, long time)
{
	if ((info->philo[i]->time != 0 &&
			time - info->philo[i]->time > info->time_to_die)
		|| (info->philo[i]->time == 0 &&
			time - info->start_time > info->time_to_die))
		return (1);
	return (0);
}

int		check_must_eat(t_info *info)
{
	int	i;

	if (info->must_eat == 0)
		return (0);
	else
	{
		i = -1;
		while (++i < info->num_philo)
		{
			if (info->must_eat > info->philo[i]->eat_count)
				return (0);
		}
		info->end_flag = 0;
		return (1);
	}
}

void	*check_status(t_info *info)
{
	struct timeval	now;
	long			time;
	int				i;

	while (info->end_flag)
	{
		gettimeofday(&now, 0);
		time = ((now.tv_sec * 1000) + (now.tv_usec / 1000));
		i = -1;
		while (++i < info->num_philo)
		{
			if (check_must_eat(info))
				return (0);
			if (info->philo[i]->is_eating == 0 && check_time(info, i, time))
			{
				print_status(info->philo[i], DEAD, DIE_MSG);
				info->end_flag = 0;
				return (0);
			}
		}
	}
	return (0);
}
