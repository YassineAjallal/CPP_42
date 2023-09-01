.PHONY: clean all re fclean
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = bureaucrat
SRC = Bureaucrat.cpp main.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp    ShrubberyCreationForm.cpp
OBJ = $(SRC:.cpp=.o)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all