#ifndef MICRO_H
# define MICRO_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <string.h>

typedef struct s_rec
{
	char	type;
	float	w;
	float	h;
	float	x;
	float	y;
	char	c;
}				t_rec;

typedef struct s_info
{
	int		w;
	int		h;
	char	c;
	char	**map;
	t_rec	rec;
}				t_info;


#endif