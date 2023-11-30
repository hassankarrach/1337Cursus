#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[i])
	{
		count += ft_putchar(s[i]);
		i++;
	}
	return (count);
}