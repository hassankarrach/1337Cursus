/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 10:44:02 by hkarrach          #+#    #+#             */
/*   Updated: 2023/12/18 21:44:37 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
