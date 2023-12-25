#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n > 0)
	{
		*p = 0;
		p++;
		n--;
	}
}

void	*ft_calloc(size_t elements_count, size_t element_size)
{
	void	*result;
	size_t	buffer_size;

	buffer_size = elements_count * element_size;
	if (elements_count > 0 && element_size > 0 && buffer_size
		/ elements_count != element_size)
		return (NULL);
	result = (void *)malloc(buffer_size);
	if (!result)
		return (NULL);
	else
		ft_bzero(result, buffer_size);
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

int	len(char *src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	int		b;
	int		a;

	b = 0;
	a = 0;
	if (!s1)
		s1 = ft_strdup("");
	join = (char *) malloc(len(s1) + len(s2) + 1);
	if (!join)
		return (0);
	while (s1[a])
	{
		join[a] = s1[a];
		a++;
	}
	while (s2[b])
	{
		join[a] = s2[b];
		a++;
		b++;
	}
	join[a] = '\0';
	return (join);
}

char	*ft_strdup(char *src)
{
	char	*dup;
	int		i;

	i = 0;
	dup = (char *) malloc(len(src) + 1);
	if (!dup)
		return (0);
	while (i < len(src))
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
