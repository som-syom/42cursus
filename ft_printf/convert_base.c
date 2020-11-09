/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 21:01:10 by dhyeon            #+#    #+#             */
/*   Updated: 2020/11/09 22:18:19 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

int		get_digit(int base_num, long long int num)
{
	long long int i;

	i = 0;
	while (num != 0)
	{
		num /= base_num;
		i++;
	}
	return (i);
}

char	*change_itoa_base(long long int num, char *base, int digit,
							int base_num)
{
	char	*ret;
	int		i;

	i = digit;
	if (!(ret = (char *)malloc(sizeof(char) * (digit + 1))))
		return (0);
	while (i > 0)
	{
		ret[i - 1] = base[num % base_num];
		num = num / base_num;
		i--;
	}
	ret[digit] = '\0';
	return (ret);
}

char	*convert_base(long long int num, char *base)
{
	int		base_num;
	int		digit;
	char	*ret;

	if (num == 0)
	{
		if (!(ret = (char *)malloc(sizeof(char) * 2)))
			return (0);
		ret[0] = '0';
		ret[1] = '\0';
		return (ret);
	}
	base_num = ft_strlen(base);
	digit = get_digit(base_num, num);
	ret = change_itoa_base(num, base, digit, base_num);
	return (ret);
}
