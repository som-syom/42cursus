/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 20:15:48 by dhyeon            #+#    #+#             */
/*   Updated: 2020/11/06 22:46:42 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

void	check_sign(t_flags *flag, int d, int *len, char **str_d)
{
	if (flag->plus == 1 && d > 0)
	{
		flag->sign = '+';
	}
	else if (flag->space == 1 && d > 0)
		flag->sign = ' ';
	else if (d < 0)
	{
		flag->sign = '-';
		(*str_d)++;
		(*len)--;
	}
}

void	reset_flag(t_flags *flag, int len)
{
	if (len < flag->precision && flag->precision < flag->width)
	{
		flag->width -= flag->precision;
		flag->precision -= len;
	}
	else if (len < flag->precision && flag->precision >= flag->width)
	{
		flag->width = 0;
		flag->precision -= len;
	}
	else if (len < flag->width && flag->width >= flag->precision)
	{
		flag->width -= len;
		flag->precision = 0;
	}
	else
	{
		flag->width = 0;
		flag->precision = 0;
	}
	// if (flag->sign != 0 && flag->minus == -1)
	// 	flag->minus = 0;
}

void	print_d_width(t_flags *flag, int *return_val)
{
	char a;

	if (flag->zero == 1 && flag->dot == 0 && flag->minus != -1)
		a = '0';
	else
		a = ' ';
	if (((flag->zero == 1 && flag->dot == 0) || (flag->zero != 1
		&& flag->minus != -1)) && flag->sign != 0)
	{
		ft_putchar_fd(flag->sign, 1);
		flag->sign = '\0';
		(*return_val)++;
	}
	if (flag->sign != 0)
		flag->width--;
	while (flag->width > 0)
	{
		ft_putchar_fd(a, 1);
		(*return_val)++;
		flag->width--;
	}
}

void	print_d_num(t_flags *flag, char *str, int *return_val)
{
	if (((flag->zero == 0 || flag->dot == 1)
		|| (flag->zero == 1 && flag->minus == -1)) && flag->sign != 0)
	{
		ft_putchar_fd(flag->sign, 1);
		flag->sign = '\0';
		(*return_val)++;
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
	check_sign(flag, d, &len, &str_d);
	reset_flag(flag, len);
	if (flag->minus >= 0)
		print_d_width(flag, return_val);
	print_d_num(flag, str_d, return_val);
	if (flag->minus == -1)
		print_d_width(flag, return_val);
	free(temp);
}