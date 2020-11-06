/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 20:14:13 by dhyeon            #+#    #+#             */
/*   Updated: 2020/11/06 21:29:57 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

void	print_space(t_flags *flag, int len, int *return_val)
{
	int		i;

	i = 0;
	if (flag->precision > 0 && len > flag->precision)
		i += flag->precision;
	flag->width -= len;
	while (i < flag->width)
	{
		ft_putchar_fd(' ', 1);
		i++;
		(*return_val)++;
	}
}

void	print_c(t_flags *flag, va_list args, int *return_val)
{
	if (flag->minus == 0)
		print_space(flag, 1, return_val);
	ft_putchar_fd(va_arg(args, int), 1);
	if (flag->minus == -1)
		print_space(flag, 1, return_val);
	(*return_val)++;
}

void	print_s_str(int len, char *str, int *return_val)
{
	while (len > 0)
	{
		ft_putchar_fd((*str), 1);
		str++;
		(*return_val)++;
		len--;
	}
}

void	print_s(t_flags *flag, va_list args, int *return_val)
{
	char	*str;
	int		len;

	str = va_arg(args, char*);
	if (str == NULL)
		str = "(null)";
	if (flag->dot == 1 && flag->precision == 0)
		str = "";
	len = ft_strlen(str);
	if (flag->precision > len)
		flag->precision = len;
	if (flag->precision != 0 && flag->precision < len)
		len = flag->precision;
	if (flag->minus == 0 && flag->width != 0)
		print_space(flag, len, return_val);
	print_s_str(len, str, return_val);
	if (flag->minus == -1 && flag->width != 0)
		print_space(flag, len, return_val);
}