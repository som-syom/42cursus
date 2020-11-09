/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 20:47:24 by dhyeon            #+#    #+#             */
/*   Updated: 2020/11/09 22:06:42 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

void	check_p_sign_flag(t_flags *flag, int *len, char **str_d)
{
	if (flag->precision > (*len))
		flag->precision -= (*len);
	else
		flag->precision = 0;
	(*len) += 2;
	if (flag->width > (*len))
		flag->width = flag->width - (flag->precision + (*len));
	else
		flag->width = 0;
	(*len) = flag->width + flag->precision + ft_strlen(*str_d);
	if (flag->sign != 0)
		(*len)++;
	(*len) += 2;
}

void	print_p_right(t_flags *flag, char *str, int len, int *return_val)
{
	while (flag->width-- > 0)
		ft_putchar_fd(' ', 1);
	ft_putstr_fd(HEX_LOW_SHARP, 1);
	while (flag->precision-- > 0)
		ft_putchar_fd('0', 1);
	ft_putstr_fd(str, 1);
	(*return_val) += len;
}

void	print_p_zero_right(t_flags *flag, char *str, int len, int *return_val)
{
	if (flag->dot == 1)
	{
		while (flag->width-- > 0)
			ft_putchar_fd(' ', 1);
		ft_putstr_fd(HEX_LOW_SHARP, 1);
	}
	else
	{
		ft_putstr_fd(HEX_LOW_SHARP, 1);
		while (flag->width-- > 0)
			ft_putchar_fd('0', 1);
	}
	ft_putstr_fd(str, 1);
	(*return_val) += len;
}

void	print_p_left(t_flags *flag, char *str, int len, int *return_val)
{
	ft_putstr_fd(HEX_LOW_SHARP, 1);
	while (flag->precision-- > 0)
		ft_putchar_fd('0', 1);
	ft_putstr_fd(str, 1);
	while (flag->width-- > 0)
		ft_putchar_fd(' ', 1);
	(*return_val) += len;
}

void	print_p(t_flags *flag, va_list args, int *return_val)
{
	long long int	num;
	char			*str_p;
	char			*temp;
	int				len;

	num = va_arg(args, long long int);
	if (num == 0 && flag->dot == 1 && flag->precision == 0)
		str_p = ft_strdup("");
	else
		str_p = convert_base(num, HEX_LOWER);
	temp = str_p;
	len = ft_strlen(str_p);
	check_p_sign_flag(flag, &len, &str_p);
	if (flag->minus == -1)
		print_p_left(flag, str_p, len, return_val);
	else if (flag->zero == 1 && flag->precision == 0)
		print_p_zero_right(flag, str_p, len, return_val);
	else
		print_p_right(flag, str_p, len, return_val);
	free(temp);
}
