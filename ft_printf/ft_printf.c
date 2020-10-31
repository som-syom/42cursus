/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 02:33:24 by dhyeon            #+#    #+#             */
/*   Updated: 2020/10/31 19:39:06 by dhyeon           ###   ########.fr       */
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
	else
	{
		flag->width = ft_atoi(*fmt_ptr);
		while (ft_isdigit(**fmt_ptr))
			(*fmt_ptr)++;
	}
}

void	check_precision(char **fmt_ptr, t_flags *flag, va_list args)
{
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

void	check_len(char **fmt_ptr, t_flags *flag)
{
	if ((ft_strncmp(*fmt_ptr, "hh", 2)) == 0)
	{
		flag->sign = 'H';
		(*fmt_ptr) += 2;
	}
	else if ((ft_strncmp(*fmt_ptr, "h", 1)) == 0)
	{
		flag->sign = 'h';
		(*fmt_ptr)++;
	}
	else if ((ft_strncmp(*fmt_ptr, "ll", 2)) == 0)
	{
		flag->sign = 'L';
		(*fmt_ptr) += 2;
	}
	else if ((ft_strncmp(*fmt_ptr, "l", 1)) == 0)
	{
		flag->sign = 'l';
		(*fmt_ptr)++;
	}
}

void	check_type(char **fmt_ptr, t_flags *flag)
{
	if (**fmt_ptr == 'c' || **fmt_ptr == 's' || **fmt_ptr == 'p' 
		|| **fmt_ptr =='d' || **fmt_ptr == 'i' || **fmt_ptr == 'u' 
		|| **fmt_ptr == 'x' || **fmt_ptr == 'X' || **fmt_ptr == '%'
		|| **fmt_ptr == 'n' || **fmt_ptr == 'f' || **fmt_ptr == 'g' 
		|| **fmt_ptr =='e')
	{
		flag->type = **fmt_ptr;
		(*fmt_ptr)++;
	}
}
void	print_c(char **fmt_ptr, t_flags *flag, va_list args, int *return_val)
{
	if (flag->width > 0)
	{
		flag->width--;
		while (flag->width != 0)
		{
			ft_putchar_fd(' ', 1);
			flag->width--;
			(*return_val)++;
		}
	}
	ft_putchar_fd(va_arg(args, int), 1);
	(*return_val)++;

	(*fmt_ptr)++;
	(*fmt_ptr)--;

	
}

void	print_type(char **fmt_ptr, t_flags *flag, va_list args, int *return_val)
{
	if (flag->type == 'c')
		print_c(fmt_ptr, flag, args, return_val);
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
	if (*fmt_ptr == '.')
		check_precision(&fmt_ptr, flag, args);
	check_len(&fmt_ptr, flag);
	check_type(&fmt_ptr, flag);
	print_type(&fmt_ptr, flag, args, return_val);
	(*format) = fmt_ptr;
	//test_print(flag);
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
			parse_print_format(args, (char **)&format, &return_val);
			//printf("status = %s||", format);
		}
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