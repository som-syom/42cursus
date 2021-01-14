/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linux.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 23:12:59 by dhyeon            #+#    #+#             */
/*   Updated: 2021/01/15 00:51:31 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINUX_H
# define LINUX_H
# define K_A			97
# define K_B			98
# define K_C			99
# define K_D			100
# define K_E			101
# define K_F			102
# define K_G			103
# define K_H			104
# define K_I			105
# define K_J			106
# define K_K			107
# define K_L			108
# define K_M			109
# define K_N			110
# define K_O			111
# define K_P			112
# define K_Q			113
# define K_R			114
# define K_S			115
# define K_T			116
# define K_U			117
# define K_V			118
# define K_W			119
# define K_X			120
# define K_Y			121
# define K_Z			122
# define K_AR_L			65361
# define K_AR_R			65363
# define K_AR_U			65362
# define K_AR_D			65364
# define K_SP			32
# define K_ESC			65307
# define K_TAB			65289

typedef struct		s_img
{
	unsigned char	reserved[32];
	int				width;
	int				height;
	int				type;
	int				format;
	int				*data;
}					t_img;

#endif
