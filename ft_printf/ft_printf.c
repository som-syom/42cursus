/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 02:33:24 by dhyeon            #+#    #+#             */
/*   Updated: 2020/11/04 21:02:51 by dhyeon           ###   ########.fr       */
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
		// test_print(flag);
			while (ft_isdigit(**fmt_ptr))
				(*fmt_ptr)++;
		}
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
	if (flag->plus_minus >= 0)
		print_space(flag, 1, return_val);
	ft_putchar_fd(va_arg(args, int), 1);
	if (flag->plus_minus == -1)
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

	//test_print(flag);
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
	if (flag->plus_minus == 0 && flag->width != 0)
		print_space(flag, len, return_val);
	print_s_str(len, str, return_val);
	if (flag->plus_minus == -1 && flag->width != 0)
		print_space(flag, len, return_val);
}

void	print_d_width(t_flags *flag, int d, int len, int *return_val)
{
	char	a;
	int		i;

	i = 0;
	if (flag->zero == 1)
		a = '0';
	else
		a = ' ';
	if (flag->zero == 1 && d < 0)
	{
		ft_putchar_fd('-', 1);
		(*return_val)++;
	}
	if (flag->sign == '+' || (flag->sign == '-' && flag->zero == 0))
		i++;
	if (flag->width > flag->precision && len < flag->precision)
		flag->width -=  flag->precision;
	else if (flag->width <= len || flag->width <= flag->precision)
		flag->width = 0;
	else if (flag->width > len)
		flag->width -= len;
	while (i < flag->width)
	{
		ft_putchar_fd(a, 1);
		i++;
		(*return_val)++;
	}
}

void	print_d_num(t_flags *flag, char *str_d, int *return_val)
{
	int len;
	int i;

	i = 0;
	if (flag->zero == 0 && (flag->sign == '+' || flag->sign == '-'))
	{
		ft_putchar_fd(flag->sign, 1);
		(*return_val)++;
	}
	if (flag->sign == '-')
		(str_d)++;
	// printf("str = %s\n", str_d);
	len = ft_strlen(str_d);
	// printf("0 = %d\n", flag->precision - len);
	// test_print(flag);
	if (len < flag->precision)
	{
		while (i < (flag->precision - len))
		{
			ft_putchar_fd('0', 1);
			i++;
			(*return_val)++;
		}
	}
	ft_putstr_fd(str_d, 1);
	(*return_val) += len;
}

void	check_sign(t_flags *flag, int d, int len)
{
	if (flag->plus_minus == 1 && d > 0)
		flag->sign = '+';
	else if ((d < 0 && flag->zero == 1) || (d < 0 && flag->precision > len))
		flag->sign = '-';
}

void	print_d(t_flags *flag, va_list args, int *return_val)
{
	int		d;
	int		len;
	char	*str_d;

	d = va_arg(args, int);
	str_d = ft_itoa(d);
	len = ft_strlen(str_d);
	check_sign(flag, d, len);
	if (flag->plus_minus >= 0)
		print_d_width(flag, d, len, return_val);
	print_d_num(flag, str_d, return_val);
	if (flag->plus_minus == -1)
		print_d_width(flag, d, len, return_val);
}

void	print_type(t_flags *flag, va_list args, int *return_val)
{
	if (flag->type == 'c')
		print_c(flag, args, return_val);
	else if (flag->type == 's')
		print_s(flag, args, return_val);
	else if (flag->type == 'd' || flag->type == 'i')
		print_d(flag, args, return_val);

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
	// check_len(&fmt_ptr, flag);
	check_type(fmt_ptr, flag);
	fmt_ptr++;
	print_type(flag, args, return_val);
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