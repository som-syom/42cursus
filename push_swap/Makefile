# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/18 14:49:27 by dhyeon            #+#    #+#              #
#    Updated: 2021/05/18 15:03:50 by dhyeon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCDIR = srcs
SRCS = srcs/main.c \
		srcs/init_stack.c \
		srcs/ft_atoi.c \
		srcs/ft_calloc.c \
		srcs/command.c \
		srcs/push.c \
		srcs/swap.c \
		srcs/rotate.c \
		srcs/revers_rotate.c \
		srcs/util.c
INCS	=	-I includes
OBJS	=	$(SRCS:.c=.o)

all : $(NAME)
$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INCS)
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)
clean :
	rm -rf $(OBJS)
fclean : clean
	rm -rf $(NAME)
re : fclean all