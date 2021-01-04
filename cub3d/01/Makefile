CC = gcc
FLAGS = -g -Wall -Wextra -Werror # -fsanitize=address # -fsanitize=address
NAME = cub3D
SRCDIR = srcs
INCDIR = includes
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(SRCS:.c=.o)
OS = $(shell uname -s)
NORM = $(shell find /usr/ ~/ 2>/dev/null | grep norminette.rb | head -1)
ifeq ($(OS), Darwin)
    MLX = ./minilibx
    MAX_WIDTH = $(shell system_profiler SPDisplaysDataType | grep Resolution | awk '{print $$2}')
    MAX_HEIGHT = $(shell system_profiler SPDisplaysDataType | grep Resolution | awk '{print $$4}')
    LINK = -lmlx -framework OpenGL -framework AppKit
else
    MLX = ./minilibx-linux
    MAX_WIDTH = $(shell xdpyinfo | grep dimensions | awk '{print $$2}' | cut -dx -f1)
    MAX_HEIGHT = $(shell xdpyinfo | grep dimensions | awk '{print $$2}' | cut -dx -f2)
    LINK = -L . -lmlx -lm -lXext -lX11
endif

$(NAME): all
$(SRCDIR)/%.o: $(SRCDIR)/%.c
    $(CC) $(FLAGS) -o $@ -c $< -I $(INCDIR) -I $(MLX) -DMAX_WIDTH=$(MAX_WIDTH) -DMAX_HEIGHT=$(MAX_HEIGHT)

all: $(OBJS)
    $(CC) $(FLAGS) $^ -o $(NAME) -I $(INCDIR) $(LINK)

clean:
    @rm -rf $(OBJS)
fclean: clean
    @rm -rf $(NAME)
re: fclean
    @make all
norm:
    @$(NORM) srcs/*.c includes/*.h
mlx:
    make re -C minilibx-linux && mv minilibx-linux/libmlx.a .