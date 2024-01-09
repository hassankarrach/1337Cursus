NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_atol.c ft_split.c ft_strlcpy.c ft_strlen.c
OBJS = $(SRCS:.c=.o)	

all : $(NAME)

$(NAME) : $(OBJS)
	@echo "Creating Libft library..."
	ar -rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(OBJ) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re