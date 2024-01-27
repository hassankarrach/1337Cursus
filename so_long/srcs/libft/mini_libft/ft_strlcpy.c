/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 05:29:14 by hkarrach          #+#    #+#             */
/*   Updated: 2024/01/27 05:29:15 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	n;

	n = 0;
	if (size == 0)
	{
		return (ft_strlen(src));
	}
	while (n < size - 1 && src[n])
	{
		dest[n] = src[n];
		n++;
	}
	if (n < size)
		dest[n] = '\0';
	while (src[n])
		n++;
	return (n);
}
