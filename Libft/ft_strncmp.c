/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:44:33 by hkarrach          #+#    #+#             */
/*   Updated: 2023/11/21 12:01:36 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i;
	i = 0;
	if (n == 0)
		return (0);
	while (str1[i] && str1[i] == str2[i] && i < n-1)
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
