CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

# mandatory ==========================
NAME	= philosopher
SRCS	= philo/main.c \
			philo/thread.c \
			philo/util.c
INC		= -I philo -I bonus
OBJS	= $(SRCS:.c=.o)

# bonus ==============================
B_NAME	= philo_bonus
B_SRCS	= bonus/main.c \
			bonus/util.c

B_INC	= -I bonus
B_OBJS	= $(B_SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INC)

$(B_NAME) : $(B_OBJS)
	$(CC) $(CFLAGS) -o $(B_NAME) $(B_OBJS) $(B_INC)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

bonus : $(B_NAME)

clean :
	rm -rf $(OBJS)
	rm -rf $(B_OBJS)

fclean : clean
	rm -rf $(NAME)
	rm -rf $(B_NAME)

re : fclean all
