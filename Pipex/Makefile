NAME = pipex
NAME_BONUS = pipex_bonus

CFLAGS = -Wall -Wextra -Werror
# -g -fsanitize=address

LIBFT = $(addprefix ./Libft/, ft_strrchr.c ft_strtrim.c ft_split.c ft_substr.c ft_strlen.c ft_strjoin.c ft_gnl_strjoin.c ft_memcpy.c ft_strdup.c ft_strncmp.c ft_strlcpy.c ft_calloc.c ft_bzero.c ft_putstr_fd.c)
SRCS = ./pipex.c ./pipex_utils.c $(LIBFT)
SRCS_BONUS = ./bonus/bonus.c ./bonus/bonus_utils.c ./bonus/bonus_utils2.c ./bonus/bonus_utils3.c $(LIBFT)

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(SRCS_BONUS:.c=.o)

all : $(NAME)
bonus : $(NAME_BONUS)

$(NAME) : $(OBJS)
	cc $(CFLAGS) $^ -o $@
$(NAME_BONUS) : $(BONUS_OBJS)
	cc $(CFLAGS) $^ -o $@
%.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean : 
	rm -f $(OBJS) $(BONUS_OBJS)
fclean : clean
	rm -f $(NAME) $(NAME_BONUS)
re : fclean all	