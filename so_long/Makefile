SRC = ./src/main.c ./src/init.c ./src/update.c ./src/game_checkers.c ./src/close.c ./src/render.c ./src/control.c ./src/utils.c ./src/input_checkers.c ./src/errors.c ./src/map_utils.c  ./src/map_mod.c ./src/animation.c
OBJ = ${SRC:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror -Ofast -g
NAME = so_long
LIBFT = libft/libft.a
PRINTF = ft_printf/ft_printf.a
INCLUDES = -I ft_printf/includes -I libft/includes
MINILIBX = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -opengl

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(OBJ) $(LIBFT) $(PRINTF) $(MINILIBX) $(INCLUDES) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(LIBFT):
	$(MAKE) -C libft

$(PRINTF):
	$(MAKE) -C ft_printf

clean:
	$(MAKE) -C ft_printf clean
	$(MAKE) -C libft clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C ft_printf fclean
	$(MAKE) -C libft fclean
	rm -f $(NAME)

re: fclean all