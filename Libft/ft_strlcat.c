/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:29:02 by hkarrach          #+#    #+#             */
/*   Updated: 2023/11/08 21:36:45 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t strlcat(char *dest, const char *src, size_t size)
{
	size_t n;
	size_t dest_len;
	size_t src_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);

	if (size <= dest_len)
	{
		return (size + dest_len);
	}
	n = 0;
	while (n < size - dest_len - 1 && src[n])
	{
		dest[dest_len + n] = src[n];
		n++;
	}
	dest[dest_len + n] = '\0';
	
	return (dest_len + src_len);
}
