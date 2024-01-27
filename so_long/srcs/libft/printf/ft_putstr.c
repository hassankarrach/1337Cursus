#include "../../../so_long.h"

int	ft_putstr(char *s)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[i])
	{
		res += ft_putchar(s[i]);
		i++;
	}
	return (res);
}
