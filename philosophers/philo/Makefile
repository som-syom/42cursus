CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g -fsanitize=address
NAME	= philo
SRCS	= main.c \
			thread.c \
			util.c \
			check.c
INC		= -pthread
OBJS	= $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INC)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
