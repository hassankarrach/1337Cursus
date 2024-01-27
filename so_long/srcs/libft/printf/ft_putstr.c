/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 05:30:17 by hkarrach          #+#    #+#             */
/*   Updated: 2024/01/27 05:30:18 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

int	ft_putstr(char *s)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[i])
	{
		res += ft_putchar(s[i]);
		i++;
	}
	return (res);
}
