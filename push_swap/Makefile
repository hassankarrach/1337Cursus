NAME = push_swap
ARCHIVE = push_swap.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
MAKE_LIB = ar -rcs

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

all : $(NAME)

$(NAME) : $(ARCHIVE)
	$(CC) $< -o $@

$(ARCHIVE) : $(OBJS)
	$(MAKE_LIB) $(ARCHIVE) $^

%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@ 

bonus : $(O_SRCB)
	${CC} $(CFLAGS) ${O_SRCB} -o checker
	
clean :
	rm -f $(OBJS) $(O_SRCB) $(ARCHIVE)

fclean : clean
	rm -f $(NAME) checker

re : fclean all

.PHONY : all clean fclea re