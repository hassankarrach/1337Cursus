/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 10:43:45 by hkarrach          #+#    #+#             */
/*   Updated: 2023/12/03 11:17:19 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
