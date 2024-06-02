NAME = philo

# Flags
#CFLAGS = #-Wall -Wextra -Werror

# Libs-Srcs

# MiniShell-Srcs
SRCS =  ./src/philo.c

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