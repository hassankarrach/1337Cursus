#include "ft_printf.h"

int	ft_puthex(unsigned int nb)
{
	int		re;
	char	*base;

	re = 0;
	base = "0123456789abcdef";
	if (nb >= 16)
	{
		re += ft_puthex(nb / 16);
		re += ft_puthex(nb % 16);
	}
	else
		re += ft_putchar(base[nb % 16]);
	return (re);
}