#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	ft_putnbr(int nb);
int	ft_putstr(char *str);
int	ft_putunbr(unsigned int nb);
int	ft_puthex_m(unsigned int nb);
int	ft_puthex(unsigned int nb);
int	ft_putadress(unsigned long nb);

#endif