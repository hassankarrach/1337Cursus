NAME = philo

# Flags
#CFLAGS = #-Wall -Wextra -Werror

# Libs-Srcs

# MiniShell-Srcs
SRC_UTILS = $(addprefix ./src/utils/, ft_atoi.c errors.c threads_wait.c)
SRC_INITS = $(addprefix ./src/inits/, inits.c)
SRC_PHILOSOPHER = $(addprefix ./src/philosopher/, create_philosopher.c lifecycle_philosopher.c)
SRCS =  ./src/philo.c $(SRC_UTILS) $(SRC_INITS) $(SRC_PHILOSOPHER)

# Objects
OBJS = $(SRCS:.c=.o)

# Deps
all : $(NAME)

# Compiling
.c.o : 
	cc -g -pthread $(CFLAGS) -c -o $@ $^
$(NAME) : $(OBJS)
	cc -g -pthread $(CFLAGS) $(OBJS) -o $(NAME) 

# Cleaning
clean : 
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re : fclean all 