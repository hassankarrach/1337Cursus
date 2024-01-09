NAME = push_swap
NAME_BONUS = checker

CC = cc
FLAGS = -Wall -Wextra -Werror -g

SRCS = 	Actions/actions.c Actions/pa.c Actions/pb.c Actions/ra.c \
		Actions/rb.c Actions/rr.c Actions/rra.c Actions/rrb.c \
		Actions/rrr.c Actions/sa.c Actions/sb.c Actions/ss.c \
		Algo/Sort_utils.c Algo/Sort_utils2.c Algo/Stack_sort.c \
		Utils/Stack_utils.c Utils/Stack_utils2.c Utils/Errors_utils.c\
		args_check.c push_swap.c
GNL_SRCS = Libft/Gnl/get_next_line_utils.c Libft/Gnl/get_next_line.c

BONUS_FILES = $(filter-out push_swap.c, $(SRCS)) $(GNL_SRCS) \
		Bonus/checker.c Bonus/checker_utils.c

LIBFT_DIR = Libft/Mini_Libft
LIBFT_LIB = Libft/Mini_Libft/libft.a

OBJS = $(SRCS:.c=.o)
B_OBJS = $(BONUS_FILES:.c=.o)

all : Header $(NAME)

bonus: $(B_OBJS) $(LIBFT_LIB)
	$(CC) $(FLAGS) $(B_OBJS) -o $(NAME_BONUS) $(LIBFT_LIB)

$(NAME) : $(OBJS) $(LIBFT_LIB)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT_LIB) -o $(NAME)

$(LIBFT_LIB) : 
	$(MAKE) -C $(LIBFT_DIR)

clean :
	rm -rf $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean : clean
	rm	-rf $(NAME) $(NAME_BONUS)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: clean all
# .PHONY: all clean fclean re bonus

Header:
	@echo "██████╗ ██╗   ██╗███████╗██╗  ██╗    ███████╗██╗    ██╗ █████╗ ██████╗"
	@echo "██╔══██╗██║   ██║██╔════╝██║  ██║    ██╔════╝██║    ██║██╔══██╗██╔══██╗"
	@echo "██████╔╝██║   ██║███████╗███████║    ███████╗██║ █╗ ██║███████║██████╔╝"
	@echo "██╔═══╝ ██║   ██║╚════██║██╔══██║    ╚════██║██║███╗██║██╔══██║██╔═══╝"
	@echo "██║     ╚██████╔╝███████║██║  ██║    ███████║╚███╔███╔╝██║  ██║██║"
	@echo "╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝    ╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝"