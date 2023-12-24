#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
int		ft_strchr(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *src);
int		len(char *src);

#endif