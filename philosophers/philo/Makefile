NAME = philo

# Flags
CFLAGS = #-Wall -Wextra -Werror -fsanitize=thread
# Philo_Srcs
SRCS =  philo.c \
		utils.c \
		init.c \
		routine.c \
		monitor.c \
		actions.c \
		destroy.c \

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