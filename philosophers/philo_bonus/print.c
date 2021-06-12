/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 00:30:28 by dhyeon            #+#    #+#             */
/*   Updated: 2021/06/13 00:52:22 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

int		print_error(char *str)
{
	printf("Error : %s\n", str);
	exit(0);
}
