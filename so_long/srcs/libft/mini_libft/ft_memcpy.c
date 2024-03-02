/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 05:29:01 by hkarrach          #+#    #+#             */
/*   Updated: 2024/01/27 16:43:31 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*buffer;
	const unsigned char	*source = src;

	buffer = dst;
	if (dst == src)
	{
		return (dst);
	}
	while (n > 0)
	{
		*buffer = *source;
		buffer++;
		source++;
		n--;
	}
	return (dst);
}
