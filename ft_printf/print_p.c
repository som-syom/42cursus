/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 20:47:24 by dhyeon            #+#    #+#             */
/*   Updated: 2020/11/06 21:28:19 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

void	print_p_width(t_flags *flag, int *return_val)
{
	flag->width -= 2;
	while (flag->width > 0)
	{
		ft_putchar_fd(' ', 1);
		(*return_val)++;
		flag->width--;
	}
}

void	print_p_num(char *str, int *return_val)
{
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(str, 1);
	(*return_val) += ft_strlen(str) + 2;
}

void    reset_p_flag(t_flags *flag, int len)
{
    if (flag->width > len)
        flag->width -= len;
    else
        flag->width = 0;
    flag->dot = 0;
    flag->precision = 0;
}

void	print_p(t_flags *flag, va_list args, int *return_val)
{
	long long int	num;
	char			*str_p;
	char			*temp;

	num = va_arg(args, long long int);
	str_p = convert_base(num, HEX_LOWER);
	temp = str_p;
	reset_p_flag(flag, ft_strlen(str_p));
	if (flag->minus == 0)
		print_p_width(flag, return_val);
	print_p_num(str_p, return_val);
	if (flag->minus == -1)
		print_p_width(flag, return_val);
	free(str_p);
}
