.PHONY: clean all re fclean
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = diamondTrap
SRC = ClapTrap.cpp main.cpp FragTrap.cpp ScavTrap.cpp DiamondTrap.cpp
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