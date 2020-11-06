/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 20:26:30 by dhyeon            #+#    #+#             */
/*   Updated: 2020/11/06 21:30:29 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

void	print_u_width(t_flags *flag, int *return_val)
{
	char a;

	if (flag->zero == 1 && flag->dot == 0)
		a = '0';
	else
		a = ' ';
	if (flag->sign != 0)
		flag->width--;
	while (flag->width > 0)
	{
		ft_putchar_fd(a, 1);
		(*return_val)++;
		flag->width--;
	}
}

void	print_u_num(t_flags *flag, char *str, int *return_val)
{
	while (flag->precision > 0)
	{
		ft_putchar_fd('0', 1);
		(*return_val)++;
		flag->precision--;
	}
	ft_putstr_fd(str, 1);
	(*return_val) += ft_strlen(str);
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
	reset_flag(flag, len);
	if (flag->minus >= 0)
		print_u_width(flag, return_val);
	print_u_num(flag, str_u, return_val);
	if (flag->minus == -1)
		print_u_width(flag, return_val);
	free(temp);
}
