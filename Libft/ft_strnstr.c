/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:45:03 by hkarrach          #+#    #+#             */
/*   Updated: 2023/11/20 17:45:27 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;

       	i = 0;
    	while (s1[i] && i < n)
    	{
       		j = 0;
       		while (s1[i + j] == s2[j] && s2[j] && i + j < n)
            	j++;
       		if (!s2[j])
            		return ((char *)s1 + i);
        	i++;
    	}
    return NULL;	
}


// int main()
// {
// 	char *str1 = "Hello, My name is Hassan";
// 	char *str2 = "name";
// 	printf("%s", ft_strnstr(str1, str2, 14));
// }
