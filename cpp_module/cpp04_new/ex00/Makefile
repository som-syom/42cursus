NAME = Animal
CC = clang++
CFLAGS = -Wall -Werror -Wextra
SRCS = ./Animal.cpp \
		./Dog.cpp \
		./Cat.cpp \
		./WrongAnimal.cpp \
		./WrongCat.cpp \
		./main.cpp

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all