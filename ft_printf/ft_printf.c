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

void    parse_format(va_list args, char **format, int *return_val)
{
    t_flags *flag;
    char    *fmt_ptr;
}

int     ft_printf(const char *format, ...)
{
    va_list args;
    int     return_val;

    return_val = 0;
    va_start(args, format);
    while(*format)
    {
        if (*format == '%')
        {
            parse_format(args, &format, &return_val);
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