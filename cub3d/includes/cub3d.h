/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 02:47:56 by dhyeon            #+#    #+#             */
/*   Updated: 2021/01/15 00:50:43 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
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
# ifdef __linux__
#  include "linux.h"
# else
#  include "mac.h"
# endif

# define TEX_H 64
# define TEX_W 64

# pragma pack(push, 1)

typedef struct		s_bmp_header
{
	char			magic[2];
	int				filesz;
	int				reserved_0;
	int				start_offset_54;
	int				header_sz_40;
	int				width;
	int				height;
	short			plane_1;
	short			bitcnt_24;
	int				compress_0;
	int				imgsz;
	int				xppm_0;
	int				yppm_0;
	int				clr_used_0;
	int				clr_imp_0;
}					t_bmp_header;
# pragma pack(pop)

typedef struct		s_xy_d
{
	double			x;
	double			y;
}					t_xy_d;

typedef struct		s_xy_i
{
	int				x;
	int				y;
}					t_xy_i;

typedef struct		s_sprite
{
	t_xy_d			sp_dir;
	double			inv_det;
	t_xy_d			transform;
	int				screen_x;
	int				mv_screen;
	int				sp_h;
	t_xy_i			draw_s;
	t_xy_i			draw_e;
	t_xy_i			tex;
}					t_sprite;

typedef struct		s_info
{
	void			*mlx;
	void			*win;
	t_xy_d			pos;
	t_xy_d			dir;
	t_xy_d			plane;
	double			move_speed;
	double			rot_speed;
	double			old_dir_x;
	double			old_plane_x;
	t_img			*img;
	int				**buf;
	int				**texture;
	double			*zbuffer;
	int				sp_num;
	t_xy_d			*sprites;
}					t_info;

typedef struct		s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

typedef struct		s_config
{
	int				is_save;
	int				fd;
	int				w;
	int				h;
	int				map_cnt;
	char			**tex_path;
	int				rgb[2];
	t_list			*map_lst;
	t_xy_i			map_size;
	char			player_dir;
	char			**map;
}					t_config;

typedef struct		s_cub
{
	t_info			info;
	t_img			img;
	t_config		conf;
	int				test;
	t_img			*dummy[5];
}					t_cub;

typedef struct		s_ray
{
	double			c_x;
	double			c_y;
	double			r_x;
	double			r_y;
	int				m_x;
	int				m_y;
	double			side_x;
	double			side_y;
	double			perp;
	double			delta_x;
	double			delta_y;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				line_h;
	int				draw_s;
	int				draw_e;
	int				color;
	int				tex_num;
	double			w_x;
	int				t_x;
	int				t_y;
	double			step;
	double			t_p;
}					t_ray;

/*
**	libft
*/

int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlen(char *str);
char				*ft_strdup(char *src);
char				*ft_strjoin(char *s1, char *s2);
char				**ft_split(char const *s, char c);
int					ft_isdigit(int c);
int					ft_atoi(const char *str);
t_list				*ft_lstnew(char *content);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
void				*ft_calloc(size_t n, size_t size);
void				*ft_memset(void *ptr, int val, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
char				*ft_strchr(const char *str, int c);

/*
**	get_next_line
*/

int					get_next_line(int fd, char **line);

/*
**	cub3d
*/

int					parse_line(t_config *conf, char *str);
int					read_map_file(t_cub *cub, t_config *conf);
int					set_map(t_cub *cub, t_config *conf, char *path);
void				set_player_dir(t_cub *cub, char dir);
int					set_player_pos(t_cub *cub, int i, int j);
void				save_sprite(t_cub *cub);
int					check_player_sp(t_config *conf, t_cub *cub, int i, int j);
void				render_sprite(t_cub *cub);
void				calc_basic(t_ray *ray, t_cub *cub);

void				key_press_w(t_cub *cub);
void				key_press_s(t_cub *cub);
void				key_press_d(t_cub *cub);
void				key_press_a(t_cub *cub);

void				draw_fc(t_cub *cub);
void				calc_draw(t_ray *ray, t_cub *cub, int x);
int					get_tex_num(t_ray *ray);
int					ft_min(int a, int b);
int					ft_max(int a, int b);

int					check_win_size(t_config *conf, char *str);
int					check_texture(t_config *conf, char *str, int info);
int					check_rgb(t_config *conf, int *c, int info);
int					check_color(t_config *conf, char *str, int info);
int					parse_line(t_config *conf, char *str);

int					map_init(t_config *conf);
int					list_to_array(t_config *conf);
int					create_map(t_config *conf);
int					check_valid_map(t_config *conf);

int					add_header(const int fd, t_cub *cub);
void				draw_img(const int fd, t_cub *cub, int padding);
void				save_bmp(t_cub *cub);

int					check_digit(char **strs);
int					check_arg(int ac, char **av, t_config *conf);
int					init_all(t_cub *cub);
int					parse_data(t_cub *cub);
void				ft_free(char **strs);
void				skip_space(char **str);
int					is_blank(char *s);
void				calc(t_cub *cub);
int					key_press(int key, t_cub *cub);
int					main_loop(t_cub *cub);
void				print_err(int num);
int					ft_exit(void);

#endif
