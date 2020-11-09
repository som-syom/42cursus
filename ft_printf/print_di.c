/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 20:15:48 by dhyeon            #+#    #+#             */
/*   Updated: 2020/11/09 22:15:47 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

void	check_sign_flag(t_flags *flag, int d, int *len, char **str_d)
{
	if (flag->plus == 1 && d >= 0)
		flag->sign = '+';
	else if (flag->space == 1 && d >= 0)
		flag->sign = ' ';
	else if (d < 0)
	{
		flag->sign = '-';
		(*str_d)++;
		(*len)--;
	}
	if (flag->precision > (*len))
		flag->precision -= (*len);
	else
		flag->precision = 0;
	if (flag->sign != 0)
		(*len)++;
	if (flag->width > (*len) + flag->precision)
		flag->width = flag->width - (flag->precision + (*len));
	else
		flag->width = 0;
	(*len) = flag->width + flag->precision + ft_strlen(*str_d);
	if (flag->sign != 0)
		(*len)++;
}

void	print_d_right(t_flags *flag, char *str, int len, int *return_val)
{
	while (flag->width-- > 0)
		ft_putchar_fd(' ', 1);
	if (flag->sign != 0)
		ft_putchar_fd(flag->sign, 1);
	while (flag->precision-- > 0)
		ft_putchar_fd('0', 1);
	ft_putstr_fd(str, 1);
	(*return_val) += len;
}

void	print_d_zero_right(t_flags *flag, char *str, int len, int *return_val)
{
	if (flag->dot == 1)
	{
		while (flag->width-- > 0)
			ft_putchar_fd(' ', 1);
		if (flag->sign != 0)
			ft_putchar_fd(flag->sign, 1);
	}
	else
	{
		if (flag->sign != 0)
			ft_putchar_fd(flag->sign, 1);
		while (flag->width-- > 0)
			ft_putchar_fd('0', 1);
	}
	ft_putstr_fd(str, 1);
	(*return_val) += len;
}

void	print_d_left(t_flags *flag, char *str, int len, int *return_val)
{
	if (flag->sign != 0)
		ft_putchar_fd(flag->sign, 1);
	while (flag->precision-- > 0)
		ft_putchar_fd('0', 1);
	ft_putstr_fd(str, 1);
	while (flag->width-- > 0)
		ft_putchar_fd(' ', 1);
	(*return_val) += len;
}

void	print_d(t_flags *flag, va_list args, int *return_val)
{
	int		d;
	int		len;
	char	*str_d;
	char	*temp;

	d = va_arg(args, int);
	if (flag->dot == 1 && flag->precision == 0 && d == 0)
		str_d = ft_strdup("");
	else
		str_d = ft_itoa(d);
	temp = str_d;
	len = ft_strlen(str_d);
	check_sign_flag(flag, d, &len, &str_d);
	if (flag->minus == -1)
		print_d_left(flag, str_d, len, return_val);
	else if (flag->zero == 1 && flag->precision == 0)
		print_d_zero_right(flag, str_d, len, return_val);
	else
		print_d_right(flag, str_d, len, return_val);
	free(temp);
}
