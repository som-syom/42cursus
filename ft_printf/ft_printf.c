/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 02:33:24 by dhyeon            #+#    #+#             */
/*   Updated: 2020/10/07 02:33:29 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

int		check_flag(char fmt_ptr, t_flags *flag)
{

	if (fmt_ptr == '+')
		flag->plus_minus = 1;
	else if (fmt_ptr == '-')
		flag->plus_minus = -1;
	else if (fmt_ptr == ' ')
		flag->space = 1;
	else if (fmt_ptr == '#')
		flag->sharp = 1;
	else if (fmt_ptr == '0')
		flag->zero = 1;
	else
		return (0);
	return (1);
}

void	init_flag(t_flags *flag)
{
	flag->plus_minus = 0;
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

}

void	parse_format(va_list args, char **format, int *return_val)
{
	t_flags	*flag;
	char	*fmt_ptr;

	printf("bb");
	fmt_ptr = ++(*format);
	if (!(flag = malloc(sizeof(t_flags))))
		return ;
	init_flag(flag);
	while (check_flag(*fmt_ptr, flag))
		fmt_ptr++;
	test_print(flag);
	check_width(&fmt_ptr, flag, args);
	return_val++;
}

int		ft_printf(const char *format, ...)
{
	va_list	args;
	int		return_val;


	return_val = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			parse_format(args, (char **)&format, &return_val);
		}
		else
		{
			ft_putchar_fd(*format, 1);
			return_val++;
		}
		format++;
	}
	va_end(args);
	return (return_val);
}