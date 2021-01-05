CC = gcc
FLAGS =-Wall -Wextra -Werror -g
NAME = cub3D
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
OS = $(shell uname -s)
ifeq ($(OS), Darwin)
	MLX = ./minilibx
	MAX_WIDTH = $(shell system_profiler SPDisplaysDataType | grep Resolution | awk '{print $$2}')
	MAX_HEIGHT = $(shell system_profiler SPDisplaysDataType | grep Resolution | awk '{print $$4}')
	LINK = -lmlx -framework OpenGL -framework AppKit
else
	MLX = ./minilibx-linux
	MAX_WIDTH = $(shell xdpyinfo | grep dimensions | awk '{print $$2}' | cut -dx -f1)
	MAX_HEIGHT = $(shell xdpyinfo | grep dimensions | awk '{print $$2}' | cut -dx -f2)
	LINK = -L $(MLX) -lmlx -lm -lXext -lX11
endif
$(NAME): all
%.o: %.c
	$(CC) -c $(FLAGS) $^ -DMAX_WIDTH=$(MAX_WIDTH) -DMAX_HEIGHT=$(MAX_HEIGHT)
all: $(OBJS)
	$(CC) $(FLAGS) $^ -o $(NAME) -I $(MLX) $(LINK)
clean:
	rm -rf $(OBJS)
fclean: clean
	rm -rf $(NAME)
re: fclean all
