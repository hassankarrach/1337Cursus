/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:45:38 by hkarrach          #+#    #+#             */
/*   Updated: 2023/11/23 17:33:26 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_substr(char const *s, unsigned int start,size_t len)
{
	char *res;
	unsigned int i;
	unsigned int s_len = ft_strlen(s);

	if(!s)
		return (NULL);
	if(start > s_len)
	{
		res = ft_calloc(1, sizeof(char));
		return (res);
	}
	
	res = (char *)malloc((sizeof(char) * len) + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s[start] && len > i)
	{
		res[i] = s[start];
		i++;
		start++;
	}
	res[i] = '\0';
	return (res);
}
