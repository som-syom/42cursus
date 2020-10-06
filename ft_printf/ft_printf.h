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

typedef struct  s_flags
{
    int         flag;
    int         zero;
    int         dot;
    int         width;
    int         space;
    int         sharp;
    char        type;
    int         minus;
}               t_flags;

int     ft_printf(const char *format, ...);

void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif