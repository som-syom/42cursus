NAME = identify
CC = clang++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -g
SRCS = ./main.cpp \
		./Base.cpp \
		./A.cpp \
		./B.cpp \
		./C.cpp
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