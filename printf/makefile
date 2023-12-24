NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_putstr.c \
	ft_putnbr.c \
	ft_putunbr.c \
    ft_putchar.c \
	ft_puthex.c \
	ft_puthex_m.c \
	ft_putadress.c \
	ft_printf.c
	
	
OBJ = ${SRC:.c=.o}
all: $(NAME)
$(NAME):$(OBJ)
		ar rcs $@ $^
%.o : %.c
		cc ${CFLAGS} -o $@ -c $^
clean :
		rm -f $(OBJ)
fclean: clean
		rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re