#include "../../../so_long.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		len_s1;
	int		len_s2;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	len_s1 = (int)ft_strlen(s1);
	len_s2 = (int)ft_strlen(s2);
	res = (char *)malloc(((len_s1 + len_s2) * sizeof(char)) + 1);
	if (!res)
		return (NULL);
	ft_memcpy(res, s1, len_s1);
	ft_memcpy(res + len_s1, s2, len_s2);
	res[len_s1 + len_s2] = '\0';
	free(s1);
	return (res);
}
