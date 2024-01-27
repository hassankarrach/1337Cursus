#include "../../../so_long.h"

int	ft_puthex_m(unsigned int nb)
{
	char	*base;
	int		res;

	res = 0;
	base = "0123456789ABCDEF";
	if (nb >= 16)
	{
		res += ft_puthex_m(nb / 16);
		res += ft_puthex_m(nb % 16);
	}
	else
		res += ft_putchar(base[nb % 16]);
	return (res);
}
