/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:41:56 by hkarrach          #+#    #+#             */
/*   Updated: 2023/11/21 12:13:55 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void *ft_memset(void *ptr,int value, size_t len)
{
	char *p;

	p = (char *)ptr;
	while(len > 0)
	{
		p[len - 1] = value;
		len--;
	}
	return (ptr);
}
