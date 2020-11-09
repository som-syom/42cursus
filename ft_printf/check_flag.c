/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 20:59:21 by dhyeon            #+#    #+#             */
/*   Updated: 2020/11/09 22:18:07 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

int		check_flag(char fmt_ptr, t_flags *flag)
{
	if (fmt_ptr == '+')
		flag->plus = 1;
	else if (fmt_ptr == '-')
		flag->minus = -1;
	else if (fmt_ptr == ' ')
		flag->space = 1;
	else if (fmt_ptr == '#')
		flag->sharp = 1;
	else if (fmt_ptr == '0')
		flag->zero = 1;
	else
		return (0);
}

void	init_flag(t_flags *flag)
{
	flag->plus = 0;
	flag->minus = 0;
	flag->zero = 0;
	flag->space = 0;
	flag->dot = 0;
	flag->width = 0;
	flag->sharp = 0;
	flag->precision = 0;
	flag->type = 0;
	flag->sign = 0;
}

void	check_width(char **fmt_ptr, t_flags *flag, va_list args)
{
	if (**fmt_ptr == '*')
	{
		flag->width = va_arg(args, int);
		(*fmt_ptr)++;
	}
	else
	{
		flag->width = ft_atoi(*fmt_ptr);
		while (ft_isdigit(**fmt_ptr))
			(*fmt_ptr)++;
	}
	if (flag->width < 0)
	{
		flag->minus = -1;
		flag->width *= -1;
	}
}

void	check_precision(char **fmt_ptr, t_flags *flag, va_list args)
{
	if (**fmt_ptr == '.')
	{
		flag->dot = 1;
		(*fmt_ptr)++;
		if (**fmt_ptr == '*')
		{
			flag->precision = va_arg(args, int);
			(*fmt_ptr)++;
		}
		else
		{
			flag->precision = ft_atoi(*fmt_ptr);
			while (ft_isdigit(**fmt_ptr))
				(*fmt_ptr)++;
		}
	}
	if (flag->precision < 0)
	{
		flag->precision = 0;
		flag->dot = 0;
	}
}

void	check_type(char *fmt_ptr, t_flags *flag)
{
	char *types;

	types = "cCsSdDioOuUxXp%n";
	while (*types)
	{
		if (*fmt_ptr == *types)
			flag->type = *types;
		if (flag->type != 0)
			break ;
		types++;
	}
}
