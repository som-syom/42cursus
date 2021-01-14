/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 21:54:26 by dhyeon            #+#    #+#             */
/*   Updated: 2021/01/14 21:55:37 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		add_header(const int fd, t_cub *cub)
{
	t_bmp_header		header;
	int					tmp;
	const unsigned char	header_base[] = {
		0x42, 0x4D, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x01, 0x00, 0x18, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	};

	ft_memcpy(&header, header_base, sizeof(header));
	header.width = cub->conf.w;
	header.height = cub->conf.h;
	tmp = 3 * header.width;
	while (tmp % 4 != 0)
		tmp++;
	header.imgsz = tmp * header.height;
	header.filesz = header.start_offset_54 + header.imgsz;
	write(fd, &header, sizeof(header));
	return (tmp - 3 * header.width);
}

void	draw_img(const int fd, t_cub *cub, int padding)
{
	int	i;
	int	j;

	i = cub->conf.h;
	while (--i >= 0)
	{
		j = -1;
		while (++j < cub->conf.w)
			write(fd, &cub->info.img->data[i * cub->conf.w + j], 3);
		j = -1;
		while (++j < padding)
			write(fd, "\x00", 1);
	}
}

void	save_bmp(t_cub *cub)
{
	const int fd = open("screenshot.bmp", O_CREAT | O_RDWR | O_TRUNC, 0644);

	if (fd == -1)
		print_err(-1);
	draw_img(fd, cub, add_header(fd, cub));
	close(fd);
	exit(0);
}
