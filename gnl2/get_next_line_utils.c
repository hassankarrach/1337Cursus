#include "get_next_line.h"

int ft_strlen(char *str)
{
	int i;

	i = 0;
	if(!str)
		return (0);
	while(str[i])
		i++;
	return (i);
}

int	ft_strchr(char *str, char c)
{
	int i;

	i = 0;
	if(!str)
		return (NULL);
	while(str[i])
	{
		if(str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char *ft_strjoin(char *s1, char *s2)
{
	int i;
	int j;
	char *res;

	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	s1[0] = '\0';
	if (!s1 || !s2)
		return (NULL);
	
	res = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if(!res)
		return (NULL);
	while(s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while(s2[j])
	{
		res[i+j] = s2[j];
		j++;
	}
	
	res[i+j] = '\0';
	return (res);
}