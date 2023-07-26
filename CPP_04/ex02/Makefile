.PHONY: clean all re fclean
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = abstract
SRC = Animal.cpp Cat.cpp Dog.cpp main.cpp Brain.cpp
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