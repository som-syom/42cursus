/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 02:47:56 by dhyeon            #+#    #+#             */
/*   Updated: 2020/12/03 07:12:07 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./key_macros.h"
# include "./mlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <limits.h>

typedef struct	s_config
{
	int		is_save;
	int		fd;
}				t_config;

typedef struct	s_xy_d
{
	double	x;
	double	y;
}				t_xy_d;

typedef struct	s_xy_i
{
	int	x;
	int	y;
}				t_xy_i;


typedef struct	s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
	int		width;
	int		height;
}				t_img;

typedef struct s_info
{
	void	*mlx;
	void	*win;
	t_xy_d	pos; //플레이어 초기 위치벡터
	t_xy_d	dir; //플레이어 초기 방향벡터
	t_xy_d	plane; //플레이어 카메라 평면
	double	move_speed;
	double	rot_speed;
	double	old_dir_x;
	double	old_plane_x;
	t_img	img;
	int		**buf; // 스크린 버퍼 배열
	int		**texture; // 텍스쳐 버퍼
	double	*zbuffer; // width 만큼 배열
}				t_info;

typedef struct	s_cub
{
	t_info	info;
	t_img	img;
}				t_cub;

/*
**	libft - 나중에 라이브러리 따로 만들기
*/

void		ft_putstr(char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlen(char *str);
char		*ft_strdup(char *src);
char		*ft_strjoin(char *s1, char *s2);

/*
**	get_next_line
*/

int			get_next_line(int fd, char **line);

/*
**	cub3d
*/





#endif