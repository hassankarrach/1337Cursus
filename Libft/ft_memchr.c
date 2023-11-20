/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:42:03 by hkarrach          #+#    #+#             */
/*   Updated: 2023/11/20 17:39:55 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *memchr(const void *str, int c, size_t n)
{
	size_t i;
	char *s;

       	s = (char *) str;
	i = 0;

	while(i < n)
	{
		if((unsigned char)s[i] == (unsigned char)c)
			return (char *)(str + i);
		i++;
	}

	return (NULL);
}
