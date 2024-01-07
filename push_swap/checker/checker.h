#ifndef CHECKER_H
# define CHECKER_H

# include <fcntl.h>
# include "../Push_swap/push_swap.h"
# define BUFFER_SIZE 4

char	*get_next_line(int fd);
char	*read_line(int fd, char *str);
char	*get_the_rest(char *str);
char	*get_the_line(char *str);
int     ft_strlen(char *str);
int     ft_strchr(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);

#endif