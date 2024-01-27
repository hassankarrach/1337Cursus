#include "../../../so_long.h"

int	ft_puthex(unsigned int nb)
{
	int		res;
	char	*base;

	res = 0;
	base = "0123456789abcdef";
	if (nb >= 16)
	{
		res += ft_puthex(nb / 16);
		res += ft_puthex(nb % 16);
	}
	else
		res += ft_putchar(base[nb % 16]);
	return (res);
}
