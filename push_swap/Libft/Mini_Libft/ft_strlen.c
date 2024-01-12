/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 09:01:11 by hkarrach          #+#    #+#             */
/*   Updated: 2024/01/12 14:09:36 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}
