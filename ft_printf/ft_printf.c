/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 02:33:24 by dhyeon            #+#    #+#             */
/*   Updated: 2020/11/09 22:09:32 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

void	print_type(t_flags *flag, va_list args, int *return_val)
{
	if (flag->type == 'c')
		print_c(flag, args, return_val);
	else if (flag->type == 's')
		print_s(flag, args, return_val);
	else if (flag->type == 'd' || flag->type == 'i')
		print_d(flag, args, return_val);
	else if (flag->type == 'u')
		print_u(flag, args, return_val);
	else if (flag->type == 'x' || flag->type == 'X')
		print_x(flag, args, return_val);
	else if (flag->type == 'p')
		print_p(flag, args, return_val);
	else if (flag->type == '%')
		print_pct(flag, return_val);
}

void	parse_print_format(va_list args, char **format, int *return_val)
{
	t_flags	*flag;
	char	*fmt_ptr;

	fmt_ptr = ++(*format);
	if (!(flag = malloc(sizeof(t_flags))))
		return ;
	init_flag(flag);
	while (check_flag(*fmt_ptr, flag))
		fmt_ptr++;
	check_width(&fmt_ptr, flag, args);
	check_precision(&fmt_ptr, flag, args);
	check_type(fmt_ptr, flag);
	fmt_ptr++;
	print_type(flag, args, return_val);
	(*format) = fmt_ptr;
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
			parse_print_format(args, (char **)&format, &return_val);
		else
		{
			ft_putchar_fd(*format, 1);
			return_val++;
			format++;
		}
	}
	va_end(args);
	return (return_val);
}
