NAME = Intern
CC = clang++
CFLAGS = -Wall -Werror -Wextra
SRCS = ./Bureaucrat.cpp \
		./Form.cpp \
		./ShrubberyCreationForm.cpp \
		./RobotomyRequestForm.cpp \
		./PresidentialPardonForm.cpp \
		./Intern.cpp \
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