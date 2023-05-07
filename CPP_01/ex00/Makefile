.PHONY: clean all re fclean
CC = c++
CFLAGS = -Wall -Wextra -Werror
NAME = zombie
SRC = newZombie.cpp main.cpp randomChump.cpp Zombie.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME)


clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all