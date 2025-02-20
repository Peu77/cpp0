CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = tests.cpp Account.cpp
OBJ = $(SRC:.cpp=.o)
NAME = accounts

INCLUDES = -I./includes

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re% 