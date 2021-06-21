NAME	= megaphone
CC		= clang++
CFLAGS	= -Wall -Werror -Wextra -std=c++98 -pedantic-errors
SRCS	= ./megaphone.cpp

OBJS	= $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all