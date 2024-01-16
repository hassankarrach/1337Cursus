NAME = push_swap
BONUS_NAME = checker
CC = gcc
CFLAGS = -Wall -Werror -Wextra

# Color codes
BLUE = \033[34m
GREEN = \033[32m
ROSE = \033[35m
RESET = \033[0m

SRCS = 	${addprefix ./Actions/, actions.c pa.c pb.c ra.c rb.c rr.c rra.c rrb.c rrr.c sa.c sb.c ss.c} \
		${addprefix ./Algo/, Sort_utils.c Sort_utils2.c Stack_sort.c Sort_Five.c} \
		${addprefix ./Utils/, Stack_utils.c Stack_utils2.c Errors_utils.c} \
		args_check.c push_swap.c ${LIBFT_SRCS}

SRCB =	${addprefix ./Actions/, actions.c pa.c pb.c ra.c rb.c rr.c rra.c rrb.c rrr.c sa.c sb.c ss.c} \
		${addprefix ./Bonus/, checker_utils.c checker.c Utils/Stack_utils.c Utils/Error_utils.c} ${LIBFT_SRCS} ${GNL_SRCS}

GNL_SRCS = ${addprefix ./Libft/Gnl/, get_next_line_utils.c get_next_line.c}
LIBFT_SRCS = ${addprefix ./Libft/Mini_Libft/, ft_atol.c ft_split.c ft_strlcpy.c ft_strlen.c ft_strrchr.c ft_strtrim.c}

OBJS = $(SRCS:.c=.o)
O_SRCB = $(SRCB:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(BLUE)Linking objects into executable:$(RESET) $(GREEN)$@$(RESET)"
	$(CC) $(CFLAGS) $^ -o $@
	@echo "$(GREEN)Compilation completed successfully!$(RESET)"

%.o: %.c
	@echo "$(BLUE)Compiling:$(RESET) $(GREEN)$<$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(O_SRCB)
	@echo "$(BLUE)Linking objects into bonus executable:$(RESET) $(GREEN)$@$(RESET)"
	$(CC) $(CFLAGS) $^ -o $@
	@echo "$(GREEN)Bonus compilation completed successfully!$(RESET)"

clean:
	@echo "$(ROSE)Cleaning object files...$(RESET)"
	rm -f $(OBJS) $(O_SRCB)

fclean: clean
	@echo "$(ROSE)Cleaning executables...$(RESET)"
	rm -f $(NAME) checker

re: fclean all

.PHONY: all clean fclean re bonus
