/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:36:53 by hkarrach          #+#    #+#             */
/*   Updated: 2023/11/20 17:36:53 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int dig_count(int n)
{
	int dig;

	dig = !n;
	while (n)
	{
		n/= 10;
		dig++;
	}
	return (dig);
}

char *ft_itoa(int n)
{
	int sign;
	int d_count;
	char *res;

	sign = n < 0; //One if it less than Zero for the MInus.
	d_count = dig_count(n) + sign;
	res = (char *)malloc(sizeof(char) * (d_count + 1));
	if (!res)
		return (res);
	res[d_count] = '\0';
	if (sign)
	{
		*res = '-';
		res[--d_count] = -(n % 10) + '0';
		n = -(n/10);
	}
	while(d_count-- - sign)
	{
		res[d_count] = n % 10 + '0';
		n /= 10;
	}
	return res;
}
