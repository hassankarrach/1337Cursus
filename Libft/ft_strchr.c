/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:43:06 by hkarrach          #+#    #+#             */
/*   Updated: 2023/11/21 12:26:22 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *strchr(const char *str, int character)
{
	while (*str)
	{
		if ((char)character == *str)
			return ((char *)str);
		str++;
	}
	return (NULL);
}
