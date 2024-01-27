NAME = so_long

MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
LIB_MLX = libmlx.a
# CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I/usr/include -Imlx

GNL_SRCS = $(addprefix ./srcs/libft/get_next_line/, get_next_line.c get_next_line_utils.c)
MINI_LIBFT_SRCS = $(addprefix ./srcs/libft/mini_libft/, ft_itoa.c ft_split.c ft_strjoin.c ft_strlen.c ft_strncmp.c ft_memcpy.c ft_strdup.c ft_substr.c ft_calloc.c ft_bzero.c ft_strlcpy.c ft_strrchr.c)
PRINTF_SRCS = $(addprefix ./srcs/libft/printf/, ft_printf.c ft_putadress.c ft_putchar.c ft_puthex_m.c ft_puthex.c ft_putnbr.c ft_putstr.c ft_putunbr.c)

SRCS = main.c $(addprefix ./srcs/checkers/, is_map_valid.c is_map_valid_helper.c) \
	$(addprefix ./srcs/Errors_handling/, error_handling.c) \
	$(addprefix ./srcs/init/, initialize_mlx.c initialize_map.c initialize_textures.c initialize_hooks.c initialize_structs.c) \
	$(addprefix ./srcs/hooks/, on_keypress.c on_destroy.c) \
	$(addprefix ./srcs/events/, handle_player_move.c player_moves_events.c handle_game_exit_won.c handle_game_lose.c handle_monster_move.c) \
	$(GNL_SRCS) $(MINI_LIBFT_SRCS) $(PRINTF_SRCS)
	
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(LIB_MLX) $^ -o $@ $(MLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re : fclean all