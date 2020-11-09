/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 19:40:56 by dhyeon            #+#    #+#             */
/*   Updated: 2020/11/09 22:16:58 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

void	check_x_sign_flag(t_flags *flag, int num, int *len, char **str_d)
{
	if (num == 0)
		flag->sharp = 0;
	if (flag->precision > (*len))
		flag->precision -= (*len);
	else
		flag->precision = 0;
	if (flag->sharp != 0)
		(*len) += 2;
	if (flag->width > (*len) + flag->precision)
		flag->width = flag->width - (flag->precision + (*len));
	else
		flag->width = 0;
	(*len) = flag->width + flag->precision + ft_strlen(*str_d);
}

void	print_x_right(t_flags *flag, char *str, int len, int *return_val)
{
	char *a;

	a = (flag->type == 'X' ? HEX_UP_SHARP : HEX_LOW_SHARP);
	while (flag->width-- > 0)
		ft_putchar_fd(' ', 1);
	if (flag->sharp == 1)
	{
		ft_putstr_fd(a, 1);
		(*return_val) += 2;
	}
	while (flag->precision-- > 0)
		ft_putchar_fd('0', 1);
	ft_putstr_fd(str, 1);
	(*return_val) += len;
}

void	print_x_zero_right(t_flags *flag, char *str, int len, int *return_val)
{
	char *a;

	a = (flag->type == 'X' ? HEX_UP_SHARP : HEX_LOW_SHARP);
	if (flag->dot == 1)
	{
		while (flag->width-- > 0)
			ft_putchar_fd(' ', 1);
		if (flag->sharp == 1)
		{
			ft_putstr_fd(a, 1);
			(*return_val) += 2;
		}
	}
	else
	{
		if (flag->sharp == 1)
		{
			ft_putstr_fd(a, 1);
			(*return_val) += 2;
		}
		while (flag->width-- > 0)
			ft_putchar_fd('0', 1);
	}
	ft_putstr_fd(str, 1);
	(*return_val) += len;
}

void	print_x_left(t_flags *flag, char *str, int len, int *return_val)
{
	char *a;

	a = (flag->type == 'X' ? HEX_UP_SHARP : HEX_LOW_SHARP);
	if (flag->sharp == 1)
	{
		ft_putstr_fd(a, 1);
		(*return_val) += 2;
	}
	while (flag->precision-- > 0)
		ft_putchar_fd('0', 1);
	ft_putstr_fd(str, 1);
	while (flag->width-- > 0)
		ft_putchar_fd(' ', 1);
	(*return_val) += len;
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
	check_x_sign_flag(flag, num, &len, &str_x);
	if (flag->minus == -1)
		print_x_left(flag, str_x, len, return_val);
	else if (flag->zero == 1 && flag->precision == 0)
		print_x_zero_right(flag, str_x, len, return_val);
	else
		print_x_right(flag, str_x, len, return_val);
	free(temp);
}
