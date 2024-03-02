/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:41:30 by hkarrach          #+#    #+#             */
/*   Updated: 2024/02/15 08:52:14 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_libft.h"

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
