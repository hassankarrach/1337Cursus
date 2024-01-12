NAME = push_swap
ARCHIVE = push_swap.a
BONUS = checker	
CC = cc
FLAGS = -Wall -Wextra -Werror
#  -g -O2 -fsanitize=address

# Printing Vars
ROSE=\033[0;95m
GREEN=\033[0;32m

SRCS = 	${addprefix ./Actions/, actions.c pa.c pb.c ra.c rb.c rr.c rra.c rrb.c rrr.c sa.c sb.c ss.c} \
		${addprefix ./Algo/, Sort_utils.c Sort_utils2.c Stack_sort.c} \
		${addprefix ./Utils/, Stack_utils.c Stack_utils2.c Errors_utils.c} \
		args_check.c push_swap.c ${LIBFT_SRCS}

SRCB =	${addprefix ./Actions/, actions.c pa.c pb.c ra.c rb.c rr.c rra.c rrb.c rrr.c sa.c sb.c ss.c} \
		${addprefix ./Bonus/, checker_utils.c checker.c Utils/Stack_utils.c Utils/Error_utils.c} ${LIBFT_SRCS} ${GNL_SRCS}

GNL_SRCS = ${addprefix ./Libft/Gnl/, get_next_line_utils.c get_next_line.c}
LIBFT_SRCS = ${addprefix ./Libft/Mini_Libft/, ft_atol.c ft_split.c ft_strlcpy.c ft_strlen.c ft_strrchr.c ft_strtrim.c}

all : ${NAME}

${NAME} : ${SRCS}
	@echo "Compiling..."
	@${CC} ${FLAGS} ${SRCS} -o ${NAME}
	@echo "${GREEN}End Compiling."

bonus : ${BONUS}

${BONUS} : ${SRCB}
	@echo "Compiling Checker..."
	@${CC} ${FLAGS} ${SRCB} -o ${BONUS}
	@echo "${GREEN}End Compiling."

clean :
	@echo "No Object Files to be cleaned."

fclean : clean
	@echo "${ROSE}Removing Executable Files..."
	@rm -f ${NAME} ${BONUS}
	@echo "${GREEN}Done."

re : fclean all

.PHONY : clean fclean re bonus
