/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 10:43:40 by hkarrach          #+#    #+#             */
/*   Updated: 2023/12/18 03:52:58 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(va_list args, char c)
{
	int	printed_chars;

	printed_chars = 0;
	if (c == 'd' || c == 'i')
		printed_chars = ft_putnbr(va_arg(args, int));
	else if (c == 's')
		printed_chars = ft_putstr(va_arg(args, char *));
	else if (c == 'c')
		printed_chars = ft_putchar(va_arg(args, int));
	else if (c == 'x')
		printed_chars = ft_puthex(va_arg(args, unsigned int));
	else if (c == 'X')
		printed_chars = ft_puthex_m(va_arg(args, unsigned int));
	else if (c == 'p')
	{
		printed_chars = ft_putstr("0x");
		printed_chars += ft_putadress(va_arg(args, unsigned long long));
	}
	else if (c == 'u')
		printed_chars = ft_putunbr(va_arg(args, unsigned int));
	else if (c == '%')
		printed_chars = ft_putchar('%');
	return (printed_chars);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		printed_chars;
	int		i;

	i = 0;
	va_start(args, format);
	printed_chars = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1])
				printed_chars += ft_check(args, format[++i]);
		}
		else
			printed_chars += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (printed_chars);
}
