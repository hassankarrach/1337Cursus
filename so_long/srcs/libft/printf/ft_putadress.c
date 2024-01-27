#include "../../../so_long.h"

int	ft_putadress(unsigned long nb)
{
	int		res;
	char	*base;

	res = 0;
	base = "0123456789abcdef";
	if (nb >= 16)
	{
		res += ft_putadress(nb / 16);
		res += ft_putadress(nb % 16);
	}
	else
		res += ft_putchar(base[nb % 16]);
	return (res);
}
