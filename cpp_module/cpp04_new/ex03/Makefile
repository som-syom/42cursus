NAME = Materia
CC = clang++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -g
SRCS = ./AMateria.cpp \
		./Character.cpp \
		./Cure.cpp \
		./Fire.cpp \
		./Ice.cpp \
		./MateriaSource.cpp \
		./Wind.cpp \
		./main.cpp

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

.cpp.o :
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all