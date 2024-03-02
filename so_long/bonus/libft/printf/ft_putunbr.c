/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 05:30:19 by hkarrach          #+#    #+#             */
/*   Updated: 2024/01/27 17:33:26 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

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
