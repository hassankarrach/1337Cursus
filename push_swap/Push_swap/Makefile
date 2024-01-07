NAME = push_swap
CC = gcc
FLAGS = -Wall -Wextra -Werror

SRCS = Actions/actions.c Actions/pa.c Actions/pb.c Actions/ra.c \
		Actions/rb.c Actions/rr.c Actions/rra.c Actions/rrb.c \
		Actions/rrr.c Actions/sa.c Actions/sb.c Actions/ss.c \
		Algo/Sort_utils.c Algo/Sort_utils2.c Algo/Stack_sort.c \
		Libft/ft_atol.c Libft/ft_split.c Libft/ft_strlcpy.c \
		Libft/ft_strlen.c \
		Utils/Stack_utils.c Utils/Stack_utils2.c Utils/Errors_utils.c\
		args_check.c push_swap.c

OBJ = $(SRCS:.c=.o)

all : Header $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm	-rf $(NAME)

re: clean all
# .PHONY: all clean fclean re bonus

Header:
	@echo "██████╗ ██╗   ██╗███████╗██╗  ██╗    ███████╗██╗    ██╗ █████╗ ██████╗"
	@echo "██╔══██╗██║   ██║██╔════╝██║  ██║    ██╔════╝██║    ██║██╔══██╗██╔══██╗"
	@echo "██████╔╝██║   ██║███████╗███████║    ███████╗██║ █╗ ██║███████║██████╔╝"
	@echo "██╔═══╝ ██║   ██║╚════██║██╔══██║    ╚════██║██║███╗██║██╔══██║██╔═══╝"
	@echo "██║     ╚██████╔╝███████║██║  ██║    ███████║╚███╔███╔╝██║  ██║██║"
	@echo "╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝    ╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝"