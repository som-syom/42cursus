NAME = ClapTrap
CC = clang++
CFLAGS = -Wall -Wextra -Werror
SRCS = ./ClapTrap.cpp \
		./ScavTrap.cpp \
		./main.cpp
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all