/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:43:51 by hkarrach          #+#    #+#             */
/*   Updated: 2024/02/13 05:54:44 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_libft.h"

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
