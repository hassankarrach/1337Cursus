#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
# endif

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

char	*ft_strdup(char *src);
char	*ft_strjoin(char *s1, char *s2);
int	    len(char *src);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t elements_count, size_t element_size);


# endif