/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:45:38 by hkarrach          #+#    #+#             */
/*   Updated: 2023/11/20 17:45:39 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_substr(char const *s, unsigned int start,size_t len)
{
	char *res;
	unsigned int Start;
	unsigned int i;
	
	res = (char *)malloc((sizeof(char) * len) + 1);
	if (!res)
		return (NULL);
	Start = start;
	i = 0;
	while (s[Start] && len > i)
	{
		res[i] = s[Start];
		i++;
		Start++;
	}
	res[i] = '\0';
	return (res);
}
