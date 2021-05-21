# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/18 14:49:27 by dhyeon            #+#    #+#              #
#    Updated: 2021/05/21 20:15:42 by dhyeon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
SRCDIR = srcs
SRCS = srcs/main.c \
		srcs/init_stack.c \
		srcs/command.c \
		srcs/push.c \
		srcs/swap.c \
		srcs/rotate.c \
		srcs/revers_rotate.c \
		srcs/util.c \
		srcs/sort.c \
		srcs/mini_sort_3_a.c \
		srcs/mini_sort_3_b.c \
		srcs/test.c 

INCS	=	-I includes -I libft
OBJS	=	$(SRCS:.c=.o)
LIBFT	=	libft/libft.a
LFT		=	-L libft -lft

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INCS) $(LFT)

$(LIBFT) :
	@make -C libft/

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

clean :
	@make clean -C libft/
	rm -rf $(OBJS)

fclean : clean
	@make fclean -C libft/
	rm -rf $(NAME)

re : fclean all