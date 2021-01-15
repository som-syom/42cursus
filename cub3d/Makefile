CC = gcc
FLAGS =-Wall -Wextra -Werror -g
NAME = cub3D
SRCDIR = srcs/
INCDIR = includes
FILES = bmp check_map draw ft_atoi ft_calloc ft_isdigit \
		ft_lstadd_back ft_lstlast ft_lstnew ft_lstsize ft_memcpy \
		ft_memset ft_split ft_strchr ft_strncmp get_next_line \
		get_next_line_utils init key_press key_press2 main parse \
		ray_calc read read2 sprite util ft_exit
SRCS = $(addprefix $(SRCDIR), $(addsuffix , $(FILES)))
OBJSDIR = srcs/
OBJS = $(addprefix $(OBJSDIR), $(addsuffix .o, $(FILES)))
OS = $(shell uname -s)

ifeq ($(OS), Darwin)
	MLX = ./mlx
	MAX_WIDTH = $(shell system_profiler SPDisplaysDataType | grep Resolution | awk '{print $$2}')
	MAX_HEIGHT = $(shell system_profiler SPDisplaysDataType | grep Resolution | awk '{print $$4}')
	LINK = -L $(MLX) -lmlx -framework OpenGL -framework AppKit
else
	MLX = ./minilibx-linux
	MAX_WIDTH = $(shell xdpyinfo | grep dimensions | awk '{print $$2}' | cut -dx -f1)
	MAX_HEIGHT = $(shell xdpyinfo | grep dimensions | awk '{print $$2}' | cut -dx -f2)
	LINK = -L $(MLX) -lmlx -lm -lXext -lX11
endif
.c.o: $(SRCS)
	$(CC) -c $(FLAGS) $^ -I $(INCDIR) -I $(MLX) -o $@ -DMAX_WIDTH=$(MAX_WIDTH) -DMAX_HEIGHT=$(MAX_HEIGHT)
$(NAME): $(OBJS)
	$(CC) $(FLAGS) $^ -o $(NAME) -I $(MLX) $(LINK)
all: $(NAME)
clean:
	rm -rf $(OBJS)
fclean: clean
	rm -rf $(NAME)
re: fclean all
