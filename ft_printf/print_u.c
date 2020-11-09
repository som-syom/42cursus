/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 20:26:30 by dhyeon            #+#    #+#             */
/*   Updated: 2020/11/09 22:07:20 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

void	check_u_sign_flag(t_flags *flag, int *len, char **str_d)
{
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

void	print_u_right(t_flags *flag, char *str, int len, int *return_val)
{
	while (flag->width-- > 0)
		ft_putchar_fd(' ', 1);
	while (flag->precision-- > 0)
		ft_putchar_fd('0', 1);
	ft_putstr_fd(str, 1);
	(*return_val) += len;
}

void	print_u_zero_right(t_flags *flag, char *str, int len, int *return_val)
{
	if (flag->dot == 1)
	{
		while (flag->width-- > 0)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (flag->width-- > 0)
			ft_putchar_fd('0', 1);
	}
	ft_putstr_fd(str, 1);
	(*return_val) += len;
}

void	print_u_left(t_flags *flag, char *str, int len, int *return_val)
{
	while (flag->precision-- > 0)
		ft_putchar_fd('0', 1);
	ft_putstr_fd(str, 1);
	while (flag->width-- > 0)
		ft_putchar_fd(' ', 1);
	(*return_val) += len;
}

void	print_u(t_flags *flag, va_list args, int *return_val)
{
	unsigned int	u;
	int				len;
	char			*str_u;
	char			*temp;

	u = va_arg(args, unsigned int);
	if (flag->dot == 1 && flag->precision == 0 && u == 0)
		str_u = ft_strdup("");
	else
		str_u = ft_itoa(u);
	temp = str_u;
	len = ft_strlen(str_u);
	check_u_sign_flag(flag, &len, &str_u);
	if (flag->minus == -1)
		print_u_left(flag, str_u, len, return_val);
	else if (flag->zero == 1 && flag->precision == 0)
		print_u_zero_right(flag, str_u, len, return_val);
	else
		print_u_right(flag, str_u, len, return_val);
	free(temp);
}
