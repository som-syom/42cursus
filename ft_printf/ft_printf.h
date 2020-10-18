/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 02:33:35 by dhyeon            #+#    #+#             */
/*   Updated: 2020/10/07 02:33:38 by dhyeon           ###   ########.fr       */
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

typedef struct  s_flags
{
	int			plus_minus;
	int			zero;
	int			space;
	int			dot;
	int			width;
	int			sharp;
	int			precision;
	char		type;
	char		sign;
}				t_flags;

int		ft_printf(const char *format, ...);
void	parse_format(va_list args, char **format, int *return_val);
void	init_flag(t_flags *flag);

void	test_print(t_flags *flag);

#endif