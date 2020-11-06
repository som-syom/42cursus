/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 09:53:35 by dhyeon            #+#    #+#             */
/*   Updated: 2020/11/06 20:01:20 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_to_num(char *res, long long int n, int i)
{
	long long	nbr;
	int			j;

	nbr = n;
	j = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		res[j++] = '-';
	}
	while (i >= j)
	{
		res[i] = (nbr % 10) + 48;
		nbr /= 10;
		i--;
	}
	return (res);
}

char	*ft_itoa(long long int n)
{
	char		*res;
	int			i;
	long long	tmp;

	i = 0;
	tmp = n;
	if (n < 0)
	{
		i++;
		tmp *= -1;
	}
	while (tmp > 0)
	{
		tmp /= 10;
		i++;
	}
	if (n == 0)
		i = 1;
	if (!(res = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	res = ft_to_num(res, n, (i - 1));
	res[i] = '\0';
	return (res);
}
