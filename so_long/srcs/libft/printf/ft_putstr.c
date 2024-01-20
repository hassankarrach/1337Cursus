/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 10:44:07 by hkarrach          #+#    #+#             */
/*   Updated: 2023/12/18 21:44:02 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
