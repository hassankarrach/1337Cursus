NAME = checker
CC = gcc
FLAGS = -Wall -Wextra -Werror -g

# Printing Vars
RED=\033[0;31m
ROSE=\033[0;95m
GREEN=\033[0;32m
NC=\033[0m

LIBFT_DIR = ../Libft/Mini_Libft
LIBFT_LIB = ../Libft/Mini_Libft/libft.a

# Srcs
SRCS = Actions/actions.c Actions/pa.c Actions/pb.c Actions/ra.c \
		Actions/rb.c Actions/rr.c Actions/rra.c Actions/rrb.c \
		Actions/rrr.c Actions/sa.c Actions/sb.c Actions/ss.c \
		Utils/Error_utils.c Utils/Stack_utils.c \
		../Libft/Gnl/get_next_line_utils.c ../Libft/Gnl/get_next_line.c \
		checker.c checker_utils.c

OBJ = $(SRCS:.c=.o)

# Targets and Rules
all : $(NAME)

$(NAME): $(OBJ) $(LIBFT_LIB)
	@echo "$(GREEN)Compiling $<...$(NC)"
	$(CC) $(FLAGS) $(OBJ) $(LIBFT_LIB) -o $(NAME)

$(LIBFT_LIB) : 
	$(MAKE) -C $(LIBFT_DIR)

clean :
	@echo "$(ROSE)Cleaning object files...$(NC)"
	rm -rf $(OBJ)
	cd ../Libft/Mini_Libft && rm -f ./*.o

fclean : clean
	@echo "$(ROSE)Cleaning library $(NAME)...$(NC)"
	rm -rf $(NAME)
	cd ../Libft/Mini_Libft && rm -f libft.a

re: clean all
.PHONY: all clean fclean re
