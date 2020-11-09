/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 02:33:35 by dhyeon            #+#    #+#             */
/*   Updated: 2020/11/09 22:15:13 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include "./libft/libft.h"

# define HEX_UPPER		"0123456789ABCDEF"
# define HEX_LOWER		"0123456789abcdef"

# define HEX_UP_SHARP	"0X"
# define HEX_LOW_SHARP	"0x"

typedef struct	s_flags
{
	int			plus;
	int			minus;
	int			zero;
	int			space;
	int			dot;
	int			width;
	int			sharp;
	int			precision;
	char		sign;
	char		type;
}				t_flags;

int				ft_printf(const char *format, ...);
void			parse_print_format(va_list args, char **format,
									int *return_val);
void			print_type(t_flags *flag, va_list args, int *return_val);

void			init_flag(t_flags *flag);
int				check_flag(char fmt_ptr, t_flags *flag);
void			check_width(char **fmt_ptr, t_flags *flag, va_list args);
void			check_precision(char **fmt_ptr, t_flags *flag, va_list args);
void			check_type(char *fmt_ptr, t_flags *flag);

void			print_c(t_flags *flag, va_list args, int *return_val);
void			print_space(t_flags *flag, int len, int *return_val);

void			print_s(t_flags *flag, va_list args, int *return_val);
void			print_s_str(int len, char *str, int *return_val);

char			*convert_base(long long int num, char *base);
int				get_digit(int base_num, long long int num);
char			*change_itoa_base(long long int num, char *base, int digit,
									int base_num);

void			print_p(t_flags *flag, va_list args, int *return_val);
void			check_p_sign_flag(t_flags *flag, int *len, char **str_d);
void			print_p_right(t_flags *flag, char *str, int len,
								int *return_val);
void			print_p_zero_right(t_flags *flag, char *str, int len,
									int *return_val);
void			print_p_left(t_flags *flag, char *str, int len,
								int *return_val);

void			print_pct(t_flags *flag, int *return_val);
void			print_pct_width(t_flags *flag, int *return_val);

void			print_x(t_flags *flag, va_list args, int *return_val);
void			check_x_sign_flag(t_flags *flag, int num, int *len,
									char **str_d);
void			print_x_right(t_flags *flag, char *str, int len,
								int *return_val);
void			print_x_zero_right(t_flags *flag, char *str, int len,
								int *return_val);
void			print_x_left(t_flags *flag, char *str, int len,
								int *return_val);

void			print_d(t_flags *flag, va_list args, int *return_val);
void			check_sign_flag(t_flags *flag, int d, int *len, char **str_d);
void			print_d_right(t_flags *flag, char *str, int len,
								int *return_val);
void			print_d_zero_right(t_flags *flag, char *str, int len,
								int *return_val);
void			print_d_left(t_flags *flag, char *str, int len,
								int *return_val);

void			print_u(t_flags *flag, va_list args, int *return_val);
void			check_u_sign_flag(t_flags *flag, int *len, char **str_d);
void			print_u_right(t_flags *flag, char *str, int len,
								int *return_val);
void			print_u_zero_right(t_flags *flag, char *str, int len,
								int *return_val);
void			print_u_left(t_flags *flag, char *str, int len,
								int *return_val);

void			test_print(t_flags *flag);

#endif
