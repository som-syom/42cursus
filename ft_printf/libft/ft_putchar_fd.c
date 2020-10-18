/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 21:28:01 by dhyeon            #+#    #+#             */
/*   Updated: 2020/07/06 17:51:23 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	unsigned char tmp;

	if (fd < 0)
		return ;
	if ((unsigned char)c >= 0x80)
	{
		tmp = (unsigned char)c / 0x40 + 0xC0;
		write(fd, &tmp, 1);
		tmp = (unsigned char)c % 0x40 + 0x80;
		write(fd, &tmp, 1);
	}
	else
		write(fd, &c, 1);
}
