#ifndef CUB3D
# define CUB3D

#include "./mlx/mlx.h"
#include "key_macos.h"
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define X_EVENT_KEY_PRESS	2
#define X_EVENT_KEY_EXIT	17
#define mapWidth 24
#define mapHeight 24
#define width 640
#define height 480
#define texWidth 280
#define texHeight 280

typedef struct	s_img
{
	void	*img;
	int		*data;

	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}				t_img;

typedef struct	s_info
{
	double	posX; //플레이어 초기 위치벡터
	double	posY;
	double	dirX; //플레이어 초기 방향벡터
	double	dirY;
	double	planeX; //플레이어 카메라 평면
	double	planeY;
	void	*mlx;
	void	*win;
	double	moveSpeed;
	double	rotSpeed;
	double	oldDirX;
	double	oldPlaneX;
	t_img	img;
	int		buf[height][width]; // 스크린 버퍼 배열
	int		**texture; // 텍스쳐 버퍼
}				t_info;

typedef struct	s_ray
{
	double	cameraX; // 카메라평면 좌표
	double	cameraY;
	double	rayDirX; // 광선의 방향벡터
	double	rayDirY;
	int		mapX; // 현재 광선의 위치(한칸)
	int		mapY;
	double	sideDistX; // 시작점 ~ 첫번째 x면까지 광선의 이동거리
	double	sideDistY;
	double	perpWallDist; // camera plane에서 벽까지의 수직거리
	double	deltaDistX; // 첫번째 x면 ~ 그 다음 x면까지의 광선의 이동거리
	double	deltaDistY;
	int		stepX; //광선의 방향이 어느 방향으로 건너뛰는지
	int		stepY; // x|y방향 rayDirX|Y 값이 양수면 +1 음수면 -1, 0이라면 상관없음
	int		hit; // 벽과 부딪혔는지 여부 (루프 종료조건)
	int		side; // (부딪힌 면  0: x면 | 1: y면 )
	int		lineHeight; // 화면에 그려야하는 수직 선의 높이
	int		drawStart;
	int		drawEnd;
	int		color;
	
}				t_ray;



void	info_new(t_info *info);

void	calc(t_info *info);
void	calc_ray_init(t_info *info, t_ray *ray, int *x);
void	calc_step_init(t_info *info, t_ray *ray);
void	calc_dda(t_info *info, t_ray *ray);
void	calc_draw(t_ray *ray, t_info *info, int x);

int		key_press(int key, t_info *info);
void	key_press_w(t_info *info);
void	key_press_s(t_info *info);
void	key_press_d(t_info *info);
void	key_press_a(t_info *info);
void	key_press_left(t_info *info);
void	key_press_right(t_info *info);

// void	verLine(t_info *info, int x, int y1, int y2, int color);
int		main_loop(t_info *info);

int		worldMap[24][24];

#endif