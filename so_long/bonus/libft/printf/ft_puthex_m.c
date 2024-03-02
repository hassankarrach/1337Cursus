/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_m.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 05:30:09 by hkarrach          #+#    #+#             */
/*   Updated: 2024/01/27 17:33:18 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

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
