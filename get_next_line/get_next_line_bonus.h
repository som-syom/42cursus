/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 06:56:45 by dhyeon            #+#    #+#             */
/*   Updated: 2020/08/12 06:07:28 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# define GNL_SUCCESS 1
# define GNL_EOF 0
# define GNL_ERROR -1

int				get_next_line(int fd, char **line);
int				get_index(char *back);
int				gnl_return(char **back, char **line, char *buf);

size_t			ft_strlen(char *str);
char			*ft_strdup(char *src);
char			*ft_strjoin(char *s1, char *s2);

#endif
