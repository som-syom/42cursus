/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 02:47:56 by dhyeon            #+#    #+#             */
/*   Updated: 2021/01/13 07:19:43 by dhyeon           ###   ########.fr       */
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

# ifndef MAX_WIDTH
#  define MAX_WIDTH 1920
# endif
# ifndef MAX_HEIGHT
#  define MAX_HEIGHT 1080
# endif
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# pragma pack(push, 1)

typedef struct	s_bmp_header
{
	char		magic[2];
	int			filesz;
	int			reserved_0;
	int			start_offset_54;
	int			header_sz_40;
	int			width;
	int			height;
	short		plane_1;
	short		bitcnt_24;
	int			compress_0;
	int			imgsz;
	int			xppm_0;
	int			yppm_0;
	int			clr_used_0;
	int			clr_imp_0;
}				t_bmp_header;
# pragma pack(pop)

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


// typedef struct	s_img
// {
// 	void	*img;
// 	int		*data;
// 	int		size_l;
// 	int		bpp;
// 	int		endian;
// 	int		width;
// 	int		height;
// }				t_img;

typedef struct		s_img
{
	unsigned char	reserved[32];
	int				width;
	int				height;
	int				type;
	int				format;
	int				*data;
}					t_img;

typedef struct		s_sprite
{
	int				screen_x;
	int				offset;
	int				size;
	int				x;
	int				y;
	int				tx;
	int				ty;
	double			xoffset;
	double			yoffset;
	t_xy_d			draw_x;
	t_xy_d			draw_y;
}					t_sprite;

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
	t_img	*img;
	int		**buf; // 스크린 버퍼 배열
	int		**texture; // 텍스쳐 버퍼
	double	*zbuffer; // width 만큼 배열
	int		sp_num;
	t_xy_d	*sprites;
}				t_info;

typedef struct	s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;

typedef struct	s_config
{
	int		is_save;
	int		fd;
	int		w;
	int		h;
	int		map_cnt;
	char	**tex_path; //후에 프리 , 0123 북남서동 4 스프라이트
	int		rgb[2]; //0F 1C
	t_list	*map_lst; // init
	t_xy_i	map_size; //init 필요
	char	player_dir;
	char	**map;
}				t_config;

typedef struct	s_cub
{
	t_info		info;
	t_img		img;
	t_config	conf;
	int			test;
}				t_cub;

typedef struct	s_ray
{
	double	c_x; // 카메라평면 좌표
	double	c_y;
	double	r_x; // 광선의 방향벡터
	double	r_y;
	int		m_x; // 현재 광선의 위치(한칸)
	int		m_y;
	double	side_x; // 시작점 ~ 첫번째 x면까지 광선의 이동거리
	double	side_y;
	double	perp; // camera plane에서 벽까지의 수직거리
	double	delta_x; // 첫번째 x면 ~ 그 다음 x면까지의 광선의 이동거리
	double	delta_y;
	int		step_x; //광선의 방향이 어느 방향으로 건너뛰는지
	int		step_y; // x|y방향 rayDirX|Y 값이 양수면 +1 음수면 -1, 0이라면 상관없음
	int		hit; // 벽과 부딪혔는지 여부 (루프 종료조건)
	int		side; // (부딪힌 면  0: x면 | 1: y면 )
	int		line_h; // 화면에 그려야하는 수직 선의 높이
	int		draw_s;
	int		draw_e;
	int		color;
	int		tex_num;
	double	w_x;
	int		t_x;
	int		t_y;
	double	step;
	double	t_p;
}				t_ray;

/*
**	libft - 나중에 라이브러리 따로 만들기
*/

void		ft_putstr(char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlen(char *str);
char		*ft_strdup(char *src);
char		*ft_strjoin(char *s1, char *s2);
char		**ft_split(char const *s, char c);
int			ft_isdigit(int c);
int			ft_atoi(const char *str);
t_list		*ft_lstnew(char *content);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
void		*ft_calloc(size_t n, size_t size);
void		*ft_memset(void *ptr, int val, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
char		*ft_strchr(const char *str, int c);

/*
**	get_next_line
*/

int			get_next_line(int fd, char **line);

/*
**	cub3d
*/

int			parse_line(t_config *conf, char *str);
int			read_map_file(t_cub *cub, t_config *conf);
int			set_map(t_cub *cub, t_config *conf, char *path);

int			check_win_size(t_config *conf, char *str);
int			check_texture(t_config *conf, char *str, int info);
int			check_rgb(t_config *conf, int *c, int info);
int			check_color(t_config *conf, char *str, int info);
int			parse_line(t_config *conf, char *str);

int			map_init(t_config *conf);
int			list_to_array(t_config *conf);
int			create_map(t_config *conf);
int			check_valid_map(t_config *conf);

int			check_digit(char **strs);
void		ft_free(char **strs);
void		skip_space(char **str);
int			is_blank(char *s);
void		calc(t_cub *cub);
int			key_press(int key, t_cub *cub);
int			main_loop(t_cub *cub);
#endif
