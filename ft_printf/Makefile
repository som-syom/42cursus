# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhyeon <dhyeon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/19 05:21:35 by dhyeon            #+#    #+#              #
#    Updated: 2020/11/06 21:03:19 by dhyeon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

FILES = ft_printf \
		testprint \
		print_cs \
		print_di \
		print_u \
		print_x \
		print_p \
		print_pct \
		check_flag \
		convert_base \

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

LIBFT_SRCS = ./libft/*.c
LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)

all : $(NAME)

.c.o : $(SRCS)
		$(CC) $(CFLAGS) -c -o $@ $< -I./libft

$(NAME): $(OBJS)
		$(MAKE) -C ./libft
		mv libft/libft.a $(NAME)
		ar rcs $(NAME) $(OBJS)

bonus : all

test : all
		$(CC) $(CFLAGS) $(SRCS) $(NAME) test.c -I./libft

clean :
		rm -rf $(OBJS) $(LIBFT_OBJS)

fclean : clean
		rm -rf $(NAME) ./libft/libft.a

re : fclean all

.PHONY: bonus all clean fclean re test
