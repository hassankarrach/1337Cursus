/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:45:19 by hkarrach          #+#    #+#             */
/*   Updated: 2023/11/20 17:45:20 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrchr(const char *str, int c)
{
	int str_len = ft_strlen(str);
	str_len--;

	if(!str)
		return (NULL);
	while (str_len >= 0)
	{
		if(str[str_len] == (unsigned char)c)
			return (char *)(str + str_len);
		str_len--;
	}

	return (NULL);
}
