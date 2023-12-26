#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H 

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

/* FUNCTIONS */
char	*read_and_getline(char *buf, int fd, char *line);
void	free_it(char *str);
char	*ft_strjoin(char *line, char *buf);
void	shift(char *buf, int endl);
int		ft_strlen(char *s);
int		ft_strchr( char *s, int readit);
char	*get_next_line(int fd);
#endif