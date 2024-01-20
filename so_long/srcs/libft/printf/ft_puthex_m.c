/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_m.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 10:43:59 by hkarrach          #+#    #+#             */
/*   Updated: 2023/12/18 22:52:18 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
