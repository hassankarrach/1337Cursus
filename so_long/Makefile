NAME = so_long

MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
INCLUDES = -I/usr/include -Imlx

SRCS = ./main.c ./srcs/checkers/is_map_valid.c ./srcs/checkers/is_map_valid_helper.c \
	./srcs/libft/get_next_line/get_next_line.c ./srcs/libft/get_next_line/get_next_line_utils.c \
	./srcs/Errors_handling/error_handling.c \
	./srcs/init/initialize_mlx.c ./srcs/init/initialize_map.c ./srcs/init/initialize_textures.c \
	./srcs/init/initialize_hooks.c ./srcs/init/initialize_structs.c \
	./srcs/hooks/on_keypress.c ./srcs/hooks/on_destroy.c ./srcs/events/handle_player_move.c
	
OBJS = $(SRCS:.c=.o)

PRINTF_LIB = libftprintf.a
PRINTF_DIR = srcs/libft/printf

LIBFT_LIB = libft.a
LIBFT_DIR = srcs/libft/libft

all: $(NAME)

$(NAME) : $(OBJS) $(PRINTF_LIB) $(LIBFT_LIB)
	$(CC) $(CFLAGS) libmlx.a $^ -o $@ $(MLX_FLAGS)

$(PRINTF_LIB):
	make -C $(PRINTF_DIR)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	rm -f $(OBJS)
	make -C $(PRINTF_DIR) clean
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(PRINTF_DIR) fclean
	make -C $(LIBFT_DIR) fclean

re : fclean all