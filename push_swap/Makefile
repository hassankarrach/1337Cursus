NAME = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror -g -O2

SRCS = 	Actions/actions.c Actions/pa.c Actions/pb.c Actions/ra.c \
		Actions/rb.c Actions/rr.c Actions/rra.c Actions/rrb.c \
		Actions/rrr.c Actions/sa.c Actions/sb.c Actions/ss.c \
		Algo/Sort_utils.c Algo/Sort_utils2.c Algo/Stack_sort.c \
		Utils/Stack_utils.c Utils/Stack_utils2.c Utils/Errors_utils.c\
		args_check.c push_swap.c

LIBFT_DIR = Libft/Mini_Libft
LIBFT_LIB = Libft/Mini_Libft/libft.a

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT_LIB)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT_LIB) -o $(NAME)

$(LIBFT_LIB) : 
	$(MAKE) -C $(LIBFT_DIR)

clean :
	rm -rf $(OBJS) 
	$(MAKE) clean -C $(LIBFT_DIR)

fclean : clean
	rm	-rf $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: clean all
# .PHONY: all clean fclean re bonus
