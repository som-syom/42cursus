/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 22:37:15 by dhyeon            #+#    #+#             */
/*   Updated: 2021/06/09 22:40:09 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #ifndef PHILO_BONUS_H
 # define PHILO_BONUS_H

typedef struct	s_info
{
	int			num_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			must_eat;
	int			eat_count;
	int			end_flag;
	long		start_time;
}				t_info;

 #endif