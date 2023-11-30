#include "ft_printf.a"

int	ft_putunbr(unsigned int nb)
{
	unsigned int	res;

	res = 0;
	if (nb > 9)
	{
		res += ft_putunbr(nb / 10);
		res += ft_putunbr(nb % 10);
	}
	else
		res += ft_putchar(nb + 48);
	return (res);
}