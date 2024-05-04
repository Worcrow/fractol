SRC=$(shell find . -name '*.c')
OBJ=$(patsubst %.c, %.o, $(SRC))
CC=cc
FLAGS= -Wall -Wextra -Werror
LINKS_FLAGS= -lmlx -lXext -lX11 -lm 
NAME=fractol

all: $(NAME)
	$(CC) $(OBJ) $(LINKS_FLAGS) -o $(NAME)

fractol: $(OBJ)
	$(CC) -c $(SRC)

clean:
	rm $(OBJ)
fclean: clean
	rm $(NAME)
re: fclean all

.phony: clean fclean re
