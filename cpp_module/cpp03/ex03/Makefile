NAME = DiamondTrap
CC = clang++
CFLAGS = -Wall -Werror -Wextra
SRCS = ./ClapTrap.cpp \
		./ScavTrap.cpp \
		./FragTrap.cpp \
		./DiamondTrap.cpp \
		./main.cpp
OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CC) -c $(CFLAGS) $^

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all