/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 18:01:30 by dhyeon            #+#    #+#             */
/*   Updated: 2021/06/12 23:21:27 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	msleep(int ms)
{
	struct timeval tv1;
	struct timeval tv2;

	gettimeofday(&tv1, NULL);
	long val1 = tv1.tv_sec * 1000 + tv1.tv_usec / 1000;
	while (1)
	{
		gettimeofday(&tv2, NULL);
		long val2 = tv2.tv_sec * 1000 + tv2.tv_usec / 1000;
		if (val2 - val1 >= ms)
			return;
		usleep(1);
	}
}

void	*ft_calloc(size_t n, size_t size)
{
	void	*ret;

	ret = (char *)malloc(size * n);
	if (!ret)
		return (0);
	memset(ret, 0, (n * size));
	return (ret);
}

int	ft_isdigit_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!('0' <= str[i] && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	print_i(const char *str, int min, long long res, int i)
{
	long long	tmp;

	tmp = 0;
	while (str[i] != 0 && ('0' <= str[i] && str[i] <= '9'))
	{
		if (min > 0 && tmp < 0)
			return (-1);
		if (min < 0 && tmp < 0)
			return (0);
		tmp = (tmp * 10) + (str[i] - 48);
		i++;
		if (str[i] == 0 || !('0' <= str[i] && str[i] <= '9'))
			return (tmp * min);
	}
	if (min == -1)
		res = tmp * -1;
	return (res);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				min;
	long long int	res;

	i = 0;
	min = 1;
	res = 0;
	while (str[i] != 0 && (str[i] == ' ' || (9 <= str[i] && str[i] <= 13)))
		i++;
	if (str[i] == '-')
		min = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	res = print_i(str, min, res, i);
	return (res);
}