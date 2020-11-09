/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 22:16:23 by dhyeon            #+#    #+#             */
/*   Updated: 2020/11/09 22:16:25 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

void	print_pct_width(t_flags *flag, int *return_val)
{
	char a;

	if (flag->zero == 1 && flag->minus == 0)
		a = '0';
	else
		a = ' ';
	flag->width--;
	while (flag->width > 0)
	{
		ft_putchar_fd(a, 1);
		(*return_val)++;
		flag->width--;
	}
}

void	print_pct(t_flags *flag, int *return_val)
{
	if (flag->minus == 0)
		print_pct_width(flag, return_val);
	ft_putchar_fd('%', 1);
	(*return_val)++;
	if (flag->minus == -1)
		print_pct_width(flag, return_val);
}
