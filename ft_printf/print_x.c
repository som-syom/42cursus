/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 19:40:56 by dhyeon            #+#    #+#             */
/*   Updated: 2020/11/06 21:30:43 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

void	print_x_width(t_flags *flag, int *return_val)
{
	char a;

	if (flag->zero == 1 && flag->dot == 0)
		a = '0';
	else
		a = ' ';
	if (flag->zero == 1 && flag->sharp == 1&& flag->dot == 0)
	{
		if (flag->type == 'X')
			ft_putstr_fd("0X", 1);
		else
			ft_putstr_fd("0x", 1);
		(*return_val) += 2;
	}
	while (flag->width > 0)
	{
		ft_putchar_fd(a, 1);
		(*return_val)++;
		flag->width--;
	}
}

void	print_x_num(t_flags *flag, char *str, int *return_val)
{
	if (flag->zero == 0 && flag->sharp == 1&& flag->dot == 0)
	{
		if (flag->type == 'X')
			ft_putstr_fd("0X", 1);
		else
			ft_putstr_fd("0x", 1);
		(*return_val) += 2;
	}
	while (flag->precision > 0)
	{
		ft_putchar_fd('0', 1);
		(*return_val)++;
		flag->precision--;
	}
	ft_putstr_fd(str, 1);
	(*return_val) += ft_strlen(str);
}

void	print_x(t_flags *flag, va_list args, int *return_val)
{
	unsigned int	num;
	char			*str_x;
	int				len;
	char			*temp;

	num = va_arg(args, unsigned int);
	if (flag->dot == 1 && flag->precision == 0 && num == 0)
		str_x = ft_strdup("");
	else if (flag->type == 'X')
		str_x = convert_base(num, HEX_UPPER);
	else
		str_x = convert_base(num, HEX_LOWER);
	temp = str_x;
	len = ft_strlen(str_x);
	reset_flag(flag, len);
	if (flag->minus >= 0)
		print_x_width(flag, return_val);
	print_x_num(flag, str_x, return_val);
	if (flag->minus == -1)
		print_x_width(flag, return_val);
	free (temp);
}
