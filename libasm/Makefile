# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/01 18:31:24 by dhyeon            #+#    #+#              #
#    Updated: 2021/03/03 20:05:35 by dhyeon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a
CC = nasm
CFLAGS = -f macho64

SRCS = ft_strlen.s \
		ft_strcpy.s \
		ft_strcmp.s \
		ft_write.s \
		ft_read.s \
		ft_strdup.s

OBJS = $(SRCS:.s=.o)

%.o: %.s
		$(CC) $(CFLAGS) $<

$(NAME) : $(OBJS)
		ar rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
		rm -rf $(OBJS)

fclean : clean
		rm -rf $(NAME)

re : fclean all

test : re
		gcc -Wall -Wextra -Werror main.c $(NAME)

.PHONY : all clean fclean re test
