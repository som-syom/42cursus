CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
NAME	= philo_bonus
SRCS	= main.c \
			check.c \
			print.c \
			process.c \
			util.c
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
