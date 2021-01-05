/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_macos.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 17:40:13 by oouklich          #+#    #+#             */
/*   Updated: 2020/12/30 01:11:34 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_MACOS_H
# define KEY_MACOS_H

# ifndef __linux__
#  define K_A			0
#  define K_B			11
#  define K_C			8
#  define K_D			2
#  define K_E			14
#  define K_F			3
#  define K_G			5
#  define K_H			4
#  define K_I			34
#  define K_J			38
#  define K_K			40
#  define K_L			37
#  define K_M			46
#  define K_N			45
#  define K_O			31
#  define K_P			35
#  define K_Q			12
#  define K_R			15
#  define K_S			1
#  define K_T			17
#  define K_U			32
#  define K_V			9
#  define K_W			13
#  define K_X			7
#  define K_Y			16
#  define K_Z			6
#  define K_AR_L		123
#  define K_AR_R		124
#  define K_AR_U		126
#  define K_AR_D		125
#  define K_SP			49
#  define K_ESC			53
#  define K_TAB			48
# else
#  define K_A			97
#  define K_B			98
#  define K_C			99
#  define K_D			100
#  define K_E			101
#  define K_F			102
#  define K_G			103
#  define K_H			104
#  define K_I			105
#  define K_J			106
#  define K_K			107
#  define K_L			108
#  define K_M			109
#  define K_N			110
#  define K_O			111
#  define K_P			112
#  define K_Q			113
#  define K_R			114
#  define K_S			115
#  define K_T			116
#  define K_U			117
#  define K_V			118
#  define K_W			119
#  define K_X			120
#  define K_Y			121
#  define K_Z			122
#  define K_AR_L		65361
#  define K_AR_R		65363
#  define K_AR_U		65362
#  define K_AR_D		65364
#  define K_SP		32
#  define K_ESC		65307
#  define K_TAB		65289
# endif
#endif
