#include "ft_printf.h"

int	ft_puthex_m(unsigned int nb)
{
	int		re;
	char	*base;

	re = 0;
	base = "0123456789ABCDEF";
	if (nb >= 16)
	{
		re += ft_puthex_m(nb / 16);
		re += ft_puthex_m(nb % 16);
	}
	else
		re += ft_putchar(base[nb % 16]);
	return (re);
}