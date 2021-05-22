# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/18 14:49:27 by dhyeon            #+#    #+#              #
#    Updated: 2021/05/22 18:23:32 by dhyeon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_P = push_swap
NAME_C = checker
NAME = $(NAME_P)

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

SRCS_C = srcs/checker.c \
		srcs/get_next_line.c \
		srcs/init_stack.c \
		srcs/util.c \
		srcs/command.c \
		srcs/rotate.c \
		srcs/revers_rotate.c \
		srcs/push.c \
		srcs/swap.c \
		srcs/sort.c \
		srcs/mini_sort_3_a.c \
		srcs/mini_sort_3_b.c \
		srcs/test.c

INCS	=	-I includes -I libft
OBJS	=	$(SRCS:.c=.o)
OBJS_C	=	$(SRCS_C:.c=.o)
LIBFT	=	libft/libft.a
LFT		=	-L libft -lft

all : $(NAME_P)

$(NAME_P) : $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INCS) $(LFT)

$(NAME_C) : $(LIBFT) $(OBJS_C)
	$(CC) $(CFLAGS) -o $(NAME_C) $(OBJS_C) $(INCS) $(LFT)

$(LIBFT) :
	@make -C libft/

bonus: $(NAME_C)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

clean :
	@make clean -C libft/
	rm -rf $(OBJS)
	rm -rf $(OBJS_C)

fclean : clean
	@make fclean -C libft/
	rm -rf $(NAME_P)
	rm -rf $(NAME_C)

re : fclean all