SRC=event_handler.c fractol.c fractol_utils.c julia.c main.c mandelboart.c
SRC_BONUS = $(shell find bonus_dir -name '*.c')

OBJ=$(patsubst %.c, %.o, $(SRC))
OBJ_BONUS=$(patsubst %.c, %.o, $(SRC_BONUS))

CC=cc
FLAGS= -Wall -Wextra -Werror
LINKS_FLAGS= -lmlx -lXext -lX11 #-Lmlx -lmlx -framework OpenGL -framework AppKit 
NAME=fractol

all: $(NAME)
	$(CC) $(OBJ) $(LINKS_FLAGS) -o $(NAME) -lm

fractol: $(OBJ)
	$(CC) -c $(SRC)

bonus: fractol_bonus
	$(CC) $(OBJ_BONUS) $(LINKS_FLAGS) -o $<

fractol_bonus: $(OBJ_BONUS)
	$(CC) -c $(SRC_BONUS)

clean:
	rm -rf $(OBJ) $(OBJ_BONUS)
fclean: clean
	rm -rf $(NAME) fractol_bonus
re: fclean all

.phony: clean fclean re
